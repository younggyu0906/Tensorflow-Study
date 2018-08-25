library verilog;
use verilog.vl_types.all;
entity bcdAdder_vlg_sample_tst is
    port(
        a               : in     vl_logic_vector(3 downto 0);
        b               : in     vl_logic_vector(3 downto 0);
        carryIn         : in     vl_logic;
        sampler_tx      : out    vl_logic
    );
end bcdAdder_vlg_sample_tst;
