library verilog;
use verilog.vl_types.all;
entity sys_var is
    port(
        i               : in     vl_logic;
        j               : in     vl_logic;
        k               : in     vl_logic;
        l               : out    vl_logic
    );
end sys_var;
