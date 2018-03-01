#include "Railfence.h"

#include <string>
#include <iostream>

bool Railfence::setKey(const string& key) {
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

string Railfence::encrypt(const string& plaintext) {
	
	string encrypted;
	// _key is the variable for key
	int num_rows = stoi(_key);
	int temp1 = 0;
	if (num_rows == 0) {
		cout << "Invalid Key" << endl;
		return false;
	}
	for (int i = 0; i < num_rows; i++) {
		temp1 += i;
		while (temp1 < plaintext.length()) {
			encrypted += plaintext[temp1];
			temp1 += num_rows;
		}
		temp1 = 0;
		encrypted += '\n';
	}
	
	return encrypted;
	
}

string Railfence::decrypt(const string& cipherText) {
	
	string decrypted = "";
	return decrypted;
}
