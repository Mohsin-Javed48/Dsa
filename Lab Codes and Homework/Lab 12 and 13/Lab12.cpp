#include "iostream"

using namespace std;

class Student
{
	friend class StudentMaxHeap;

private:
	double cgpa;
	int rollNo;
};

class StudentMaxHeap
{
private:
	Student* arr;
	int curSize;
	int maxSize;


public:
	StudentMaxHeap(int size)
	{
		maxSize = size;
		arr = new Student[size];
		curSize = 0;
	}

	~StudentMaxHeap()
	{
		curSize = maxSize = 0;
		delete arr;
	}
	
	void heapify(int i)
	{
		int li = 2 * i + 1;
		int ri = 2 * i + 2;
		int max = i;

		if (li < curSize && arr[li].cgpa > arr[max].cgpa)
			max = li;


		if (ri < curSize && arr[ri].cgpa > arr[max].cgpa)
			max = ri;

		if (max != i) {
			swap(arr[max].cgpa, arr[i].cgpa);
			heapify(max);
		}
	}

	bool isEmpty()
	{
		return curSize == 0;
	}

	bool isFull()
	{
		return curSize == maxSize;
	}

	bool insert(int rollNo, double cgpa)
	{
		if (!this->isFull())
		{
			arr[curSize].rollNo = rollNo;
			arr[curSize].cgpa = cgpa;
			heapify(curSize);
			++curSize;
			return true;
		}
		else if (this->isFull())
		{
			cout << "Array Full" << endl;
			return false;
		}
		else
		{
			cout << "Insertion Failed" << endl;
			return false;
		}
	}

	bool remove(int& rollNo, double& cgpa)
	{
		rollNo = arr[0].rollNo;
		cgpa = arr[0].cgpa;

		arr[0] = arr[--curSize];

		heapify(0);

		return rollNo, cgpa;
	}

	void displayStudentList()
	{
		for (int i = curSize-1; i >= 0; i--)
			cout << arr[i].rollNo << " " << arr[i].cgpa << endl;

		cout << endl;
	}

	void levelOrder()
	{
		for (int i = 0; i < curSize; ++i)
			cout << arr[i].rollNo << " " << arr[i].cgpa << endl;

		cout << endl;
	}

	void menu()
	{
		int c;

		cout << "1. Insert new student" << endl;
		cout << "2. Remove (and display) the student with Max CGPA" << endl;
		cout << "3. Display the list of students (Descending order of CGPA)" << endl;
		cout << "4. Display the list of students (Level order traversal)" << endl;
		cout << "5. Exit" << endl << endl;
		cout << "Enter your choice: ";

		cin >> c;

		if (c == 1)
		{
			int roll;
			double cgpa;
			
			cout << "Enter Roll Number: ";
			cin >> roll;
			cout << "Enter CGPA: ";
			cin >> cgpa;

			insert(roll, cgpa);
		}
		else if (c == 2)
		{
			int roll;
			double cgpa;
			remove(roll, cgpa);
			cout << roll << "\t" << cgpa << endl;
		}
		else if (c == 3)
		{
			displayStudentList();
		}
		else if (c == 4)
		{
			levelOrder();
		}
		else
		{
			cout << "--- Exiting ---" << endl;
			exit(0);
		}

	}

};

int main()
{
	StudentMaxHeap h(5);
	
	h.insert(1, 3.78);
	h.insert(2, 2.78);
	h.insert(3, 3.56);
	h.insert(4, 3.01);

	h.menu();

	return 0;
}