#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

//주어진 트리에 대하여 전위 중위 후위로 링크,배열

//링크를 이용한 순회

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;

TreeNode n1 = {4,NULL,NULL};
TreeNode n2 = {5,NULL,NULL};
TreeNode n3 = {3,&n1,&n2 };
TreeNode n4 = {6,NULL,NULL };
TreeNode n5 = {2,&n3,&n4 };
TreeNode n6 = {8,NULL,NULL };
TreeNode n7 = {10,NULL,NULL };
TreeNode n8 = {11,NULL,NULL };
TreeNode n9 = {9,&n7,&n8 };
TreeNode n10 = {7,&n6,&n9 };
TreeNode n11 = {1,&n5,&n10 };
TreeNode* root = &n11;

// 전위 순회 함수
void preorder(TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);

    }
}
//중위 순회
void inorder(TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
//후위 순회
void postorder(TreeNode* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
        
    }
}

// 배열을 이용한 순회

int resultArray[11]; 

int currentIndex = 0; 

// 전위 순회 함수 (배열 이용)
void preorderToArray(TreeNode* node) {
    if (node != NULL) {
        resultArray[currentIndex++] = node->data; 
        preorderToArray(node->left);
        preorderToArray(node->right);
    }
}

// 중위 순회 함수
void inorderToArray(TreeNode* node) {
    if (node != NULL) {
        inorderToArray(node->left);
        resultArray[currentIndex++] = node->data; 
        inorderToArray(node->right);
    }
}

// 후위 순회 함수
void postorderToArray(TreeNode* node) {
    if (node != NULL) {
        postorderToArray(node->left);
        postorderToArray(node->right);
        resultArray[currentIndex++] = node->data; 
    }
}

int main(void) {

    printf("<Link Tree>\n\n"); //link tree 출력
    printf("1.전위 순회= ");
    preorder(root);
    printf("\n");
    printf("2.중위 순회= ");
    inorder(root);
    printf("\n");
    printf("3.후위 순회= ");
    postorder(root);
    printf("\n");

    printf("\n");

    printf("<Array Tree>\n\n"); //array tree 출력
    currentIndex = 0; 
    preorderToArray(root);
    printf("1.전위 순회= " );
    for (int i = 0; i < currentIndex; i++) {
        printf("%d ", resultArray[i]);
    }
    printf("\n");
    printf("2.중위 순회= ");
    currentIndex = 0; 
    inorderToArray(root);

    for (int i = 0; i < currentIndex; i++) {
        printf("%d ", resultArray[i]);
    }
    printf("\n");

    printf("3.후위 순회= ");
    currentIndex = 0; 
    postorderToArray(root);

    for (int i = 0; i < currentIndex; i++) {
        printf("%d ", resultArray[i]);
    }

    printf("\n");

    return 0;



}