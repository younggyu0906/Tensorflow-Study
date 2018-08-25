library verilog;
use verilog.vl_types.all;
entity nor_sys is
    port(
        a               : in     vl_logic_vector(7 downto 0);
        c               : out    vl_logic
    );
end nor_sys;
