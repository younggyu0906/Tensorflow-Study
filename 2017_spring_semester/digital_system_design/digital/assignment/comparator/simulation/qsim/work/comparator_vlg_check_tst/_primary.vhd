library verilog;
use verilog.vl_types.all;
entity comparator_vlg_check_tst is
    port(
        a_out           : in     vl_logic;
        b_out           : in     vl_logic;
        s_out           : in     vl_logic;
        sampler_rx      : in     vl_logic
    );
end comparator_vlg_check_tst;
