onerror {quit -f}
vlib work
vlog -work work parity.vo
vlog -work work parity.vt
vsim -novopt -c -t 1ps -L cycloneive_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.parity_vlg_vec_tst
vcd file -direction parity.msim.vcd
vcd add -internal parity_vlg_vec_tst/*
vcd add -internal parity_vlg_vec_tst/i1/*
add wave /*
run -all
