library verilog;
use verilog.vl_types.all;
entity signal_lamp_vlg_check_tst is
    port(
        xlamp0          : in     vl_logic_vector(4 downto 0);
        xlamp1          : in     vl_logic_vector(4 downto 0);
        xlamp2          : in     vl_logic_vector(4 downto 0);
        xlamp3          : in     vl_logic_vector(4 downto 0);
        ylamp0          : in     vl_logic_vector(4 downto 0);
        ylamp1          : in     vl_logic_vector(4 downto 0);
        ylamp2          : in     vl_logic_vector(4 downto 0);
        ylamp3          : in     vl_logic_vector(4 downto 0);
        sampler_rx      : in     vl_logic
    );
end signal_lamp_vlg_check_tst;
