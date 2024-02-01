#include "Array.hpp"
#include "Array.tpp"

int main(int, char**)
{
    try {
        // Test construction with no parameter
        Array<int> emptyArray;
        cout << "Empty array size: " << emptyArray.size() << endl;

        // Test construction with an unsigned int n as a parameter
        Array<int> intArray(5);
        cout << "Initialized array size: " << intArray.size() << endl;

        // Test copy constructor and assignment operator
        Array<int> copiedArray(intArray);
        Array<int> assignedArray;
        assignedArray = intArray;

        // Modify the original array to check for independence
        intArray[0] = 100;

        cout << "Copied array size: " << copiedArray.size() << endl;
        cout << "Assigned array size: " << assignedArray.size() << endl;

        // Access elements and display
        cout << "Original array[0]: " << intArray[0] << endl;
        cout << "Copied array[0]: " << copiedArray[0] << endl;
        cout << "Assigned array[6]: " << assignedArray[6] << endl;

        // Access out of bounds to test exception
        // Uncomment the line below to test the exception
        // std::cout << intArray[10] << std::endl;

    } catch (const std::exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }

    return 0;
}