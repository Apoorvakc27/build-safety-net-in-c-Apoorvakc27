#ifndef SOUNDEX_H
#define SOUNDEX_H

/* Lookup table for Soundex codes for 'A' to 'Z' */
char soundexMap[26] = {
    '0', '1', '2', '3', '0', '1', '2', '0', '0', '2', // A-J
    '2', '4', '5', '5', '0', '1', '2', '6', '2', '3', // K-T
    '0', '1', '0', '2', '0', '2'                      // U-Z
};

char toUpperCase(char c) {
    return toupper(c);
}
void initializeSoundex(const char *name, char *soundex, int *sIndex) {
    soundex[0] = toUpperCase(name[0]);  
    *sIndex = 1;  /* Initialize the index to the second character */
}

/* Function to generate the Soundex code */
void generateSoundex(const char *name, char *soundex) {
    int len = strlen(name);
    int sIndex = 1;
     initializeSoundex(name, soundex, &sIndex);  
}



#endif // SOUNDEX_H
