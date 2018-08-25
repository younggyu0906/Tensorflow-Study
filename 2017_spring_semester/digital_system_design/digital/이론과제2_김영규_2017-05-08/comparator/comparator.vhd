library ieee; 
use ieee.std_logic_1164.all;

entity comparator is
	generic (size : integer := 4);
	port( a, b 	: in std_logic_vector(4 downto 0);
			a_large, b_large, same : out std_logic);
end comparator;
	
architecture sample of comparator is
begin
	process (a, b)
	variable temp : integer;	-- 같은 경우를 확인하기 위한 변수
	begin
		temp := 0;
		if a(size) = b(size) then
				for i in size - 1 downto 0 loop
					if a(i) > b(i) then
						a_large <= '1';
						b_large <= '0';
						same <= '0';
					elsif a(i) < b(i) then
						a_large <= '0';
						b_large <= '1';
						same <= '0';
					else
						temp := temp + 1;
					end if;
				end loop;
				if temp = size then
					a_large <= '0';
					b_large <= '0';
					same <= '1';
				end if;
		else
			if a(size) > b(size) then
				a_large <= '0';
				b_large <= '1';
				same <= '0';
			else
				a_large <= '1';
				b_large <= '0';
				same <= '0';
			end if;
		end if;
	end process;
end sample;