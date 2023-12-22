#include "Serializer.hpp"
#include "Data.hpp"

int	main(void) {
	Data *originalData = new Data(42);

	uintptr_t serializedPtr = Serializer::serialize(originalData);

	Data* deserializedData = Serializer::deserialize(serializedPtr);

	if (deserializedData == originalData) {
		cout << "Serialization and deserialization successful." << endl;
		cout << "Original Data value: " << originalData->getDataValue() << endl;
	}
	else
		std::cerr << "Serialization and deserialization failed." << endl;

	delete originalData;

	return 0;
}