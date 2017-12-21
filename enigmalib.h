//enigmalib.h

#define EOF_DOP ''

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
#define PERMUTATION_RB "YRUHQSLDPXNGOKMIEBFZCWVJAT"

#define ALFABETO "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

#ifdef linux
    #define ESC 27
    #define RIGHT 67
    #define LEFT 68
    #define UP 65
    #define DOWN 66
#else
    #define ESC 224
    #define RIGHT 77
    #define LEFT 75
    #define UP 72
    #define DOWN 80
#endif

struct rotor {
    struct rotor *prev;
    struct rotor *next;
    int number;
    int cur_position;
    char letter;
    struct rotor *input;
    struct rotor *output;
};

struct blok_R {
    struct rotor *rotor_1;
    struct rotor *rotor_2;
    struct rotor *rotor_3;
    struct rotor *reflektor_B;
};

int inputRV (struct blok_R *);

void ramka (struct blok_R *);

char reflector_B (char);

void rotor_tools (struct blok_R *);

char rotor_crypt (char, struct blok_R *);

char kom_panel (char, char*, char);

struct rotor *init_rotor (char, char*);

int free_rotor (struct rotor *);

struct blok_R *init_blokR (void);

char *input_KP (void);

void rotor_cikle (struct rotor *, char);

int mygetch (void);
