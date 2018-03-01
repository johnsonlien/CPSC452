#ifndef CAESAR_H
#define CAESAR_H

#include "CipherInterface.h"
#include <string>

class Caesar : public CipherInterface {

public:
	virtual bool setKey(const string& key);
	virtual string encrypt(const string& plaintext);
	virtual string decrypt(const string& cipherText);

protected:
	string _key;
};

#endif
