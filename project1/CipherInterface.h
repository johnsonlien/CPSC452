#ifndef __CIPHER_INTERFACE__
#define __CIPHER_INTERFACE__

#include <string> /* For C++ strings */

using namespace std;

/**
 * This class implements the interface for a typical cipher.
 * It defines functions usually used in a cipher
 */
class CipherInterface
{
	/** The public members **/
	public:

		/**
		 * The default constructor
		 */
		CipherInterface(){}
		
		
		/**
		 * Sets the key to use
		 * @param key - the key to use
		 * @return - True if the key is valid and False otherwise
		 */
		virtual bool setKey(const string& key){ return false;  }

		/**	
		 * Encrypts a plaintext string
		 * @param plaintext - the plaintext string
		 * @return - the encrypted ciphertext string
		 */
		virtual string encrypt(const string& plaintext){ return ""; }

		/**
		 * Decrypts a string of ciphertext
		 * @param ciphertext - the ciphertext
		 * @return - the plaintext
		 */
		virtual string decrypt(const string& ciphertext) { return ""; }

		/* The protected members */
	protected:
	
};

#endif
