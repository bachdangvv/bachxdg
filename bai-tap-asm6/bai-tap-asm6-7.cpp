#include <stdio.h>
 main(){
	int n;
    do {
    	printf("Nhap so luong phan tu cua mang: ");
    	scanf("%d",&n);
	}while(n<=0);
	
	int player[n];
	for(int i = 0;i < n;i++){
		printf("Nhap phan tu vao mang: ");
		scanf("%d",&player[i]);
	}
	
	int x = 0;
	int y = 0;
	
	for(int i = 0;i < n;i++){
		if(player[i] > 0){
			x = x + player[i];
			if(x > y){
				y = x;
			}
		}else{
			x = 0;
		}
	}
	
	if(y == 0){
		printf("Mang khong co chuoi so duong nao");
	}else{
		printf("Tong lon nhat cua cac chuoi so duong lien tiep la: %d",y);
	}
	
}
