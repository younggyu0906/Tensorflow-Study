library verilog;
use verilog.vl_types.all;
entity apollo_vlg_check_tst is
    port(
        green_led       : in     vl_logic;
        red_led         : in     vl_logic;
        yellow_led      : in     vl_logic;
        sampler_rx      : in     vl_logic
    );
end apollo_vlg_check_tst;
