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
	
	int high = player[0];
	
	for(int i = 0;i < n;i++){
		if(player[i]>high){
			high = player[i];
		}
	}
	
	if(high > 0){
		int min = high;
		for(int i = 0;i < n;i++){
			if(player[i] > 0 && player[i] < min){
				min = player[i];
			}
		}
		printf("So duong nho nhat: %d",min);
	}else{
		printf("Mang toan so am");
	}
}
