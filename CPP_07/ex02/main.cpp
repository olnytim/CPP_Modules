#include "Array.hpp"
#include "Array.tpp"

int main(int, char**)
{
    try {
        // Test construction with no parameter
        Array<int> emptyArray;
        std::cout << "Empty array size: " << emptyArray.size() << std::endl;

        // Test construction with an unsigned int n as a parameter
        Array<int> intArray(5);
        std::cout << "Initialized array size: " << intArray.size() << std::endl;

        // Test copy constructor and assignment operator
        Array<int> copiedArray(intArray);
        Array<int> assignedArray;
        assignedArray = intArray;

        // Modify the original array to check for independence
        intArray[0] = 100;

        std::cout << "Copied array size: " << copiedArray.size() << std::endl;
        std::cout << "Assigned array size: " << assignedArray.size() << std::endl;

        // Access elements and display
        std::cout << "Original array[0]: " << intArray[0] << std::endl;
        std::cout << "Copied array[0]: " << copiedArray[0] << std::endl;
        std::cout << "Assigned array[6]: " << assignedArray[6] << std::endl;

        // Access out of bounds to test exception
        // Uncomment the line below to test the exception
        // std::cout << intArray[10] << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}