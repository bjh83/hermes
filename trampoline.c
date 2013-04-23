//Provides a trampoline from C to MIPS
void read_string(char* buffer, int size) {
	asm(
			"addi $a0, %0, 0x0\n"
			"addi $a1, %1, 0x0\n"
			"li $v0, 8\n"
			"syscall\n"
			: //no output
			: "r" (buffer), "r" (size)
			: "$a0", "$a1", "$v0"
	   );
}

void print_string(char* buffer) {
	asm(
			"addi $a0, %0, 0x0\n"
			"li $v0, 4\n"
			"syscall\n"
			: //no output
			: "r" (buffer)
			: "$a0", "$v0"
	   );
}

void exit() {
	asm(
			"li $v0, 10\n"
			"syscall\n"
	   );
}

void exodus() {
	int (*mips_main)(int, char**);
	int argc;
	char* argv[];
	
	asm(
			"addi %0, $a1, 0x0\n"
			"addi %1, $a2, 0x0\n"
			"addi %2, $a3, 0x0\n"
			: "=r" (mips_main), "=r" (argc), "=r" (argv) //round up the parameters for main
	   );

	(*mips_main)(argc, argv); //Call the actual main

	exit();
}

//This expects a main function
void fork(int (*mips_main)(int, char**), int argc, char* argv[]) {
	asm(
			"addi $a0, %0, 0x0\n"
			"addi $a1, %1, 0x0\n"
			"addi $a2, %2, 0x0\n"
			"addi $a3, %3, 0x0\n"
			"li $v0, 21\n"
			"syscall"
			: //no outputs
			: "r" (&exodus), "r" (mips_main), "r" (argc), "r" (argv)
	   );
}

