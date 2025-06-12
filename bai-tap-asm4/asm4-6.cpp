#include <stdio.h>
int main(){
	int f0 = 0;
	int f1 = 1;
	int fn = 0;
	int n;
	printf("Nhap n: ");
	scanf("%d",&n);
	
	if(n<=0){
		printf("Khong co so tiem can duoi voi %d ma thuoc day fibonacci",n);
	}else{
			while((f1+fn)<=n){
					f0 = f1;
					f1 = fn;	
					fn = f0 + f1;
					}
					printf("%d la so tiem can duoi voi %d ma thuoc day fibonacci",fn,n);
		}
	}
