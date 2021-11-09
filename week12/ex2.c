//Vagif Khalilov BS20-04
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <string.h>
#include <unistd.h> 
#include <sys/resource.h>
#include <stdint.h>
#include <dirent.h>
#include <linux/input.h>
#include <fcntl.h>

//to save output in ex2.txt run sudo ./ex2.c > ex2.txt
int main(){
    int keybordEvent;
	struct input_event event;
	keybordEvent = open("/dev/input/by-path/platform-i8042-serio-0-event-kbd", O_RDONLY);
    
    if (keybordEvent == -1) return -1;

	while(1) {
        read(keybordEvent, &event, sizeof(event));
		if (event.type == EV_KEY) {
			if (event.value == 0)
				printf("RELEASED 0x%04x (%d)\n", event.code, event.code);
			else if (event.value == 1)
				printf("PRESSED 0x%04x (%d)\n", event.code, event.code);
		}
    }
}
