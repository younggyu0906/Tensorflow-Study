library verilog;
use verilog.vl_types.all;
entity adder is
    port(
        a               : in     vl_logic_vector(3 downto 0);
        b               : in     vl_logic_vector(3 downto 0);
        carry           : inout  vl_logic_vector(4 downto 0);
        y_out           : out    vl_logic_vector(4 downto 0)
    );
end adder;
