library ieee;
use ieee.std_logic_1164.all;

entity or_2 is
	port( a, b 	: in std_logic;
           c  		: out std_logic );
end or_2;

architecture sample of or_2 is
begin
	c <= a or b;
end sample;