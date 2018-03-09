#include "Vigenere.h"

/**
 * Sets the key to use
 * @param key - the key to use
 * @return - True if the key is valid and False otherwise
 */
bool Vigenere::setKey(const string& key)
{ 
	for(int i = 0; i < key.length(); i++) {
		if(!isalpha(key[i])) {
			return false;
		}
		if(key[i] >= 'a' && key[i] <= 'z') {	//In case of lowercase
			_key += key[i] + 'A' - 'a';		//Append the uppercase version
		}
		else if(key[i] >= 'A' && key[i] <= 'Z') {
			_key += key[i];
		}
	}
	return true;  
}

/**	
 * Encrypts a plaintext string
 * @param plaintext - the plaintext string
 * @return - the encrypted ciphertext string
 */
string Vigenere::encrypt(const string& plaintext)
{
	string encrypted = "";
	for(int i = 0, index = 0; i < plaintext.length(); i++) {
		char temp = plaintext[i];
		if(temp >= 'a' && temp <= 'z') {
			temp += 'A' -'a';		//Capitalize our lowercase char
		}
		else if(temp < 'A' || temp > 'Z') {	//Ignore symbols and numbers
			continue;
		}
		encrypted += (temp + _key[index] - 2*'A')%26 + 'A';	//Find corresponding letter
		index = (index+1)%_key.length(); 
	}
	return encrypted; 
}

/**
 * Decrypts a string of ciphertext
 * @param cipherText - the ciphertext
 * @return - the plaintext
 */
string Vigenere::decrypt(const string& cipherText) 
{ 
	string decrypted = "";
	for(int i = 0, index = 0; i < cipherText.length(); i++) {
		char temp = cipherText[i];
		if(temp >= 'a' && temp <= 'z') {
			temp += 'A' - 'a';
		}
		else if (temp < 'A' || temp > 'Z') {	//Ignore symbols and numbers
			continue;
		}
		decrypted += (temp - _key[index] + 26)%26 + 'A';	//Formula to get plaintext
		index = (index+1)%_key.length();				//recalculate our new index key value
	}
	return decrypted;
}

