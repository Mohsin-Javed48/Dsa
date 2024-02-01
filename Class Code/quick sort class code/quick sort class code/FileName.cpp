//https://www.youtube.com/channel/UCJEPLDddB_FZv2ATOTs6gRA
//#ub

/*
//Quick Sort
#include<iostream>

using namespace std;


int partition(int A[], int left, int right)
{
	int p = left;	//Choosing first element as pivot

	//Partition based on p (pivot)
	while (left < right)
	{
		while (A[p] >= A[left] && left < right)
			left++;

		while (A[p] < A[right])
			right--;

		if (left < right)
		{
			swap(A[left], A[right]);
		}
	}

	swap(A[right], A[p]);
	//Partitioning end

	return right;
}

//Quick Sort
void quickSort(int A[], int left, int right)
{
	if (left < right)
	{
		//pi is Partition Index
		int pi = partition(A, left, right);

		//Recursive calls 
		quickSort(A, left, pi - 1);		//for left array having smaller values from pivot
		quickSort(A, pi + 1, right);	//for right array having greater values from pivot
	}
}

int main()
{
	int A[] = { 7,5,4,6,8,2 };
	int n = sizeof(A) / sizeof(A[0]);

	cout << "List:\t\t";
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << "\t";
	}

	cout << endl;

	quickSort(A, 0, n - 1);

	cout << "Sorted List:\t";
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << "\t";
	}

	cout << endl << endl;

	return 0;
}
*/
#include<iostream>
using namespace std;

int partition(int A[], int left, int right)
{
	int p = left;
	

	while (left<right)
	{
		while (A[p] <= A[left] )
		{
			left++;
		}
		while (A[p] > A[right])
		{
			right--;
		}
		if (left < right)
		{
			swap(A[left], A[right]);
		}

	}

		swap(A[right], A[p]);

		return right;
}

void quickSort(int A[],int left,int right)
{
	if(left<right)
	{
		int pi = partition(A, left, right);

		quickSort(A, left, pi - 1);
		quickSort(A, pi+1, right);

	}

}


int main()
{
	int arr[9] = { 5,3,1,2,9,4,8,6,7};
	int n = sizeof(arr) / sizeof(int);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';

	}
	cout << endl;

	quickSort(arr,0,n-1);

	for (int i = 0; i < 9; i++)
	{
		cout << arr[i] << ' ';

	}


}