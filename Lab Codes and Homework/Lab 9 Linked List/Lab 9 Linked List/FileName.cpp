#include <iostream>
#include <fstream>
#include"string"

using namespace std;

class Student {
    friend class StudentList;

private:
    int id;
    string name;
    float cgpa;
    Student* next;

public:
    Student(int id, string name, float cgpa, Student* next)
    {
        this->id = id;
        this->name = name;
        this->cgpa = cgpa;
        this->next = next;
    }

    void studentDetails() const
    {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "CGPA: " << cgpa << endl;
        cout << endl;
    }
};

class StudentList
{
private:
    Student* head;
    Student* cursor;

public:

    StudentList()      
    {
        head = NULL;
        cursor = NULL;
    }

    ~StudentList()     
    {
        Student* temp;
        while (head != NULL)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insert( Student& newStd)
    {
        if (head == NULL)            
        {
            head = new Student(newStd.id, newStd.name, newStd.cgpa, NULL);
            cursor = head;
        }
        else
        {
            Student* newNode = new Student(newStd.id, newStd.name, newStd.cgpa, cursor->next);
            cursor->next = newNode;
            cursor = newNode;
        }
    }

    void remove(int id)
    {
        Student* prev = NULL;
        Student* curr = head;

        while (curr != NULL && curr->id != id)
        {
            prev = curr;
            curr = curr->next;
        }

        if (curr != NULL)                    
        {
            if (curr == cursor)             
            {
                if (curr == head)               
                {
                    head = cursor->next;
                }
                else                           
                {
                    prev->next = cursor->next;
                }
                cursor = prev;              
            }
            else                         
            {
                prev->next = curr->next;
            }
            delete curr;
        }
        else                                      
        {
            cout << "Student with ID " << id << " not found in the list." << endl;
        }
    }

    void search(float cgpa) const
    {
        bool check = false;
        Student* cur = head;

        while (cur != NULL)
        {
            if (cur->cgpa == cgpa)
            {
                check = true;
                cur->studentDetails();
                cout << endl;
            }
            cur = cur->next; 
        }

        if (!check)
        {
            cout << "No student found with CGPA " << cgpa << "." << endl;
        }
    }

    void replace(const Student& newStd)
    {
        Student* curr = head;
        bool check = false;

        while (curr != NULL)
        {
            if (curr->id == newStd.id)
            {
                check = true;
                curr->name = newStd.name;
                curr->cgpa = newStd.cgpa;
                cursor = curr;
                break;
            }
            curr = curr->next;
        }


    }

    bool isEmpty() const
    {
        return head == NULL;
    }

    void gotoBeginning()
    {
        cursor = head;
    }

    void gotoEnd()
    {
        cursor = NULL;
        Student* curr = head;

        while (curr != NULL)
        {
            curr = curr->next;
        }
    }

    bool gotoNext()
    {
        if (cursor != NULL)
        {
            cursor = cursor->next;
            return true;
        }
        else {
            return false;
        }
    }

    bool gotoPrior()
    {
        if (cursor == head)
        {
            return false;       
        }

        Student* prev = head;
        Student* curr = head->next;

        while (curr != cursor)
        {
            prev = curr;
            curr = curr->next;
        }

        cursor = prev;
        return true;
    }
    Student getCursor() const
    {
        if (cursor == NULL)
        {
            cout << "Cursor not pointing to a valid student";
        }

        Student currentStudent = * cursor;
        return currentStudent;
    }

    void showstructure()
    {
        if (head == NULL)
        {
            cout << "Empty list" << endl;
        }
        else
        {
            Student* cur = head;
            while (cur != NULL)
            {
                cur->studentDetails();
                cout << endl;
            }
        }
    }

};

int main()
{
    StudentList studentList;
    ifstream inputFile("input.txt");

    if (!inputFile.is_open())
    {
        cout << "Error: Unable to open input file." << endl;
        return 1;
    }

    while (!inputFile.eof())
    {
        int id;
        string name;
        float cgpa;

        inputFile >> id;
        inputFile.ignore();
        getline(inputFile, name);
        inputFile >> cgpa;
        inputFile.ignore();

        Student newStudent(id, name, cgpa, NULL);
        studentList.insert(newStudent);
        newStudent.studentDetails();
    }

    

    studentList.showstructure();

    studentList.remove(1);

    studentList.showstructure();
     
}