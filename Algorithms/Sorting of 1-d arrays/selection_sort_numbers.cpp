#include <iostream> 
using namespace std; 

void selectionSort(int arr[], int n) 
{ 
	for (int i = 0; i < n-1; i++) // One by one move boundary of unsorted subarray
	{ 
		int min_idx = i; // Find the minimum element in unsorted array 
		for (int j = i+1; j < n; j++) 
		if (arr[j] < arr[min_idx]) 
			min_idx = j; 
 
		swap(arr[min_idx], arr[i]); // Swap the found minimum element with the first element
	} 
} 

/* Function to print an array */
void printArray(int arr[], int size) 
{ 
	for (int i=0; i < size; i++) 
		cout << arr[i] << " "; 
	cout << endl; 
} 

// Driver code
int main() 
{ 
	int arr[] = {64, 25, 12, 22, 11, 1, 34}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	selectionSort(arr, n); 
	cout << "Sorted array: "<<endl; 
	printArray(arr, n); 
	return 0; 
} 