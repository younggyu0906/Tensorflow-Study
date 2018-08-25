library verilog;
use verilog.vl_types.all;
entity kygmaxmin2 is
    port(
        x               : in     vl_logic_vector(4 downto 0);
        y               : in     vl_logic_vector(4 downto 0);
        max             : out    vl_logic_vector(4 downto 0);
        min             : out    vl_logic_vector(4 downto 0)
    );
end kygmaxmin2;
