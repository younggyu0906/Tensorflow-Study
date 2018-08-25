library verilog;
use verilog.vl_types.all;
entity kygmin1_vlg_sample_tst is
    port(
        a               : in     vl_logic_vector(2 downto 0);
        b               : in     vl_logic_vector(2 downto 0);
        y_out           : in     vl_logic_vector(2 downto 0);
        sampler_tx      : out    vl_logic
    );
end kygmin1_vlg_sample_tst;
