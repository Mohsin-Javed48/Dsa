#include<iostream>
using namespace std;

void insertion_sort(int arr[], int size)
{
	int key;
	int j = 0;

	for (int i = 1; i < size; i++)
	{
		key = arr[i];
		j = i - 1;
		
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;

	}
}
int main()
{
	int arr[5] = { 5,2,6,4,5};
	insertion_sort(arr, 5);

	for (int i = 0; i < 5; i++)
	{
		cout << arr[i]<<"  ";
	}
}