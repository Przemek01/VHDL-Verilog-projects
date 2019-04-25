
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;



entity CRC16_tb is

end CRC16_tb;

architecture Behavioral of CRC16_tb is

component CRC16
port
 (
 -- rejestr wejsciowy danych
we     : in std_logic_vector (15 downto 0);
wy     : out std_logic_vector (15 downto 0);
clk    : in std_logic;
nreset : in std_logic;

 -- rejestr CRC dzielnik
 we2     : in std_logic_vector (16 downto 0);
 -- poczatkowy stan kodu nadmiarowego
 we3 : in std_logic_vector (15 downto 0);

-- licznik 
B : in std_logic_vector (4 downto 0);
Q : out std_logic_vector (4 downto 0);


--licznik transmisji
Q2 : out std_logic;

wy_dane2     : out std_logic_vector (15 downto 0);

clk_wy : out std_logic;
wyslij : out std_logic;
transmisja_dane_wyj :out std_logic
);
end component;

component CRC16_deserializer
port
 (
 clk_2    : in std_logic;
 nreset_2 : in std_logic;
 
  -- rejestr CRC dzielnik
 we2_2     : in std_logic_vector (16 downto 0);
 
 -- licznik CRC serializer
 B_2 : in std_logic_vector (4 downto 0);
 Q_2 : out std_logic_vector (4 downto 0);

 
 --licznik transmisji
 Q2_2 : out std_logic;

 
 -- wysylanie
 
 transmisja_dane_wyj_2 :in std_logic;
 we_dane_2_out :out std_logic_vector(15 downto 0);
 DANE :out std_logic_vector(15 downto 0)

 );
 end component;
 -----------------------------------------------------
 -------------------------------------------------------
 --------------------------------------------------------

 signal we     :  std_logic_vector (15 downto 0);
signal wy     :  std_logic_vector (15 downto 0);
signal clk    :  std_logic;
signal clk_wy :  std_logic;
signal nreset :  std_logic;
signal B :  std_logic_vector (4 downto 0);
 -- rejestr CRC dzielnik
signal we2     :  std_logic_vector (16 downto 0);
signal we3 :  std_logic_vector (15 downto 0);


-- licznik 

signal Q :  std_logic_vector (4 downto 0);


-- licznik transmisji
signal Q2 :  std_logic;

 signal wy_dane2 : std_logic_vector (15 downto 0);
 
 signal wyslij :  std_logic;
 signal transmisja_dane_wyj : std_logic;
-----------------------------------------------------------
----------------DESERIALIZER-------------------------------
-------------------------------------------------------------
signal clk_2    :  std_logic;
signal nreset_2 :  std_logic;
signal DANE : std_logic_vector(15 downto 0);
 
 -- licznik CRC serializer
signal B_2 :  std_logic_vector (4 downto 0);
signal Q_2 :  std_logic_vector (4 downto 0);


   -- rejestr CRC dzielnik
signal we2_2  :  std_logic_vector (16 downto 0);
 
 --licznik transmisji
 signal Q2_2 :  std_logic;
 
 -- wysylanie

signal transmisja_dane_wyj_2 : std_logic;

signal we_dane_2_out : std_logic_vector(15 downto 0);

-------------------------------------------------
-------------------------------------------------
constant clk_period : time := 10 ns;

begin
 serializer: CRC16 PORT MAP (
         
         nreset => nreset,
         clk => clk,
          we => we,
            we2 => we2,
            we3 => we3,
         wy => wy,
         wy_dane2 => wy_dane2,
           
            Q => Q,
            Q2 => Q2,
            clk_wy => clk_wy,
            B => B,
            wyslij => wyslij,
            transmisja_dane_wyj => transmisja_dane_wyj
      
            
            
       );

deserializer: CRC16_deserializer PORT MAP (

         clk_2 => clk_2,
           
        we2_2 =>  we2_2,
        we_dane_2_out => we_dane_2_out,
         nreset_2 => nreset_2,
         transmisja_dane_wyj_2 => transmisja_dane_wyj_2,
          
            Q_2 => Q_2,
            Q2_2 => Q2_2,
            B_2 => B_2,
      DANE => DANE
            
            
       );
clk_2 <= clk_wy;
nreset_2 <= wyslij;
transmisja_dane_wyj_2 <= transmisja_dane_wyj;

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
      nreset <= '0';
      we <= "1100110000010100";
            we2 <= "11111010100000001";
            we2_2 <= "11111010100000001";
            we3 <= "0000000000000000";
      
      B <= "10000";
      B_2 <= "10000";
     
      
      wait for 1*clk_period;
      nreset <= '1';
      
      
     wait for 72*clk_period;
    
   assert false severity failure;
  end process;




end Behavioral;
