#include <stdio.h>

int main(){
	int n;
	int S = 0;
	do{
    	printf("Nhap so n nguyen duong: ");
    	scanf("%d",&n);
	}while(n<=0);
	
	for(int i = 1;i <= n;i++){
		S = S + i;
	}
	
	printf("Tong cac so tu 1 toi n la: %d",S);
}
