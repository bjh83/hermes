#include "trampoline.h"

extern void interpret(char*);

int shell_main(int argc, char* argv[]) {
	char buffer[64];
	print_string("Welcome to Hermes!!!\r\n");
	for(;;) {
		print_string("=>");
		read_string(buffer, 64);
		interpret(buffer);
		break;
	}
	for (;;);
	return 0;
}

