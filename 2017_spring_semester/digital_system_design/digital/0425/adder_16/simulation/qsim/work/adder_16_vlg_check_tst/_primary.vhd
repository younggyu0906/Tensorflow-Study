library verilog;
use verilog.vl_types.all;
entity adder_16_vlg_check_tst is
    port(
        add_out         : in     vl_logic_vector(15 downto 0);
        carry_out       : in     vl_logic;
        overflow_check  : in     vl_logic;
        sampler_rx      : in     vl_logic
    );
end adder_16_vlg_check_tst;
