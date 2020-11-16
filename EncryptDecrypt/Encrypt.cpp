# include "Encrypt.h"
# include <iostream>
# include <string>

Encrypt::Encrypt() {};  // Default constructor
Encrypt::~Encrypt() {};  // Destructor

// Receives a string and returns the encoded string
std::string Encrypt::eCryptString(std::string rawString)
{
	int rawStringLength{};  // Determine length; needed to output last character
	int loopCounter = 0;
	bool lastIteration = false;

	// Find the length of the string
	rawStringLength = rawString.length();
	// std::cout << "The length of the string is: " << rawStringLength << std::endl;

	// Iterate through the raw string
	for (stringIt = rawString.begin(); stringIt != rawString.end(); ++stringIt)

	{
		if (firstIt)  // Checks for beginning of iteration
		{
			firstIt = false;  // Change first iteration to false
			temp1 = *stringIt;  // temp1 gets first character
			loopCounter++;
			continue;  // Go to next iteration
		}

		temp2 = *stringIt;  // Read in next character

		// Check to see if temp2 is last character and it is the same as last character and there were previous duplicates
		if ((loopCounter == rawStringLength - 1) && (count >= 1) && (temp1 == temp2))
		{
			count += 2;  // Adds the temp1 and temp2 duplicates
			encoded.append(std::to_string(count));  // Add the number of duplicates
			encoded.append(temp1);	// Add the duplicate character
			continue;
		}

		// Test if all characters have been read in
		if (loopCounter == rawStringLength - 1)
			lastIteration = true;

		theEncoder(temp2, lastIteration);  // Call the encoder

		loopCounter++;
		
	}

	return encoded;
}

void Encrypt::theEncoder(std::string temp, bool lastIteration)
{
	// Check if current character is the same as previous character
	if ((temp1 == temp2))
	{
		count++; // Increment duplicate couter
	}
	
	// Check if currenct and previous characters are not equal and there were no previous duplicates
	else if ((temp1 != temp2) && (count == 0))
	{
		encoded.append(temp1);  // Add letter to encoded string
		temp1 = temp2;  // Move new character to temp1

		// Output last character in raw file since last iteration and it was not the same as previous letter; previous character was not duplicated
		if (lastIteration)
			encoded.append(temp1);
	}

	// Check if current and previous characters are not equal and there were previous duplicates
	else if ((temp1 != temp2) && (count != 0))
	{
		count++;  // Adds last duplicate to the count
		encoded.append(std::to_string(count));  // Add the number of duplicates
		encoded.append(temp1);	// Add the duplicate character
		temp1 = temp2;  // Move new character to temp1

		// Output last character in raw file since last iteration and it was not the same as previous letter; previous characters were duplicated
		if (lastIteration)
			encoded.append(temp1);

		count = 0;  // Reset duplicate counter
	}
}

