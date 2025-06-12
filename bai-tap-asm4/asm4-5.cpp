#include <stdio.h>
int main(){
	int f0 = 0;
	int f1 = 1;
	int fn;
	int cnt = 2;
	int n;
	printf("Nhap n: ");
	scanf("%d",&n);
	
	if(n==0){
		printf("%d la so thu %d trong day fibonacci",f0,n);
	}else{
		if(n==1){
			printf("%d la so thu %d trong day fibonacci",f1,n);
		}else{
			while(cnt<=n){
					fn = f0 + f1;
					f0 = f1;
					f1 = fn;
					cnt++;
					}
					printf("%d la so thu %d trong day fibonacci",fn,n);
		}
	}
}
