library verilog;
use verilog.vl_types.all;
entity full_adder_vlg_check_tst is
    port(
        c_out           : in     vl_logic;
        sum             : in     vl_logic;
        sampler_rx      : in     vl_logic
    );
end full_adder_vlg_check_tst;
