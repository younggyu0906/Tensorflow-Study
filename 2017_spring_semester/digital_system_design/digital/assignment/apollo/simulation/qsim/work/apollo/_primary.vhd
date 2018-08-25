library verilog;
use verilog.vl_types.all;
entity apollo is
    port(
        battery_voltage : in     vl_logic_vector(31 downto 0);
        red_led         : out    vl_logic;
        green_led       : out    vl_logic;
        yellow_led      : out    vl_logic
    );
end apollo;
