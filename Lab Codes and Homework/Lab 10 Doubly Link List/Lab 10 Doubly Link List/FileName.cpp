#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Book
{
	int id;
	string title;
	float price;
	Book* next;
	Book* pre;
public:
	Book(int id, string title, float price, Book* next, Book * pre)
	{
		this->id = id;
		this->title = title;
		this->price = price;
		this->next = next;
		this->pre = pre;
	}
	void bookDetails()
	{
		cout << "Id: " << id << endl << "Title: " << title << endl<<"Price: "<<price<<endl;
	}
	friend class BookList;
};

class BookList
{
	Book* head;
	Book* cursor;
	Book* last;
public:
	BookList()
	{
		head = cursor = last = NULL;

	}
	void insert(const Book& newItem)
	{
		Book* temp = new Book(newItem.id,newItem.title,newItem.price,NULL,NULL);

		if (head== NULL)
		{
			head = temp;
			cursor = temp;
			last = temp;
		}
		else
		{
			cursor->next = temp;
			temp->pre = cursor;
			cursor = cursor->next;
			last = cursor;

		}
	}

	void showStructureForward() const
	{
		Book* cur = head;
		while (cur != NULL)
		{
			cur->bookDetails();
			cur = cur->next;
		}
	}
	void showStructureReverse() const
	{
		Book* cur = last;
		while (cur != NULL)
		{
			cur->bookDetails();
			cur = cur->pre;
		}

	}

	void remove()
	{
		if(head == NULL)
		{
			cout<<"list is empty "<<endl;
			return;

		}
		else
		{
			if (cursor->next == NULL)
			{
				Book* temp = cursor;
				cursor->pre->next = NULL;
				cursor = head;
				cursor->next = head->next;
				delete temp;

			}
			else
			{
				Book* temp = cursor;
				cursor = cursor->next;
				cursor->pre = temp->pre;
				delete temp;
			}
		}
	}
	void search(string title)
	{
		bool check = false;
		Book* cur = head;
		while ( cur!= NULL)
		{
			if (cur->title == title)
			{
				check = true;
				cur->bookDetails();
				
			}
			cur = cur->next;
		}
		if (!check)
		{
			cout << "node did not found" << endl;
		}
		
	}
	void replace(const Book& newItem)
	{

		Book* temp = new Book(newItem.id, newItem.title, newItem.price, NULL, NULL);
		cursor->id = temp->id;
		cursor->title = temp->title;
		cursor->price = temp->price;
	}
	bool isEmpty()
	{
		return (head == NULL);
		
	}
	void gotoBeginning()
	{
		cursor = head;

	}
	void gotoEnd()
	{
		cursor = last;
	}
	bool gotoNext()
	{
		if (cursor != last)
		{
			cursor = cursor->next;
			return true;
		}
		return false;
	}
	Book getCursor()
	{
		if (cursor!=NULL)
		{
			return *cursor;

		}
	}
	bool gotoPrior()
	{
		if (cursor!= head)
		{
			cursor = cursor->pre;
			return true;
		}
		return false;
	}

	~BookList()
	{
		Book* cur = head;
		Book* post = head->next;
		while (cur!=NULL)
		{
			delete cur;
			cur = post;
			post = post->next;
			
		}

	}
};
int main()
{
	//Book b1(1, "mohsin",1.334f,NULL,NULL);
	//Book b2(2, "ali",1.334f,NULL,NULL);
	//Book b3(3, "haon",1.334f,NULL,NULL);
	//Book b4(4, "afeef",1.334f,NULL,NULL);
	BookList bk1;

	ifstream inf("input.txt");
	if (!inf)
	{
		cout << "file not open" << endl;
		exit(0);
	}
	int id;
	string title;
	float price;
	while (!inf.eof())
	{
		inf >> id;
		inf.ignore();
		getline( inf,title);
		inf >> price;
		inf.ignore();

		Book b(id, title, price, NULL, NULL);
		bk1.insert(b);
	}
	bk1.showStructureForward();
	inf.close();
	return 0;
}