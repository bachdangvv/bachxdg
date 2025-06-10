#include <stdio.h>

int main(){
	int tn;
	printf("Nhap vao thu nhap hang thang: ");
	scanf("%d",&tn);
	
	int tndt = tn-11;
	int tax = 0;
	if(tndt <= 0){
		printf("Thu nhap chua can dong thue");
	}else if(tndt <= 5){
		tax = tndt*0.05;
		printf("So tien thue can nop la %d",tax);
	}else if(tndt <= 10){
		tax = 5*0.05+(tndt-5)*0.1;
		printf("So tien thue can nop la %d",tax);
	}else if(tndt <= 18){
		tax = 5*0.05+5*0.1+(tndt-10)*0.15;
		printf("So tien thue can nop la %d",tax);
	}else if(tndt <= 32){
		tax = 5*0.05+5*0.1+8*0.15+(tndt-18)*0.2;
		printf("So tien thue can nop la %d",tax);
	}else if(tndt <= 52){
		tax = 5*0.05+5*0.1+8*0.15+14*0.2+(tndt-32)*0.25;
		printf("So tien thue can nop la %d",tax);
	}else if(tndt <= 80){
		tax = 5*0.05+5*0.1+8*0.15+14*0.2+20*0.25+(tndt-52)*0.3;
		printf("So tien thue can nop la %d",tax);
	}else{
		tax = 5*0.05+5*0.1+8*0.15+14*0.2+20*0.25+28*0.3+(tndt-80)*0.35;
		printf("So tien thue can nop la %d",tax);
	}
}
