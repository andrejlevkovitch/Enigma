# Makefile for Enigma

enigma: libenigma.so
	gcc -o enigma -L. -lenigma -Wl,-rpath,. -lncurses -Wall

libenigma.so: main.o input_rotor_values.o ramka.o reflector_B.o rotor_tools.o rotor_crypt.o kom_panel.o init_rotor.o free_rotor.o init_blokR.o input_KP.o
	gcc -shared -o libenigma.so main.o input_rotor_values.o ramka.o reflector_B.o rotor_tools.o rotor_crypt.o kom_panel.o init_rotor.o free_rotor.o init_blokR.o input_KP.o -Wall

main.o: main.c
	gcc -c -fPIC main.c -Wall

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

kom_panel.o: kom_panel.c
	gcc -c -fPIC kom_panel.c -Wall

1.o: 1.c
	gcc -c 1.c -Wall

init_rotor.o: init_rotor.c
	gcc -c -fPIC init_rotor.c -Wall

free_rotor.o: free_rotor.c
	gcc -c -fPIC free_rotor.c -Wall

init_blokR.o: init_blokR.c
	gcc -c -fPIC init_blokR.c -Wall

input_KP.o: input_KP.c
	gcc -c -fPIC input_KP.c -Wall

clean:
	rm -f *.o *.so enigma

#install: enigma libenigma.so
#	sudo install libenigma.so /usr/lib
#	sudo install ./enigma /usr/local/bin

#uninstall:
#	sudo rm -rf /usr/lib/libenigma.so
#	sudo rm -rf /usr/local/bin/enigma
