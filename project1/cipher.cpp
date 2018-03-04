#include <iostream>
#include <string>
#include <fstream>
#include "CipherInterface.h"
#include "Playfair.h"
#include "Vigenere.h"
#include "Railfence.h"
#include "Caesar.h"

using namespace std;

int main(int argc, char** argv)
{
	 string plf = "PLF";
	 string ces = "CES";
	 string rts = "RTS";
	 string vig = "VIG";
	 string rfc = "RFC";
	 string enc = "ENC";
	 string dec = "DEC";
	 string current_cipher = argv[1];
	 string current_key = argv[2];
	 string current_op = argv[3];
	 string in = argv[4];
	 string out = argv[5];
	 ofstream outfile;
	 string plaintext, ciphertext;
	 fstream infile(argv[4], fstream::in);

	 // check arguments
	 cout << "**************\n";
	 cout << "cipher: " << argv[1] << endl;
	 cout << "key: " << argv[2] << endl;
	 cout << "ENC/DEC: " << argv[3] << endl;
	 cout << "input file: " << argv[4] << endl;
	 cout << "output file: " << argv[5] << endl;

		// read the plaintext
		getline(infile, plaintext, '\0');

		//getline(infile, plaintext);
		cout << "plaintext: " << plaintext << endl;
		cout << "**************\n" << endl;

		// close the input file
		infile.close();

		// open output file
		outfile.open(out);

		// create the ciphers
		CipherInterface* cipher;

		if(argc < 6)
		{
			cout << "incorrect execution: \n";
			cout << "correct: ./cipher <CIPHER NAME> <KEY> <ENC/DEC> ";
			cout << "<INPUT FILE> <OUTPUT FILE>\n";
			cout << "valid ciphers: PLF (playfair), RTS (row transposition), ";
			cout << "RFC (railfence), VIG (vigenre), CES (caesar)\n";
		}
		else if(current_cipher.compare(plf) == 0)
		{
			/* Create an instance of the Playfair cipher */
			cipher = new Playfair();

		}
		else if(current_cipher.compare(ces) == 0)
		{
				/* Create an instance of the Caesar cipher */
				cipher = new Caesar();

		}
		else if(current_cipher.compare(rfc) == 0)
		{
			/* Create an instance of the Railfence cipher */
			cipher = new Railfence();

		}
		else if(current_cipher.compare(vig) == 0)
		{
				/* Create an instance of the viginere cipher */
				cipher = new Vigenere();

		}
		else if(current_cipher.compare(rts) == 0)
		{
				/* Create an instance of the row transposition cipher */
				// STILL HAS TO BE WRITTEN
		}
		else
		{
			// if cipher cannot be found
			cout << "Non-valid choice of cipher\n" << endl;
		}

		/* Error checks */
		if(!cipher)
		{
			fprintf(stderr, "ERROR [%s %s %d]: could not allocate memory\n",
			__FILE__, __FUNCTION__, __LINE__);
			exit(-1);
		}
		else	// the fun stuff
		{
			/* Set the encryption key */
			cipher->setKey(argv[2]);

			if(current_op.compare(enc) == 0)
			{
				/* Perform encryption */
				ciphertext = cipher->encrypt(plaintext);
				cout << "ENCRYPT: " << endl << ciphertext << endl << endl;
				outfile << ciphertext;
				outfile.close();
			}
			else if(current_op.compare(dec) == 0)
			{
				/* Perform decryption */
				string originaltext = cipher->decrypt(plaintext);
				cout << "DECRYPT: " << endl << originaltext << endl << endl;
				outfile << originaltext;
				outfile.close();
			}
			else
			{
				cout << "Invalid operation: must be ENC/DEC for encrypt/decrypt\n";
			}
		}

	//system("pause");
	return 0;
}
