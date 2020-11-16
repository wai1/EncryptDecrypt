This program will encrypt a text file and it can also decrypt a text file.

The encryption part of the program will read in characters from "LettersFile.txt" file and check to 
see if a character is duplicated by the adjacent character. If it is, it will keep track of the  
duplicates and insert the number of duplicates removing the duplicate letters. The encrypted file 
will be saved to "encryptedFile.txt" file.

The decryption part of the program will read in "encryptedFile.txt" file, detect if there is a number,
which represents the number of duplicated letters, and output the letters with correct duplicates  
to the "decryptedFile.txt" file.