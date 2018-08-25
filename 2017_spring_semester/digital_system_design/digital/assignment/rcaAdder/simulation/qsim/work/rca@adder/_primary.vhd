library verilog;
use verilog.vl_types.all;
entity rcaAdder is
    port(
        x               : in     vl_logic_vector(3 downto 0);
        y               : in     vl_logic_vector(3 downto 0);
        c_in            : in     vl_logic;
        carry           : out    vl_logic;
        sum             : out    vl_logic_vector(3 downto 0)
    );
end rcaAdder;
