//binary search tree(insertion,search,deletion)
#include<iostream>
using namespace std;
struct node 
{
	int data;
	node*left;
	node*right;
 };
 node*createnode(int data)
 {
 	node*newnode=new node();
 	newnode->data=data;
 	newnode->left=0;
 	newnode->right=0;
 	return newnode;
  } 
  //function to insert data in BST
 node*insert(node*root,int data)
 {
 	if(root==0)
 	{
 		return createnode(data);
	 }
	 else if (data<root->data)
	 {
	 	root->left=insert(root->left,data);
	 }
	 else
	 {
	 	root->right=insert(root->right,data);
	 }
	 return root;
  } 
  
// function to search a data in a BST
node* search(node* root, int data) 
{  
    if (root == NULL || root->data == data)
        return root;

    if (root->data < data)
        return search(root->right, data);
        
    return search(root->left, data);
}

 node* getSuccessor(node* curr)
{
    curr = curr->right;
    while (curr != NULL && curr->left != NULL)
        curr = curr->left;
    return curr;
}
//function to delete a data in BST
node* delNode(node* root, int x)
{
    if (root == NULL)
        return root;

    // If key to be searched is in a subtree
    if (root->data > x)
        root->left = delNode(root->left, x);
    else if (root->data < x)
        root->right = delNode(root->right, x);

    // If root matches with the given key
    else {

        // Cases when root has 0 children
        // or only right child
        if (root->left == NULL) {
            node* temp = root->right;
            delete root;
            return temp;
        }

        // When root has only left child
        if (root->right == NULL) {
            node* temp = root->left;
            delete root;
            return temp;
        }

        // When both children are present
        node* succ = getSuccessor(root);
        root->data = succ->data;
        root->right = delNode(root->right, succ->data);
    }
    return root;
}
//function to diplay inorder
void inorder(node* root)
{
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
//function to display the elements
void display(node*root)
{
	if(root!=0)
	{
		display(root->left);
		cout<<root->data<<" ";
		display(root->right);
	}
}
int main()
{
	node*root=0;
	int data,n,value;
	cout<<"Enter how many values you want to insert";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter the value "<<i+1<<" ";
		cin>> value;
		root=insert(root,value);
	}
	cout<<endl;
	cout<<"Ordered traversal is "<<endl;
	display(root);
	cout<<endl;
	while(n!=3)
	{
		cout<<"Enter what you want to do \n"<<"1.Search"<<"2.Delete"<<"3.Display";
		cin>>n;
		switch(n) //applying switch case
		{
			case 1:
				{
					cout<<"Enter the element to be searched"<<endl;
    				cin>>data;
    				(search(root, data) != NULL)? 	cout <<data<< " is Found\n": 
                               							cout <<data<< " is Not Found\n";
                    break;           								
				}
			case 2:
				{
					cout<<"Enter element to be deleted";
					cin>>data;
					root = delNode(root, data);
					cout<<data<<"is deleted"<<endl;
					break;
					
				}
		}
	}
    cout<<"After Deletion node is "<<endl;
    display(root);
    
	return 0;
}
