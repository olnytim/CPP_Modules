#include "Array.hpp"

int main(int, char**)
{
    try {
		Array<int> emptyArray;
		cout << "Empty array size: " << emptyArray.size() << endl;

		Array<int> intArray(5);
		cout << "Initialized array size: " << intArray.size() << endl;

		for (size_t i = 0; i < intArray.size(); ++i) {
			intArray[i] = i;
			cout << intArray[i] << endl;
		}

		Array<const int> constArray;
		cout << "Constant array size: " << constArray.size() << endl;

		Array<int> copiedArray(intArray);
		for (size_t i = 0; i < copiedArray.size(); ++i) {
			cout << copiedArray[i] << endl;
		}
		if (constArray.size() != 0)
			for (size_t i = 0; i < constArray.size(); ++i)
				cout << constArray[i] << endl;

		Array<int> assignedArray;
            assignedArray = intArray;

            intArray[0] = 100;

        cout << "Copied array size: " << copiedArray.size() << endl;
        cout << "Assigned array size: " << assignedArray.size() << endl;

        cout << "Original array[0]: " << intArray[0] << endl;
//        cout << "const array[0]: " << constArray[0] << endl;
        cout << "Copied array[0]: " << copiedArray[0] << endl;
//        cout << "Assigned array[5]: " << assignedArray[5] << endl;

//        std::cout << intArray[10] << std::endl;

    }
    catch (const std::exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }

    return 0;
}

//#include <iostream>
////#include <Array.hpp>
//
//#define MAX_VAL 750
//int main(int, char**)
//{
//    Array<int> numbers(MAX_VAL);
//    int* mirror = new int[MAX_VAL];
//    srand(time(NULL));
//    for (int i = 0; i < MAX_VAL; i++)
//    {
//        const int value = rand();
//        numbers[i] = value;
//        mirror[i] = value;
//    }
//    //SCOPE
//    {
//        Array<int> tmp = numbers;
//        Array<int> test(tmp);
//    }
//
//    for (int i = 0; i < MAX_VAL; i++)
//    {
//        if (mirror[i] != numbers[i])
//        {
//            std::cerr << "didn't save the same value!!" << std::endl;
//            return 1;
//        }
//    }
//    try
//    {
//        numbers[3] = 0;
//    }
//    catch(const std::exception& e)
//    {
//        std::cerr << e.what() << '\n';
//    }
//    try
//    {
//        numbers[MAX_VAL - 1] = 0;
//    }
//    catch(const std::exception& e)
//    {
//        std::cerr << e.what() << '\n';
//    }
//
//    for (int i = 0; i < MAX_VAL; i++)
//    {
//        numbers[i] = rand();
//    }
//    delete [] mirror;
//    return 0;
//}