# Makefile for Enigma

enigma: main.o libenigma.so
	gcc -o enigma main.o -L. -lenigma -Wl,-rpath,. -Wall

main.o: main.c
	gcc -c main.c -Wall

libenigma.so: sort_fun.o
	gcc -shared -o libenigma.so sort_fun.o -Wall

sort_fun.o: sort_fun.c
	gcc -c -fPIC sort_fun.c -Wall

clean:
	rm *.o *.so enigma

#install: enigma libenigma.so
#	sudo install libenigma.so /usr/lib
#	sudo install ./enigma /usr/local/bin

#uninstall:
#	sudo rm -rf /usr/lib/libenigma.so
#	sudo rm -rf /usr/local/bin/enigma
