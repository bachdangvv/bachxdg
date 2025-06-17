#include <stdio.h>
int main(){
	int n;
	printf("Nhap n: ");
	scanf("%d",&n);
	int sole = 1;
	
	while(n>0){
		int dv = n%10;
		if(dv%2==0){
			sole = 0;
			break;
		}
		n = n/10;
	}
	if(sole==1){
		printf("Chu so n toan le");
	}else{
		printf("Chu so n khong toan le");
	}
	
}
