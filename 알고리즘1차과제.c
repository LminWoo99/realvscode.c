#include <stdio.h>

int factorial(int n){
   if(n==1){
       return 1;
   }
   return n*factorial(n-1);
}
int main(){
     int minu;

    printf("정수를 입력하시오 : ");
     scanf("%d", &minu);
     printf("%d", factorial(minu));
     return 0;
}