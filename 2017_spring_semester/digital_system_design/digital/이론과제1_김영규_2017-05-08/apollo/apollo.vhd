library ieee; 
use ieee.std_logic_1164.all;

entity apollo is
	port( battery_voltage	: in integer;	-- 배터리의 전압 
			red_led, green_led, yellow_led	: out std_logic);	-- 적색, 녹색, 황색 led
end apollo;
	
architecture kyg_apollo of apollo is
begin
	process (battery_voltage)
	begin
		if battery_voltage <= 6 then		-- 전압이 0~6v 일 때
			red_led <= '1';
			green_led <= '0';
			yellow_led <= '0';
		else										-- 전압이 6v 이상일 때
			if battery_voltage <= 10 then	-- 6~10v일 때
				red_led <= '0';
				green_led <= '1';
				yellow_led <= '1';
			elsif battery_voltage <= 12 then	-- 6~12v 일 때 
				red_led <= '0';
				green_led <= '1';
				yellow_led <= '0';
			else									-- 12v 초과일 때
				red_led <= '0';
				green_led <= '0';
				yellow_led <= '0';
			end if;
		end if;
	end process;
end kyg_apollo;