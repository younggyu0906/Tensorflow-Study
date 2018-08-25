library verilog;
use verilog.vl_types.all;
entity cla4_vlg_check_tst is
    port(
        carry           : in     vl_logic;
        sum             : in     vl_logic_vector(3 downto 0);
        sampler_rx      : in     vl_logic
    );
end cla4_vlg_check_tst;
