library verilog;
use verilog.vl_types.all;
entity parity_vlg_check_tst is
    port(
        parity_check    : in     vl_logic;
        sampler_rx      : in     vl_logic
    );
end parity_vlg_check_tst;
