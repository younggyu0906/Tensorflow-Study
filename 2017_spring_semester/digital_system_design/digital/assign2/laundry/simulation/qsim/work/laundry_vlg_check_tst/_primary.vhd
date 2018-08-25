library verilog;
use verilog.vl_types.all;
entity laundry_vlg_check_tst is
    port(
        dewater         : in     vl_logic;
        drainage        : in     vl_logic;
        l_stop          : in     vl_logic;
        rinse           : in     vl_logic;
        spin            : in     vl_logic;
        wash            : in     vl_logic;
        waterSupply     : in     vl_logic;
        sampler_rx      : in     vl_logic
    );
end laundry_vlg_check_tst;
