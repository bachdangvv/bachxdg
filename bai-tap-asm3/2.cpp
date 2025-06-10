#include <stdio.h>

int main(){
	int d,m,y,max;
	
	printf("Nhap ngay: ");
	scanf("%d",&d);
	printf("Nhap thang: ");
	scanf("%d",&m);
	printf("Nhap nam: ");
	scanf("%d",&y);
	
	max = 28;
	
	if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12){
		max = 31;
	}else if(m==4 || m==6 ||  m==9 || m==11){
		max = 30;
	}else if(y%4==0 && y%100!=0){
		max = 29;
	}else{
		max = 28;
	}
	
	if(d < max){
		printf("Ngay ke tiep: %d/%d/%d",d+1,m,y);
	}else{
		if(m<12){
			printf("Ngay ke tiep: %d/%d/%d",1,m+1,y);	
		}else{
			printf("Ngay ke tiep: %d/%d/%d",1,1,y+1);
		}
	}
	
}

