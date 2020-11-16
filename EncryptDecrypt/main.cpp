/*  The encryption part of the program will read in characters from "LettersFile.txt" file and check to 
 *  see if a character is duplicated by the adjacent character. If it is, it will keep track of the  
 *  duplicates and insert the number of duplicates removing the duplicate letters. The encrypted file 
 *  will be saved to "encryptedFile.txt" file.
 * 
 *  The decryption part of the program will read in "encryptedFile.txt" file, detect if there is a number,
 *  which represents the number of duplicated letters, and output the letters with correct duplicates  
 *  to the "decryptedFile.txt" file.
*/

# include "Encrypt.h"
# include "Decrypt.h"

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>

using namespace std;

int main()
{
	int duplicates = 0;
	string stringToEncrypt{};
	string stringToDecrypt{};
	string encryptedString{};
	string decryptedString{};

	ifstream inFile("LettersFile.txt");  // Open file for reading
	stringstream buffer;  
	fstream inEncryptedFile("encryptedFile.txt"); 
	ofstream outDecryptedFile("decryptedFile.txt");

	Encrypt encryption; // Reference to Encrypt class
	Decrypt decryption; // Reference to Decrypt class

	if (inFile) {
		buffer << inFile.rdbuf();  // Read in characters from the file
		stringToEncrypt = buffer.str();  // Needed to convert from stringstream to string
	}
	else {
		cout << "Unable to open the file." << endl;
		return 1;
	}	

	encryptedString = encryption.eCryptString(stringToEncrypt);

	if (inEncryptedFile) {
		inEncryptedFile << encryptedString << endl;
	}
	else
	{
		cout << "File could not be written to." << endl;
		return 1;
	}
		
	if (inEncryptedFile)
	{
		buffer.clear();
		buffer << inEncryptedFile.rdbuf();  // Read in encrypted charaters
		stringToDecrypt = buffer.str();  // Convert from stringstream to string
	}
	else 
	{
		cout << "Unable to open the file." << endl;
		return 1;
	}

	decryptedString = decryption.dCryptString(stringToDecrypt);

	if (outDecryptedFile) {
		outDecryptedFile << decryptedString << endl;
	}
	else
	{
		cout << "File could not be written to." << endl;
		return 1;
	}

	inFile.close();
	inEncryptedFile.close();
	outDecryptedFile.close();

	return 0;
}