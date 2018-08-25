library verilog;
use verilog.vl_types.all;
entity andlogic_vlg_sample_tst is
    port(
        a               : in     vl_logic_vector(0 to 3);
        sampler_tx      : out    vl_logic
    );
end andlogic_vlg_sample_tst;
