#include <iostream>
#include <cstdlib> 
#include <ctime>   

using namespace std;

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

    
    delete[] arr;

    return 0;
}
