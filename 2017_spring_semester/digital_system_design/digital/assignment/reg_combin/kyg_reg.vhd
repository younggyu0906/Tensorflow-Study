library ieee;
use ieee.std_logic_1164.all;

entity kyg_reg is
	generic(size : integer);
	port (data_in : in std_logic_vector(size - 1 downto 0);
			reg_out : out std_logic_vector(size - 1 downto 0));
end kyg_reg;

architecture kyg_reg_arch of kyg_reg is
begin
	reg_out <= data_in;
end kyg_reg_arch;