library ieee;
use ieee.std_logic_1164.all;

entity decoder24 is
	port ( a	: in std_logic_vector(1 downto 0);
            y 	: out std_logic_vector(3 downto 0) );
end decoder24;

architecture sample of decoder24 is
begin
	process(a)
		variable input1 : std_logic_vector(3 downto 0);
		variable input2 : std_logic_vector(3 downto 0);	
   begin
		input1 := "0000";
		input2 := "0000";
		if a(0) = '1' then
			input1(1) := '1'; input1(3) := '1';
		else
			input1(0) := '1'; input1(2) := '1';
		end if;
		
		if a(1) = '1' then
			input2(2) := '1'; input2(3) := '1';
		else
			input2(0) := '1'; input2(1) := '1';
		end if;
      
		for i in 0 to 3 loop
			y(i) <= input1(i) and input2(i);
      end loop;
   end process;
end sample;

--library ieee;
--use ieee.std_logic_1164.all;

--entity decoder24 is
--	port ( a	: in std_logic_vector(1 downto 0);
--            y 	: out std_logic_vector(3 downto 0) );
--end decoder24;

--architecture sample of decoder24 is
--begin
--	process(a)
--	variable temp : integer; 
--   begin
--		if a = "00" then
--			temp := 0;
--		elsif a = "01" then
--			temp := 1;
--		elsif a = "10" then
--			temp := 2;
--		else
--			temp := 3;
--		end if;
 --     
--		for i in 0 to 3 loop
 --          	if i = temp then
--					y(i) <= '1';
--				else
--					y(i) <= '0';
--				end if;
 --     end loop;
  -- end process;
--end sample;