#include <stdio.h>
#include <string.h>
int main(int argc, char* argv[]){
int n=0;
for(int i=0; i<strlen(argv[1]); i++){
	n*=10;
	n=n+(argv[1][i]-'0');
} 
int it1=(2*n-1)/2;
int it2=it1;
for(int i=0; i<n; i++){
	for(int j=0; j<2*n-1; j++){
		if(j>=it1 && j<=it2) printf("*");
		else printf(" ");
	}
	printf("\n");
	it1--;
	it2++;
}

}
