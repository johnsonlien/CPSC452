#include "Caesar.h"

#include <string>
#include <iostream>

bool Caesar::setKey(const string& key) {
	//Our key needs to be an int
	if (key.length() > 0) {
		for (int i = 0; i < key.length(); i++) {
			if (isalpha(key[i])) {
				return false;
			}
			_key += key[i];
		}
		return true;
	}
	printf("You did not enter a key\n");
	return false;
}

string Caesar::encrypt(const string& plaintext) {
	string encrypted = "";
	// _key is the variable for key
	int offset = stoi(_key) % 26;
	for (int i = 0; i < plaintext.length(); i++) {
		char temp = plaintext[i];
		if (temp >= 'a' && temp <= 'z') {
			temp += 'A' - 'a';		//Capitalize our lowercase char
		}
		else if (temp < 'A' || temp > 'Z') {	//Ignore symbols and numbers
			continue;
		}
		temp += offset;
		if (temp > 'Z') {
			temp = 'A' + (temp - 'Z' - 1);
		}
		encrypted += temp;
	}

	return encrypted;

}

string Caesar::decrypt(const string& cipherText) {
	string decrypted = "";
	int offset = stoi(_key) % 26;
	for (int i = 0; i < cipherText.length(); i++) {
		char temp = cipherText[i];
		temp -= offset;
		if (temp < 'A') {
			temp = 'Z' - ('A' - temp  - 1);
		}
		decrypted += temp;
	}
	return decrypted;
}
