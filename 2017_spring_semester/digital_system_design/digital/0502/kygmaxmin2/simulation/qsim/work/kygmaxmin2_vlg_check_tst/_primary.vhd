library verilog;
use verilog.vl_types.all;
entity kygmaxmin2_vlg_check_tst is
    port(
        max             : in     vl_logic_vector(4 downto 0);
        min             : in     vl_logic_vector(4 downto 0);
        sampler_rx      : in     vl_logic
    );
end kygmaxmin2_vlg_check_tst;
