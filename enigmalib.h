//enigmalib.h

#define EOF_DOP 4

#define N_ROTORS 3

#define STR_RV 1
#define STR_KP 5
#define STR_TXT 11

#define IN 'l'
#define OUT 'r'
#define N_LETTERS 26

#define STP_MECH_1 'R'
#define STP_MECH_2 'F'
#define STP_MECH_3 'W'

#define PERMUTATION_R1 "USPAIBRCJEKMFLGDQVZNTOWYHX"
#define PERMUTATION_R2 "IRUXBLHWTMCQGZNPYFVOEAJDKS"
#define PERMUTATION_R3 "USQOBDFHJLCPRTXVZNYEIWGAKM"

#define ALFABETO "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

struct rotor {
    struct rotor *prev;
    struct rotor *next;
    int number;
    char letter;
    struct rotor *input;
    struct rotor *output;
};

struct blok_R {
    struct rotor *rotor_1;
    struct rotor *rotor_2;
    struct rotor *rotor_3;
};

void inputRV (struct blok_R*);

void ramka (void);

char reflector_B (char);

void rotor_tools (struct blok_R *);

char rotor_crypt (char, struct blok_R *);

char kom_panel (char, char*, char);

struct rotor *init_rotor (char, char*);

int free_rotor (struct rotor *rotor);

struct blok_R *init_blokR (void);

char *input_KP (void);
