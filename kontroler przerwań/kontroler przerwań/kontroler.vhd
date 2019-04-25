
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity irq_control is
port (
	reset, clk : in std_logic;
	data_out   : in std_logic_vector (7 downto 0);
	data_in	   : out std_logic_vector (7 downto 0);
	adres	   : in std_logic_vector (1 downto 0);
	nr_w	   : in std_logic;
	irq_in	   : in std_logic_vector (4 downto 0);
	irq_out	   : out std_logic);
end irq_control;

architecture irq_control_a of irq_control is

-- memory map (adresy rejestrow programowalnych):
constant JAK_adr : std_logic_vector(1 downto 0):= "01";
constant MASKA_adr :std_logic_vector(1 downto 0):="11";
constant KTORY_adr :std_logic_vector(1 downto 0):="10";

-- rejestry
signal JAK : std_logic_vector (4 downto 0); -- okresla czy „aktywne" zboczem/poziomem
signal MASKA : std_logic_vector (4 downto 0); -- gdy '0' to przerw. „zamaskowane" (niewidoczne)
signal KTORY : std_logic_vector (2 downto 0); -- okresla z jakiego zrodla pochodzi przerwanie

-- selektory rejestrow
signal JAK_sel : std_logic;
signal MASKA_sel : std_logic;
signal KTORY_sel : std_logic;

-- inne
signal a_irq : std_logic_vector (4 downto 0);
signal aa_irq : std_logic_vector (4 downto 0);
signal zbocze : std_logic_vector (4 downto 0);
signal jest_irq : std_logic_vector (4 downto 0);
signal n_jest_irq : std_logic_vector (4 downto 0);

begin	 -- "cialo architektury"
-- rozpoznawanie zbocza na irq_in
edge_finder: process (reset, clk)
begin 
	if reset = '0' then
		a_irq <= (others => '0');
		aa_irq <= (others => '0');
	elsif clk'event and clk='1' then
		a_irq <= irq_in;
		aa_irq <= a_irq;
	end if;
end process edge_finder;

zbocze <= a_irq and not aa_irq; -- poza procesem!

-- rejestry programowalne (JAK, MASKA)
reg_prog: process (reset, clk)
begin 
	if reset = '0' then
		MASKA <= (others => '0');
		JAK   <= (others => '0');
	elsif clk'event and clk='1' then
		if MASKA_sel='1' and nr_w = '1' then
			MASKA <= data_out (4 downto 0);
		elsif JAK_sel = '1' and nr_w = '1' then
			JAK <= data_out (4 downto 0);
		end if;
	end if;
end process reg_prog;

-- adresowanie
MASKA_sel <= '1' when adres = MASKA_adr else '0';
KTORY_sel <= '1' when adres = KTORY_adr else '0';
JAK_sel	<= '1' when adres = JAK_adr else '0';

-- odczyt rejestrow
data_in <= "000" & MASKA when (MASKA_sel='1' and nr_w='0')
      	else  "000" & JAK when (JAK_sel='1' and nr_w='0')
      	else  "00000" & KTORY when (KTORY_sel='1' and nr_w='0')
	else  "0000" &"0000";

-- Jaki charakter przerwania (zbocze/poziom)
jest_irq(4)<= zbocze(4) when JAK(4)='1' else irq_in(4);
jest_irq(3)<= zbocze(3) when JAK(3)='1' else irq_in(3);
jest_irq(2)<= zbocze(2) when JAK(2)='1' else irq_in(2);
jest_irq(1)<= zbocze(1) when JAK(1)='1' else irq_in(1);
jest_irq(0)<= zbocze(0) when JAK(0)='1' else irq_in(0);
n_jest_irq <= jest_irq and MASKA; -- maskowanie

-- dekodowanie zrodla przerwania
irq_source: process (reset, clk)
begin
	if reset='0' then
		KTORY<= "000";
	elsif clk'event and clk='1' then
		if n_jest_irq(0) = '1' then KTORY <= "001";
		elsif n_jest_irq(1) = '1' then KTORY <= "010";
		elsif n_jest_irq(2) = '1' then KTORY <= "011";
		elsif n_jest_irq(3) = '1' then KTORY <= "100";
		elsif n_jest_irq(4) = '1' then KTORY <= "101";
		else KTORY <= "000";
		end if;
	end if;
end process irq_source;

-- wyjscie z kontrolera (czyli 5-wej. bramka OR)
irq_out <=  n_jest_irq(0) or n_jest_irq(1) or n_jest_irq(2) or n_jest_irq(3) or n_jest_irq(4);

end irq_control_a; -- koniec architektury :)


