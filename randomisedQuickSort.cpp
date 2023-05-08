#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to swap two elements in an array.
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Function to partition the array using a pivot.
int partition(vector<int> &arr, int low, int high, int &comparisons)
{
    int pivot = arr[high]; // Choose the last element as the pivot.
    int i = low - 1;       // Index of smaller element.

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than or equal to pivot.
        if (arr[j] <= pivot)
        {
            i++;                  // Increment index of smaller element.
            swap(arr[i], arr[j]); // Swap current element with the smaller element.
        }
        comparisons++;
    }

    swap(arr[i + 1], arr[high]); // Swap the pivot with the element at the next index of the smaller element.
    return i + 1;                // Return the index of the pivot.
}

// Function to randomly select a pivot element and partition the array.
int randomizedPartition(vector<int> &arr, int low, int high, int &comparisons)
{
    srand(time(NULL));                                 // Seed the random number generator.
    int randomIndex = low + rand() % (high - low + 1); // Generate a random index within the range [low, high].
    swap(arr[randomIndex], arr[high]);                 // Swap the randomly selected element with the last element.
    return partition(arr, low, high, comparisons);     // Partition the array using the last element as the pivot.
}

// Function to perform Quick Sort.
void quickSort(vector<int> &arr, int low, int high, int &comparisons)
{
    if (low < high)
    {
        // Partition the array using a randomly selected pivot.
        int pi = randomizedPartition(arr, low, high, comparisons);

        // Recursively sort the sub-arrays on both sides of the pivot.
        quickSort(arr, low, pi - 1, comparisons);
        quickSort(arr, pi + 1, high, comparisons);
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

    // Sort the array using Quick Sort and count the number of comparisons.
    int comparisons = 0;
    quickSort(arr, 0, arr.size() - 1, comparisons);

    // Print the sorted array and the number of comparisons made during the sorting process.
    cout << "Sorted array: ";
    printArray(arr);
    cout << "Number of comparisons: " << comparisons << endl;

    return 0;
}
