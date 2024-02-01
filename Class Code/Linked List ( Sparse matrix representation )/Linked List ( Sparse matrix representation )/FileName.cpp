#include<iostream>
using namespace std;

class Node
{
	int row;
	int col;
	int val;
	Node* Next;
public:
	Node(int row, int col, int val, Node* Next)
	{
		this->row = row;
		this->col = col;
		this->val = val;
		this->Next = Next;
	}
	friend class Sparse_LinkedList;
};

class Sparse_LinkedList
{
	Node* head;
public:
	Sparse_LinkedList()
	{
		head = NULL;

	}
	void insert(int row, int col,int val, int** arr)
	{
		Node* temp = new Node(row, col, val, NULL);	

		if (head == NULL)
		{
			int count = 0;
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					if (arr[i][j] != 0)
						count++;
				}
			}
			Node* meta = new Node(row, col, count, NULL);
			head = meta;
			head->Next = temp;
		}
		else
		{
			head->val = val++;
			Node* cur = head;
			while (cur->Next != NULL)
			{
				cur = cur->Next;
			}
			cur->Next = temp;
		}
	}

	Node* getHead()
	{
		return head;
	}
	void display()
	{
		if (head == NULL)
		{
			cout << "List is empty!!!!!!!!" << endl;
		}
		else
		{
			Node* cur = head->Next;
			do
			{
				cout << cur->val<<"  ";
				cur = cur->Next;
			} while (cur!=NULL);
		}
	}

	void addLinkedList(Sparse_LinkedList L)
	{
		
		if (head->row == L.getHead()->row && head->col == L.getHead()->col)
		{
			int row3 = head->row;
			int col3 = head->col;
			int count = 0;

			int** arr3 = new int* [row3];

			for (int i = 0; i < row3; ++i)
			{
				arr3[i] = new int[col3];
			}
			for (int i = 0; i < row3; ++i) {
				for (int j = 0; j < col3; ++j) {
					arr3[i][j] = 0;
				}
			}

			Sparse_LinkedList S3;

			
			Node* ptr = L.getHead();
			S3.insert(head->row, head->col, count, arr3);
			ptr = ptr->Next;

			Node* cur = head;
			


			while ( cur != NULL && ptr !=NULL)
			{
			
				if (count == 0)
				{
					cur = cur->Next;
				}
				else if (cur == NULL)
				{
					while (ptr!=NULL)
					{

						S3.insert(ptr->row, ptr->col, ptr->val, arr3);	
						ptr = ptr->Next;

					}
					break;

				}
				else if (ptr == NULL)
				{
					while (cur != NULL)
					{
						S3.insert(cur->row, cur->col, cur->val, arr3);
						cur = cur->Next;

					}
					break;
				}
				else
				{
					if (cur->row == ptr->row && cur->col == ptr->col  )
					{
						S3.insert(cur->row, cur->col, ptr->val+ cur->val, arr3);
						cur = cur->Next;
						ptr = ptr->Next;
						count++;
					}
					else 
					{
						if (cur->row > ptr->row || cur->col > ptr->col)
						{
							S3.insert(ptr->row, ptr->col, ptr->val, arr3);
							ptr = ptr->Next;
							count++;
						}
						else
						{
							S3.insert(cur->row, cur->col, cur->val, arr3 );
							cur = cur->Next;
							count++;

						}
					}
				}
			}
			S3.getHead()->val = count;
			S3.display();
			
			
		delete[] arr3;
		}
		else
		{
			cout << "Boht lists has different dimensions.........." << endl;
		}
	}

	~Sparse_LinkedList()
	{
		Node* cur = head;
		while (cur != nullptr)
		{
			Node* nextNode = cur->Next;  // Preserve the reference to the next node
			delete cur;  // Delete the current node
			cur = nextNode;  // Move to the next node
		}
		head = nullptr;  // Reset head to indicate the list is empty
	}

};
int main()
{
	int row = 4;
	int col = 6;

	// Allocate memory for a 2D array
	int** arr = new int* [row];
	for (int i = 0; i < row; ++i) {
		arr[i] = new int[col];
	}

	// Initialize the array
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			arr[i][j] = 0;
		}
	}

	//Array 2
	int row2 = 4;
	int col2 = 6;

	int** arr2 = new int* [row2];
	for (int i = 0; i < row2; i++)
	{
		arr2[i] = new int[col2];
	}

	for (int i = 0; i < row2; ++i)
	{
		for (int j = 0; j < col2; ++j)
		{
			arr2[i][j] = 0;
		}
	}



	Sparse_LinkedList S;
	Sparse_LinkedList S2;

	S.insert(0, 0, 1,arr);
	S.insert(1, 2, 3,arr);
	S.insert(3, 2, 9,arr);
	S2.insert(1, 2, 5,arr2);
	S2.insert(3, 4, 7,arr2);

	S.display();
	cout << endl;
	S2.display();
	S.addLinkedList(S2);


	delete[] arr;
	delete[] arr2;

}