#include<iostream>
using namespace std;

class Node
{
	int data;
	Node* left;
	Node* right;
public:
	Node(int data, Node* left, Node* right)
	{
		this->data = data;
		this->left = left;
		this->right = right;
	}
	friend class Tree;
};

class Tree
{
	Node* root;

	void inOrder(Node* next)
	{
		if (next != NULL)
		{
			inOrder(next->left);
			cout << next->data << " ";
			inOrder(next->right);
		}
	}

	void preOrder(Node* next)
	{
		if (next != NULL)
		{
			cout << next->data << " ";
			preOrder(next->left);
			preOrder(next->right);
		}
	}	void postOrder(Node* next)
	{
		if (next != NULL)
		{
			postOrder(next->left);
			postOrder(next->right);
			cout << next->data << " ";
		}
	}

	void destroy(Node* next)
	{
		if (next != NULL)
		{
			destroy(next->left);
			destroy(next->right);
			delete next;
		}
	}
public:
	Tree()
	{
		root = NULL;
	}

	bool isEmpty()
	{
		return (root == NULL);
	}

	void insert(int data)
	{
		Node* temp = new Node(data, NULL, NULL);

		Node* cur = root; //Cur node point to root
		Node* pre = NULL; //There is no predecossor of root

		while (cur != NULL)	//iterate till NULL
		{
			pre = cur; //Take the adress of current node

			if (cur->data > data)  // check that left side data of node if smaller then current node
			{
				cur = cur->left; // triverse to left
			}
			else
			{
				cur = cur->right;	// if data is greater then current node data than triverse current to right
			}
		}

		if (pre == NULL) // check for first insertion at first pre is NULL
		{
			root = temp;
		}
		else if (pre->data > data) // if there are more then 1 nodes in tree check if data is smaller than pre data
		{
			pre->left = temp;	// insert comming node to left side of pre-subtree
		}
		else
		{
			pre->right = temp; //insert comming node to left side of pre-subtree
		}

	}

	bool search(int val)
	{
		Node* cur = root; // only cur is required for search

		while (cur != NULL)
		{
			if (cur->data > val) //check if data is greater then current node data
				cur = cur->left; // triverse current node to left subtree
			else if (cur->data < val) //check if data is smaller then current node data
				cur = cur->right;  // triverse current node to right subtree
			else
				return true;	// return true if value match with any of the node in tree
		}
		return false;
	}

	void inOrder()
	{
		inOrder(root);
	}

	void preOrder()
	{
		preOrder(root);
	}

	void postOrder()
	{
		postOrder(root);
	}

	~Tree()
	{
		destroy(root);
	}

	void deleteNode(int val)
	{
		Node* cur = root;
		Node* pre = NULL;

		if (root == NULL)
		{
			cout << "Tree is empty...." << endl;
			exit(0);
		}
		while (cur != NULL)
		{
			if (cur->data == val)
			{
				break;
			}

			pre = cur;
			if (cur->data > val)
			{
				cur = cur->left;
			}
			else if (cur->data < val)
			{
				cur = cur->right;
			}
			
		}

		if (cur == NULL)
		{
			cout << "The node with value " << val << " not fount" << endl;
			return;
		}

		else if (cur->left == NULL && cur->right == NULL)
		{
			if (pre == NULL)
			{
				root = NULL;
			}
			else if (pre->left == cur)
			{
				pre->left = NULL;
				
			}
			else
			{
				pre->right = NULL;
			}
		
		}

		else if (cur->left != NULL && cur->right != NULL)
		{

			Node* suc = cur;
			Node* preSuc = NULL;
			Node* linkingNode = NULL;

			if (suc->right != NULL)
			{
				suc = suc->right;
			}
			while (suc != NULL)
			{
				linkingNode = preSuc;
				preSuc = suc;
				suc = suc->left;
			}

			cur->data = preSuc->data;

			if (preSuc->left == NULL && preSuc->right == NULL)
			{
					linkingNode->left = NULL;
					delete preSuc;

			}
			else
			{
				if (linkingNode != NULL )
				{
					preSuc->right = linkingNode->left;
					delete preSuc;

				}
				
			}
		}
		
		else
		{
			if (pre == NULL)
			{
				root = NULL;
			}
			else if (pre->left == cur)
			{
				if (cur->left != NULL)
				{
					pre->left = cur->left;
					delete cur;

				}
				else
				{
					pre->left = cur->right;
					delete cur;
				}
			}
			else
			{
				if (cur->right != NULL)
				{
					pre->right = cur->right;
					delete cur;
				}
				else
				{
					pre->right = cur->left;
					delete cur;
				}


			}
		}
		
	}






	


};
int main()
{
	Tree t1;
	t1.insert(5);
	t1.insert(8);
	t1.insert(3);
	t1.insert(7);
	t1.insert(4);
	t1.insert(9);
	t1.insert(6);
	t1.insert(1);
	t1.insert(2);

	t1.deleteNode(5);
	t1.inOrder();

}