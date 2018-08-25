library verilog;
use verilog.vl_types.all;
entity decoder24_vlg_sample_tst is
    port(
        a               : in     vl_logic_vector(1 downto 0);
        sampler_tx      : out    vl_logic
    );
end decoder24_vlg_sample_tst;
