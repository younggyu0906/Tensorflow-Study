library verilog;
use verilog.vl_types.all;
entity bcdAdder is
    port(
        a               : in     vl_logic_vector(3 downto 0);
        b               : in     vl_logic_vector(3 downto 0);
        carryIn         : in     vl_logic;
        out_put_carry   : out    vl_logic;
        sum             : out    vl_logic_vector(3 downto 0)
    );
end bcdAdder;
