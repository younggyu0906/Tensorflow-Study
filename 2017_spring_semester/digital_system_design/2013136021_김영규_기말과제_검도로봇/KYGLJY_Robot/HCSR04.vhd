library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;
use ieee.numeric_std.all;


entity HCSR04 is
     	port( clk, Echo : in std_logic;
            Triger : out std_logic;
				Di : out std_logic_vector(7 downto 0));
end HCSR04;
  
 architecture sample of HCSR04 is
			signal tclk : std_logic;
			signal Distance : integer :=0;

 begin
 
			
TrigerOut : process(clk)
		variable m : integer := 0;
        begin
				if (rising_edge(clk)) then
					if m>= 5000 then
						m := 0;
						tclk <= not tclk;
					else
						m := m+1;
					end if;
				end if;
			end process;

TrigOut : process(tclk)
		begin
			Triger <= tclk;
		end process;
			

EchoIn : process(Echo,clk)
		variable DisMe1 : integer := 0;
		variable DisMe2 : integer := 0;
			begin
		
		if (rising_edge(clk)) then
			DisMe1 := DisMe1 + 1;
		end if;
		
		
		if (rising_edge(Echo)) then
			DisMe2 := DisMe1;
		elsif (falling_edge(Echo)) then
			Distance <= (DisMe1 - DisMe2);
		end if;
		
	end process;

	
	
PrintDistance : process(Distance)
		begin
		
		if Distance > 0 and Distance < 250 then
			Di <= "00000001";
		elsif Distance > 250 and Distance < 500 then
			Di <= "00000010";
		elsif Distance > 500 and Distance < 750 then
			Di <= "00000100";
		elsif Distance > 750 and Distance < 1000 then
			Di <= "00001000";
		elsif Distance > 1000 and Distance < 1250 then
			Di <= "00010000";
		elsif Distance > 1250 and Distance < 1500 then
			Di <= "00100000";
		elsif Distance > 1500 and Distance < 1750 then
			Di <= "01000000";
		else
			Di <= "00000000";
		end if;
end process;
	
  end sample;