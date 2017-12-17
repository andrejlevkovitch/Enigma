//enigmalib.h

#define EOF_DOP 4
#define N_ROTORS 3
#define STR_RV 1
#define STR_TXT 3
#define LEFT 'l'
#define RIGHT 'r'
#define N_LETTERS 26

#define STP_MECH_1 'R'
#define STP_MECH_2 'F'
#define STP_MECH_3 'W'

char rotor_1 (char, char);

char rotor_2 (char, char);

char rotor_3 (char, char);

char *inputRV (void);

void ramka (void);

char reflector_B (char);

void rotor_tools (char *);

char rotor_crypt (char, char *);
