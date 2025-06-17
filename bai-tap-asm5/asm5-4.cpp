#include <stdio.h>
int main(){
	int n;
	printf("Nhap 1 so nguyen duong: ");
	scanf("%d",&n);
	
	while(n>=10){
		n = n/10;
	}
	printf("Chu so dau tien la:  %d",n);
}
