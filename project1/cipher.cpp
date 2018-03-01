
#include <string>
#include "CipherInterface.h"
#include "Playfair.h"
#include "Vigenere.h"
#include "Railfence.h"


// ./cipher <CIPHER NAME> <KEY> <ENC/DEC> <INPUT FILE> <OUTPUT FILE> 
/*Valid names
 * PLF (playfair), RTS (row transposition), RFC (railfence), VIG (vigenre), CES (caesar)
 * 
 * 
*/

using namespace std;

int main(int argc, char** argv)
{
	
	/* REPLACE THIS PART WITH YOUR CODE 
	 * THE CODE BELOW IS A SAMPLE TO 
	 * ILLUSTRATE INSTANTIATION OF CLASSES
	 * THAT USE THE SAME INTERFACE.
	 */	
		

	/* Create an instance of the Playfair cipher */	
	//CipherInterface* cipher = new Playfair();
	CipherInterface* cipher = new Railfence();
	//put some if else here ^^


	/* Error checks */
	if(!cipher)
	{
		fprintf(stderr, "ERROR [%s %s %d]: could not allocate memory\n",	
		__FILE__, __FUNCTION__, __LINE__);
		exit(-1);
	}
	
	/* Set the encryption key */
	cipher->setKey("2");
	
	/* Perform encryption */
	string cipherText = cipher->encrypt("helloworld");
	cout << cipherText;
	
	/* Perform decryption */
	cipher->decrypt(cipherText);	
	
	system("pause");
	return 0;
}
