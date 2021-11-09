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

typedef struct shortcut{
    int val[6];
}shortcut;

//shortcut C + A + P - "Get some cappuccino!"
//c = 46, a = 30, p = 25
int is_CAP(shortcut s){
    int n=0;
    for(int i=0; i<6; i++){ //
        if(s.val[i]==46){
            n++;
            break;
        }
    }
    for(int i=0; i<6; i++){ //
        if(s.val[i]==30){
            n++;
            break;
        }
    }
    for(int i=0; i<6; i++){ //
        if(s.val[i]==25){
            n++;
            break;
        }
    }
    if(n==3) return 1;
    return 0;
}
//shortcut P + E - "I passed the Exam!"
//p = 25, e = 18
int is_PE(shortcut s){ 
    int n =0;
    for(int i=0; i<6; i++){ //
        if(s.val[i]==25){
            n++;
            break;
        }
    }
    for(int i=0; i<6; i++){ //
        if(s.val[i]==18){
            n++;
            break;
        }
    }
    if(n==2) return 1;
    return 0;
}

//shortcut S + Y + E - "See you on retake!"
//s = 31, y = 21, e = 18
int is_SYR(shortcut s){ 
    int n=0; 
    for(int i=0; i<6; i++){ //
        if(s.val[i]==31){
            n++;
            break;
        }
    }
    for(int i=0; i<6; i++){ //
        if(s.val[i]==21){
            n++;
            break;
        }
    }
    for(int i=0; i<6; i++){ //
        if(s.val[i]==18){
            n++;
            break;
        }
    }
    if(n==3) return 1;
    return 0;
}

void clear_shortcut(shortcut s){
    for(int i=0; i<6; i++){
        s.val[i]=-1;
    }
}
int main(){
    FILE* output = fopen("./ex3.txt", "w+");
    shortcut s;
    int keybordEvent;
	struct input_event event;
	keybordEvent = open("/dev/input/by-path/platform-i8042-serio-0-event-kbd", O_RDONLY);
    
    if (keybordEvent == -1) return -1;
    printf("available shortcuts:\n");
    printf(" C + A + P - print \"Get some cappuccino!\"\n");
    printf(" P + E - print \"I passed the Exam!\"\n");
    printf(" S + Y + E - print \"See you on retake!\"\n");
    fputs("available shortcuts:\n", output);
    fputs(" C + A + P - print \"Get some cappuccino!\"\n", output);
    fputs(" P + E - print \"I passed the Exam!\"\n", output);
    fputs(" S + Y + E - print \"See you on retake!\"\n", output);
    fflush(output);
    int it=0;
	while(1) {
        read(keybordEvent, &event, sizeof(event));
		if (event.type == EV_KEY) {
			if (event.value == 0){
				//printf("RELEASED 0x%04x (%d)\n", event.code, event.code);
                for(int i=0; i<6; i++){
                    s.val[i]=-1;
                }
                it=0;
            }
			else if (event.value == 1){
				//printf("PRESSED 0x%04x (%d)\n", event.code, event.code);
                if(it>5) it=0;
                s.val[it] = (int)event.code;
                it++;
                if(is_CAP(s)){
                    printf("Get some cappuccino!\n");
                    fputs("Get some cappuccino!\n", output);
                    clear_shortcut(s);
                    it=0;
                }
                else if(is_PE(s)){
                    printf("I passed the Exam!\n");
                    fputs("I passed the Exam!\n", output);
                    clear_shortcut(s);
                    it=0;
                }
                else if(is_SYR(s)){
                    printf("See you on retake!\n");
                    fputs("See you on retake!\n", output);
                    clear_shortcut(s);
                    it=0;
                }
                fflush(output);
            }
		}
    }
}
