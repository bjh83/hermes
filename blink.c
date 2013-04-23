#include"blink.h"

void _blink_R() {
	asm(
			"jal hal_xmips_blink_r\n"
			: // No inputs
			: // No outputs
			: "%ra"
	   );
};

void _blink_B() {
	asm(
			"jal hal_xmips_blink_b\n"
			: // No inputs
			: // No outputs
			: "%ra"
	   );
};

void _blink_G() {
	asm(
			"jal hal_xmips_blink_g\n"
			: // No inputs
			: // No outputs
			: "%ra"
	   );
};

void blink(int rgb) {
	switch(rgb) {
		case RED:
			_blink_R();
			break;
		case BLUE:
			_blink_B();
			break;
		case GREEN:
			_blink_G();
			break;
	}
}

int blink_main(int argc, char* argv[]) {
   if(strcmp(argv[0], "red")) {
	   blink(RED);
   } else if(strcmp(argv[0], "blue")) {
	   blink(BLUE);
   } else if(strcmp(argv[0], "green")) {
	   blink(GREEN);
   }
   return 0;
}

