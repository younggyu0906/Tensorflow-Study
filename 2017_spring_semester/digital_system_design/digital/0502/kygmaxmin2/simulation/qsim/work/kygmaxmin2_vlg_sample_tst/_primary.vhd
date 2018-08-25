library verilog;
use verilog.vl_types.all;
entity kygmaxmin2_vlg_sample_tst is
    port(
        x               : in     vl_logic_vector(4 downto 0);
        y               : in     vl_logic_vector(4 downto 0);
        sampler_tx      : out    vl_logic
    );
end kygmaxmin2_vlg_sample_tst;
