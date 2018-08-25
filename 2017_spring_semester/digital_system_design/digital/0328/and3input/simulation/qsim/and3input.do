onerror {quit -f}
vlib work
vlog -work work and3input.vo
vlog -work work and3input.vt
vsim -novopt -c -t 1ps -L cycloneii_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.and3input_vlg_vec_tst
vcd file -direction and3input.msim.vcd
vcd add -internal and3input_vlg_vec_tst/*
vcd add -internal and3input_vlg_vec_tst/i1/*
add wave /*
run -all
