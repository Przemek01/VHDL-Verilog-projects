library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.std_logic_unsigned.all;



entity CRC16 is
port
 (
 
 clk    : in std_logic;
nreset : in std_logic;

 -- rejestr wejsciowy danych
we     : in std_logic_vector (15 downto 0);


 -- rejestr CRC dzielnik
 we2     : in std_logic_vector (16 downto 0);
 -- poczatkowy stan kodu nadmiarowego rejestr crc wyjsciowy
 we3 : in std_logic_vector (15 downto 0);



-- licznik CRC serializer
B : in std_logic_vector (4 downto 0);
Q : out std_logic_vector (4 downto 0);


--licznik transmisji
Q2 : out std_logic;

wy_dane2     : out std_logic_vector (15 downto 0);
-- wysylanie
clk_wy : out std_logic;
wyslij : out std_logic;
transmisja_dane_wyj :out std_logic;

wy     : out std_logic_vector (15 downto 0)
);
 
end CRC16;

architecture Behavioral of CRC16 is

signal we_dane : std_logic_vector(15 downto 0);
signal we_CRC : std_logic_vector(16 downto 0);

signal wy_dane : std_logic_vector(15 downto 0);
signal wy_CRC : std_logic_vector(15 downto 0);


signal transmisja_dane_wej : std_logic_vector(15 downto 0);

signal c : std_logic_vector(4 downto 0);
signal c2 : std_logic_vector(1 downto 0);
signal load : std_logic;


begin

rejestr_CRC_dzielnik: process (nreset,clk,load) 

      begin
      if(nreset = '0') then 

      we_CRC <= (others => '0');
      elsif (clk'Event  and clk='1' and load = '1') then 

      we_CRC  <=  we2(16 downto 0);
      end if;
end process rejestr_CRC_dzielnik;


rejestr_wejsciowy: process (nreset,clk) 

    begin
     if(nreset = '0') then 

      we_dane <= (others => '0');
                  elsif (clk'Event  and clk='1') then 
                  if load = '1'  then
                  
                      we_dane(15 downto 0) <= we(15 downto 0);
                      wy_CRC(15 downto 0) <= we3(15 downto 0);
                      
                    
                      





                  elsif(load = '0' and we_dane(15) = '1') then
						
we_dane(15)  <= we_dane(15) xor we_CRC(16);
we_dane(14)  <= we_dane(14) xor we_CRC(15);
we_dane(13)  <= we_dane(13) xor we_CRC(14);
we_dane(12)  <= we_dane(12) xor we_CRC(13);
we_dane(11)  <= we_dane(11) xor we_CRC(12);
we_dane(10)  <= we_dane(10) xor we_CRC(11);
we_dane(9)   <= we_dane(9) xor we_CRC(10);
we_dane(8)   <= we_dane(8) xor we_CRC(9);
we_dane(7)   <= we_dane(7) xor we_CRC(8);
we_dane(6)   <= we_dane(6) xor we_CRC(7);
we_dane(5)   <= we_dane(5) xor we_CRC(6);
we_dane(4)   <= we_dane(4) xor we_CRC(5);
we_dane(3)   <= we_dane(3) xor we_CRC(4);
we_dane(2)   <= we_dane(2) xor we_CRC(3);
we_dane(1)   <= we_dane(1) xor we_CRC(2);
we_dane(0)   <= we_dane(0) xor we_CRC(1);
wy_CRC(15)   <= wy_CRC(15) xor we_CRC(0);


                
                  end if;
                  
     elsif(clk'Event  and clk = '0' and load = '0' and c > "00001" ) then
we_dane <= we_dane(14 downto 0) & wy_CRC(15);             
wy_CRC <=   wy_CRC(14 downto 0)  & '0';    


  
     
      end if;
end process rejestr_wejsciowy;
 














licznik: process (nreset,clk) 

begin
if (nreset = '0') then 
c <= (others=> '0');

elsif (clk'event  and clk='1')  then 

if (c > B ) then 
c <= "00000";
else
c <= c + 1 ;
end if;


end if;

end process licznik;




licznik2: process (nreset,clk,c2) 

begin
if (nreset = '0') then 
c2 <= (others=> '0');


elsif (clk'event  and clk='1' and c = B)  then 
if (c2 = "11" ) then 
c2 <= "00";
else
c2 <= c2 + 1 ;

end if;
end if;
end process licznik2;

-- pobieranie danych
load <= '1' when c = "00000" else '0';


Q <= c;
Q2 <= c2(0);

wysylanie:process(c)
begin
  
   
                  if(c2(0) = '0') then
                       if(c = "00001") then
                        transmisja_dane_wej <= we_dane(15 downto 0);
                        else
                        transmisja_dane_wej <= '0' & transmisja_dane_wej(15 downto 1);
                        end if;
                     
                  elsif(c2(0) = '1' ) then
                      if(c = "00000") then
                        transmisja_dane_wej <= we_dane(15 downto 0);
                        else
                        transmisja_dane_wej <= '0' & transmisja_dane_wej(15 downto 1);
                        end if;
              
 end if;            
end process wysylanie;

clk_wy <= clk;
wyslij <= nreset;
transmisja_dane_wyj <= transmisja_dane_wej(0);

wy <= we_dane(15 downto 0);
 wy_dane2 <= transmisja_dane_wej(15 downto 0 );
end Behavioral;