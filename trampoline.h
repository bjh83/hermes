#define NOP 0
#define PRINT_INT 1
#define PRINT_FLOAT 2
#define PRINT_DOUBLE 3
#define PRINT_STRING 4
#define READ_INT 5
#define READ_FLOAT 6
#define READ_DOUBLE 7
#define READ_STRING 8
#define SBRK 9
#define EXIT 10
#define PRINT_CHARACTER 11
#define READ_CHARACTER 12
#define OPEN 13
#define READ 14
#define WRITE 15
#define CLOSE 16
#define EXIT2 17
#define YIELD 18
#define MUTEX_AQUIRE 19
#define MUTEX_RELEASE 20
#define CREATE_THREAD 21
#define MUTEX_INIT 22
#define KRNL_WAIT_FOR_THREAD 23
#define WRITE_CHAR_LED 24
#define READ_SECTOR 25

extern void nop();
extern void print_int(int value);
extern void print_float(float value);
extern void print_double(double value);
extern void print_string(char* buffer);
extern int read_int();
extern float read_float();
extern double read_double();
extern void read_string(char* buffer, int size);
extern void* sbreak(int size); 
extern void byebye();
extern void print_char(char value);
extern char read_char();
extern int open(char* file_name);
extern int read(int file_descr, void* buffer, int length);
extern void exit_2(int error);
extern void yield();
extern void mutex_aquire(int* mutex);
extern void mutex_release(int* mutex);
extern void* spoon(int (*mips_main)(int, char**), int argc, char* argv[]);
extern void mutex_init(int* mutex);
extern void wait_thread(void* thread);
extern void write_chars_LED(char first, char second);
extern int read_sector(int address, void* data);

