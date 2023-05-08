#include <iostream>
#include <vector>

using namespace std;

// Function to swap two elements in an array.
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Function to heapify a subtree rooted at index i.
void heapify(vector<int> &arr, int n, int i, int &comparisons)
{
    int largest = i;       // Initialize largest as root.
    int left = 2 * i + 1;  // Left child.
    int right = 2 * i + 2; // Right child.

    // If left child is larger than root.
    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
    comparisons++;

    // If right child is larger than largest so far.
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }
    comparisons++;

    // If largest is not root.
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree.
        heapify(arr, n, largest, comparisons);
    }
}

// Function to perform Heap Sort.
void heapSort(vector<int> &arr, int &comparisons)
{
    int n = arr.size();

    // Build heap (rearrange array).
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i, comparisons);
    }

    // Extract elements from heap one by one.
    for (int i = n - 1; i >= 0; i--)
    {
        // Move current root to end.
        swap(arr[0], arr[i]);

        // Call max heapify on the reduced heap.
        heapify(arr, i, 0, comparisons);
    }
}

// Function to print an array.
void printArray(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    // Initialize an array.
    vector<int> arr = {5, 2, 8, 3, 1, 6, 9, 7, 4};

    // Sort the array using Heap Sort and count the number of comparisons.
    int comparisons = 0;
    heapSort(arr, comparisons);

    // Print the sorted array and the number of comparisons made during the sorting process.
    cout << "Sorted array: ";
    printArray(arr);
    cout << "Number of comparisons: " << comparisons << endl;

    return 0;
}
