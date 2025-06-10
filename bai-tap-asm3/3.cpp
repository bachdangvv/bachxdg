#include <stdio.h>

int main(){
	int m;
	printf("Nhap so tien: ");
	scanf("%d",&m);
	
	int m500 = m/500;
	int r500 = m%500;
	int m200 = r500/200;
	int r200 = r500%200;
	int m100 = r200/100;
	int r100 = r200%100;
	int m50 = r100/50;
	int r50 = r100%50;
	int m20 = r50/20;
	int r20 = r50%20;
	int m10 = r20/10;
	int r10 = r20%10;
	
	printf("So luong tien can tra: %d to 500, %d to 200, %d to 100, %d to 50, %d to 20, %d to 10",m500,m200,m100,m50,m20,m10);
}
	
	
