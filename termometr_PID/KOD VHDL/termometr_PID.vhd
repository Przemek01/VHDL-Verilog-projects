
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.std_logic_unsigned.all;



entity termometr_PID is
Port (


reset :in std_logic;
IN_OUT : inout std_logic;
clk : in std_logic;
---ENKODER-----
rotary_a : in std_logic;
rotary_b : in std_logic;
rotary_press : in std_logic;
-----podgrzewacz------
podgrzej : out std_logic;
LED : out STD_LOGIC_VECTOR (5 downto 0);
----LCD--------
a_to_g : out STD_LOGIC_VECTOR (6 downto 0);		-- poszczególne segmenty wyœwietlacza, segmenty a,b,c,d,e,f,g
anody : out STD_LOGIC_VECTOR (3 downto 0);			-- sekcje wyœwietlacza, wspólne anody
dot : out  STD_LOGIC		
---------------

);
end termometr_PID;

architecture Behavioral of termometr_PID is

---konwerter---temperatury-------
signal c_seg_1 :  STD_LOGIC_VECTOR (3 downto 0);
signal c_seg_2 :  STD_LOGIC_VECTOR (3 downto 0);
signal wyswietl :  STD_LOGIC_VECTOR (7 downto 0);
signal zatrzask_konw : STD_LOGIC;
signal resetuj_licznik : STD_LOGIC;
signal odejmij_jeden : STD_LOGIC;
---PODGRZEWACZ------------------------------
signal jeden_pwm :  STD_LOGIC_VECTOR (5 downto 0);
signal zero_pwm :  STD_LOGIC_VECTOR (5 downto 0);
signal c_jeden :  STD_LOGIC_VECTOR (5 downto 0);
signal c_zero :  STD_LOGIC_VECTOR (5 downto 0);
signal LED_signal : STD_LOGIC_VECTOR (5 downto 0);
--------ENKODER------------------------
signal      rotary_a_in : std_logic;
signal      rotary_b_in : std_logic;
signal        rotary_in : std_logic_vector(1 downto 0);
signal        rotary_q1 : std_logic;
signal        rotary_q2 : std_logic;
signal  delay_rotary_q1 : std_logic;
signal     rotary_event : std_logic;
signal      rotary_left : std_logic;
signal  rotary_press_in : std_logic;
---------------------------------------

-----LCD--------------------------------
signal x : STD_LOGIC_VECTOR (7 downto 0);						
signal digit : STD_LOGIC_VECTOR (3 downto 0);
signal clk_div : STD_LOGIC_VECTOR (23 downto 0) := X"000000";
signal s : STD_LOGIC_VECTOR (1 downto 0);	

----DS18B20---------------------------------------
--------------------------------------------------
signal DS18B20 : std_logic;
signal clk_1us : std_logic;
signal clk_1ms : std_logic;
signal glowny_c : std_logic_vector(5 downto 0);
signal delay : std_logic_vector(9 downto 0);
signal delay_ms : std_logic_vector(9 downto 0);
signal c_1ms : std_logic_vector(9 downto 0);
signal ramka_danych : std_logic_vector(15 downto 0);
signal temperatura : std_logic_vector(15 downto 0);
signal komenda : std_logic_vector(7 downto 0);
signal reset_delay : std_logic;
signal reset_delay_ms : std_logic;
signal odczyt1 : std_logic;
signal odczyt2 : std_logic;
signal RW : std_logic;
signal zatrzask : std_logic;
signal zatrzask2 : std_logic;
signal wyslij : std_logic;
signal wczytaj : std_logic;
signal bajt : std_logic_vector(3 downto 0);
signal bajtx2 : std_logic_vector(4 downto 0);

type stan is(RESET_PULSE,PRESENT_PULSE,CONVERT_T,SKIP_ROM,CZEKAJ_750ms,READ_SCRATCHPAD,ODCZYT);
signal stan_obecny,stan_nastepny:stan;

