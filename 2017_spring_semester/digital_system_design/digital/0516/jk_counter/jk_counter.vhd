library ieee;
use ieee.std_logic_1164.all;

entity jk_counter is
	port( clk : in std_logic;
            y_out : buffer std_logic_vector(3 downto 0));
end jk_counter;

architecture sample of jk_counter is
signal temp : std_logic_vector(4 downto 0); 

	component jkpr
		port( clk, j,k : in std_logic;
					y_out : buffer std_logic );
	end component;
begin

			u1 : jkpr port map(clk, '1', '1', temp(0));
			u2 : jkpr port map(clk, temp(0), temp(0), temp(1));
			temp(2) <= temp(0) and temp(1);
			u3 : jkpr port map(clk, temp(2), temp(2), temp(3));
			temp(4) <= temp(2) and temp(3);
			u4 : jkpr port map(clk, temp(4), temp(4), y_out(3));
			
			y_out(0) <= temp(0);
			y_out(1) <= temp(1);
			y_out(2) <= temp(3);
			
end sample;