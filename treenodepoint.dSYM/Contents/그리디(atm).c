#include <stdio.h>
int main(){
    int n;
    
    printf("인출할 사람의 수 : ");
    scanf("%d", &n);
    int ti[]={0};
    printf("걸리는 시간은 : ");
    for(int i=0; i<n; i++){
    scanf("%d", ti[i]);
   }
    return 0;
}