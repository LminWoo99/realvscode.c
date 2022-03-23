#include <stdio.h>
#include <stdlib.h>
#define MAX(a,b)(a)

typedef struct AVLNode {
	struct AVLNode *left;
                 int key;
	struct AVLNode *right;
} AVLNode;

// 트리의 높이를 반환
int get_height(AVLNode *node) {
	int height = 0;
	if (node != NULL)
		height = 1 + MAX(get_height(node->left),
			get_height(node->right));
	return height;
}
// 노드의 균형인수를 반환
int get_balance(AVLNode* node) {
	if (node == NULL) return 0;

	return get_height(node->left)
		- get_height(node->right);
}
AVLNode* create_node(int key) {              //노드 생성
	AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	return(node);
}
// 오른쪽으로 회전시키는 함수
AVLNode *rotate_right(AVLNode *parent) {         
	AVLNode* child = parent->left;
	parent->left = child->right;
	child->right = parent;
                
	return child;
}
// 왼쪽으로 회전시키는 함수
AVLNode *rotate_left(AVLNode *parent) {
                 printf("(before)rotate_left () [ %d ] \n", parent->key);
	AVLNode *child = parent->right;
	parent->right = child->left;
	child->left = parent;
                 printf("(after )rotate_left () [ %d ] \n", child->key);
	return child;
}
AVLNode* insert(AVLNode* node, int key) {
	// 이진 탐색 트리의 노드 추가 수행
	printf("insert(%d, %d) 실행\n", node, key);
	if (node == NULL)
	                return(create_node(key));
	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else	// 동일한 키는 허용되지 않음
		return node;
	// 노드들의 균형인수 재계산
	int balance = get_balance(node);
                 printf("balance(%d) = %d\n", node->key, balance);
	// LL 타입 처리
	if (balance > 1 && key < node->left->key)
		return rotate_right(node);
	// RR 타입 처리
	if (balance < -1 && key > node->right->key)
		return rotate_left(node);
	// LR 타입 처리
	if (balance > 1 && key > node->left->key) {
		printf("LR 회전 %d \n", node->key);
		node->left = rotate_left(node->left);
		return rotate_right(node);	
	// RL 타입 처리
	if (balance < -1 && key < node->right->key) {
		printf("RL 회전 %d \n", node->key);
		node->right = rotate_right(node->right);
		return rotate_left(node);
	}
	return node;
}
}
int main(void)
{
	AVLNode *root = NULL;
	// 예제 트리 구축
	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 30);
	root = insert(root, 15);
	root = insert(root, 13);
	root = insert(root, 5);
	root = insert(root, 8);
	printf("전위 순회 결과 \n");
	preorder(root);
	return 0;
}
