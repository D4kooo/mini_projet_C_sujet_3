all: chiffrement.exe

chiffrement.exe: main.o cesar.o vigenere.o
	gcc -o chiffrement.exe main.o cesar.o vigenere.o

main.o: main.c cesar.h vigenere.h
	gcc -c main.c

cesar.o: cesar.c cesar.h
	gcc -c cesar.c

vigenere.o: vigenere.c vigenere.h
	gcc -c vigenere.c

clean:
	rm -f chiffrement.exe *.o
