library ieee;
use ieee.std_logic_1164.all;
use work.kygcla.all; -- 패키지를 선언하고 가시화 하라
entity adder_16 is
	generic(size : integer := 8);
	port ( x, y : in std_logic_vector(size-1 downto 0);
			 add_out : out std_logic_vector(size-1 downto 0);
			 carry_out : out std_logic; 
			 overflow_check : out std_logic); -- Over flow 검출 신호를 정의하라
end adder_16;

architecture sample of adder_16 is
begin
	process(x, y)
		variable temp1 : std_logic_vector(size-1 downto 0);
		variable temp2 : std_logic_vector(size downto 0);
	begin
		temp2(0) := '0';
		for i in 0 to size-1 loop
			cla( x(i), y(i), temp2(i), temp1(i), temp2(i + 1) );		
		end loop;
		add_out <= temp1;
		carry_out <= temp2(size);
		
		if x(size-1) = y(size-1) then
			if x(size-1) = temp2(size) then
				overflow_check <= '0';
			else
				overflow_check <= '1';
			end if;
		else
			overflow_check <= '0';
		end if;
		
	end process;
end sample;