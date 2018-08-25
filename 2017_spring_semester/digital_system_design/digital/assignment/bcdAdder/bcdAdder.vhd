library ieee;
use ieee.std_logic_1164.all;

entity bcdAdder is
	port( a, b 			: in std_logic_vector (3 downto 0);
			carryIn		: in std_logic;
			out_put_carry	: out std_logic;
         sum			: out std_logic_vector (3 downto 0)); 
end bcdAdder;

architecture sample of bcdAdder is          
	signal sum_temp, temp : std_logic_vector (3 downto 0);
	signal temp1, temp2 : std_logic;
	signal temp3, temp4 : std_logic;
	signal carry_out, opctemp : std_logic;
	
	component rcaAdder port( x, y 	: in std_logic_vector (3 downto 0);
									 c_in		: in std_logic;
									 carry	: out std_logic;
									 sum		: out std_logic_vector (3 downto 0));
 	end component;
	
	component and_2 port( a, b : in std_logic;
									 c	: out std_logic);
 	end component;

	component or_3 port( a, b, c 	: in std_logic;
										o	: out std_logic);
 	end component;
	
begin
	temp3 <= '0';
	u1 : rcaAdder port map(a, b, carryIn, carry_out, sum_temp);
	u2 : and_2 port map(sum_temp(3), sum_temp(2), temp1);
	u3 : and_2 port map(sum_temp(3), sum_temp(1), temp2);
	u4 : or_3 port map(carry_out, temp1, temp2, opctemp);
	temp(0) <= '0';
	temp(1) <= opctemp;
	temp(2) <= opctemp;
	temp(3) <= '0';
   u5 : rcaAdder port map(temp, sum_temp, temp3, temp4, sum);
	out_put_carry <= opctemp;
end sample;