# Makefile for Enigma

enigma: libenigma.so
	gcc -o enigma -L. -lenigma -Wl,-rpath,. -lncurses -Wall

libenigma.so: main.o rotor_1.o rotor_2.o rotor_3.o input_rotor_values.o ramka.o reflector_B.o rotor_tools.o rotor_crypt.o
	gcc -shared -o libenigma.so main.o rotor_1.o rotor_2.o rotor_3.o input_rotor_values.o ramka.o reflector_B.o rotor_tools.o rotor_crypt.o -Wall

main.o: main.c
	gcc -c -fPIC main.c -Wall

rotor_1.o: rotor_1.c
	gcc -c -fPIC rotor_1.c -Wall

rotor_2.o: rotor_2.c
	gcc -c -fPIC rotor_2.c -Wall

rotor_3.o: rotor_3.c
	gcc -c -fPIC rotor_3.c -Wall

input_rotor_values.o: input_rotor_values.c
	gcc -c -fPIC input_rotor_values.c -Wall

ramka.o: ramka.c
	gcc -c -fPIC ramka.c -Wall

reflector_B.o: reflector_B.c
	gcc -c -fPIC reflector_B.c -Wall

rotor_tools.o: rotor_tools.c
	gcc -c -fPIC rotor_tools.c -Wall

rotor_crypt.o: rotor_crypt.c
	gcc -c -fPIC rotor_crypt.c -Wall

clean:
	rm -f *.o *.so enigma

#install: enigma libenigma.so
#	sudo install libenigma.so /usr/lib
#	sudo install ./enigma /usr/local/bin

#uninstall:
#	sudo rm -rf /usr/lib/libenigma.so
#	sudo rm -rf /usr/local/bin/enigma
