library verilog;
use verilog.vl_types.all;
entity KYGLJY_Robot_vlg_check_tst is
    port(
        HS_Trigger      : in     vl_logic;
        SBM_output      : in     vl_logic;
        STM1_output     : in     vl_logic_vector(3 downto 0);
        STM2_output     : in     vl_logic_vector(3 downto 0);
        sampler_rx      : in     vl_logic
    );
end KYGLJY_Robot_vlg_check_tst;
