library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity HS311 is
     	port( clk, dir : in std_logic;
             	       q 		: out std_logic);
end HS311;
  
 architecture sample of HS311 is
       	signal tclk : std_logic;
			signal Angle : integer := 1000;
 begin
 
clock : process(clk)
		variable m : integer := 0;
        begin
          	if (clk'event and clk ='1') then
                  if m>=Angle then
							m := 0;
							tclk <= not tclk;
						else
							m := m+1;
						end if;
				end if;
     	end process;
			
step : process(tclk)
        begin
				q <= tclk;
      end process;
			
			
WhatAngle : process(dir)
		begin
		if dir = '1' then
			Angle <= 600;
		else 
			Angle <= 1500;
		end if;
	end process;
  end sample;