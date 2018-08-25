library ieee;
use ieee.std_logic_1164.all;

entity full_adder is 
  	port( a, b, c_in 	: in std_logic;
          c_out, sum	: out std_logic );
end full_adder;

architecture ygfa of full_adder is
  	signal sn1, sn2, sn3 : std_logic;
begin
      	sn1 <= a and b;
			sn2 <= a and c_in;
			sn3 <= b and c_in;
      	c_out <= sn1 or sn2 or sn3;
			sum <= a xor b xor c_in;
end ygfa;