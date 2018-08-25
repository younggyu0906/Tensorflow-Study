library ieee;
use ieee.std_logic_1164.all;

entity jk_counter2 is
	port( clk : in std_logic;
            y_out : buffer std_logic_vector(3 downto 0));
end jk_counter2;

architecture sample of jk_counter2 is
signal temp : std_logic_vector(3 downto 0); 

	component jkpr
		port( clk, j,k : in std_logic;
					y_out : buffer std_logic );
	end component;
begin
			u1 : jkpr port map(clk, '1', '1', temp(0));
			u2 : jkpr port map(not(temp(0)), '1', '1', temp(1));
			u3 : jkpr port map(not(temp(1)), '1', '1', temp(2));
			u4 : jkpr port map(not(temp(2)), '1', '1', temp(3));
			
			y_out(0) <= temp(0);
			y_out(1) <= temp(1);
			y_out(2) <= temp(2);
			y_out(3) <= temp(3);
end sample;