onerror {quit -f}
vlib work
vlog -work work decoder24.vo
vlog -work work decoder24.vt
vsim -novopt -c -t 1ps -L cycloneive_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.decoder24_vlg_vec_tst
vcd file -direction decoder24.msim.vcd
vcd add -internal decoder24_vlg_vec_tst/*
vcd add -internal decoder24_vlg_vec_tst/i1/*
add wave /*
run -all
