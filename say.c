#include"trampoline.h"
#include"stdlib.h"

int say_main(int argc, char* argv[]) {
	if(argc != 1) {
		return 0;
	}
	char* string = argv[0];
	int length = len(string);
	if(length < 1) {
		return 0;
	}
	char old;
	char new = string[0];
	int i = 1;
	for(; i < length; i++) {
		old = new;
		new = string[i];
		write_chars_LED(old, new);
	}
	return 0;
}

