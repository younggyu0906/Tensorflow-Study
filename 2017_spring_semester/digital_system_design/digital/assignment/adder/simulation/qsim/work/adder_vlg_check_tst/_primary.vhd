library verilog;
use verilog.vl_types.all;
entity adder_vlg_check_tst is
    port(
        carry           : in     vl_logic_vector(4 downto 0);
        y_out           : in     vl_logic_vector(4 downto 0);
        sampler_rx      : in     vl_logic
    );
end adder_vlg_check_tst;
