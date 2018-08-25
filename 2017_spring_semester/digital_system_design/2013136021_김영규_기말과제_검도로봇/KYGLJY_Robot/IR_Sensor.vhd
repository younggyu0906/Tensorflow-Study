library ieee;
 use ieee.std_logic_1164.all;
 
 entity IR_Sensor is
 port( clk : in std_logic; -- Clock signal
         sig : in std_logic;
         y_out : out std_logic); -- Low logic interrupt output
 end entity;
 
 architecture sample of IR_Sensor is
 begin
   Decoder: process(clk)
   begin
      if(clk'event and clk = '1') then
         y_out <= sig;
      end if;
   end process;
 end sample;