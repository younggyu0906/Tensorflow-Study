library verilog;
use verilog.vl_types.all;
entity adder_16 is
    port(
        x               : in     vl_logic_vector(15 downto 0);
        y               : in     vl_logic_vector(15 downto 0);
        add_out         : out    vl_logic_vector(15 downto 0);
        carry_out       : out    vl_logic;
        overflow_check  : out    vl_logic
    );
end adder_16;
