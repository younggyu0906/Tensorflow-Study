library ieee;
use ieee.std_logic_1164.all;

entity and3input is
	port ( a, b, c	: in std_logic;
	          o  : out std_logic );
end and3input;

architecture ygand of and3input is
	signal sn : std_logic;
begin
	sn <= a and b;
	o <= sn and c;
end ygand;