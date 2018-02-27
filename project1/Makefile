all:	cipher

cipher:	cipher.o Playfair.o Vigenere.o
	g++ cipher.o Playfair.o Vigenere.o -o cipher

cipher.o:	cipher.cpp
	g++ -g -c cipher.cpp 

Playfair.o:	Playfair.cpp Playfair.h CipherInterface.h
	g++ -g -c Playfair.cpp
	
Vigenere.o: Vigenere.cpp Vigenere.h CipherInterface.h
	g++ -g -c Vigenere.cpp

# Uncomment this code once you add the appropriate files
#RowTransposition.o:	RowTransposition.cpp RowTransposition.h
#	g++ -g -c RowTransposition.cpp

clean:
	rm -rf *.o cipher
