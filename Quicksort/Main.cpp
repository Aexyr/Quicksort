#include <iostream>

using namespace std;

void quicksort(int *arr, int low, int high);
int partition(int *arr, int low, int high);
void print(int *arr);

int main() {
	int *test = new int[10] { 35, 33, 42, 10, 14, 19, 27, 44, 26, 31 };
	cout << "Unsorted Array: ";
	print(test);
	cout << endl;
	
	quicksort(test, 0, 9);
	cout << "Sorted Array: ";
	print(test);
	cout << endl;

	system("pause");
	return 0;
}

void quicksort(int *arr, int low, int high)
{
	if (low < high)
	{
		int pivot = high;
		int p = partition(arr, low, high);
		quicksort(arr, low, p - 1);
		quicksort(arr, p + 1, high);
	}
}

int partition(int *arr, int low, int high)
{
	int pivot = arr[high];
	int i = low - 1; // Left index tracker
	int j = high; // Right index tracker
	int temp = 0; // Swapping agent
	bool isDone = false; // Flag
	while (!isDone)
	{
		while ((i < j) && (i < high) && (arr[++i] < pivot));
		while ((i < j) && (j > 0) && (arr[--j] > pivot));
		if (i >= j)
		{
			// Swaps pivot && arr[j]
			temp = arr[high];
			arr[high] = arr[j];
			arr[j] = temp;
			isDone = true;
		}
		else
		{
			// Swaps arr[i] && arr[j]
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	return j;
}

// Hoare partition scheme
/*int partition(int *arr, int low, int high)
{
	int pivot = arr[low];
	int i = low - 1;
	int j = high + 1;
	int temp = 0;
	bool isDone = false;
	while (!isDone)
	{
		while (arr[++i] < pivot);
		while (arr[--j] > pivot);
		if (i >= j)
		{
			isDone = true;
		}
		else
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	return j;
}*/

void print(int *arr)
{
	for (int i = 0; i < 10; ++i)
	{
		cout << arr[i] << " ";
	}
}
