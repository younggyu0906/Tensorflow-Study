library verilog;
use verilog.vl_types.all;
entity nor4test_vlg_sample_tst is
    port(
        a               : in     vl_logic;
        b               : in     vl_logic;
        c               : in     vl_logic;
        d               : in     vl_logic;
        sampler_tx      : out    vl_logic
    );
end nor4test_vlg_sample_tst;