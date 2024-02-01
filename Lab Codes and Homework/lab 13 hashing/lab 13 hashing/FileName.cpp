#include "iostream"
#include "string"

using namespace std;

class HashTable
{
private:
	string* table;
	int size;
	int curSize;

public:
	HashTable(int size)
	{
		this->size = size;
		table = new string[size];
		curSize = 0;

		for (int i = 0; i < size; i++)
		{
			table[i] = "EMPTY";
		}
	}

	~HashTable()
	{
		delete table;
		size = curSize = 0;
	}

	float loadFactor()
	{
		int loadFactor = curSize / size;
		return loadFactor;

	}

	int hash(string name)
	{
		return value(name) % size;
	}

	int value(string name)
	{
		int val = 0;
		for (int i = 0; i < name.length(); i++)
		{
			val = val + name[i];
		}
		return val;
	}

	bool insert(string name)
	{
		if (curSize != size)
		{
			int s = hash(name);
			for (int i = 0; i < size; i++)
			{
				if (table[s] == "EMPTY")
				{
					table[s] = name;
					curSize++;
					return true;
				}
				else
				{
					s = (s + 1) % size;
				}
			}
			cout << "Can't insert the element" << endl;
			return false;
		}
		else
		{
			cout << "Error! Table is already full" << endl;
			return false;
		}
	}

	bool search(string name)
	{
		if (curSize != 0)
		{
			int s = hash(name);
			for (int i = 0; i < size; i++) //try with size
			{
				if (table[s] == name)
				{
					cout << "Found" << endl;
					return true;
				}
				else
				{
					s = (s + 1) % size;
				}
			}
			cout << "Not Found" << endl;
			return false;
		}
		cout << "Empty Table" << endl;
		return false;
	}

	bool remove(string name)
	{
		if (curSize != 0)
		{
			int s = hash(name);
			for (int i = 0; i < size; i++)
			{
				if (table[s] == name)
				{
					cout << "Removed" << endl;
					curSize--;
					table[s] = "EMPTY";
					return true;
				}
				else
				{
					s = (s + 1) % size;
				}
			}
			cout << "Not Found" << endl;
			return false;
		}
		cout << "Empty Table" << endl;
		return false;
	}

	void display()
	{
		for (int i = 0; i < size; i++)
		{
			cout << table[i] << endl;
		}
	}

	void menu()
	{
		while (1)
		{
			cout << "1. Insert a Name" << endl;
			cout << "2. Search for a Name" << endl;
			cout << "3. Remove a Name" << endl;
			cout << "4. Display the Table" << endl;
			cout << "5. Display the load factor of the table" << endl;
			cout << "6. Exit" << endl;

			int c;
			cout << "Enter your choice: ";
			cin >> c;

			if (c == 1)
			{
				string name;
				cout << "Enter a name: ";
				cin >> name;
				insert(name);
			}
			else if (c == 2)
			{
				string name;
				cout << "Enter a name to search: ";
				cin >> name;
				search(name);
			}
			else if (c == 3)
			{
				string name;
				cout << "Enter a name you want to remove: ";
				cin >> name;
				remove(name);
			}
			else if (c == 4)
			{
				cout << "Displaying the Table" << endl << endl;
				display();
			}
			else if (c == 5)
			{
				cout << "Load Factor = " << loadFactor() << endl;
			}
			else if (c == 6)
			{
				cout << "Exiting" << endl;
				exit(0);
			}
			else
			{
				cout << "Invalid Input... Terminating" << endl;
				exit(1);
			}
		}

	}

};

int main()
{
	int s = 0;
	cout << "Enter the size of hash table: ";
	cin >> s;
	HashTable h(s);

	h.menu();

	return 0;
}