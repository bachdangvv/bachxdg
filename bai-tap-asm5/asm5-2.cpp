#include <stdio.h>
int main(){
	int a;
	printf("Nhap a: ");
	scanf("%d",&a);
	int b;
	printf("Nhap b: ");
	scanf("%d",&b);
	int x = 0;
	int y = 0;
	
	for(int i = 1;i<a&&i<b;i++){
		if(a%i==0&&b%i==0){
			x = i;
		}
	}
	printf("Uoc chung lon nhat cua %d va %d la: %d\n",a,b,x);
	
	for(int i;i>a&&i>b;i++){
		if(i%a==0&&i%b==0){
			y = i;
			break;
		}
	}
	printf("Boi chung nho nhat cua %d va %d la: %d",a,b,y);
}
