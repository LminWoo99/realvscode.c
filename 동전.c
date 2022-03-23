#include <stdio.h>
#include <string.h>
#define MAX_ARRAY_SIZE 100
int main(){
    int n,k,result;  //n이 동전 개수의 종류, k가 돈 값
    int a[MAX_ARRAY_SIZE];
    printf(""); //동전의 개수와 돈 얼만지
    scanf("%d %d", &n, &k);
    
    for(int i=0; i<n; i++){
        printf("");
        scanf("%d", &a[i]);
    }
    int cnt=0;
    for(int j=n-1; j>=0; j--){
        while(1){
        if(a[j]<=k){ 
             k -= a[j]; //k가 계속 a[j]로 뺴서 a[j]보다 작아질떄까지 반복
          cnt++;          

          }
        else{
         break;

        }
        }
       

    }
printf("%d", cnt);
return 0;
}