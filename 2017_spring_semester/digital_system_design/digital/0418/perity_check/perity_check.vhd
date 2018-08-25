library ieee;
use ieee.std_logic_1164.all;

entity perity_check is
	port ( a 		: in std_logic_vector(4 downto 0);
            parity_check 	: out std_logic );
end perity_check ;

architecture sample of perity_check is
	signal y : std_logic_vector(3 downto 0);
   	component xor2
      	port ( a, b : in std_logic;
                     c   : out std_logic );
	end component; 
begin
	u3 : xor2 port map(a(4), a(3), y(3));
     	g1 : for i in 2 downto 0 generate
		g2 : if (i < 3) generate
      ux : xor2 port map(y(i+1), a(i), y(i));
	end generate g2;
	end generate g1;
     	parity_check <= y(0);
end sample;