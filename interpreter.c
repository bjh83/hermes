#include"trampoline.h"
#include"stdlib.h"
#include"blink.h"

char* command[32];

char* load_command(char* statement) {
	int length = len(statement);
	int i;
	for(i = 0; i < length && statement[i] != ' '; i++) {
		command[i] = statement[i];
	};
	if(i < length) {
		i++;
	}
	command[i] = '\0';
	return statement + i;
}

void interpret(char* statement) {
	statement = load_command(statement);
	if(strcmp(command, "blink")) {
		fork(&blink_main, 1, &statement);
	}
}

