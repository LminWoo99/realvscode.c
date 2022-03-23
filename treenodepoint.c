#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
typedef struct TreeNode{
    struct TreeNode *left;
    int data;
    struct TreeNode *right;
}TreeNode;

int main(){
    char minuLeft='/';
    char minuRight='/';
    TreeNode *root, *n1,*n2,*n3;
    n1=(TreeNode*)malloc(sizeof(TreeNode));
    n2=(TreeNode*)malloc(sizeof(TreeNode));
    n3=(TreeNode*)malloc(sizeof(TreeNode));
    root=n1;
    n1->data=10;
    n1->left=n2;
    n1->right=n3;
    n2->data=20;
    n2->left=NULL;
    n2->right=NULL;
    n3->data=30;
    n3->left=NULL;
    n3->right=NULL;
    printf("n1의 주소:%d, 값: %d, n2 주소:%d, 값: %d, n3 주소:%d, 값:%d\n", &n1, n1, &n2, n2, &n3, n3);
    printf("%5d\n", n1->data);
    printf("%4c %c\n", minuLeft,minuRight);
    printf("%d %5d\n", n2->data, n3->data);
    free(n1);
    free(n2);
    free(n3);
    return 0;
}
