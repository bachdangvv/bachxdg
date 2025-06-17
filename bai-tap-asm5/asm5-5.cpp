#include <stdio.h>
int main(){
	int n;
	printf("Nhap n: ");
	scanf("%d",&n);
	int maxdv = 0;
	
	while(n>0){
		int dv = n%10;
		if(dv>maxdv){
			maxdv = dv;
		}
		n = n/10;
	}
	printf("Chu so lon nhat la: %d",maxdv);
}
