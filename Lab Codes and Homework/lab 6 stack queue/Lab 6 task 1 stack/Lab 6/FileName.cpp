#include<iostream>
using namespace std;

template <class T>
class Stack
{
private:
	//Data members
	T* data; //array of items to be allocated dynamically as per MAX_SIZE
	int top; //top of the stack
	int MAX_SIZE; //maximum capacity of the stack
public:
	//constructor
	Stack(const int MAX_SIZE = 5) {
		this->MAX_SIZE = MAX_SIZE;
		data = new T[MAX_SIZE];
		top = -1;

	}
	//destructor
	~Stack()
	{
		delete[] data;
	}
	//stack manipulation operations
	void push(const T newItem)
	{
		if (top == MAX_SIZE -1)
		{
			cout << "Stack overflow........." << endl;
		}
		else {
			data[++top] = newItem;
		}
	}//push a new item
	void pop()
	{
		if (top == -1)
		{
			cout << "Stack underflow........" << endl;
		}
		else {
			top--;
		}
	}
		//pop an item
	void clear()
	{
		top = -1;
	}//clear the stack
	//stack accessor
	T getTop() const
	{
		if (top != -1)
		{
			return data[top];
		}
		else {
			cout << "stack is empty" << endl;
		}
	}
	 //return item at the top
	//stack status operations
	bool isEmpty() const
	{
		if (top == -1) {
			cout << "Stack is empty" << endl;
			return true;
		}
		else
			return false;
	}
	
		
	
	//is stack empty?
	bool isFull() const
	{
		if (top == MAX_SIZE - 1) {
			cout << "Stack is full" << endl;
			return true;
		}
	}//is stack full?
	//outputs the data in stack. If the stack is empty, outputs “Empty Stack”.
	void showStructure() const
	{
		if (!isEmpty())
		{
			cout << "Top-->";
			for (int i = top; i != -1; i--)
				cout <<"\t"<< data[i] << endl;
		}
		cout << "......................................" << endl;
	}
};

int main() {
	Stack <int> s1(4);
	s1.push(3);
	s1.push(2);
	s1.push(3);
	s1.push(5);

	s1.showStructure();

	Stack <string> s2(20);
	s2.push("mohsin");
	s2.push("fakhra");
	s2.push("amna");
	s2.pop();
	s2.pop();
	s2.showStructure();

	Stack <float> s3(3);
	s3.push(1.1);
	s3.push(1.2);
	
	cout <<"The value at the top is "<< s3.getTop()<<endl;
	s3.isFull();
}


