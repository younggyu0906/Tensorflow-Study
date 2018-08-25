library ieee;
use ieee.std_logic_1164.all;

entity reg_combin is
	port (	reg1 : in std_logic_vector(3 downto 0);
				reg2 : in std_logic_vector(7 downto 0);
				reg3 : out std_logic_vector(11 downto 0));
end reg_combin;

architecture kyg_combin of reg_combin is
signal r1 : std_logic_vector(3 downto 0);
signal r2 : std_logic_vector(7 downto 0);
signal r3 : std_logic_vector(11 downto 0);
	component kyg_reg
      generic(size : integer);
      port(	data_in : in std_logic_vector(size - 1 downto 0);
				reg_out : out std_logic_vector(size - 1 downto 0));
   end component;		
begin 
		u1 : kyg_reg generic map(4) port map(reg1, r1);
		u2 : kyg_reg generic map(8) port map(reg2, r2);
		r3 <= r1 & r2;
		u3 : kyg_reg generic map(12) port map(r3, reg3);
end kyg_combin;