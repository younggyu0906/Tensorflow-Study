onerror {quit -f}
vlib work
vlog -work work reg4.vo
vlog -work work reg4.vt
vsim -novopt -c -t 1ps -L cycloneive_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.reg4_vlg_vec_tst
vcd file -direction reg4.msim.vcd
vcd add -internal reg4_vlg_vec_tst/*
vcd add -internal reg4_vlg_vec_tst/i1/*
add wave /*
run -all
