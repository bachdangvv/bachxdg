#include <stdio.h>
int main(){
	int n;
	int x;
	int cnt=1;
	printf("Nhap n: ");
	scanf("%d",&n);
	
	while(cnt<n){
		if(cnt%6==0){
			x = cnt;
		}
		cnt++;
	}
	printf("So lon nhat nho hon n va chia het cho 2 va 3 la: %d",x);
}
