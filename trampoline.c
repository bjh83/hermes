#include "trampoline.h"

//Provides a trampoline from C to MIPS

void nop() {
	asm(
			"li $v0, 0\n"
			"syscall\n"
	   );
}

void print_int(int value) {
	asm(
			"addi $a0, %0, 0x0\n"
			"li $v0, 1\n"
			"syscall\n"
			: //no output
			: "r" (value)
			: "%a0", "%v0"
	   );
}

void print_float(float value) {
	asm(
			"addi $a0, %0, 0x0\n"
			"li $v0, 2\n"
			"syscall\n"
			: //no output
			: "r" (value)
			: "%a0", "%v0"
	   );
}

void print_double(double value) {
	asm(
			"addi $a0, %0, 0x0\n"
			"li $v0, 3\n"
			"syscall\n"
			: //no output
			: "r" (value)
			: "%a0", "%v0"
	   );
}

void print_string(char* buffer) {
	asm(
			"addi $a0, %0, 0x0\n"
			"li $v0, 4\n"
			"syscall\n"
			: //no output
			: "r" (buffer)
			: "%a0", "%v0"
	   );
}

int read_int() {
	int value;
	asm(
			"li $v0, 5\n"
			"syscall"
			"addi %0, $v0, 0x0\n"
			: "=r" (value)
			: //no input
			: "%v0"
	   );
	return value;
}

float read_float() {
	float value;
	asm(
			"li $v0, 6\n"
			"syscall"
			"addi %0, $v0, 0x0\n"
			: "=r" (value)
			: //no input
			: "%v0"
	   );
	return value;
}

double read_double() {
	double value;
	asm(
			"li $v0, 7\n"
			"syscall"
			"addi %0, $v0, 0x0\n"
			: "=r" (value)
			: //no input
			: "%v0"
	   );
	return value;
}

void read_string(char* buffer, int size) {
	asm(
			"addi $a0, %0, 0x0\n"
			"addi $a1, %1, 0x0\n"
			"li $v0, 8\n"
			"syscall\n"
			: //no output
			: "r" (buffer), "r" (size)
			: "%a0", "%a1", "%v0"
	   );
}

void* sbreak(int size) {
	void* memory;
	asm(
			"addi $a0, %1, 0x0\n"
			"li $v0, 9\n"
			"syscall\n"
			"addi %0, $v0, 0x0\n"
			: "=r" (memory)
			: "r" (size)
			: "%a0", "%v0"
	   );
	return memory;
}

void byebye() {
	asm(
			"li $v0, 10\n"
			"syscall\n"
			: // no output
			: // no input
			: "%v0"
	   );
}

void print_char(char value) {
	asm(
			"addi $a0, %0, 0x0\n"
			"li $v0, 11\n"
			"syscall\n"
			: //no output
			: "r" (value)
			: "%a0", "%v0"
	   );
}

char read_char() {
	char value;
	asm(
			"li $v0, 11\n"
			"syscall\n"
			"addi %0, $v0, 0x0\n"
			: "=r" (value)
			: // no input
			: "%v0"
	   );
	return value;
}

void exit_2(int error) {
	asm(
			"addi $a0, %0, 0x0\n"
			"li $v0, 17\n"
			"syscall\n"
			: //no output
			: "r" (error)
			: "%a0", "%v0"
	   );
}

void yield() {
	asm(
			"li $v0, 18\n"
			"syscall\n"
			: "%v0"
	   );
}

void mutex_aquire(int* mutex) {
	asm(
			"addi $a0, %0, 0x0\n"
			"li $v0, 19\n"'
			"syscall\n"
			: //no output
			: "r" (mutex)
			: "%a0", "%v0"
	   );
}

void mutex_release(int* mutex) {
	asm(
			"addi $a0, %0, 0x0\n"
			"li $v0, 20\n"
			"syscall\n"
			: //no output
			: "r" (mutex)
			: "%a0", "%v0"
	   );
}

void exodus() {
	int (*mips_main)(int, char**);
	int argc;
	char** argv;
	
	asm(
			"addi %0, $a0, 0x0\n"
			"addi %1, $a1, 0x0\n"
			"addi %2, $a2, 0x0\n"
			: "=r" (mips_main), "=r" (argc), "=r" (argv) //round up the parameters for main
			: // no inputs
			: "%a0", "%a1", "%a2"
	   );

	(*mips_main)(argc, argv); //Call the actual main

	byebye();
}

//This expects a main function
void* spoon(int (*mips_main)(int, char**), int argc, char* argv[]) {
	asm(
			"addi $a0, %0, 0x0\n"
			"addi $a1, %1, 0x0\n"
			"addi $a2, %2, 0x0\n"
			"addi $a3, %3, 0x0\n"
			"li $v0, 21\n"
			"syscall"
			: "=r" (thread)
			: "r" (&exodus), "r" (mips_main), "r" (argc), "r" (argv)
			: "%a0", "%a1", "%a2", "%a3", "%v0"
	   );
}

void mutex_init(int* mutex) {
	asm(
			"addi $a0, %0, 0x0\n"
			"li $v0, 22\n"
			"syscall\n"
			: //no output
			: "r" (mutex)
			: "%a0", "%v0"
	   );
}

void wait_thread(void* thread) {
	asm(
			"addi $a0, %0, 0x0\n"
			"li $v0, 23\n"
			"syscall\n"
			: //no output
			: "r" (thread)
			: "%a0", "%v0"
	   );
}

