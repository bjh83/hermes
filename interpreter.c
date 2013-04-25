#include"trampoline.h"
#include"stdlib.h"
#include"blink.h"

extern int say_main(int argc, char* argv[]);
extern int ls_main(int argc, char* argv[]);

char command[32];

char* load_command(char* statement) {
	int length = len(statement);
	int i;
	for(i = 0; i < length && statement[i] != ' '; i++) {
		command[i] = statement[i];
	};
	command[i] = '\0';
	if(i < length) {
		i++;
	}
	return statement + i;
}

void interpret(char* statement) {
	statement = load_command(statement);
	void* thread = NULL;
	if(strcmp(command, "blink")) {
		thread = spoon(&blink_main, 1, &statement);
	} else if(strcmp(command, "say")) {
		thread = spoon(&say_main, 1, &statement);
	} else if(strcmp(command, "ls")) {
		thread = spoon(&ls_main, 0, NULL);
	}
	if(thread != NULL) {
		wait_thread(thread);
	}
}

