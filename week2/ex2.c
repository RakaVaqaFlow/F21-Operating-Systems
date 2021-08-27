#include<stdio.h>
#include<string.h>
int main(){

printf("Enter a string:\n");
char str[1000];
fgets(str, 1000, stdin);
printf("revesre string:\n");
for(int i=strlen(str)-2; i>=0; i--){
printf("%c", str[i]);
}
printf("\n");
}
