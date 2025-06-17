#include <stdio.h>
int main(){
	int n;
	printf("Nhap n: ");
	scanf("%d",&n);
	int x = 0;
	
	for(int i=n;i>0;){
		x = x+(i%10);
		i = i/10;
	}
	printf("Tong cac chu so cua %d la: %d",n,x);
}
