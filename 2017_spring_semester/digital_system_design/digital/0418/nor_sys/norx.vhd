library ieee;
use ieee.std_logic_1164.all;
entity norx is
	generic(size : integer); 
   	port( x	: in std_logic_vector(size-1 downto 0);
           z	: out std_logic );
end norx;

architecture sample of norx is
begin 
	process(x)
      	variable temp : std_logic;
      begin
		temp := x(0);
		for i in 1 to size-1 loop
              temp := temp or x(i);
           	end loop;
           	z <= not(temp); 
 	end process;
end sample;