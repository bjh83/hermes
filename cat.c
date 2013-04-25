#include"trampoline.h"

int cat_main(int argc, char* argv[]) {
	if(argc != 1) {
		print_string("Not enough arguments\r\n");
		return 1;
	}
	char buffer[33];
	buffer[32] = '\0';
	int file = open(argv[0]);
	if(file == -1) {
		print_string("Open file failed\r\n");
	}
	int num_read;
	do {
		num_read = read(file, buffer, 32);
		if(num_read == -1) {
			print_string("Reading failed\r\n");
			return 1;
		}
		print_string(buffer);
	} while(num_read == 32);
	print_string("\r\n");
	return 0;
}

