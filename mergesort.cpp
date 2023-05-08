#include <iostream>
#include <vector>

using namespace std;

// Function to merge two sub-arrays of arr[].
int merge(vector<int> &arr, int left, int mid, int right, int &comparisons)
{
    int i, j, k;
    int count = 0;

    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
            count += n1 - i;
        }
        k++;
        comparisons++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
        comparisons++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
        comparisons++;
    }

    return count;
}

// Function to sort an array using Merge Sort.
int mergeSort(vector<int> &arr, int left, int right, int &comparisons)
{
    int count = 0;

    if (left < right)
    {
        int mid = left + (right - left) / 2;

        count += mergeSort(arr, left, mid, comparisons);
        count += mergeSort(arr, mid + 1, right, comparisons);

        count += merge(arr, left, mid, right, comparisons);
    }

    return count;
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

    // Sort the array using Merge Sort and count the number of comparisons
    int comparisons = 0;
    int count = mergeSort(arr, 0, arr.size() - 1, comparisons);

    // Print the sorted array and the number of comparisons made during the sorting process
    cout << "Unsorted array :";
    cout << "{5, 2, 8, 3, 1, 6, 9, 7, 4}"
         << endl;
    cout
        << "Sorted array: ";
    printArray(arr);
    cout << "Number of comparisons: " << comparisons << endl;

    return 0;
}
