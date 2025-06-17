#include <stdio.h>
int main(){
	int a,b,x;
	do {
		printf("Nhap a (a<b): ");
		scanf("%d",&a);
		printf("Nhap b (b>a): ");
		scanf("%d",&b);
	}while(a>b);
	
	printf("Cac so nguyen to trong khoang tu %d den %d la: ",a,b);
	for(int i=a;i>=a&&i<=b;i++){
		int songuyento = 1;
		for(int n=2;n<i;n++){
			if(i%n==0){
				songuyento = 0;
				break;
			}
		}
		if(songuyento!=1){
			printf("%d ",x);
		}
	}
	
}
