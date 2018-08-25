library verilog;
use verilog.vl_types.all;
entity or2test is
    port(
        a               : in     vl_logic;
        b               : in     vl_logic;
        y               : out    vl_logic
    );
end or2test;
