#include "Array.hpp"

int main(int, char**)
{
    try {
        Array<int> emptyArray;
        cout << "Empty array size: " << emptyArray.size() << endl;

        Array<int> intArray(5);
        cout << "Initialized array size: " << intArray.size() << endl;

        Array<int> copiedArray(intArray);
        Array<int> assignedArray;
        assignedArray = intArray;

        intArray[0] = 100;

        cout << "Copied array size: " << copiedArray.size() << endl;
        cout << "Assigned array size: " << assignedArray.size() << endl;

        cout << "Original array[0]: " << intArray[0] << endl;
        cout << "Copied array[0]: " << copiedArray[0] << endl;
//        cout << "Assigned array[5]: " << assignedArray[5] << endl;

//        std::cout << intArray[10] << std::endl;

    } catch (const std::exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }

    return 0;
}