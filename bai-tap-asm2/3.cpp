#include <stdio.h>
#include <math.h>

int main(){
	int a;
	printf("Nhap a: ");
	scanf("%d",&a);
	int b;
	printf("Nhap b: ");
	scanf("%d",&b);
	int c;
	printf("Nhap c: ");
	scanf("%d",&c);
	int x, d;
	float x1, x2;
	
	if(a==0){
		if(b==0){
			if(c==0){
				printf("Vo so nghiem");
			}else{
				printf("Vo nghiem");
			}
		}else{
			x=-c/b;
			printf("Phuong trinh co 1 nghiem la: %d",x);
		}
	}else{
		d=b*b-4*a*c;
		if(d>0){
			x1=(-b+sqrt(d))/(2*a);
			x2=(-b-sqrt(d))/(2*a);
			printf("Phuong trinh co 2 nghiem la: %f va %f",x1,x2);
		}else{
			if(d==0){
				x=-b/(2*a);
				printf("Phuong trinh co 1 nghiem la: %d",x);
			}else{
				printf("Vo nghiem");
			}
		}
	}
}
