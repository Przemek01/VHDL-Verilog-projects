
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 

ENTITY tb IS
END tb;
 
ARCHITECTURE behavior OF tb IS 
 

 
    COMPONENT termometr_PID
    PORT(
	 ------------------------------------
         reset : IN  std_logic;
         IN_OUT : INOUT  std_logic;
         clk : IN  std_logic;
			--------------------------------LCD
			a_to_g : out STD_LOGIC_VECTOR (6 downto 0);		-- poszczególne segmenty wyœwietlacza, segmenty a,b,c,d,e,f,g
         anody : out STD_LOGIC_VECTOR (3 downto 0);			-- sekcje wyœwietlacza, wspólne anody
         dot : out  STD_LOGIC	
        );
    END COMPONENT;
    

   --Inputs
   signal reset : std_logic := '0';
   signal clk : std_logic := '0';

	--BiDirs
   signal IN_OUT : std_logic;
	
	--LCD----------
signal a_to_g :  STD_LOGIC_VECTOR (6 downto 0);		-- poszczególne segmenty wyœwietlacza, segmenty a,b,c,d,e,f,g
signal anody :  STD_LOGIC_VECTOR (3 downto 0);			-- sekcje wyœwietlacza, wspólne anody
signal dot :   STD_LOGIC;	
   -- Clock period definitions
   constant clk_period : time := 20 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: termometr_PID PORT MAP (
	
          reset => reset,
          IN_OUT => IN_OUT,
          clk => clk,
			 
			 a_to_g => a_to_g,
          anody => anody,
          dot => dot
        );

   -- Clock process definitions
   clk_process :process
   begin
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
   end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
	
		 reset <= '1';
      wait for clk_period*1;
reset <= '0';
wait for clk_period*200;
      -- insert stimulus here 

      wait;
   end process;

END;
