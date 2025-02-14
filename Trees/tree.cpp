#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct n {
    int data;
    struct n *left;
    struct n *right;
};

typedef struct n node;

node *ekle(node *agac, int x) {
    if (agac == NULL) {
        node *root = (node *)malloc(sizeof(node));
        root->left = NULL;
        root->right = NULL;
        root->data = x;
        return root;
    }

    if (x < agac->data) {
        agac->left = ekle(agac->left, x);
    } else if (x > agac->data) {
        agac->right = ekle(agac->right, x);
    }

    return agac;
}
int getHeight(node* root) {
    if (root == NULL) return 0;
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

void printLevel(node* root, int level, int space, int gap) {
    if (root == NULL) {
        for (int i = 0; i < space + gap; i++) printf(" ");
        return;
    }
    if (level == 1) {
        for (int i = 0; i < space; i++) printf(" ");
        printf("%d", root->data);
        for (int i = 0; i < gap; i++) printf(" ");
    } else if (level > 1) {
        printLevel(root->left, level - 1, space, gap);
        printLevel(root->right, level - 1, space, gap);
    }
}

void printTree(node* root) {
    int height = getHeight(root);
    int maxWidth = pow(2, height) - 1;
    int space = maxWidth * 2;        

    for (int i = 1; i <= height; i++) {
        int gap = space / pow(2, i); 
        printLevel(root, i, gap / 2, gap);
        printf("\n");

        if (i < height) {
            for (int j = 0; j < gap / 2 - 1; j++) printf(" ");
            for (int k = 0; k < pow(2, i - 1); k++) {
                printf("/");
                for (int j = 0; j < gap - 1; j++) printf(" ");
                printf("\\");
                for (int j = 0; j < gap - 1; j++) printf(" ");
            }
            printf("\n");
        }
    }
}

int max(node* agac){
	while(agac->right != NULL){
		agac = agac->right;
	}
	return agac->data;
}

int min(node* agac){
	while(agac->left != NULL){
		agac = agac->left;
	}
	return agac->data;
}

node* find(node* root, int key) {
    if (root == NULL) 
        return NULL;
    if (root->data == key) 
        return root;

    if (key < root->data) 
        return find(root->left, key);
    else 
        return find(root->right, key);
}


node* sil(node* agac, int target) {
    if (agac == NULL) {
        return NULL; 
    }

    if (target < agac->data) {

        agac->left = sil(agac->left, target);
    } else if (target > agac->data) {

        agac->right = sil(agac->right, target);
    } else {

        if (agac->left == NULL && agac->right == NULL) {
            free(agac); 
            return NULL;
        }

        if (agac->left == NULL) {
            node* temp = agac->right;
            free(agac);
            return temp;
        } else if (agac->right == NULL) {
            node* temp = agac->left;
            free(agac);
            return temp;
        }

        int minValue = min(agac->right); 
        agac->data = minValue;         
        agac->right = sil(agac->right, minValue); 
    }

    return agac; 
}

void preorder(node *root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(node *root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(node *root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    node *root = NULL;  
    root = ekle(root, 8);
	ekle(root, 7);
	ekle(root, 2);
	ekle(root, 9);
	ekle(root, 5);
	
    printf("Preorder -> ");
    preorder(root);
    printf("\n");

    printf("Inorder -> ");
    inorder(root);
    printf("\n");

    printf("Postorder -> ");
    postorder(root);
    printf("\n");
    
    printTree(root);

    return 0;
}