subtype komendy is std_logic_vector(7 downto 0);
constant skip:komendy := "11001100";
constant convert:komendy := "01000100";
constant read1:komendy := "10111110";
-------------------------------------------
-------------------------------------------


begin

-----------------------------ONE----WIRE--DS18B20---------------------------------
licznik_glowny: process(clk, reset,glowny_c)

  begin
    if reset= '1'  then
      glowny_c <= "000000";
		clk_1us <= '0';
    elsif rising_edge(clk) then
      if (glowny_c = "011000") then
		glowny_c <= "000000";
		  if(clk_1us = '0') then
		      clk_1us <= '1';
		     else
			   clk_1us <= '0';
		  end if;
	   else
		  glowny_c <= glowny_c + '1';
		end if;
        
    end if;
  end process licznik_glowny;
 
 
 
  
  licznik_ms: process(clk_1us, reset,c_1ms)

  begin
    if reset= '1'  then
      c_1ms <= "0000000000";
		clk_1ms <= '0';
    elsif rising_edge(clk_1us) then
      if (c_1ms = "0111110100") then
		c_1ms <= "0000000000";
		  if(clk_1ms = '0') then
		      clk_1ms <= '1';
		     else
			   clk_1ms <= '0';
		  end if;
	   else
		  c_1ms <= c_1ms + '1';
		end if;
        
    end if;
  end process licznik_ms;
  
  
  
  opoznienie: process(clk_1us, reset)
  begin
    if reset= '1' then
      delay <= "0000000000";
    elsif rising_edge(clk_1us) then
      if (reset_delay = '1') then
        delay <= "0000000000";
		        else
             delay <= delay + 1;
       end if;
	  end if;
  end process opoznienie;



opoznienie_ms: process(clk_1ms, reset)
  begin
    if reset= '1' then
      delay_ms <= "0000000000";
    elsif rising_edge(clk_1ms) then
      if (reset_delay_ms = '1') then
        delay_ms <= "0000000000";
		        else
             delay_ms <= delay_ms + 1;
       end if;
	  end if;
  end process opoznienie_ms;


