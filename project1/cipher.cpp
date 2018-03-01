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
	/* REPLACE THIS PART WITH YOUR CODE
	 * THE CODE BELOW IS A SAMPLE TO
	 * ILLUSTRATE INSTANTIATION OF CLASSES
	 * THAT USE THE SAME INTERFACE.
	 */

	 // parse command line arguments
	 // ./cipher <CIPHER NAME> <KEY> <ENC/DEC> <INPUT FILE> <OUTPUT FILE>
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
	 ifstream infile;
	 ofstream outfile;
	 string plaintext, ciphertext;

	 // check arguments
	 cout << "**************\n";
	 cout << "cipher: " << argv[1] << endl;
	 cout << "key: " << argv[2] << endl;
	 cout << "ENC/DEC: " << argv[3] << endl;
	 cout << "input file: " << argv[4] << endl;
	 cout << "output file: " << argv[5] << endl;

		// open the input files
		infile.open(in);

		// open output file
		outfile.open(out);

		// read the plaintext
		// DOES NOT ACCOUNT FOR LARGE.TXT WITh MULTIPLE LINES
		getline(infile, plaintext);
		cout << "plaintext: " << plaintext << endl;
		cout << "**************\n" << endl;

		// close the input file
		//infile.close();


	 // should check for 6 argv, for now just 4 - save in/out files for later
		if(argc < 5)
		{
			cout << "incorrect execution: \n";
			cout << "correct: ./cipher <CIPHER NAME> <KEY> <ENC/DEC> <INPUT FILE> <OUTPUT FILE>\n";
			cout << "valid ciphers: PLF (playfair), RTS (row transposition), RFC (railfence), VIG (vigenre), CES (caesar)\n";
		}
		else if(current_cipher.compare(plf) == 0)
		{
			/* Create an instance of the Playfair cipher */
			CipherInterface* cipher = new Playfair();

			/* Error checks */
			if(!cipher)
			{
				fprintf(stderr, "ERROR [%s %s %d]: could not allocate memory\n",
				__FILE__, __FUNCTION__, __LINE__);
				exit(-1);
			}

			/* Set the encryption key */
			// check if valid key for playfair!!!!!!!
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
				string originaltext = cipher->decrypt(ciphertext);
				cout << "DECRYPT: " << endl << originaltext << endl << endl;
				outfile << originaltext;
				outfile.close();
			}
			else
			{
				cout << "Invalid operation: must be ENC/DEC for encrypt/decrypt\n";
			}
		}
		else if(current_cipher.compare(ces) == 0)
		{
				// code for caesar salad
				/* Create an instance of the Caesar cipher */
				CipherInterface* cipher = new Caesar();

				/* Error checks */
				if(!cipher)
				{
					fprintf(stderr, "ERROR [%s %s %d]: could not allocate memory\n",
					__FILE__, __FUNCTION__, __LINE__);
					exit(-1);
				}

				/* Set the encryption key */
				// check if valid key for caesar!!!!!!!
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
					string originaltext = cipher->decrypt(ciphertext);
					cout << "DECRYPT: " << endl << originaltext << endl << endl;
					outfile << originaltext;
					outfile.close();
				}
				else
				{
					cout << "Invalid operation: must be ENC/DEC for encrypt/decrypt\n";
				}
		}
		else if(current_cipher.compare(rfc) == 0)
		{
			/* Create an instance of the Railfence cipher */
			CipherInterface* cipher = new Railfence();

			/* Error checks */
			if(!cipher)
			{
				fprintf(stderr, "ERROR [%s %s %d]: could not allocate memory\n",
				__FILE__, __FUNCTION__, __LINE__);
				exit(-1);
			}

			/* Set the encryption key */
			// check if valid key for railfence!!!!!!!!
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
				string originaltext = cipher->decrypt(ciphertext);
				cout << "DECRYPT: " << endl << originaltext << endl << endl;
				outfile << originaltext;
				outfile.close();
			}
			else
			{
				cout << "Invalid operation: must be ENC/DEC for encrypt/decrypt\n";
			}
		}
		else if(current_cipher.compare(vig) == 0)
		{
				/* Create an instance of the viginere cipher */
				/* Create an instance of the Railfence cipher */
				CipherInterface* cipher = new Vigenere();

				/* Error checks */
				if(!cipher)
				{
					fprintf(stderr, "ERROR [%s %s %d]: could not allocate memory\n",
					__FILE__, __FUNCTION__, __LINE__);
					exit(-1);
				}

				/* Set the encryption key */
				// check if valid key for playfair!!!!!!!
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
					string originaltext = cipher->decrypt(ciphertext);
					cout << "DECRYPT: " << endl << originaltext << endl << endl;
					outfile << originaltext;
					outfile.close();
				}
				else
				{
					cout << "Invalid operation: must be ENC/DEC for encrypt/decrypt\n";
				}
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

	//system("pause");
	return 0;
}
