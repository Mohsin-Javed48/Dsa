#include<iostream>
using namespace std;

class Heap
{
	int curSize = 0;
	int* arr;
public:
	Heap(int curSize)
	{
		arr = new int[curSize]; //Initialize new array with size (curSize)
	}

	void inset_max_heap(int val)
	{
		arr[curSize] = val; //insert value in the current size of array
		
		int new_pos = curSize; // now aur pointer names new_pos will track the current element

		curSize++; // The newSize will increment for new element next time

		while ((new_pos != 0) && (arr[new_pos] > arr[(new_pos - 1) / 2])) // Loop until new position pointer not reach to root node and until child is greater then parent
		{
			swap(arr[new_pos], arr[(new_pos - 1) / 2]); // swap the parent and with new_pos element

			new_pos = (new_pos - 1) / 2; // new_pos pointer will now point the parent element and same thing will happen for this parent element
		}

	}

	//Same logic as Max heap
	void inset_min_heap(int val)
	{
		arr[curSize] = val;
		
		int new_pos = curSize;

		curSize++;

		while ((new_pos != 0) && (arr[new_pos] < arr[(new_pos - 1) / 2]))
		{
			swap(arr[new_pos], arr[(new_pos - 1) / 2]);

			new_pos = (new_pos - 1) / 2;
		}

	}

	

	void display()
	{
		for (int i = 0; i < curSize; i++)
		{
			cout << arr[i]<<"\t";
		}
		cout << endl;
	}
	
	~Heap()
	{
		delete[] arr;
	}
};

void maxHeapify(int arr[], int i, int curSize)
{
	int left_i = (2 * i) + 1; //Find the left child of given index(i)

	int right_i = (2 * i) + 2; //Find the right child of given index(i) in array (arr)
	
	int largest = i; //lets suppose largest is the ith element in aur array


	if (right_i < curSize && arr[right_i] > arr[i]) // Check If the right side is greater the parent 
	{
		largest = right_i; //Largest will be updated as right_i
	}

	if (left_i < curSize && arr[left_i] > arr[i]) // Check If the left side is greater the parent 
	{
		largest = left_i;  //Largest will be updated as left_i
	}
	
	if (largest != i) //if largest is not equal to i means the left or right there is a greater element
	{
		swap(arr[i], arr[largest]);

		maxHeapify(arr, largest, curSize); // recursively call for bottom elements of given index i
	}
}


void build_max_heap(int arr[],int* curSize)
{
	for(int i = (*curSize/2-1); i >= 0; i--)
	{
		maxHeapify(arr,i,*curSize);
	}
}

int get_max_periority_queue(int arr[], int* curSize)
{
	int max = arr[0];

	arr[0] = arr[*curSize-1]; //Replace the last element in array with root element
	
	*curSize = *curSize - 1;

	maxHeapify(arr,0,*curSize); //Call maxheapify function for root element to arrange elements

	return max; //return maximum element
	
}

void heap_sort(int arr[], int curSize)
{
	int j = curSize;
	
	for(int i = curSize-1;i>1;i--)
	{
	
		swap(arr[0],arr[i]);

		j = j - 1;

		maxHeapify(arr,0, j);
		
	}
}

int main() 
{
	/*
	Heap h(10);
	Heap h2(5);

	h.inset_max_heap(6);
	h.inset_max_heap(8);
	h.inset_max_heap(1);
	h.inset_max_heap(4);
	h.inset_max_heap(7);
	h.inset_max_heap(3);
	h.inset_max_heap(5);
	h.inset_max_heap(0);
	h.inset_max_heap(9);
	h.inset_max_heap(2);

	h.display();

	h2.inset_min_heap(5);
	h2.inset_min_heap(2);
	h2.inset_min_heap(1);
	h2.inset_min_heap(3);
	h2.inset_min_heap(4);

	h2.display();
	*/

	int arr[10] = { 9,8,5,7,6,10,3,0,4,2 };

	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;

	int curSize = sizeof(arr) / sizeof(arr[0]);
	build_max_heap(arr,&curSize);

	cout << "Maximmum value in heap is " << get_max_periority_queue(arr,&curSize)<<endl;

	for (int i = 0; i < curSize; i++) 
	{
		cout << arr[i] << "\t";
	}

	heap_sort(arr, curSize);

	cout << endl;

	for (int i = 0; i < curSize; i++)
	{
		cout << arr[i] << "\t";
	}

}


