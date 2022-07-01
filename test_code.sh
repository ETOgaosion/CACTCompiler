./build.sh
# ./run_test.sh > res/code_gen_res.txt
gdb build/compiler test/samples_codegen/20_array_double_vector_add.cact
riscv64-unknown-elf-gcc -g test/samples_codegen/20_array_double_vector_add.S -L./ -lcact -o test/samples_codegen/20_array_double_vector_add
riscv64-unknown-elf-objdump -S test/samples_codegen/20_array_double_vector_add > test/samples_codegen/20_array_double_vector_add.obj
spike pk test/samples_codegen/20_array_double_vector_add