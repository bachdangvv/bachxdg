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
			x++;
			if(x > y){
				y++;
			}
		}else{
			x = 0;
		}
	}
	
	printf("So luong cac so duong lien tiep nhieu nhat la: %d",y);
}
