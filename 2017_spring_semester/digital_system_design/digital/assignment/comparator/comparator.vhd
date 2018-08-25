library ieee; 
use ieee.std_logic_1164.all;

entity comparator is
	port( a, b 	: in std_logic_vector(3 downto 0);
			a_out, b_out, s_out : out std_logic);
end comparator;
	
architecture sample of comparator is
begin
	process (a, b)
	variable temp : integer;
	begin
		temp := 0;
		for i in 3 downto 0 loop
			if a(i) > b(i) then
				a_out <= '1';
				b_out <= '0';
				s_out <= '0';
			elsif a(i) < b(i) then
				a_out <= '0';
				b_out <= '1';
				s_out <= '0';
			else
				temp := temp + 1;
			end if;
		end loop;
		if temp = 4 then
			a_out <= '0';
			b_out <= '0';
			s_out <= '1';
		end if;
	end process;
end sample;