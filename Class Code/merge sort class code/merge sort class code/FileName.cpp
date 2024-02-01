//https://www.youtube.com/channel/UCJEPLDddB_FZv2ATOTs6gRA
//#ub


//Merge Sort
#include<iostream>

using namespace std;

//Merge
void merge(int A[], int left, int mid, int right)
{
	int n1 = mid - left + 1;	//size of left sub array
	int n2 = right - mid;		//size of right sub array

	
	int* L = new int[n1];
	int* R = new int[n2];


	for (int i = 0; i < n1; i++)
		L[i] = A[left + i];

	for (int i = 0; i < n2; i++)
		R[i] = A[mid + 1 + i];

	
	int i = 0, j = 0, k = left; // Initial index of merged subarray

	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			A[k] = L[i];
			i++;
		}
		else
		{
			A[k] = R[j];
			j++;
		}
		k++;
	}

	
	while (i < n1)
	{
		A[k] = L[i];
		i++;
		k++;
	}


	while (j < n2)
	{
		A[k] = R[j];
		j++;
		k++;
	}

	// Free temporary arrays
	delete[]L;
	delete[]R;
}

//Merge Sort
void mergeSort(int A[], int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;

		// Sort first and second halves
		mergeSort(A, left, mid);		//left half
		mergeSort(A, mid + 1, right);	//right half

		merge(A, left, mid, right);		//merge the elements
	}
}

int main()
{
	int A[] = { 6, 7, 5, 3, 9,};
	int n = sizeof(A) / sizeof(A[0]);

	mergeSort(A, 0, n - 1);

	//display the array content 
	for (size_t i = 0; i < n; i++)
	{
		cout << A[i] << endl;
	}

	return 0;
}




// For descending sorting
/*
#include<iostream>
using namespace std;

void merge(int A[], int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;

	int* L = new int[n1];
	int* R = new int[n2];

	for (int i = 0; i < n1; i++)
	{
		L[i] = A[left + i];
	}

	for (int i = 0; i < n2; i++)
	{
		R[i] = A[mid + i + 1];
	}

	int i = 0, j = 0, k = left;

		while (i < n1 && j < n2)
		{
			if (L[i] >= R[j])
			{
				A[k] = L[i];
				i++;
			}
			else
			{
				A[k] = R[i];
				j++;
			}
				k++;
		}

		while (i < n1)
		{
			A[k] = L[i];
			i++;
			k++;
		}

		while (j < n2)
		{
			A[k] = R[j];
			j++;
			k++;
		}

	
		delete [] L;
		delete [] R;

}

void mergeSort(int A[], int left, int right)
{
	if(left < right)
	{
		int mid = left + (right - left) / 2;

		mergeSort(A, left, mid);
		mergeSort(A, mid+1, right);

		merge(A, left, mid, right);

	}
}

int main()
{
	int arr[5] = { 3,4,8,9,1 };
	mergeSort(arr, 0, 4);

	for (int i = 0; i < 5; i++)
	{
		cout << arr[i]<<' ';

	}

	return 0;
}
*/