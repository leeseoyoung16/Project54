#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

//주어진 트리에 대하여 전위 중위 후위로 링크,배열 (01과제)
//스택과 링크 표현법을 이용한 전위,중위, 후위순회(02과제)

#define SIZE 100

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;


//stack을 이용한 순회

int top = -1;
TreeNode* stack[SIZE];


void push(TreeNode* item) {
    if (top < SIZE - 1) {
        stack[++(top)] = item;
    }
}

TreeNode* pop() {
    TreeNode* item = NULL;
    if (top >= 0) {
        item = stack[top--];
    }
    return item;
}


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

//링크를 이용한 순회
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
// 스택을 사용한 전위 순회 함수
void stackPreorder(TreeNode* root) {
    if (root == NULL) return;

    push(root);

    while (top >= 0) {
        TreeNode* current = pop();
        printf("%d ", current->data);

        if (current->right != NULL) {
            push(current->right);
        }

        if (current->left != NULL) {
            push(current->left);
        }
    }
}

// 스택을 사용한 중위 순회 함수
void stackInorder(TreeNode* root) {
    if (root == NULL) return;

    TreeNode* current = root;

    while (current != NULL || top >= 0) {
        while (current != NULL) {
            push(current);
            current = current->left;
        }

        current = pop();
        printf("%d ", current->data);
        current = current->right;
    }
}

// 스택을 사용한 후위 순회 함수
void stackPostorder(TreeNode* root) {
    if (root == NULL) return;

    TreeNode* current = root;
    TreeNode* lastVisited = NULL;

    while (current != NULL || top >= 0) {
        while (current != NULL) {
            push(current);
            current = current->left;
        }

        current = stack[top];

        if (current->right == NULL || current->right == lastVisited) {
            printf("%d ", current->data);
            pop();
            lastVisited = current;
            current = NULL;
        }
        else {
            current = current->right;
        }
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

    printf("\n<Traversal with Stack>\n\n"); //Traversal with Stack 출력
    printf("1.전위 순회= ");
    stackPreorder(root);
    printf("\n");
    printf("2.중위 순회= ");
    stackInorder(root);
    printf("\n");
    printf("3.후위 순회= ");
    stackPostorder(root);
    printf("\n");


    return 0;



}