automat_DS18B20: process(clk_1us,reset)
begin
  if reset = '1' then
    stan_obecny <= RESET_PULSE;
	 stan_nastepny <= RESET_PULSE;
	 reset_delay <= '1';
	 DS18B20 <= '1';
	 RW <= '0';
	 wyslij <= '0';
	 wczytaj <= '0';
	 bajtx2 <= "00000";
	 bajt <= "0000";
	 odczyt2 <= '1';
	 
	   elsif rising_edge(clk_1us) then
    case stan_obecny is
      when RESET_PULSE =>
		     
		     reset_delay <= '0';
		     DS18B20 <= '0';
			  wczytaj <= '0';
			  if (delay = "0000000001") then
			      wczytaj <= '1';
		     elsif (delay = "0111110100") then
		       stan_obecny <= PRESENT_PULSE;
			    reset_delay <= '1';
			    DS18B20 <= '1';
			else
				 stan_obecny <= RESET_PULSE;
		   end if;
			
        		  
      when PRESENT_PULSE =>
		
		     
		     reset_delay <= '0';
			  
			if (delay = "0000110010") then
			  odczyt2 <= IN_OUT;
			  
			elsif(delay = "1110000000") then
			
			  stan_obecny <= SKIP_ROM;
			  reset_delay <= '1';
			  wczytaj <= '1';
			else
			  stan_obecny <= PRESENT_PULSE;
		   end if;
			
		when SKIP_ROM =>
		
		      reset_delay <= '0';
				wczytaj <= '0';
				
		   if(bajt = "1000") then
			
			  if (delay = "0001100100") then
			      if(stan_nastepny = READ_SCRATCHPAD) then
					
		           stan_obecny <= READ_SCRATCHPAD;
			        bajt <= "0000";
					  wczytaj <= '1';
					  reset_delay <= '1';
					  
					else
					
					  stan_obecny <= CONVERT_T;
			        bajt <= "0000";
					  wczytaj <= '1';
					  reset_delay <= '1';
					  
					end if;
			   else
			       wyslij <= '0';
			   end if;
				
			else
			   
				if (delay = "0000000000") then
				
				      DS18B20 <= '0';
						wyslij <= '0';
						
			   elsif (delay = "0000000100") then
				
				   if(komenda(0) = '1') then
					
					   DS18B20 <= '1';
						
			      end if;
					
				elsif (delay = "0001010011") then
				 if(komenda(0) = '1') then
				      bajt <= bajt + 1;
		            wyslij <= '1';
						reset_delay <= '1';
						
					else
					DS18B20 <= '1';
					end if;
				elsif (delay = "0001100000") then
				       bajt <= bajt + 1;
		             wyslij <= '1';
						 reset_delay <= '1';
				end if;
		   end if;
			
		when CONVERT_T =>
		
		      reset_delay <= '0';
				wczytaj <= '0';
				
		   if(bajt = "1000") then
			
		      stan_obecny <= CZEKAJ_750ms;
			   bajt <= "0000";
			   wyslij <= '0';
				reset_delay_ms <= '1';
				DS18B20 <= '1';
				reset_delay <= '1';
				
			else
			   
				if (delay = "0000000000") then
				
				      DS18B20 <= '0';
						wyslij <= '0';
						
			   elsif (delay = "0000000100") then
				
				   if(komenda(0) = '1') then
					
					   DS18B20 <= '1';
						
			      end if;
					
				elsif (delay = "0001010011") then
				
				   if(komenda(0) = '1') then
				      bajt <= bajt + 1;
		            wyslij <= '1';
						reset_delay <= '1';
						
					else
					DS18B20 <= '1';
					end if;
				elsif (delay = "0001100010") then
				       bajt <= bajt + 1;
		             wyslij <= '1';
						 reset_delay <= '1';
				end if;
		   end if;
			
		when CZEKAJ_750ms =>
				reset_delay_ms <= '0';

			if (delay_ms = "0000100000") then
			
			  stan_obecny <= RESET_PULSE;
			  stan_nastepny <= READ_SCRATCHPAD;
			  
			else
			
			  stan_obecny <= CZEKAJ_750ms;
			  
			end if;
			
		when READ_SCRATCHPAD =>
			
		      reset_delay <= '0';
				wczytaj <= '0';
				
		   if(bajt = "1000") then
			
			  if (delay = "0001100100") then
			      
		           stan_obecny <= ODCZYT;
			        bajt <= "0000";
					  reset_delay <= '1';
					  
			  else
			       wyslij <= '0';
			  end if;
				
			else
			   
				if (delay = "0000000000") then
				
				      DS18B20 <= '0';
						wyslij <= '0';
						
			   elsif (delay = "0000000100") then
				
				   if(komenda(0) = '1') then
					
					   DS18B20 <= '1';
						
			      end if;
					
				elsif (delay = "0001010011") then
				
				   if(komenda(0) = '1') then
				      bajt <= bajt + 1;
		            wyslij <= '1';
						reset_delay <= '1';
						
					else
					DS18B20 <= '1';
					end if;
				elsif (delay = "0001100010") then
				       bajt <= bajt + 1;
		             wyslij <= '1';
						 reset_delay <= '1';
				end if;
		   end if;
			
		when ODCZYT =>
		
		     reset_delay <= '0';
			  wczytaj <= '0';
		
		 if(bajtx2 = "10000") then
		 
		    
			 reset_delay <= '1';
			 bajtx2 <= "00000";
			 wyslij <= '0';
			 stan_obecny <= RESET_PULSE;
			 stan_nastepny <= RESET_PULSE;
			 
		 else
		    if(delay = "0000000000") then
			    DS18B20 <= '0';
				 wyslij <= '0';
				 
		    elsif(delay = "0000000100") then
		       DS18B20 <= '1';
				 
			 elsif(delay = "0000001100") then
		       odczyt1 <= IN_OUT;
				 
			 elsif(delay = "0000100011") then
				 bajtx2 <= bajtx2 + 1;
		       wyslij <= '1';
				 reset_delay <= '1';
				 
		    end if;
		 end if;
			
    end case;  
	 
  end if;
