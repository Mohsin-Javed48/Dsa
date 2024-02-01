#include<iostream>
#include<fstream>
using namespace std;

void arrayToFile(string nameOfFile, int *array, int size) {
	ofstream outf(nameOfFile, ios::binary | ios::out);
	if (!outf) {
		cout << "FIle does not open"<<endl;
	}
	else {

		outf.write(reinterpret_cast<char*> (array), sizeof(int)*size);
		outf.close();
	}
}

void fileToArray(string nameOfFile, int array[], int size) {
	ifstream inf(nameOfFile, ios::binary | ios::in);
	
	if (!inf) {
		cout << "File does not open" << endl;
	}
	else {
		
			inf.read(reinterpret_cast<char*> (array), sizeof(int) * size);

		
		inf.close();
	}



}
int main()
{
	int array[10] = { 1,2,3,4,5,6,7,8,9,0 };
	int array2[10];
	arrayToFile("test.dat", array, 10);
	fileToArray("test.dat",array2, 10);
	for (int i = 0; i < 10; i++)
	{

	cout << array2[i];
	}



}