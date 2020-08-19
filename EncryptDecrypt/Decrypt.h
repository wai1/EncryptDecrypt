#pragma once
#include <sstream>
#include <string>

class Decrypt
{
public:
	Decrypt();  // Default constructor
	~Decrypt();  // Destructor

	std::string dCryptString(std::string encryptedString);

	// An iterator for string which will not change the value of the string
	std::string::const_iterator decryptIt{};

private:
	void theDecoder(std::string temp, bool lastIteration); 
	bool CheckForNumber(std::string encodedChar);

	bool aNumber = false;  // For return of function to test for numbers
	int duplicates = 0;  // Keeps track of number of duplicates
	int tempDuplicate = 0;  // For storing new number read in
	std::string decoded{};  // Contains the encoded string
	std::string encodedChar{};  // Holds string character read in
	std::string decryptedString{};
};

