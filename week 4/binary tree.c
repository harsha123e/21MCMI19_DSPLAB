//binary tree

#include <stdio.h>  
#include <stdlib.h>  

#define COUNT 10

struct node{  
    int data;  
    struct node *left;  
	struct node *right;  
};  
       
struct node *root= NULL;  
       
struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}
 
struct node* insertLevelOrder(int arr[], struct node* root,int i, int n)
{
    if (i < n)
    {
        struct node* temp = newNode(arr[i]);
        root = temp;
 
        root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n);
 
        root->right = insertLevelOrder(arr,root->right, 2 * i + 2, n);
    }
    return root;
}
 
void preorderTraversal(struct node* node){
    if(root == NULL){  
        printf("Tree is empty\n");  
        return;  
    }  
	else{
	    printf("%d ", node->data); 
	    if(node->left!= NULL)
			preorderTraversal(node->left);	 
	    if(node->right!= NULL)
			preorderTraversal(node->right);
	}
}

	       
void inorderTraversal(struct node *node) {              
    if(root == NULL){  
        printf("Tree is empty\n");  
        return;  
    }  
    else {              
        if(node->left!= NULL)  
            inorderTraversal(node->left);  
        printf("%d ", node->data);  
        if(node->right!= NULL)  
            inorderTraversal(node->right);      
    }        
}  

void postorderTraversal(struct node* node){
    if(root == NULL){  
        printf("Tree is empty\n");  
        return;  
    }
	else{
	    if(node->left!= NULL)  
            postorderTraversal(node->left);  
	    if(node->right!= NULL)  
            postorderTraversal(node->right);      
	    printf("%d ", node->data);
	}
}
 
void print2DUtil(struct node *node, int space){
    
    int i;
	
	if (node == NULL)
        return;
        
    space += COUNT;
 
    print2DUtil(node->right, space);
 
    printf("\n");
    for (i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", node->data);
 
    print2DUtil(node->left, space);
}
 
void print2D(struct node *node){
	
   print2DUtil(node, 0);
}

int maxDepth(struct node* node){
    if (node == NULL)
        return 0;
    else {
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);
 
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
} 
            
int main(){  
        
	int choice = -1,data[10],n,i;
	
	while(choice!=0){
		printf("\n\n");
		printf("Press 1 to insert data into binary tree:\n");
		printf("Press 2 to display inorder traversal:\n");
		printf("Press 3 to display preorder traversal:\n");
		printf("Press 4 to display postorder traversal:\n");
		printf("Press 5 to display height of tree:\n");
		printf("Press 6 to display in tree format:\n");
		printf("Press 0 to exit\n");
		printf("Enter your choice\n");
		scanf("%d",&choice);
	
		if(choice==1){
			printf("Enter number of elements : ");
			scanf("%d",&n);
			
			printf("Enter data to be entered: ");
			for(i=0;i<n;i++)
				scanf("%d",&data[i]);
				
			root = insertLevelOrder(data, root, 0, n);				
		}
		if(choice==2){
	        printf("Inorder Traversal: \n");  
			inorderTraversal(root);  
		}
		if(choice==3){
	        printf("Preorder Traversal: \n");  
			preorderTraversal(root);  
		}
		if(choice==4){
	        printf("Postorder Traversal: \n");  
			postorderTraversal(root);  
		}
		if(choice==5)
			printf("Height of tree is : %d \n", maxDepth(root));
		if(choice==6){
			printf("Binary tree in Tree Format: \n");
			print2D(root);
		}    
	}
        return 0;  
}  
