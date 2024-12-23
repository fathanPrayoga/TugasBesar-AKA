#include <iostream>
#include <vector>
using namespace std;

// Binary Search - Recursive Version
int binarySearchRecursive(const vector<int>& arr, int left, int right, int target, int& steps) {
    steps++; // Increment the step counter
    if (left > right) return -1; // Base case: Target not found

    int mid = left + (right - left) / 2;

    if (arr[mid] == target) return mid; // Found the target

    if (arr[mid] > target)
        return binarySearchRecursive(arr, left, mid - 1, target, steps);

    return binarySearchRecursive(arr, mid + 1, right, target, steps);
}

int main() {
    int n, target, steps = 0;

    // Input range of numbers
    cout << "Enter the size of the range (e.g., 100 for 1-100): ";
    cin >> n;

    // Generate the range of numbers
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        arr[i] = i + 1; // Range: 1 to n
    }

    // User chooses a number to be "guessed" by the algorithm
    cout << "Think of a number between 1 and " << n << " (inclusive) and enter it: ";
    cin >> target;

    // Perform binary search
    int result = binarySearchRecursive(arr, 0, n - 1, target, steps);

    // Output results
    if (result != -1) {
        cout << "Number " << target << " was found at index " << result << " in " << steps << " steps!" << endl;
    } else {
        cout << "Number " << target << " was not found after " << steps << " steps." << endl;
    }

    return 0;
}
