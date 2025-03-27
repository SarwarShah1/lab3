#include <iostream>
using namespace std;

template <typename A>
int binarySearch(A* arr,int size, A key) {
    int low = 0, high = size - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int intArray[5] = { 11, 12, 22, 25, 64 };
    int intkey = 22;

    
    int intIndex = binarySearch(intArray,5, intkey);

    cout << intIndex << endl;

    float floatArray[4] = { 0.57, 1.62, 2.71, 3.14 };
    float floatKey = 2.71;
    int floatIndex = binarySearch(floatArray,4, floatKey);
    cout << floatIndex << endl;

    string stringArray[4] = { "apple", "banana", "grape", "orange" };
    string stringKey = "banana";
    int stringIndex = binarySearch(stringArray, 4 , stringKey);
    cout << stringIndex << endl;
    return 0;
}
