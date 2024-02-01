
#include<iostream>
#include<fstream>
using namespace std;
 

class Student
{
	int id;
	float marks;
	friend istream& operator >> (istream&, Student&);
	friend ostream& operator << (ofstream&, Student&);
	
public:
	Student(int id = 0, float marks = 0.0f) {
		this->id = id;
		this->marks = marks;
	}
	void addStudent(ofstream* ptr) {

		ptr->write(reinterpret_cast<char*>(this), sizeof(Student));
	}
	static void displayAllStudents(ifstream* ptr)
	{
		Student temp;
		ptr->read(reinterpret_cast<char*>(&temp), sizeof(temp));
		while (!ptr->eof())
		{
			cout << temp;
			ptr->read(reinterpret_cast<char*>(&temp), sizeof(temp));
		}
	}

	bool findStudent(ifstream* ptr) 
	{
		Student temp;

		ptr->read(reinterpret_cast<char*>(&temp), sizeof(Student));
		while (!ptr->eof())
		{
			if (this->id == temp.id && this->marks == temp.marks)
			{
				return true;
			}
		}
		

		
			return false;

	}
	bool deleteStudent(ifstream* ptr) 
	{
		Student tempStd;

		ptr->read(reinterpret_cast<char*>(&tempStd), sizeof(Student));

		ofstream tem("temp.dat", ios::binary);

		if (!tem) {
			cout << "FIle not found";
			exit(0);
		}

			ptr->read(reinterpret_cast<char*>(&tempStd), sizeof(tem));
		while (!ptr->eof())
		{
			if (tempStd.id == this->id && tempStd.marks == this->marks) {
				continue;
			}
			tem.write(reinterpret_cast<char*>(&tempStd), sizeof(tem));
		}
			tem.close();
			ptr->close();
			remove("temp.dat");
			rename("temp.dat", "test.dat");

	}
	
};

 istream& operator >> (istream& cin, Student& std) {
	cout << "Enter id";
	cin >> std.id;
	cout << "Enter marks";
	cin >> std.marks;
	return cin;
}
 ostream& operator << (ofstream& cout, Student& std) {
	cout << "Id is " << std.id << " Marks are" << std.marks << endl;
	return cout;
}

int main() {
	Student s1(1, 40), s2(2, 45), s3(3, 50);
	
	ofstream outf("test.dat", ios::binary);

	if (!outf) {
		cout << "error while creating the file";
		exit(0);
	}
	s1.addStudent(&outf);
	s2.addStudent(&outf);
	s3.addStudent(&outf);

	outf.close();

	ifstream inf("test.dat", ios::binary);
	
	if (!inf)
	{
		cout << "Error while opening the file";
		exit(0);
	}
	if (s1.findStudent(&inf) == 1) {
		cout << "Ture";
	}
	else {
		cout << "false";
	}

	Student::displayAllStudents(&inf);
	inf.close();
}


