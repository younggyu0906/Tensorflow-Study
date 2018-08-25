library ieee;
use ieee.std_logic_1164.all;
use work.mypack2.all;

entity kygmin2 is
	port( a, b 	: in std_logic_vector (7 downto 0);
           y_out 	: out std_logic_vector (7 downto 0) );
end kygmin2;

architecture sample of kygmin2 is     	
begin
	y_out <= min1(a, b);
end sample;