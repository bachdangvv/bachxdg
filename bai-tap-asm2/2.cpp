#include <stdio.h>

int main(){
	int kwh;
	int t;
	printf("Nhap so kwh da tieu thu: ");
	scanf("%d",&kwh);
	
	if(kwh<=50){
		t=kwh*1678;
		printf("So tien dien la: %d",t);
	}else{
		if(kwh<=100){
			t=50*1678+(kwh-50)*1734;
			printf("So tien dien la: %d",t);
		}else{
			if(kwh<=200){
				t=50*1678+50*1734+(kwh-100)*2014;
				printf("So tien dien la: %d",t);
			}else{
				t=50*1678+50*1734+100*2014+(kwh-200)*2536;
				printf("So tien dien la: %d",t);
			}
		}
	}
}
