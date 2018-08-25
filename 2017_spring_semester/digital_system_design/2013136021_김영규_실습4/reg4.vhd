library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;

entity reg4 is
	port (clk : in std_logic; 
			data_in : in std_logic_vector(3 downto 0);
			reg_in, reg_out : inout std_logic_vector(3 downto 0));
end reg4;

architecture reg4arch of reg4 is
begin
	reg_in <= data_in;
	
	process(clk)
	begin
		if(rising_edge(clk)) then
			reg_out <= reg_in;
		end if;
	end process;
end reg4arch;