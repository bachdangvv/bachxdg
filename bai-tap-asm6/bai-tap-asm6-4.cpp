#include <stdio.h>
int main(){
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
	
	int x=-1;
	for (int i = n - 1;i >= 0; i--) {
        if (player[i] % 2 != 0) {
            x = player[i];
            break;
        }
    }
    
    if(x!=-1){
    	printf("So le cuoi cung trong mang la: %d",x);
	}else{
		printf("Khong co so le cuoi cung trong mang");
	}
}
