library ieee; 
use ieee.std_logic_1164.all;

entity comp is
	port( a, b 	: in std_logic_vector(1 downto 0);
	equal 	: out std_logic ); 
end comp;

architecture data_flow of comp is
	begin
	equal <= not( a(1) xor b(1) ) and not( a(0) xor b(0) );
end data_flow;