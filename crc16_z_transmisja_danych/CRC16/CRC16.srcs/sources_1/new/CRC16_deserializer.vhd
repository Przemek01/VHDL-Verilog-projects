library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.std_logic_unsigned.all;



entity CRC16_deserializer is
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


DANE :out std_logic_vector(15 downto 0);
we_dane_2_out :out std_logic_vector(15 downto 0)
);
 
end CRC16_deserializer;

architecture Behavioral of CRC16_deserializer is


signal c : std_logic_vector(4 downto 0);
signal c2 : std_logic_vector(1 downto 0);
signal we_CRC : std_logic_vector(16 downto 0);
signal load : std_logic;
signal load2 : std_logic;

signal we_dane : std_logic_vector(15 downto 0);
signal wy_CRC : std_logic_vector(15 downto 0);
signal transmisja_dane_wyj : std_logic_vector(15 downto 0);
signal start_crc : std_logic;
begin





odbieranie: process (nreset_2,clk_2,load) 

      begin
      if(nreset_2 = '0') then 
      transmisja_dane_wyj <= (others => '0');
      
      elsif (clk_2'Event  and clk_2='1' ) then 

      transmisja_dane_wyj  <= transmisja_dane_wyj_2 & transmisja_dane_wyj(15 downto 1);
      end if;
end process odbieranie;


DANE <= transmisja_dane_wyj;








rejestr_wejsciowy: process (nreset_2,clk_2) 

    begin
     if(nreset_2 = '0') then 

      we_dane <= (others => '0');
                  elsif (clk_2'Event  and clk_2='1') then 
                  if (c = B_2 + 1 and c2(0) = '1') then
                  
                      we_dane(15 downto 0) <= transmisja_dane_wyj(15 downto 0);
                      
             
                      
                    
                      


                  elsif(load = '0') then
						if( we_dane(15) = '1' and c2(0) = '0') then
						
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

elsif(c2(0) = '1' and c = B_2) then
wy_CRC(15 downto 0) <= transmisja_dane_wyj(15 downto 0);

                end if;
                  end if;
               
                
               
     elsif(clk_2'Event  and clk_2 = '0' and load = '0' and c = B_2 + 1 and c2(0) = '0') then
                  start_crc <= '1';     
                  
     elsif(clk_2'Event  and clk_2 = '0' and load = '0' and c > "00000" and c2(0) = '0') then
we_dane <= we_dane(14 downto 0) & wy_CRC(15);             
wy_CRC <=   wy_CRC(14 downto 0)  & '0';    

  
     
      end if;
end process rejestr_wejsciowy;
 






licznik: process (nreset_2,clk_2) 

begin
if (nreset_2 = '0') then 
c <= (others=> '0');

elsif (clk_2'event  and clk_2='1')  then 

if (c > B_2 ) then 
c <= "00000";
else
c <= c + 1 ;
end if;


end if;

end process licznik;


licznik2: process (nreset_2,clk_2) 

begin
if (nreset_2 = '0') then 
c2 <= (others=> '0');


elsif (clk_2'event  and clk_2='1' and c = B_2)  then 
if (c2 = B_2) then 
c2 <= "00";
else
c2 <= c2 + 1 ;


end if;
end if;
end process licznik2;







rejestr_CRC_dzielnik: process (nreset_2,clk_2,load) 

      begin
      if(nreset_2 = '0') then 

      we_CRC <= (others => '0');
      elsif (clk_2'Event  and clk_2='1' and load = '1') then 

      we_CRC  <=  we2_2(16 downto 0);
      end if;
end process rejestr_CRC_dzielnik;

-- pobieranie danych
load <= '1' when c = "00000" and load2 = '1' else '0';

zatrzask: process(c)
begin
    if(nreset_2 = '0') then
     load2 <= '0' ;
    else
     if(c > "00000") then
       load2 <= '1';
       
     end if;
    end if;
end process zatrzask;

Q_2 <= c;
Q2_2 <= c2(0);

we_dane_2_out <= we_dane;

end Behavioral;