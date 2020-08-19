#pragma once

# include <string>
# include <vector>

class Encrypt
{
public:
	Encrypt();  // Default constructor
	~Encrypt();  // Destructor

	// Getters and setters
	// std::string get_letter() { return letter;}
	// int get_count() { return count; }
	// std::string get_encoded() { return encoded; }
	// void set_letter(char aLetter) { this->letter = aLetter; }
	// void set_count(int aCount) { this->count = aCount; }
	// void set_encoded(std::string aString) { this->encoded = aString; }

	// An iterator for string which will not change the value of the string
	std::string::const_iterator stringIt{};

	// Encrypt the string prototype
	std::string eCryptString(std::string rawString);

private:
	// The actual encoder prototype
	void theEncoder(std::string temp, bool lastIteration);

	std::string temp1{};  // Contains current character
	std::string temp2{};  // Contains next character
	std::string encoded{};  // Contains the encoded string
	int count = 0;  // Used to keep track of duplicate characters
	bool firstIt{ true };  // Used to store first iteration information

};

