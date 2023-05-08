#include <iostream>
#include <vector>

using namespace std;

// Function to perform insertion sort and count the number of comparisons
int insertionSort(vector<int> &arr)
{
    int comparisons = 0;

    for (int i = 1; i < arr.size(); i++)
    {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
            comparisons++;
        }
        arr[j + 1] = key;
    }

    return comparisons;
}

// Function to print an array
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
    // Initialize an array
    vector<int> arr = {5, 2, 8, 3, 1, 6, 9, 7, 4};

    // Sort the array using Insertion Sort and count the number of comparisons
    int comparisons = insertionSort(arr);

    // Print the sorted array and the number of comparisons made during the sorting process
    cout << "Sorted array: ";
    printArray(arr);
    cout << "Number of comparisons: " << comparisons << endl;

    return 0;
}
