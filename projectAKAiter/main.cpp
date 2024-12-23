#include <iostream>
#include <vector>
using namespace std;

// Binary Search - Iterative Version
int binarySearchIterative(const vector<int>& arr, int target, int& steps) {
    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        steps++; // Increment the step counter
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) return mid; // Found the target

        if (arr[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }

    return -1; // Target not found
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
    int result = binarySearchIterative(arr, target, steps);

    // Output results
    if (result != -1) {
        cout << "Number " << target << " was found at index " << result << " in " << steps << " steps!" << endl;
    } else {
        cout << "Number " << target << " was not found after " << steps << " steps." << endl;
    }

    return 0;
}
