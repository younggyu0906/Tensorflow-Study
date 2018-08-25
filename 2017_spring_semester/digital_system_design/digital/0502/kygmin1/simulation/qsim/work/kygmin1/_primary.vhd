library verilog;
use verilog.vl_types.all;
entity kygmin1 is
    port(
        a               : in     vl_logic_vector(2 downto 0);
        b               : in     vl_logic_vector(2 downto 0);
        y_out           : inout  vl_logic_vector(2 downto 0);
        seg1            : out    vl_logic_vector(6 downto 0);
        seg2            : out    vl_logic_vector(6 downto 0);
        seg3            : out    vl_logic_vector(6 downto 0);
        segsel1         : out    vl_logic;
        segsel2         : out    vl_logic;
        segsel3         : out    vl_logic
    );
end kygmin1;
