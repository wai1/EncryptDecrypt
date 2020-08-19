#include "Decrypt.h"
# include <iostream>
# include <string>

Decrypt::Decrypt() {};  // Default constructor
Decrypt::~Decrypt() {};  // Destructor

// Receives encrypted string and returns the decrypted string
std::string Decrypt::dCryptString(std::string encryptedString)
{

	// Iterate through the encrypted string
	for (decryptIt = encryptedString.begin(); decryptIt != encryptedString.end(); ++decryptIt)
	{
		encodedChar = *decryptIt;
		aNumber = CheckForNumber(encodedChar);

		if ((!aNumber) && (duplicates == 0))
		{
			decryptedString.append(encodedChar);
		}
		else if ((!aNumber) && (duplicates != 0))
		{
			for (int i = 0; i < duplicates; i++)
			{
				decryptedString.append(encodedChar);
			}

			duplicates = 0;  // Reset duplicate counter
		}
		else
		{
			if (duplicates == 0)
				duplicates = tempDuplicate;
			else
			{
				duplicates = 10 * duplicates + tempDuplicate;
			}
		}
	}

	return decryptedString;
}

void Decrypt::theDecoder(std::string temp, bool lastIteration)
{

}

bool Decrypt::CheckForNumber( std::string encodedChar)
{
	aNumber = false;

	if ((encodedChar >= "0") && (encodedChar <= "9"))
	{
		
		std::istringstream convert(encodedChar);  // Stream used to convert string to int
		convert >> tempDuplicate;  // Temporarily store number
		aNumber = true;
	}

	return aNumber;
}