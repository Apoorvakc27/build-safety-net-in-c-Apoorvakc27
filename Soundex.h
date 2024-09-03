#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <ctype.h>
#include <string.h>

// Lookup table for Soundex codes for 'A' to 'Z'.
char soundexMap[26] = {
    '0', '1', '2', '3', '0', '1', '2', '0', '0', '2', // A-J
    '2', '4', '5', '5', '0', '1', '2', '6', '2', '3', // K-T
    '0', '1', '0', '2', '0', '2'                      // U-Z
};

// Helper function to check if a character is an uppercase letter
int isUpperCaseLetter(char c) {
    return c >= 'A' && c <= 'Z';
}

// Helper function to convert character to uppercase
char toUpperCase(char c) {
    return toupper(c);
}

// Function to get Soundex code from the lookup table
char getSoundexCode(char c) {
    c = toUpperCase(c);
    if (isUpperCaseLetter(c)) {
        return soundexMap[c - 'A'];  // Return mapped code from lookup table
    }
    return '0'; // For non-alphabet characters
}

// Helper function to check if the code is valid to add
int isValidCode(char code, char previousCode) {
    return code != '0' && code != previousCode;
}

// Helper function to add a character to the Soundex code, if valid
void addToSoundex(char *soundex, char code, int *sIndex) {
    if (isValidCode(code, soundex[*sIndex - 1])) {
        soundex[(*sIndex)++] = code;
    }
}

// Helper function to initialize Soundex code
void initializeSoundex(const char *name, char *soundex, int *sIndex) {
    soundex[0] = toUpperCase(name[0]);  // Start with the first letter capitalized
    *sIndex = 1;  // Initialize the index to the second character
}

// Helper function to pad remaining characters with '0'
void padSoundex(char *soundex, int *sIndex) {
    while (*sIndex < 4) {
        soundex[(*sIndex)++] = '0';
    }
    soundex[4] = '\0';  // Null-terminate the Soundex code
}

// Helper function to process a single character and update Soundex
void processCharacter(const char *name, int *i, int len, int *sIndex, char *soundex) {
    if (*i < len) {  // Single decision point for processing a character
        char code = getSoundexCode(name[*i]);
        addToSoundex(soundex, code, sIndex);  // Add valid code to Soundex
        (*i)++;  // Increment index
    }
}

// Helper function to ensure Soundex code is of length 4
void ensureSoundexLength(char *soundex, int *sIndex) {
    while (*sIndex < 4) {  // Loop until Soundex code reaches the required length
        padSoundex(soundex, sIndex);  // Pad with '0's to make it of length 4
    }
}

// Function to generate the Soundex code
void generateSoundex(const char *name, char *soundex) {
    int len = strlen(name);
    int sIndex = 0;  // Index to keep track of Soundex code position

    initializeSoundex(name, soundex, &sIndex);  // Initialize Soundex with first character

    int i = 1;  // Start from the second character of the input

    // First loop: Process characters until the end of the name
    while (i < len) {  // Loop until end of name
        if (sIndex >= 4) {  // Check if Soundex is complete
            break;  // Exit the loop if Soundex code has reached the required length
        }
        processCharacter(name, &i, len, &sIndex, soundex);  // Process each character
    }

    // Call the new function to ensure the length of Soundex code
    ensureSoundexLength(soundex, &sIndex);
}


#endif // SOUNDEX_H
