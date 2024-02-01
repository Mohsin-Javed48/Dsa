#include<iostream>
using namespace std;

class Node
{
	int data;
	Node* next;
public:
	Node(int data, Node* next)
	{
		this->data = data;
		this->next = next;
	}
	friend class CircularLinkedList;
};
class CircularLinkedList
{
	Node* head;
public:
	CircularLinkedList()
	{
		head = NULL;
	}
	~CircularLinkedList()
	{
		Node* cur = head;
		Node* last = head;
		Node* newNode = head;
		while (last->next != head)
		{
			last = last->next;
		}
		do
		{
			newNode = cur->next;
			delete cur;
			cur = newNode;

		} while (cur != head);

		head = NULL;
	}
	bool isEmpty()
	{
		if (head == NULL)
			return true;
		else
			return false;
	}
	void insertAtLast(int data)
	{
		Node* temp = new Node(data, NULL);
		if (head == NULL)
		{
			head = temp;
			head->next = head;
		}
		else
		{
			Node* cur = head;
			while (cur->next!=NULL)
			{
				cur = cur->next;
			}
			cur ->next = temp;
			temp->next = head;
		}
	}
	void insertAtStart(int data)
	{
		Node* temp = new Node(data, NULL);
		if (head ==NULL)
		{
			head = temp;
			head->next = head;
		}
		else
		{
			Node* cur = head;
			while (cur->next != head)
			{
				cur = cur->next;
			}
			temp->next = head;
			head = temp;
			cur->next = head;
		}

	}
	void deleteFirst()
	{
		if (head ==NULL)
		{
			cout << "List is empty......" << endl;
		}
		else if (head->next == head)
		{
			head = NULL;
			delete head;

		}
		else
		{
			Node* pre = head;
			Node* cur = head->next;
			head = cur;
			while (cur->next != NULL)
			{
				cur = cur->next;
			}
			cur->next = head;
			delete pre;
		}
	}
	void display()
	{
		Node* cur = head;
		if (head==NULL)
		{
			cout << "list is empty....." << endl;
		}
		else
		{
			do
			{
				cout << cur->data <<" ";
				cur = cur->next;

			} while (cur != head);
		}
	}
	


	//complete its implementation. if oldItem does not exist, give appropriate error message and do nothing
	/** inserts a newItem before the oldItem */
	void insertBefore(int oldItem, int newItem)
	{
		Node* temp = new Node(newItem, NULL);
		Node* cur = head;
		Node* pre = head;


		if (head->data == oldItem)
		{
			while (cur->next != head)
			{
				cur = cur->next;
			}

			temp->next = head;
			head = temp;
			cur->next = head;
		}
		else
		{
			cur = cur->next;
			while (cur->next!=head && cur->data!=oldItem)
			{
				cur = cur->next;
				pre = pre->next;
			}
			if (cur->data == oldItem)
			{
				pre->next = temp;
				temp->next = cur;

			}

		}
	}

	//complete its implementation. if oldItem does not exist, give appropriate error message and do nothing
	/** inserts a newItem after the oldItem. */
	void insertAfter(int oldItem, int newItem)
	{
		Node* temp = new Node(newItem, NULL);
		Node* cur = head;
		Node* post = cur->next;


		if (head->data == oldItem)
		{
			while (cur->next != head)
			{
				cur = cur->next;
			}

			head->next = temp;
			temp->next = post;
		}
		else
		{
			while (cur->next != head && cur->data != oldItem)
			{
				cur = cur->next;
				if (post->next != head)
					post = post->next;
			}
			if (cur == post)
			{
				cur -> next = temp;
				temp->next = head;
			}
			else if(cur->data == oldItem)
			{
				cur->next = temp;
				temp->next = post;
			}

		}

	}

	//complete its implementation. Give appropriate error message item does not exist.
	/** removes an item of the linked list. */
	void removeItem(int item)
	{
		Node* cur = head;
		Node* pre = NULL;
		Node* post = NULL;

		if (head != NULL)
		{
			post = head->next;

			if (head->data == item)
			{
				if (head->next == head)
				{
					// Only one node in the list
					delete head;
					head = NULL;
				}
				else
				{
					// Move to the last node to update the 'next' pointer
					while (cur->next != head)
					{
						cur = cur->next;
					}

					cur->next = head->next;
					delete head;
					head = cur->next; // Update head to the new first node
				}
			}
			else
			{
				// Find the node with the desired data value
				while (cur->data != item && cur->next != head)
				{
					pre = cur;
					cur = cur->next;
					post = post->next;
				}

				if (cur->data == item)
				{
					pre->next = post;
					delete cur;
				}
				// else: Node with 'item' not found
			}
		}


	}
};
int main()
{
	CircularLinkedList cl;
	cl.insertAtStart(1);
	cl.insertAtStart(2);
	cl.insertAtStart(3);
	//cl.insertBefore(2,7);
	//cl.insertAfter(2,7);
	cl.removeItem(3);
	cl.display();

}
