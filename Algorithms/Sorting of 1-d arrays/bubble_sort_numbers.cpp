#include <iostream> 
using namespace std; 

// A function to implement bubble sort 
void bubbleSort(int arr[], int n) 
{ 
	for (int i = 0; i < n-1; i++)// Last i elements are already in place 
		for (int j = 0; j < n-i-1; j++) 
			if (arr[j] > arr[j+1]) 
				swap(arr[j], arr[j+1]); 
} 

// Utility function to print an array of size n
void printArray(int arr[], int size) 
{ 
	for (int i = 0; i < size; i++) 
		cout << arr[i] << " "; 
	cout << endl; 
} 

// Driver code 
int main() 
{ 
	int arr[] = {64, 34, 25, 12, 22, 11, 90, 1}; 
	int n = sizeof(arr)/sizeof(arr[0]); 

	bubbleSort(arr, n); 

	cout<<"Sorted array: "<<endl; 
	printArray(arr, n); 
    
	return 0; 
}
