#include <stdio.h>
int main(){
	int n;
	printf("Nhap n: ");
	scanf("%d",&n);
	int x = 0;
	int cnt = 1;
	
	printf("Cac uoc cua %d la: ",n);
	while(cnt<=n){
		if(n%cnt==0){
			printf("%d ",cnt);
			x = x + cnt;
		}
		cnt++;
	}
	printf("\nTong cac uoc cua n la %d",x);
}
