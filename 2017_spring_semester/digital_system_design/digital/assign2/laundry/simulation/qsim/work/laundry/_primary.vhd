library verilog;
use verilog.vl_types.all;
entity laundry is
    port(
        clk             : in     vl_logic;
        l_start         : in     vl_logic;
        pollution       : in     vl_logic;
        l_stop          : out    vl_logic;
        wash            : out    vl_logic;
        rinse           : out    vl_logic;
        dewater         : out    vl_logic;
        waterSupply     : out    vl_logic;
        spin            : out    vl_logic;
        drainage        : out    vl_logic
    );
end laundry;
