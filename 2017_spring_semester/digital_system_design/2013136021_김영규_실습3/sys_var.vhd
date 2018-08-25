library ieee;
use ieee.std_logic_1164.all;
entity sys_var is
	port ( i, j, k	: in std_logic;
	          l   	: out std_logic );
end sys_var;
architecture sample of sys_var is
begin
	process(i, j, k)
	    	variable temp : std_logic;
	begin
		temp := '1';
		temp := i and temp;
		temp := j and temp;
		temp := k and temp;
	        l <= temp;	 
	end process;
end sample;