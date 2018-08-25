library ieee;
use ieee.std_logic_1164.all;

entity and_2 is
	port( a, b 	: in std_logic;
					o 	: out std_logic );
end and_2;

architecture sample of and_2 is
begin
	o <= a and b;
end sample;