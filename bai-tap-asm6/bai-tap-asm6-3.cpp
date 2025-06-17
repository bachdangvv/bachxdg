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

    int x;
    printf("Nhap x: ");
    scanf("%d",&x);
    int found = 0;
    
    for(int i = 0;i < n;i++){
    	if(x == player[i]){
    		found = 1;
    		break;
		}
	}
	
	if(found != 0){
		printf("Co so %d trong mang",x);
	}else{
		printf("Khong co so %d trong mang",x);
	}
}
