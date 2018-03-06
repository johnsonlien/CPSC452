#include "RowTransposition.h"

#include <string>
#include <iostream>
#include <vector>

bool RowTransposition::setKey(const string& key) {
	//Our key needs to be an int
	_key = key;
	return false;
}

string RowTransposition::encrypt(const string& plaintext) {

	string encrypted = "";
	int lengthPlaintext = plaintext.length();
	int lengthKey = _key.length();
	int num_rows = lengthPlaintext / lengthKey;
	int plaintextPosition = 0;

	//convert plaintext into a matrix
	vector<string>  plaintextMatrix(num_rows);
	for (int i = 0; i < num_rows; i++) {
		for (int j = 0; j < lengthKey; j++) {
			plaintextMatrix[i].push_back(plaintext[plaintextPosition + j]);
		}
		plaintextPosition += lengthKey;
	}

	int targetColumn;
	//reorganize rows based on key
	for (int i = 0; i < lengthKey; i++) {
		targetColumn = int(_key[i]) - '0';
		for (int j = 0; j < num_rows; j++) {
			encrypted += plaintextMatrix[j][targetColumn - 1];
		}
	}

	return encrypted;

}

string RowTransposition::decrypt(const string& cipherText) {

	string decrypted = "";
	int lengthCiphertext = cipherText.length();
	int lengthKey = _key.length();
	int num_rows = lengthCiphertext / lengthKey;
	int currentColumn = (int(_key[0]) - '0') - 1;
	int currentColumnIndex = 0;
	int targetColumn = 0;
	int setCounter = 0;
	int offsetCounter = 0;
	int offset = 0;


	while (offset < num_rows) {
		while (offsetCounter < lengthKey) {
			//currentColumn holds the INTEGER value of the current column being checked
			currentColumnIndex = 0;
			while (currentColumn != targetColumn) {
				currentColumnIndex++;
				currentColumn = (int(_key[currentColumnIndex]) - '0') - 1;
			}
			//SUCCESS
			//insert the characters for the correct index num_row times
			setCounter = currentColumnIndex * num_rows;
			decrypted += cipherText[setCounter + offset];
			targetColumn++;
			currentColumn = (int(_key[0]) - '0') - 1;
			if (targetColumn == lengthKey) {
				offsetCounter++;
				targetColumn = 0;
				break;
			}
		}
		offset++;
	}

	return decrypted;
}
