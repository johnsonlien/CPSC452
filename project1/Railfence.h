#ifndef RAILFENCE_H
#define RAILFENCE_H

#include "CipherInterface.h"
#include <string>

class Railfence: public CipherInterface {
	
	public:
		virtual bool setKey(const string& key);
		virtual string encrypt(const string& plaintext);
		virtual string decrypt(const string& cipherText);
	
	protected:
		string _key;
};

#endif
