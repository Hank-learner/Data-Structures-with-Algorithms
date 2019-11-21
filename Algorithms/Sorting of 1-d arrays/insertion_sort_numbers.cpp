#include <iostream> 
using namespace std; 

// Function to sort an array using insertion sort
void insertionSort(int arr[], int n) 
{  
	for (int i = 1; i < n; i++) 
	{ 
		int key = arr[i]; 
		int j = i - 1; 

		while (j >= 0 && arr[j] > key) //swap places of unsorted elements till position for i element is freed
		{ 
			arr[j + 1] = arr[j]; 
			j = j - 1; 
		} 
		arr[j + 1] = key; 
	} 
} 

// A utility function to print an array of size n 
void printArray(int arr[], int n) 
{ 
	for (int i = 0; i < n; i++) 
		cout << arr[i] << " "; 
	cout << endl; 
} 

//  Driver code 
int main() 
{ 
	int arr[] = { 12, 11, 13, 5, 6, 111, 1 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 

	insertionSort(arr, n); 
	cout << "Sorted array: "<<endl; 
	printArray(arr, n); 

	return 0; 
} 