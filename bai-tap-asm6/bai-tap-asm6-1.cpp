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

    int s = 0;
	int c = 0;  
    for (int i = 0; i < n; i++) {
        if (player[i] % 2 != 0) {
            s = s + player[i];
            c++;
        }
    }
    
    if(c > 0){
    	float tbc = (float)s / c;
    	printf("Trung binh cong so le la: %f",tbc);
	}else{
		printf("Khong co so le");
	}
}
