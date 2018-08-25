library ieee; 
use ieee.std_logic_1164.all;

entity add4 is
	port( a, b 	: in std_logic_vector(3 downto 0);
			c	: in std_logic;
			y_out	: out std_logic_vector(4 downto 0));
end add4;
	
architecture sample of add4 is
begin
	process (a, b, c)
	variable ctemp : std_logic_vector(3 downto 0);
	begin
		ctemp := "0000";
		-- 0bit
		if a(0) = b(0) then
			if c = '1' then
				y_out(0) <= '1';
			else
				y_out(0) <= '0';
			end if;
			if a(0) = '1' then
				ctemp(0) := '1';
			end if;
		else
			if c = '1' then
				y_out(0) <= '0';
				ctemp(0) := '1';
			else
				y_out(0) <= '1';
			end if;
		end if;
		-- 1, 2, 3bit
		for i in 1 to 3 loop
		if a(i) = b(i) then
			if ctemp(i-1) = '1' then
				y_out(i) <= '1';
			else
				y_out(i) <= '0';
			end if;
			if a(i) = '1' then
				ctemp(i) := '1';
			end if;
		else
			if ctemp(i-1) = '1' then
				y_out(i) <= '0';
				ctemp(i) := '1';
			else
				y_out(i) <= '1';
			end if;
		end if;
		end loop;
		-- 4bit
		y_out(4) <= ctemp(3);
	end process;
end sample;