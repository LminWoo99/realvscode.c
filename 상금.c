#include <stdio.h>

int main(){
    int n,temp,temp1,min=0;
    scanf("%d", &n);
    int a[n],b[n];
    

    for(int i=0; i<n; i++){
    scanf("%d", &a[i]);
}
    for(int i=0; i<n; i++){
    scanf("%d", &b[i]);
  }


  for(int x=0; x<n; x++){
    for(int j=x+1; j<n; j++){
  if(a[x]>a[j]){
    temp=a[x];
     a[x]=a[j];
     a[j]=temp;
     }
  }
  }
  for(int x=0; x<n; x++){
    for(int j=x+1; j<n; j++){
  if(b[x]<b[j]){
    temp1=b[x];
     b[x]=b[j];
     b[j]=temp1;
     }
  }
  }
  for(int num=0; num<n; num++){
    min+=(a[num]*b[num]);
  }
  printf("%d",min);
  return 0;
}