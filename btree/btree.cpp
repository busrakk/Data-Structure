#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node BTREE;

BTREE *newNode(int data){
    BTREE *p = (BTREE*)malloc(sizeof(BTREE));
    p -> data = data;
    p -> left = NULL;
    p -> right = NULL;
    return p;
}

BTREE *find(BTREE *root, int k){
    BTREE *temp = root;
    BTREE *findNumber = NULL;

    int count = 0;

    while(temp != NULL){
        if(temp -> right == NULL){
            if(++count == k)
                findNumber = temp; 
            temp = temp -> left;    
        }
        else{
            BTREE *temp2 = temp -> right;

            while(temp2 -> left != NULL && temp2 -> left != temp){
                temp2 = temp2 -> left;
            }
            if(temp2 -> left == NULL){
                temp2 -> left = temp;
                temp = temp -> right;
            }
            else{
                temp2 -> left == NULL;
                if(++count == k)
                    findNumber = temp;
                temp = temp -> left;    
            }
        }
    }
    return findNumber;
}

int main(){
    BTREE *root = newNode(40); 
    root->left = newNode(20); 
    root->right = newNode(70); 
    root->left->left = newNode(10); 
    root->left->right = newNode(30); 
    root->right->left = newNode(60); 
    root->right->right = newNode(100); 

    printf("find %d\n",find(root,2)->data);
}
