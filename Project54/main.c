#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

//�־��� Ʈ���� ���Ͽ� ���� ���� ������ ��ũ,�迭 (01����)
//���ð� ��ũ ǥ������ �̿��� ����,����, ������ȸ(02����)

#define SIZE 100

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;


//stack�� �̿��� ��ȸ

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

//��ũ�� �̿��� ��ȸ
// ���� ��ȸ �Լ�
void preorder(TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left); 
        preorder(root->right); 

    }
}
//���� ��ȸ
void inorder(TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data); 
        inorder(root->right); 
    }
}
//���� ��ȸ
void postorder(TreeNode* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right); 
        printf("%d ", root->data); 
        
    }
}

// �迭�� �̿��� ��ȸ

int resultArray[11]; 

int currentIndex = 0; 

// ���� ��ȸ �Լ� (�迭 �̿�)
void preorderToArray(TreeNode* node) {
    if (node != NULL) {
        resultArray[currentIndex++] = node->data; 
        preorderToArray(node->left);
        preorderToArray(node->right);
    }
}

// ���� ��ȸ �Լ�
void inorderToArray(TreeNode* node) {
    if (node != NULL) {
        inorderToArray(node->left);
        resultArray[currentIndex++] = node->data; 
        inorderToArray(node->right);
    }
}

// ���� ��ȸ �Լ�
void postorderToArray(TreeNode* node) {
    if (node != NULL) {
        postorderToArray(node->left);
        postorderToArray(node->right);
        resultArray[currentIndex++] = node->data; 
    }
}
// ������ ����� ���� ��ȸ �Լ�
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

// ������ ����� ���� ��ȸ �Լ�
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

// ������ ����� ���� ��ȸ �Լ�
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

    printf("<Link Tree>\n\n"); //link tree ���
    printf("1.���� ��ȸ= ");
    preorder(root);
    printf("\n");
    printf("2.���� ��ȸ= ");
    inorder(root);
    printf("\n");
    printf("3.���� ��ȸ= ");
    postorder(root);
    printf("\n");

    printf("\n");

    printf("<Array Tree>\n\n"); //array tree ���
    currentIndex = 0; 
    preorderToArray(root);
    printf("1.���� ��ȸ= " );
    for (int i = 0; i < currentIndex; i++) {
        printf("%d ", resultArray[i]);
    }
    printf("\n");
    printf("2.���� ��ȸ= ");
    currentIndex = 0; 
    inorderToArray(root);

    for (int i = 0; i < currentIndex; i++) {
        printf("%d ", resultArray[i]);
    }
    printf("\n");

    printf("3.���� ��ȸ= ");
    currentIndex = 0; 
    postorderToArray(root);

    for (int i = 0; i < currentIndex; i++) {
        printf("%d ", resultArray[i]);
    }

    printf("\n");

    printf("\n<Traversal with Stack>\n\n"); //Traversal with Stack ���
    printf("1.���� ��ȸ= ");
    stackPreorder(root);
    printf("\n");
    printf("2.���� ��ȸ= ");
    stackInorder(root);
    printf("\n");
    printf("3.���� ��ȸ= ");
    stackPostorder(root);
    printf("\n");


    return 0;



}