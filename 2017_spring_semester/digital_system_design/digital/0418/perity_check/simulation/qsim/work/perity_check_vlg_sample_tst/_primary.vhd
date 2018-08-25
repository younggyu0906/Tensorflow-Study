library verilog;
use verilog.vl_types.all;
entity perity_check_vlg_sample_tst is
    port(
        a               : in     vl_logic_vector(4 downto 0);
        sampler_tx      : out    vl_logic
    );
end perity_check_vlg_sample_tst;
