library ieee;
use ieee.std_logic_1164.all;

entity cla4 is
	port( a, b			: in std_logic_vector (3 downto 0);
			carryIn		: in std_logic;
         carry			: out std_logic;
			sum			: out std_logic_vector (3 downto 0));
end cla4;

architecture kyg_cla4 of cla4 is          
	signal temp : std_logic_vector (8 downto 0);
	signal p, g : std_logic_vector (2 downto 0);
	signal c_temp : std_logic_vector (2 downto 0);
	signal tmp : std_logic;
	
	component and_2 port( a, b : in std_logic;
									 o	: out std_logic);
 	end component;
	component and_3 port( a, b, c : in std_logic;
									 o	: out std_logic);
 	end component;
	component and_4 port( a, b, c, d : in std_logic;
									 o	: out std_logic);
 	end component;
	component or_2 port( a, b 	: in std_logic;
									o	: out std_logic);
 	end component;
	component or_3 port( a, b, c 	: in std_logic;
										o	: out std_logic);
 	end component;
	component or_4 port( a, b, c, d 	: in std_logic;
										o	: out std_logic);
 	end component;
	component HA port( x, y  	: in std_logic;
							 c, s		: out std_logic );
	end component;
	component full_adder port( w, x, y		: in std_logic;
										carry, sum	: out std_logic );
	end component;	
	
begin
	u1 : HA port map(a(0), b(0), g(0), p(0));
	u2 : HA port map(a(1), b(1), g(1), p(1));
	u3 : HA port map(a(2), b(2), g(2), p(2));

	u4 : and_4 port map(carryIn, p(0), p(1), p(2), temp(0));
	u5 : and_3 port map(g(0), p(1), p(2), temp(1));
	u6 : and_2 port map(g(1), p(2), temp(2));
	u7 : and_3 port map(carryIn, p(0), p(1), temp(3));
	u8 : and_2 port map(g(0), p(1), temp(4));
	u9 : and_2 port map(p(0), carryIn, temp(5));
	u10 : or_4 port map(temp(0), temp(1), temp(2), g(2), c_temp(2));
	u11 : or_3 port map(temp(3), temp(4), g(1), c_temp(1));
	u12 : or_2 port map(temp(5), g(0), c_temp(0));
	
	u13 : full_adder port map(a(0), b(0), carryIn, tmp, sum(0));
	u14 : full_adder port map(a(1), b(1), c_temp(0), tmp, sum(1));
	u15 : full_adder port map(a(2), b(2), c_temp(1), tmp, sum(2));
	u16 : full_adder port map(a(3), b(3), c_temp(2), tmp, sum(3));
end kyg_cla4;