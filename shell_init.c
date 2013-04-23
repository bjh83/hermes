#include"trampoline.h"
#include"interpreter.h"

int mips_main(int argc, char* argv[]) {
	char buffer[64];
	print_string("Welcome to hydra!!!\n");
	for(;;) {
		print_string("=>");
		read_string(buffer, 64);
		interpret(buffer);
	}
	return 0;
}