end process automat_DS18B20;


IN_OUT <= '0' when DS18B20 = '0' else 'Z';
---------------------------------------------------------------
-------------------------------------------------------------
wyslij_komende:process(reset,stan_obecny,wyslij,wczytaj,RW,clk_1us) 
  begin

    if reset= '1' then
      komenda <= "00000000";
		zatrzask <= '0';
	elsif rising_edge(clk_1us) then
		if zatrzask = '1' then
		  zatrzask <= '0';
	 elsif stan_obecny = SKIP_ROM and wczytaj = '1' then
	    komenda <= skip;
	 elsif stan_obecny = CONVERT_T and wczytaj = '1' then
	    komenda <= convert;
	 elsif stan_obecny = READ_SCRATCHPAD and wczytaj = '1'  then
	    komenda <= read1;	
	 elsif stan_obecny /= ODCZYT and wyslij = '1' and zatrzask = '0' then
      komenda <= RW & komenda(7 downto 1);
		zatrzask <= '1';
		end if;
		
   end if;
  end process wyslij_komende;
  
  
  
  
   wyslij_dane:process(reset,stan_obecny,wyslij,wczytaj,odczyt1,clk_1us) 
  begin

    if reset= '1' then
		ramka_danych <= "0000000000000000";
		temperatura <= "0000000000000000";
		zatrzask2 <= '0';
		zatrzask_konw <= '0';
		wyswietl <= "00000000";
		c_seg_1 <= "0000";
		c_seg_2 <= "0000";
		resetuj_licznik <= '0';
		odejmij_jeden <= '0';
	 elsif rising_edge(clk_1us) then
		if zatrzask2 = '1' then
		   zatrzask2 <= '0';
	   elsif wyslij = '1' and stan_obecny = ODCZYT and zatrzask = '0' then
		  ramka_danych <= odczyt1 & ramka_danych(15 downto 1);
        zatrzask2 <= '1';
		  
	   elsif stan_obecny = RESET_PULSE and wczytaj = '1' then
	     temperatura <= ramka_danych;
		  zatrzask_konw <= '1';
		elsif stan_obecny = ODCZYT and zatrzask_konw = '1' then
		   if temperatura(14) = '0' then
             if c_seg_1 = "1010" then
              c_seg_1 <= "0000";
				  c_seg_2 <= c_seg_2 + 1;
				  odejmij_jeden <= '1';
             else
              c_seg_1 <= c_seg_1 + 1;
		        temperatura <=temperatura  - 16;
             end if;
	     else
		        if odejmij_jeden = '1' then
				      if c_seg_1 = "0000" then
					      c_seg_2 <= c_seg_2 - 1;
							odejmij_jeden <= '0';
					   else
						   c_seg_1 <= c_seg_1 - 1;
							odejmij_jeden <= '0';
					   end if;
		        elsif resetuj_licznik = '1' then
				     c_seg_1 <= "0000";
				     c_seg_2 <= "0000";
					  resetuj_licznik <= '0';
					  zatrzask_konw <= '0';
				  else
		           wyswietl <= c_seg_2 & c_seg_1;
					  resetuj_licznik <= '1';
			     end if;  
        end if;
	   end if;
   end if;
  end process wyslij_dane;
  
  
