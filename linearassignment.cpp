#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>
#include <climits>
//#include "matplotlibcpp.h" // Include matplotlib-cpp

//namespace plt = matplotlibcpp;
using namespace std;


int linearSearch(const vector<int>& arr, int key) {
    int comparisons = 0;
    for (int i = 0; i < arr.size(); i++) {
        comparisons++;
        if (arr[i] == key) {
            return comparisons;
        }
    }
    return comparisons;
}

int main() {
    int lower, upper, size, key;

    
    cout << "Enter the lower bound of the range: ";
    cin >> lower;
    cout << "Enter the upper bound of the range: ";
    cin >> upper;

    if (lower > upper) {
        cout << "Invalid range. Lower bound must be less than or equal to the upper bound." << endl;
        return 1;
    }

    
    srand(time(nullptr));

    
    cout << "Enter the size of the array: ";
    cin >> size;

    
    int* arr = new int[size];
    cout << "Generated array: ";
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % (upper - lower + 1) + lower;
        cout << arr[i] << " ";
    }
    cout << endl;

    
    cout << "Enter the key to search for: ";
    cin >> key;

    int comparisons = 0;
    bool found = false;

    
    for (int i = 0; i < size; ++i) {
        comparisons++;
        if (arr[i] == key) {
            cout << "Key found at index " << i << "." << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Key not found in the array." << endl;
    }

    
    cout << "Number of comparisons made: " << comparisons << endl;

    
    cout << "Best case: 1 comparison (key is at the first position)." << endl;
    cout << "Average case: " << (size + 1) / 2 << " comparisons (key is found at a random position)." << endl;
    cout << "Worst case: " << size << " comparisons (key is at the last position or not present)." << endl;

    
    ofstream file("linear_search_results.csv");
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    file << "n,MinComparisons,MaxComparisons,AverageCase\n";

    for (int n = 10; n <= 100; n += 5) {
        vector<int> arr(n);
        vector<int> keys(n + 1);
        int totalComparisons = 0;
        int minComparisons = INT_MAX;
        int maxComparisons = INT_MIN;

        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 1000;
            keys[i] = arr[rand() % n];
            int comparisons = linearSearch(arr, keys[i]);
            totalComparisons += comparisons;
            minComparisons = min(minComparisons, comparisons);
            maxComparisons = max(maxComparisons, comparisons);
        }

        keys[n] = 1001; 
        int lastComparisons = linearSearch(arr, keys[n]);
        totalComparisons += lastComparisons;
        maxComparisons = max(maxComparisons, lastComparisons);

        double averageCase = static_cast<double>(totalComparisons) / (n + 1);

        file << n << "," << minComparisons << "," << maxComparisons << "," << averageCase << "\n";
    }

    file.close();
    cout << "Results saved to linear_search_results.csv." << endl;

    delete[] arr;
    return 0;
}