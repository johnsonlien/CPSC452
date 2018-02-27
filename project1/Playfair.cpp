#include "Playfair.h"

/**
 * Sets the key to use
 * @param key - the key to use
 * @return - True if the key is valid and False otherwise
 */
bool Playfair::setKey(const string& key)
{ 
	if(key.length() > 0) {	//Check that key is not null
		_key = key;
		return true;
	}
	printf("You did not enter a key\n");
	return false;  
}

/**	
 * Encrypts a plaintext string
 * @param plaintext - the plaintext string
 * @return - the encrypted ciphertext string
 */
string Playfair::encrypt(const string& plaintext)
{
	string mcontent = "";
	string temp = plaintext;	//Create a temporary string to store our capitilized plaintext
	string pairedtxt = "";
	//Create the string to populate our 5x5 matrix
	_key += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for(string::iterator it = _key.begin(); it != _key.end(); ++it) {
		*it = toupper(*it);				//Capitalize our key
		if((*it < 65) || (*it > 90)) { 	//If the char is not an uppercase, English letter, then skip this one
			continue;
		}
		if(*it == 'I') {
			*it = 'J';					//Convert I's to J's for our key
		}
		if(mcontent.find(*it) == -1) {	//If char is not found in our "matrix content", add the char to our mcontent
			mcontent += *it;
		}
	}
	copy(mcontent.begin(), mcontent.end(), &_matrix[0][0]);	//Populate our matrix
	
	//Change our plaintext copy to uppercase and convert the I's to J's
	for(string::iterator it = temp.begin(); it != temp.end(); ++it) {
		*it = toupper(*it);				//Capitalize our plaintext
		if((*it < 65) || (*it > 90)) {	//Again, ignore stuff that isn't an uppercase alphabet
			continue;
		}
		if(*it == 'I') {				//Convert 'I' to 'J'
			*it = 'J';					//Why 'J'? My name starts with 'J'
		}
	}
	
	//Pair the letters
	int length = temp.length(); 		//So our program won't keep calculating the plaintext's string length each iteration
	
	for(int i = 0; i < length; i+=2) {
		pairedtxt += temp[i];			//Append the character
		if(i+1 < length) {				//Check for array out-of-bounds
			if(temp[i] == temp[i+1]) {	//If the pair of letter is the same, use 'X' as the second half
				pairedtxt += 'X';
			}
			pairedtxt += temp[i+1];		//Append the next character
		}
	}
	if(pairedtxt.length()%2 == 1) {		//If we have a single remaining character, pair with 'X'
		pairedtxt += 'X';
	}
	
	//Encrypt our pairedtxt
	string encrypted = "";
	int x1, y1, x2, y2; 		//To store coordinates
	for(string::iterator it = pairedtxt.begin(); it != pairedtxt.end(); it++) {
		if(getCoor(*it++, x1, y1)) {
			if(getCoor(*it, x2, y2)) {
				if(x1 == x2) {			//Check if the characters are on same row
					encrypted += getChar(x1, y1+1);	//Increment the y-value since we will swap the x and y
					encrypted += getChar(x2, y2+1);
				}
				else if(y1 == y2) {		//Check if the characters are on same col
					encrypted += getChar(x1+1, y1);
					encrypted += getChar(x2+1, y2);
				}
				else {
					encrypted += getChar(x2, y1);
					encrypted += getChar(x1, y2);
				}
			}
		}
	}
	return encrypted; 
}

//Private helper function to return the character of the matrix given the coordinates
char Playfair::getChar(int x, int y) {
	return _matrix[(y+5)%5][(x+5)%5];
}

//Private helper function to get the coordinates from our matrix given a char
bool Playfair::getCoor(char a, int &x, int &y) {
	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 5; j++) {
			if(_matrix[i][j] == a) {
				x = j;
				y = i;
				return true;
			}
		}
	}
	return false;
}

/**
 * Decrypts a string of ciphertext
 * @param cipherText - the ciphertext
 * @return - the plaintext
 */
string Playfair::decrypt(const string& cipherText) 
{ 
	string mcontent = "";
	string temp = cipherText;	//Create a temporary string to store our capitilized ciphered text
	string pairedtxt = "";
	//Create the string to populate our 5x5 matrix
	_key += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for(string::iterator it = _key.begin(); it != _key.end(); ++it) {
		*it = toupper(*it);				//Capitalize our key
		if((*it < 65) || (*it > 90)) { 	//If the char is not an uppercase, English letter, then skip this one
			continue;
		}
		if(*it == 'I') {
			*it = 'J';					//Convert I's to J's for our key
		}
		if(mcontent.find(*it) == -1) {	//If char is not found in our "matrix content", add the char to our mcontent
			mcontent += *it;
		}
	}
	copy(mcontent.begin(), mcontent.end(), &_matrix[0][0]);	//Populate our matrix
	
	cout << "MATRIX\n";
	for(int i = 0; i < 5; i++) {
		for(int j = 0; j <5; j++) {
			cout << _matrix[i][j];
		}
		cout << endl;
	}
	
	//Change our plaintext copy to uppercase and convert the I's to J's
	for(string::iterator it = temp.begin(); it != temp.end(); ++it) {
		*it = toupper(*it);				//Capitalize our plaintext
		if((*it < 65) || (*it > 90)) {	//Again, ignore stuff that isn't an uppercase alphabet
			continue;
		}
		if(*it == 'I') {				//Convert 'I' to 'J'
			*it = 'J';					//Why 'J'? My name starts with 'J'
		}
	}
	
	//Pair the letters
	int length = temp.length(); 		//So our program won't keep calculating the plaintext's string length each iteration
	
	for(int i = 0; i < length; i+=2) {
		pairedtxt += temp[i];			//Append the character
		if(i+1 < length) {				//Check for array out-of-bounds
			if(temp[i] == temp[i+1]) {	//If the pair of letter is the same, use 'X' as the second half
				pairedtxt += 'X';
			}
			pairedtxt += temp[i+1];		//Append the next character
		}
	}
	if(pairedtxt.length()%2 == 1) {		//If we have a single remaining character, pair with 'X'
		pairedtxt += 'X';
	}
	
	//Decrypt our pairedtxt
	string decrypted = "";
	int x1, y1, x2, y2; 		//To store coordinates
	for(string::iterator it = pairedtxt.begin(); it != pairedtxt.end(); it++) {
		if(getCoor(*it++, x1, y1)) {
			if(getCoor(*it, x2, y2)) {
				if(x1 == x2) {			//Check if the characters are on same row
					decrypted += getChar(x1, y1-1);	//Increment the y-value since we will swap the x and y
					decrypted += getChar(x2, y2-1);
				}
				else if(y1 == y2) {		//Check if the characters are on same col
					decrypted += getChar(x1-1, y1);
					decrypted += getChar(x2-1, y2);
				}
				else {
					decrypted += getChar(x2, y1);
					decrypted += getChar(x1, y2);
				}
			}
		}
	} 
	return decrypted;
}

