#include <stdio.h>
int main(){
	int n;
	int x;
	int cnt=1;
	printf("Nhap n: ");
	scanf("%d",&n);
	
	while(cnt<n){
		if(n%cnt==0){
			x = x + cnt;
		}
		cnt++;
	}
	if(x==n){
		printf("n la so hoan hao");
	}else{
		printf("n khong la so hoan hao");
	}
}
