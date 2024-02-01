
#include<iostream>
using namespace std;

template <class T>
class Queue
{
private:
	//data members
	T* data; //array of items to be allocated dynamically as per MAX_SIZE
	int front; //front index
	int rear; //rear index
	int MAX_SIZE; //maximum capacity of queue

public:
	//constructor
	Queue(const int MAX_SIZE = 5)
	{
		this-> MAX_SIZE = MAX_SIZE;
		data = new T[MAX_SIZE];
		front = -1;
		rear = -1;

	}
	//destructor
	~Queue()
	{
		delete[] data;
	}
	//queue manipulation operations
	void enQueue(const T newItem)
	{
		if ((rear + 1) % MAX_SIZE == front)
		{
			cout << "Queue is full and value cannot be inserted" << endl;
		}
		else {
			if (front == -1)
				front = 0;

			rear = (rear + 1) % MAX_SIZE;
			data[rear] = newItem;
		}
	}

	//add an element to the rear of queue
	void deQueue()
	{
		if (front == -1)
		{
			cout << "Queue is empty and value cannot be removed" << endl;
		}
		else {
			if (front == rear)
				front = rear = -1;
			else
			front = (front + 1) % MAX_SIZE;

		}
	}//delete element at the front of queue
	void clear()
	{
		front = rear = -1;
	}	//clear the queue
	//queue accessors
	T getFront() const
	{
		if (front != -1)
		{
			return data[front];
		}
	}//return element at the front
	T getRear() const
	{
		if (rear != -1)
		{
			return data[rear];
		}
	}//return element at the rear
	//queue status operations
	bool isEmpty() const
	{
		if (front == -1)
		{
			cout << "Array is empty" << endl;
			return true;
		}
		else
			return false;
	}//is queue empty?
	bool isFull() const
	{
		if ((rear+1) % MAX_SIZE == front )
		{
			cout << "Array is full" << endl;
			return true;
		}
	}//is queue full?
	//outputs the data in queue. If the queue is empty, outputs “Empty Queue”.
	void showStructure() const
	{
		if (isEmpty())
			return;
		else {
			cout << "Front-->";
			for (int i = front; i <= rear; i++)
			{
				if (i == front)
					cout << " " << data[i];
				else
					cout << "\t " << data[i];

				if (i == rear)
					cout << " <--Rear";
				cout << endl;

			}
			cout << endl << endl;
		}
	}
};
int main() {
	Queue <int> q1;
	q1.enQueue(1);
	q1.enQueue(2);
	q1.enQueue(3);
	q1.deQueue();
	q1.enQueue(5);
	q1.showStructure();

}
