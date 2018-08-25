library ieee; 
use ieee.std_logic_1164.all;

entity adder is
	port( a, b 	: in std_logic_vector(3 downto 0);
			carry	: inout std_logic_vector(4 downto 0) := "00000";
			y_out	: out std_logic_vector(4 downto 0));
end adder;
	
architecture sample of adder is
begin
	process (a, b, carry)
	begin
		for i in 0 to 3 loop
		if a(i) = b(i) then
			if carry(i) = '1' then
				y_out(i) <= '1';
			else
				y_out(i) <= '0';
			end if;
			if a(i) = '1' then
				carry(i) <= '1';
			end if;
		else
			if carry(i) = '1' then
				y_out(i) <= '0';
				carry(i) <= '1';
			else
				y_out(i) <= '1';
			end if;
		end if;
		end loop;
		-- 4bit
		y_out(4) <= carry(4);
	end process;
end sample;