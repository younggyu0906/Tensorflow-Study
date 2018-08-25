library ieee;
use ieee.std_logic_1164.all;

entity andlogic is
	port ( a	: in std_logic_vector(0 to 3);
            y 	: out std_logic );
end andlogic;

architecture sample of andlogic is
begin
	process(a)
      	variable temp : std_logic; 
      begin     
		temp := '1';
      	for i in 0 to 3 loop
            		temp := a(i) and temp;
             	end loop;
             	y <= temp;
    	end process;
end sample;