#include<stdio.h>
#include<stdlib.h>

struct node 
{
	struct node *left;
	struct node *right;
	int data;
};

struct node *new_node(int x)
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = x;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

struct node *search(struct node *root , int x)
{
	if(root == NULL || root->data == x)
	return root;

	else if(x > root->data)
	return search(root->right , x);

	else
	return search(root->left,x);
}

struct node *insert(struct node *root , int x)
{
	if(root == NULL)
	return new_node(x);

	else if(x > root->data)
	root->right = insert(root->right,x);

	else
	root->left = insert(root->left,x);

	return root;
}


struct node *find_min(struct node *root)
{
	if (root == NULL)
    return NULL;
  else if (root -> left != NULL) // node with minimum value will have no left child
    return find_min(root -> left); // left most element will be minimum
  return root;
}

struct node *delete_node(struct node *root, int x)
{
	if(root == NULL)
	return NULL;

	else if(x > root->data)
	root->right = delete_node(root->right,x);

	else if(x < root->data)
	root->left =delete_node(root->left,x);

	else
	{
		if(root->right == NULL && root->left == NULL)
		{
			free(root);
			return NULL;
		}

		else if(root->right == NULL || root->left == NULL)
		{
			struct node *temp;
			if(root->right == NULL)
			temp = root->left;

			else 
			temp = root->right;

			free(root);
			return temp;
		}
		else {
      struct node *temp = find_min(root -> right);
      root -> data = temp -> data;
      root -> right = delete_node(root -> right, temp -> data);
    }
	}
	return root;
}

void *preorder(struct node *root)
{
	if(root!=NULL)
	{
		printf(" %d ", root ->data);
		preorder(root -> left);
		preorder(root -> right);
	}
}

void *inorder(struct node *root)
{
	if(root!=NULL)
	{
		inorder(root -> left);
		printf(" %d ", root ->data);
		inorder(root -> right);
	}
}

void *postorder(struct node *root)
{
	if(root!=NULL)
	{
		postorder(root -> left);
		postorder(root -> right);
		printf(" %d ", root ->data);
	}
}
