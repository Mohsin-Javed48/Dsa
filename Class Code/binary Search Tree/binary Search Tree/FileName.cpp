#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
	friend class StudentBST;

private:
	int id;
	string name;
	float fee;
	Student* left;
	Student* right;

public:
	Student(int id, string name, float fee, Student* left, Student* right) {

		this->id = id;
		this->name = name;
		this->fee = fee;
		this->left = left;
		this->right = right;
	}
};


class StudentBST {

private:
	Student* root;

	void inOrder(Student* stree) {
		if (stree != NULL) {
			inOrder(stree->left);
			cout << stree->id << '\t' << stree->name << '\t' << stree->fee << endl;
			inOrder(stree->right);
		}
	}

	void preOrder(Student* stree) {
		if (stree != NULL) {
			cout << stree->id << '\t' << stree->name << '\t' << stree->fee << endl;
			inOrder(stree->left);
			inOrder(stree->right);
		}
	}

	void postOrder(Student* stree) {
		if (stree != NULL) {
			inOrder(stree->left);
			inOrder(stree->right);
			cout << stree->id << '\t' << stree->name << '\t' << stree->fee << endl;
		}
	}

	void destroy(Student* stree) {
		if (stree != NULL) {
			destroy(stree->left);
			destroy(stree->right);
			delete stree;
		}
	}

public:
	StudentBST() {
		root = NULL;
	}

	bool insert(int actNo, string name, float balance) {

		Student* temp = new Student(actNo, name, balance, NULL, NULL);

		Student* cur = root;
		Student* pre = NULL;
		while (cur != NULL) {
			pre = cur;
			if (cur->id == temp->id) {
				cout << "The Student number already exist\n";
				cout << "Student Number = " << cur->id << "\nName = " << cur->name << "\nBalance = " << cur->fee << endl;
				cout << "Not listed!\n\n";
				return false;
			}
			else if (cur->id > temp->id)
				cur = cur->left;
			else
				cur = cur->right;
		}
		if (pre == NULL)
			root = temp;
		else if (pre->id > temp->id)
			pre->left = temp;
		else
			pre->right = temp;
		return true;
	}

	bool search(int id) {
		Student* cur = root;
		Student* pre = NULL;
		while (cur != NULL) {
			pre = cur;
			if (cur->id == id) {
				cout << "Student Number = " << cur->id << "\nName = " << cur->name << "\nBalance = " << cur->fee << endl;
				return true;
			}
			else if (cur->id >id)
				cur = cur->left;
			else
				cur = cur->right;
		}
		cout << "Student number entered Not Found\n";
		return false;
	}

	void inOrder() {
		inOrder(this->root);
	}

	void preOrder() {
		preOrder(root);
	}


	void postOrder() {
		postOrder(root);
	}


	void deleteE(int stdID)
	{
		Student* current = root;
		Student* parent = nullptr;

		while (current && current->id != stdID)
		{
			parent = current;
			if (stdID < current->id) {
				current = current->left;
			}
			else {
				current = current->right;
			}
		}

	
		if (!current) {
			cout << "Student with ID " << stdID << " not found." << endl;
			return;
		}

		
		Student* child;
		if (current->left)
		{
			child = current->left;
		}
		else
		{
			child = current->right;
		}

		
		if (!parent)
		{
			root = child;
		}
		else if (parent->left == current) {
			parent->left = child;
		}
		else {
			parent->right = child;
		}

		
		if (current->right == child) {

			current->right = nullptr;
		}
		else if (current->left == child) {

			current->left = nullptr;
		}

		
		delete current;
	}

	~StudentBST() {
		destroy(root);
	}
};

int main()
{
	StudentBST obj;
	int id;
	float balance;
	string name;
	ifstream input;
	input.open("input.txt");
	while (!input.eof())
	{
		input >> id;
		input >> name;
		input >> balance;
		obj.insert(id, name, balance);
	}
	input.close();

	obj.deleteE(2);

	cout << endl << endl;
	obj.inOrder();
	

	

	return 0;
}