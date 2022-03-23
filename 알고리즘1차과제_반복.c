#include <stdio.h>
int factorial(int n){
    int temp=1;
    if(n==1){
        return 1;
    }
    
     for(int i=1; i<=n; i++){
        temp*=i;  //temp=temp*i;
    }  
    return temp;
}

int main(){
    int num;
    printf("정수를 입력하시오: ");
    scanf("%d", &num);
    printf("%d",factorial(num));
    return 0;
}
