library verilog;
use verilog.vl_types.all;
entity andlogic is
    port(
        a               : in     vl_logic_vector(0 to 3);
        y               : out    vl_logic
    );
end andlogic;
