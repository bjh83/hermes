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

int atoi(char* string) {
	int length = len(string);
	int retVal = 0;
	char number;
	int i = 0;
	if(length < 1) {
		return 0;
	}
	do {
		number = string[i];
		number -= '0';
		retVal *= 10;
		retVal += number;
		i++;
	} while(i < length);
	return retVal;
}

