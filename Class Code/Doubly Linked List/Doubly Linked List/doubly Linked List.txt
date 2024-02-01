#include<iostream>
using namespace std;

class Node
{
	int data;
	Node* pre;
	Node* next;
public:
	Node(int data, Node* pre, Node* next)
	{
		this->data = data;
		this->pre = pre;
		this->next = next;
	}
	friend class doublyLinkedList;
};
class doublyLinkedList
{
	Node* head;
public:
	doublyLinkedList()
	{
		head = NULL;
	}
	~doublyLinkedList()
	{
		Node* cur = head;
		while (cur!=NULL)
		{
			head = head->next;
			delete cur;
			cur = head;
		}
		head = NULL:
	}
	void insertAtEnd(int item)
	{
		Node* temp = new Node(item, NULL, NULL);
		Node* cur = head;
		if (head == NULL)
		{
			head = temp;
		}
		else 
		{
			while (cur->next != NULL)
				cur = cur->next;
			cur->next = temp;
			temp->pre = cur;
		}
	}
	void insertAtStart(int item)
	{
		Node* temp = new Node(item, NULL, NULL);
		Node* cur = head;
		if (head == NULL)
			head = temp;
		else
		{
			temp->next = head;
			head->pre = temp;
			head = temp;
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
	}

};
int main()
{
	doublyLinkedList dl;
	dl.insertAtEnd(1);
	dl.insertAtEnd(2);
	dl.insertAtEnd(3);
	dl.insertAtStart(4);
	dl.display();
}