library ieee;
use ieee.std_logic_1164.all;

entity reg_decom is
	port (	reg1 : out std_logic_vector(3 downto 0);
				reg2 : out std_logic_vector(7 downto 0);
				reg3 : in std_logic_vector(11 downto 0));
end reg_decom;

architecture kyg_decom of reg_decom is
signal r1 : std_logic_vector(3 downto 0);
signal r2 : std_logic_vector(7 downto 0);
signal r3 : std_logic_vector(11 downto 0);
	component kyg_reg
      generic(size : integer);
      port(	data_in : in std_logic_vector(size - 1 downto 0);
				reg_out : out std_logic_vector(size - 1 downto 0));
   end component;	
begin 
		u1 : kyg_reg generic map(12) port map(reg3, r3);
		g1 : for i in 3 downto 0 generate
			r1(i) <= r3(i + 8);
		end generate;
		g2 : for i in 7 downto 0 generate
			r2(i) <= r3(i);
		end generate;
		u2 : kyg_reg generic map(4) port map(r1, reg1);
		u3 : kyg_reg generic map(8) port map(r2, reg2);
end kyg_decom;