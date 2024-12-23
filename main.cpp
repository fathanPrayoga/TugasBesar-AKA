#include <iostream>
#include <vector>
#include <numeric> // Untuk iota
using namespace std;

// Binary Search - Iterative Version
int binarySearchIterative(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if target is at mid
        if (arr[mid] == target)
            return mid;

        // If target is smaller than mid, search in the left half
        if (arr[mid] > target)
            right = mid - 1;
        else
            // Otherwise, search in the right half
            left = mid + 1;
    }

    // Target not found
    return -1;
}

int main() {
    // Membuat array terurut dari 1 hingga 1.000.000
    vector<int> arr(1000000);
    iota(arr.begin(), arr.end(), 1); // Mengisi array dengan angka 1 hingga 1.000.000
    int target;

    cout << "Array dibuat dengan angka 1 hingga 1.000.000." << endl;

    // Input angka yang ingin dicari
    cout << "Masukkan angka yang ingin dicari (1 hingga 1.000.000): ";
    cin >> target;

    // Panggil fungsi binarySearchIterative
    int result = binarySearchIterative(arr, target);

    // Tampilkan hasil
    if (result != -1)
        cout << "Angka ditemukan di indeks: " << result << endl;
    else
        cout << "Angka tidak ditemukan." << endl;

    return 0;
}
