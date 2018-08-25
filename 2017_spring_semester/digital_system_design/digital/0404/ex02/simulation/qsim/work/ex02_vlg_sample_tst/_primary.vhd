library verilog;
use verilog.vl_types.all;
entity ex02_vlg_sample_tst is
    port(
        d               : in     vl_logic;
        en              : in     vl_logic;
        sampler_tx      : out    vl_logic
    );
end ex02_vlg_sample_tst;
