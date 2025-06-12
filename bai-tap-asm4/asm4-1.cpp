#include <stdio.h>
int main(){
	int n;
	int cnt=1;
	printf("Nhap n: ");
	scanf("%d",&n);
	
	while(cnt<=n){
		if(cnt%2!=0){
			printf("%d ",cnt);
		}
		cnt++;
	}
}
