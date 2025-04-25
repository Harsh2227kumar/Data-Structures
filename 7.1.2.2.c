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

