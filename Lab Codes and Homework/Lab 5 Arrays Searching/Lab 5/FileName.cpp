#include<iostream>
#include<algorithm>
#include<fstream>
#include<string>
#include<conio.h>

using namespace std;

int intersection1(int A[], int B[], int C[], int n) {
	
	int count= 0;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (A[i] == B[j]) {
				C[count] = A[i];
				
				count++;
			}
		}
		
	}
	return count;
	
}
int intersection2(int A[], int B[], int C[], int n) {
	int high = 0;
	int low = 0;
	int mid = 0;
	int common = 0;
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		low = 0;
		high = n-1;
	
	while (low <= high) {

		mid = low + ((high - low) / 2);
		if (A[mid] == B[i])
		{	
			k++;
			common++;
			break;
		}
		else if (A[mid] < B[i]) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
			
		}
	}

	}
	return common;

	

}

int findKthSmallest(int A[], int n, int k) {
	int j = 0;
	for (int i = 0; i < n-1; i++)
	{
		j = i + 1;
		while (j > 0 && A[j] < A[j - 1])
		{
			swap(A[j], A[j - 1]);
			j--;
		}
	
	}
	for (int i = 0; i < n; i++)
	{
		cout << A[i]<<" ";

	}
	cout << "Smallest value at position " << k << " is";
	return A[k-1];
}


int length(char s[])
{
	int i = 0;
	for (i; s[i] != 0; i++);
	return i;
}

int search(char a[], char word[])
{
	int k = 0;
	int common = 0;

	for (int i = 0; a[i] != 0; i++)
	{
		if (a[i] == word[k])
		{
			k++;
			if (k == length(word))
			{
				common++;
				k = 0;
			}
		}
		else k = 0;
	}
	return common;
}

int main() {
	int M[5] = { 1,2,4,3,5 };
	int A[5] = { 1,2,3,4,5 };
	int B[5] = { 6,7,8,3,2 };
	int C[5];
	//cout << intersection2(A, B, C, 5);

	cout<<findKthSmallest(M, 5, 2);
	
	/*fstream file("input3.txt", ios::in);

	char word[20];

	char s[300];

	file.getline(word, 20);
	int i = 1;
	cout << "Word searched : " << word << endl << endl;
	while (true)
	{
		file.getline(s, 200);

		if (file.eof()) break;

		cout << "line " << i << " : ";

		cout << search(s, word) << endl << endl;
		i++;
	}*/
	return 0;
}