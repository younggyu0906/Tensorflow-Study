onerror {quit -f}
vlib work
vlog -work work or2test.vo
vlog -work work or2test.vt
vsim -novopt -c -t 1ps -L cycloneii_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.or2test_vlg_vec_tst
vcd file -direction or2test.msim.vcd
vcd add -internal or2test_vlg_vec_tst/*
vcd add -internal or2test_vlg_vec_tst/i1/*
add wave /*
run -all
