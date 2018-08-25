library verilog;
use verilog.vl_types.all;
entity full_adder is
    port(
        w               : in     vl_logic;
        x               : in     vl_logic;
        y               : in     vl_logic;
        carry           : out    vl_logic;
        sum             : out    vl_logic
    );
end full_adder;
