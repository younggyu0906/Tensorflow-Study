library verilog;
use verilog.vl_types.all;
entity comparator_vlg_sample_tst is
    port(
        a               : in     vl_logic_vector(3 downto 0);
        b               : in     vl_logic_vector(3 downto 0);
        sampler_tx      : out    vl_logic
    );
end comparator_vlg_sample_tst;
