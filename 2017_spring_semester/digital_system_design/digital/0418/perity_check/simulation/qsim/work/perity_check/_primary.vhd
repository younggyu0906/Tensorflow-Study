library verilog;
use verilog.vl_types.all;
entity perity_check is
    port(
        a               : in     vl_logic_vector(4 downto 0);
        parity_check    : out    vl_logic
    );
end perity_check;
