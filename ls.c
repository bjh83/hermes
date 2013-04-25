#include"trampoline.h"
#include"stdlib.h"

typedef struct {
	unsigned int magic;
	char name[16];
	unsigned int start;
	unsigned int size;
	char pad[4];
} rawentry_t;

struct raw_index {
	int magic;
	unsigned int size;
	unsigned int entry_number;
	char pad[20];
	rawentry_t entries[31];
};

char data[1024];

int read_index(struct raw_index* index) {
	if(read_sector(0, (void*) data) != 1) {
		return 0;
	}
	if(read_sector(512, (void*) (data + 512)) != 1) {
		return 0;
	}
	*index = *((struct raw_index*) data);
	return 1;
}

int ls_main(int argc, char* argv[]) {
	struct raw_index index;
	if(read_index(&index) != 1) {
		print_string("reading the filesystem failed\r\n");
		return 1;
	}
	int i;
	for(i = 0; i < index->entry_number; i++) {
		print_string(index->entries[i].name);
		print_string("\r\n");
	}
	return 0;
}

