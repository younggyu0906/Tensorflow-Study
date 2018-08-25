library ieee;
use ieee.std_logic_1164.all;

entity rcaAdder is
	port( x, y 		: in std_logic_vector (3 downto 0);
			c_in		: in std_logic;
			carry		: out std_logic;
         sum		: out std_logic_vector (3 downto 0)); 
end rcaAdder;

architecture sample of rcaAdder is          
	signal temp : std_logic_vector (2 downto 0);
	
	component full_adder port( w, x, y : in std_logic;
										carry, sum : out std_logic);
 	end component;
 
begin
	u1 : full_adder port map(x(0), y(0), c_in, temp(0), sum(0)); 
   u2 : full_adder port map(x(1), y(1), temp(0), temp(1), sum(1));  
   u3 : full_adder port map(x(2), y(2), temp(1), temp(2), sum(2));
	u4 : full_adder port map(x(3), y(3), temp(2), carry, sum(3));
end sample;