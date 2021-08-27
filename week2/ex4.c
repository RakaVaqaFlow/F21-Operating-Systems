#include <stdio.h>
#include <string.h>

void swap(int* a, int* b){
int s=*a;
*a=*b;
*b=s;
}

int main(){
char a[15];
int a1=0, a2=0;
printf("enter 1st number:\n");
fgets(a, 15, stdin);
for(int i=0; i<strlen(a)-1; i++){
a1*=10;
a1=a1+(a[i]-'0');
}
printf("enter 2nd number:\n");
fgets(a, 15, stdin);
for(int i=0; i<strlen(a)-1; i++){
a2*=10;
a2=a2+(a[i]-'0');
}
printf("before swaping: 1st=%d and 2nd=%d\n", a1, a2);
swap(&a1, &a2);
printf("after swaping: 1st=%d and 2nd=%d\n", a1, a2);
}

