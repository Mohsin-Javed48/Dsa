#include<iostream>
using namespace std;

class Node
{
	int data;
	Node* next;
public:
	Node( int data, Node* next)
	{
		this->data = data;
		this->next = next;
	}

	friend class linkList;

};

class linkList
{
	Node* head;
public:
	linkList()
	{
		head = NULL;
	}
	bool isEmpty() {
		if (head == NULL)
			return true;
	}
	void insertAtEnd(int data)
	{
		Node* temp = new Node(data, NULL);
		if (head == NULL)
		{
			head = temp;
		}
		else {
			Node* cur = head;

			while (cur->next != NULL)
			{
				cur = cur->next;
			}
			cur-> next= temp;
		}
	}

	void display()
	{
		Node* cur = head;
		while (cur != NULL)
		{
			cout << cur->data << " ";
			cur = cur->next;
		}
		cout << endl;
	}

	void insertAtStart(int data) {
		head = new Node(data, head);
		/*if (head->next != NULL)
		{
			head->next = temp;
		}*/

	}

	void deleteLast()
	{
		if (head == NULL)
		{
			cout << "List is empty,cannot delete" << endl;
		}
		else if(head->next == NULL)
		{
			delete head;
			head = NULL;
		}
		else
		{
			Node* pre = head;
			Node* cur = pre->next;
			while (cur->next != NULL)
			{
				pre = cur;
				cur = cur->next;
			}
			pre->next = NULL;
			delete cur;
		}
	}

	void deleteStart()
	{
		if (head == NULL)
		{
			cout << "List is empty........" << endl;

		}
		else if (head->next == NULL)
		{
			delete head;
			head = NULL;
		}
		else
		{
			Node* cur = head;
			if (cur->next != NULL)
			{
				head = cur->next;
				delete cur;
			}
			else
			{
				delete head;
				head = NULL;
			}
			

		}
	}
	~linkList()
	{
		Node* cur = head;

		while (cur != NULL)
		{
			head = head-> next;
			delete cur;
			cur = head;
		}
	}



	//complete its implementation. Give appropriate error message item does not exist.
	/** removes an item of the linked list. */
	void removeItem(int item)
	{
		bool check = false;
		Node* cur = head;
		Node* pre = cur;
		Node* post = cur;

		if (head->next !=NULL && head->data == item )
		{
			cur = cur->next;
			delete head;
			head = cur;
		}
		else 
		{
			while (cur != NULL && cur->data != item)
			{

				pre = cur;
				cur = cur->next;
				if (cur!=NULL)
				{
				post = cur->next;
				}

			}
			if (cur->data == item)
			{
				pre->next = post;
				delete cur;
				check = true;
			} 

			
		}
		if (!check)
		{
			cout << "item did not find...." << endl;
		}

	}



	//complete its implementation. if oldItem does not exist, give appropriate error message and do nothing
	/** inserts a newItem before the oldItem */
	void insertBefore(int oldItem, int newItem)
	{
		bool check = false;
		Node* temp = new Node(newItem, NULL);
		Node* cur = head;
		Node* pre = cur;

		while (cur->data != oldItem )
		{
			pre = cur;
			cur = cur->next;
		}
		if (cur->data == oldItem)
		{
			pre->next = temp;
			temp->next = cur;
			check = true;
		}
		if (!check)
		{
			cout << "item did not find...." << endl;
		}

	}

	//complete its implementation. if oldItem does not exist, give appropriate error message and do nothing
	/** inserts a newItem after the oldItem. */
	void insertAfter(int oldItem, int newItem)
	{
		bool check = false;
		Node* temp = new Node(newItem, NULL);
		Node* cur = head;
		Node* post = cur->next;

		while (cur->data != oldItem)
		{
			cur = cur->next;
			post = cur->next;;
		}
		if (cur->data == oldItem)
		{
			cur->next = temp;
			temp->next = post;
			check = true;
		}
		if (!check)
		{
			cout << "item did not find...." << endl;
		}

	}

};
int main() {
	linkList l;
	l.insertAtStart(5);
	l.insertAtStart(6);
	l.insertAtStart(7);
	l.insertAtStart(8);
	l.insertAtStart(9);
	l.display();
	l.removeItem(5);
	l.display();

}