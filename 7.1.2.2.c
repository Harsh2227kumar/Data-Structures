#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *left, *right;
};
  
typedef struct node *BSTNODE;

BSTNODE newNodeInBST(int item) {
	BSTNODE temp =  (BSTNODE)malloc(sizeof(struct node));
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}
  
void inorderInBST(BSTNODE root) {
	//write your code here..
	if(root == NULL){
		return;
	}
	else{
		inorderInBST(root->left);
		printf("%d ", root->data);
		inorderInBST(root->right);
	}
	
}
void preorderInBST(BSTNODE root) {
	//write your code here..
	if(root == NULL)
		return;
	else{
		printf("%d ", root->data);
		preorderInBST(root->left);
		preorderInBST(root->right);
	}
}
void postorderInBST(BSTNODE root){
	//write your code here..
	if(root == NULL)
		return;
	else{
		postorderInBST(root->left);
		postorderInBST(root->right);
		printf("%d ", root->data);
	}
	
}


// void postorderInBST(BSTNODE root) {
    BSTNODE insertNodeInBST(BSTNODE node, int ele){

        if(node == NULL){
            printf("Successfully inserted.\n");
            return newNodeInBST(ele);
        }
        if(ele<node->data)
            node->left=insertNodeInBST(node->left,ele);
        else if(ele>node->data)	
            node->right=insertNodeInBST(node->right,ele);
        else
            return node;
        return node;
        
        
    }
    // BSTNODE insertNodeInBST(BSTNODE node, int ele) {
        //write your code here..
        
        
    // }
    
    BSTNODE searchNodeInBST(BSTNODE root, int ele) {
        //write your code here..
        if(root==NULL || root->data==ele){
            return root;
        }
        if(ele<root->data){
            return searchNodeInBST(root->left, ele);
        }
        else{
            return searchNodeInBST(root->right, ele);
        }
        
    }