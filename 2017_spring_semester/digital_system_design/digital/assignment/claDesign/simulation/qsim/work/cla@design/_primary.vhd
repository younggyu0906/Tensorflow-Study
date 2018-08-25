library verilog;
use verilog.vl_types.all;
entity claDesign is
    port(
        a               : in     vl_logic_vector(3 downto 0);
        b               : in     vl_logic_vector(3 downto 0);
        carryIn         : in     vl_logic;
        carry           : out    vl_logic;
        sum             : out    vl_logic_vector(3 downto 0)
    );
end claDesign;
