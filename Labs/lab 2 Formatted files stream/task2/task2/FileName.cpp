#include<iostream>

#include<fstream>

#include <string>

using namespace std;

class Student
{
	int id;
	float marks;

	friend istream& operator >> (istream&, Student&);

	friend ostream& operator << (ostream&, const Student&);

public:

	Student(int id = 0, float marks = 0.0f)
	{
		this->id = id;
		this->marks = marks;
	}

	void addStudent(ofstream* ptr) {

		ptr->write(reinterpret_cast<char*>(this), sizeof(Student));
	}

	static void displayAllStudents(ifstream* ptr) {

		Student temp;

		ptr->read(reinterpret_cast<char*>(&temp), sizeof(temp));

		while (!ptr->eof())
		{
			cout << temp;
			ptr->read(reinterpret_cast<char*>(&temp), sizeof(temp));
		}
	}

	bool findStudent(ifstream* ptr) {

		Student temp;

		ptr->read(reinterpret_cast<char*>(&temp), sizeof(temp));

		while (!ptr->eof()) {


			if (this->id == temp.id && this->marks == temp.marks) {
				return true;
			}

			ptr->read(reinterpret_cast<char*>(&temp), sizeof(temp));
		}
		return false;
	}

	void deleteStudent(ifstream* ptr) {
		Student tempstd;

		ofstream temp("temp.dat", ios::binary);

		if (!temp) {
			cout << "File not Found";
			exit(0);
		}

		while (!ptr->eof()) {

			ptr->read(reinterpret_cast<char*>(&tempstd), sizeof(temp));
			if (tempstd.id == this->id && tempstd.marks == this->marks) {
				continue;
			}
			temp.write(reinterpret_cast<char*>(&tempstd), sizeof(temp));
		}
		temp.close();
		ptr->close();
		remove("test.dat");
		rename("temp.dat", "test.dat");
	}
	friend ostream& operator << (ostream& cout, Student& std) {
		cout << "ID: " << std.id << "\t" << "Marks: " << std.marks << endl;
		return cout;
	}
	friend istream& operator >> (istream& cin, Student& std) {

		cout << "Enter id : ";
		cin >> std.id;
		cout << "Enter marks : ";
		cin >> std.marks;

		return cin;
	}

};



//ostream &operator << (ostream &cout, Student &std){
//	cout << "ID: " << std.id << "\t" << "Marks: " << std.marks << endl;
	//return cout;
//}

int main()
{
	Student obj1(1, 70), obj2(2, 75), obj3(3, 65);

	ofstream outf("test.dat", ios::binary | ios::out);

	if (!outf) {
		cout << "File not found";
		exit(0);
	}

	obj1.addStudent(&outf);
	obj2.addStudent(&outf);
	obj3.addStudent(&outf);

	outf.close();
}