---------------------ENKODER--OBROTOWY--------------------------------
----------------------------------------------------------------------
 rotary_filter: process(clk)
  begin
    if clk'event and clk='1' then

      rotary_a_in <= rotary_a;
      rotary_b_in <= rotary_b;
      

      rotary_in <= rotary_b_in & rotary_a_in;

      case rotary_in is

        when "00" => rotary_q1 <= '0';         
                     rotary_q2 <= rotary_q2;
 
        when "01" => rotary_q1 <= rotary_q1;
                     rotary_q2 <= '0';

        when "10" => rotary_q1 <= rotary_q1;
                     rotary_q2 <= '1';

        when "11" => rotary_q1 <= '1';
                     rotary_q2 <= rotary_q2; 

        when others => rotary_q1 <= rotary_q1; 
                       rotary_q2 <= rotary_q2; 
      end case;

    end if;
  end process rotary_filter;



 direction: process(clk)
  begin
    if clk'event and clk='1' then

      delay_rotary_q1 <= rotary_q1;
      if rotary_q1='1' and delay_rotary_q1='0' then
        rotary_event <= '1';
        rotary_left <= rotary_q2;
       else
        rotary_event <= '0';
        rotary_left <= rotary_left;
      end if;

    end if;
  end process direction;
  
  
  podgrzewacz: process(clk,reset)
  begin
  if reset = '1' then
  jeden_pwm <= "000000";
  zero_pwm <= "111111";
  LED_signal <= "000000";
   else
    if clk'event and clk='1' then

      if rotary_event='1' then
        if rotary_left='1' then 
            zero_pwm <= zero_pwm - 1;
			   jeden_pwm <= jeden_pwm + 1;
				LED_signal <= LED_signal + 1;
         else
				jeden_pwm <= jeden_pwm - 1;
				zero_pwm <= zero_pwm + 1;
				LED_signal <= LED_signal - 1;
        end if;
      end if;
		
		 if rotary_press_in='1' then
        jeden_pwm <= "000001";
        zero_pwm <= "000001";
      end if;
    end if;
	end if;
  end process podgrzewacz;
  
 LED <= LED_signal;
------------------------------------------------------------------------
------------------PODGRZEWACZ------------------------------------------------

PWM:process(clk_1us, reset)
  begin
    if reset= '1' then
      c_jeden <= "000001";
		c_zero <= "000001";
    elsif rising_edge(clk_1us) then
      if c_jeden <= jeden_pwm then
		c_jeden <= c_jeden + 1;
		podgrzej <= '1';
		elsif c_zero <= zero_pwm then
		c_zero <= c_zero + 1;
		podgrzej <= '0';
		else
		c_jeden <= "000000";
		c_zero <= "000000";
		end if;
    end if;
  end process PWM;  
  
  
  
  
  
--------------7 segmentowy-------------------------------------------------
-----------------------------------------------------------------
                                                                             

x <= wyswietl;

	dot <= '0';	
--
	wybor_sekcji:process (clk, s, x) is
	begin
		if (clk'event and clk ='1') then
			case s is 
				when "00" => digit <= x(3 downto 0);
					if s ="00" then anody <= "0001"; else null; end if;  
				when others => digit <= x(7 downto 4);
					if s ="01" then anody <= "0010"; else null; end if; 
			end case;
			end if; 
	end process wybor_sekcji;		
	
--		
segmenty	:process (clk, digit) is
	begin 
		if (clk'event and clk ='1') then
			case digit is
				when X"0" => a_to_g <= "1111110";			--definicja cyfry 0
				when X"1" => a_to_g <= "0110000";			--definicja cyfry 1
				when X"2" => a_to_g <= "1101101";			--definicja cyfry 2
				when X"3" => a_to_g <= "1111001";			--definicja cyfry 3
				when X"4" => a_to_g <= "0110011";			--definicja cyfry 4
				when X"5" => a_to_g <= "1011011";			--definicja cyfry 5
				when X"6" => a_to_g <= "1011111";			--definicja cyfry 6
				when X"7" => a_to_g <= "1110010";			--definicja cyfry 7
				when X"8" => a_to_g <= "1111111";			--definicja cyfry 8
				when X"9" => a_to_g <= "1111011";			--definicja cyfry 9
				when others => a_to_g <= "1001111";			--definicja litery E
			end case;
		end if; 
	end process segmenty;
--			
	process (clk)
		 begin
			  if (clk'event and clk = '1') then
					clk_div <= clk_div + '1';
			  end if;
	end process;
--		
    process (clk_div(17))
    begin
        if (clk_div(17)'Event and clk_div(17) = '1') then

                s <= s + '1';   
        end if;
    end process;
	 
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------

  
end Behavioral;

