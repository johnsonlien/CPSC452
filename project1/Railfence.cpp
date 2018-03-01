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
	cout << ("You did not enter a key\n");
	return false;
}

string Railfence::encrypt(const string& plaintext) {

	string encrypted = "";
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
	string stripped = "";
	int num_rows = stoi(_key);


	//First remove newline characters
	for (int i = 0; i < cipherText.length(); i++) {
		if (cipherText[i] != '\n') {
			stripped += cipherText[i];
		}
	}
	int length = stripped.length();
	int temp1 = length % num_rows;
	int num_columns;
	if (temp1 != 0) {
		num_columns = (stripped.length() / num_rows) + 1;
	}
	else {
		num_columns = stripped.length() / num_rows;
	}
	int columncounter = 0;
	while (columncounter != num_columns) {
		if (columncounter == num_columns - 1) {
			for (int i = 0; i < length % num_rows; i++) {
				decrypted += stripped[columncounter];
				columncounter += (length / num_rows) + 1;
			}
			break;
		}
		for (int i = columncounter; i < stripped.length(); i++) {
			decrypted += stripped[i];
			//check for last row
			if (temp1 != 0) {
				i++;
				temp1--;
			}
			i += (length/num_rows) - 1;
		}
		temp1 = length % num_rows;
		columncounter++;
	}
	//last row


	return decrypted;
}
