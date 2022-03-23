		#include <stdio.h>
		#include <stdlib.h>
		#include <memory.h>

		typedef struct TreeNode {
			char data;
			struct TreeNode *left, *right;
		} TreeNode;
		#define SIZE 100
		int top = -1;
		TreeNode *stack[SIZE];
		void push(TreeNode *p)
		{
			if (top < SIZE - 1)
				stack[++top] = p;
		}
		TreeNode *pop()
		{
			TreeNode *p = NULL;
			if (top >= 0)
				p = stack[top--];
			return p;
		}
		void inorder_iter(TreeNode *root)
		{
			while (1) {
				for (; root; root = root->left)
					push(root);
				root = pop();
				if (!root) break;
				printf("[%c] [%d}", root->data, &root->data);
				root = root->right;
			}
		}
		TreeNode n1 = { 'b',  NULL, NULL };
		TreeNode n2 = { 'a',  NULL, NULL };
		TreeNode n3 = { 'e', NULL, NULL };
		TreeNode n4 = { 'f', NULL, NULL };
		TreeNode n5 = { 'g', NULL, NULL };
		TreeNode n6 = { 'x', &n1, &n2 };
		TreeNode n7 = { 'x', &n6, &n5 };
		TreeNode n8 = { 'x', &n3,  &n4 };
		TreeNode n9 = { '+', &n7,  &n8 };
		TreeNode *root = &n9;
		int main(void)
		{
			printf("중위 순회=");
			inorder_iter(root);
			printf("\n");
			printf("%d", &root);
			return 0;
		}
