library verilog;
use verilog.vl_types.all;
entity KYGLJY_Robot is
    port(
        IR1_input       : in     vl_logic;
        IR2_input       : in     vl_logic;
        clk             : in     vl_logic;
        HS_Echo         : in     vl_logic;
        STM1_output     : out    vl_logic_vector(3 downto 0);
        STM2_output     : out    vl_logic_vector(3 downto 0);
        SBM_output      : out    vl_logic;
        HS_Trigger      : out    vl_logic
    );
end KYGLJY_Robot;
