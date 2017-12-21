# Makefile for Enigma

enigma: libenigma.so
	gcc -o enigma -L. -lenigma -Wl,-rpath,. -lncurses -Wall

libenigma.so: main.o input_rotor_values.o ramka.o rotor_tools.o rotor_crypt.o kom_panel.o init_rotor.o free_rotor.o init_blokR.o input_KP.o rotor_cikle.o
	gcc -shared -o libenigma.so main.o input_rotor_values.o ramka.o rotor_tools.o rotor_crypt.o kom_panel.o init_rotor.o free_rotor.o init_blokR.o input_KP.o rotor_cikle.o -Wall

main.o: main.c
	gcc -c -fPIC main.c -Wall

input_rotor_values.o: input_rotor_values.c
	gcc -c -fPIC input_rotor_values.c -Wall

ramka.o: ramka.c
	gcc -c -fPIC ramka.c -Wall

rotor_tools.o: rotor_tools.c
	gcc -c -fPIC rotor_tools.c -Wall

rotor_crypt.o: rotor_crypt.c
	gcc -c -fPIC rotor_crypt.c -Wall

kom_panel.o: kom_panel.c
	gcc -c -fPIC kom_panel.c -Wall

init_rotor.o: init_rotor.c
	gcc -c -fPIC init_rotor.c -Wall

free_rotor.o: free_rotor.c
	gcc -c -fPIC free_rotor.c -Wall

init_blokR.o: init_blokR.c
	gcc -c -fPIC init_blokR.c -Wall

input_KP.o: input_KP.c
	gcc -c -fPIC input_KP.c -Wall

rotor_cikle.o: rotor_cikle.c
	gcc -c -fPIC rotor_cikle.c -Wall

clean:
	rm -f *.o *.so enigma

#install: enigma libenigma.so
#	sudo install libenigma.so /usr/lib
#	sudo install ./enigma /usr/local/bin

#uninstall:
#	sudo rm -rf /usr/lib/libenigma.so
#	sudo rm -rf /usr/local/bin/enigma
