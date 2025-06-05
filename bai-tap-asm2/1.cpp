#include <stdio.h>

int main(){
	float a;
	printf("Nhap canh a: ");
	scanf("%f",&a);
	
	float b;
	printf("Nhap canh b: ");
	scanf("%f",&b);
	
	float c;
	printf("Nhap canh c: ");
	scanf("%f",&c);
	
	if(a+b>c){
		if(a+c>b){
			if (b+c>a){
				printf("a,b,c la 3 canh cua 1 tam giac");
			}else{
				printf("a,b,c khong phai la 3 canh cua 1 tam giac");
			}
		}else{
			printf("a,b,c khong phai la 3 canh cua 1 tam giac");
		}
	}else{
		printf("a,b,c khong phai la 3 canh cua 1 tam giac");
	}
}
