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
	
	string encrypted = "";
	// _key is the variable for key
	int num_rows = stoi(_key);
	int temp1 = 0;
	if (num_rows == 0) {
		cout << "Invalid Key" << endl;
		exit(EXIT_FAILURE);
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
	int cipherLength = stripped.length();
	int extraChar = cipherLength % num_rows;

	//Determine if the length is divisable by num_rows
	bool isDivisable;
	if (cipherLength % num_rows == 0) {
		isDivisable = true;
	}
	else isDivisable = false;
	int columncounter = 0;

	int num_columns;
	if (extraChar != 0) {
		num_columns = (stripped.length() / num_rows) + 1;
	}
	else {
		num_columns = stripped.length() / num_rows;
	}


	if (isDivisable) {
		for (int i = 0; i < cipherLength / num_rows; i++) {
			for (int j = 0; j < cipherLength;) {
				decrypted += stripped[j + columncounter];
				j += (cipherLength / num_rows);
			}
			columncounter++;
		}
	}
	else {
		while (columncounter != num_columns) {
			//check if the current column is the last one
			if (columncounter == num_columns - 1) {
				for (int i = 0; i < cipherLength % num_rows; i++) {
					decrypted += stripped[columncounter];
					columncounter += (cipherLength / num_rows) + 1;
				}
				break;
			}
			//this does a check for when there are less 
			//characters in a colum than there are rows
			for (int i = columncounter; i < stripped.length(); i++) {
				decrypted += stripped[i];
				if (extraChar != 0) {
					i++;
					extraChar--;
				}
				i += (cipherLength / num_rows) - 1;
			}
			extraChar = cipherLength % num_rows;
			columncounter++;
		}
	}

	return decrypted;
}
