library verilog;
use verilog.vl_types.all;
entity system_vlg_sample_tst is
    port(
        k1              : in     vl_logic;
        k2              : in     vl_logic;
        k3              : in     vl_logic;
        sampler_tx      : out    vl_logic
    );
end system_vlg_sample_tst;
