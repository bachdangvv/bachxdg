#include <stdio.h>
#include <math.h>

int isPrime(int n){
    if(n < 2) return 0;        
    if(n == 2) return 1;       
    if(n % 2 == 0) return 0;  

    for(int i = 3; i <= sqrt(n); i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int main(){
    int n;

    do{
    	printf("Nhap so n nguyen duong: ");
    	scanf("%d",&n);
	}while(n<=0);

    if (isPrime(n)) {
        printf("%d la so nguyen to.\n", n);
    } else {
        printf("%d khong phai la so nguyen to.\n", n);
    }

    return 0;
}
