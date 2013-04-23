int len(char* buffer) {
	int length;
	for(length = 0; buffer[length] != '\0'; length++) {}
	return length;
}

void copy(char* old, char* new) {
	int old_len = len(old);
	int new_len = len(new);
	if(old_len > new_len) {
		old_len = new_len;
	}
	int index;
	for(index = 0; index < old_len; index++) {
		new[index] = old[index];
	}
}

int strcmp(char* old, char* new) {
	int length = len(old);
	if(length != len(new)) {
		return 0;
	}
	int i;
	for(i = 0; i < length; i++) {
		if(old[i] != new[i]) {
			return 0;
		}
	}
	return 1;
}

