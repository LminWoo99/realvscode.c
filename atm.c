#include <stdio.h>
#include <stdlib.h>
int atm(int *p, int n){
    int temp;
    int result1=0;
    int sum1=0 ,sum2=0;
  
   for(int i=0; i<n; i++){
       for(int j=i+1; j<n; j++){
           if(p[j]<p[i]){
               temp=p[j];
               p[j]=p[i];
               p[i]=temp;
           }
       }
       }
       for(int num=0; num<n; num++){
           sum1+=p[num];
           sum2+=sum1;
       }
   return sum2;
}
int main(){
    int n;
    int result=0;
    
    printf("");  //몇명
    scanf("%d", &n);
    int ti[n];
    printf(""); // 인출 시간
    for(int i=0; i<n; i++){
    scanf("%d", &ti[i]);
    
}
 printf("%d\n",atm(ti,n));
 return 0;    
    

}

