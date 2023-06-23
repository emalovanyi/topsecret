#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "playfair.h"

//first_function
char* playfair_encrypt(const char* key, const char* text){
    if(key == NULL || text == NULL || strlen(key) == 0 || strlen(text) == 0){
        return NULL;
    }

    for(int i = 0; i < strlen(text); i++){
        if(text[i] == 'W'){
            return NULL;
        }
    }

    for(int i = 0; i < strlen(key); i++){
        if(!isalpha(key[i]) && key[i] != ' '){
            return NULL;
        }
    }

    if(key[0] == ' '){
        return NULL;
    }

    int txt = strlen(text);
    int i = 0;
    char* play_enc = calloc(txt + 1 - i, sizeof(char));

    return play_enc;

}
//first_function

//second_function
char* playfair_decrypt(const char* key, const char* text){
	if(key == NULL || text == NULL || strlen(key) == 0 || strlen(text) == 0){
        return NULL;
    }

    for(int i = 0; i < strlen(text); i++){
        if(text[i] == 'W'){
            return NULL;
        }
    }

    for(int i = 0; i < strlen(key); i++){
        if(!isalpha(key[i]) && key[i] != ' '){
            return NULL;
        }
    }

    if(key[0] == ' '){
        return NULL;
    }

	int txt_1 = strlen(text);
    int i = 0;
    char* play_dec = calloc(txt_1 + 1 - i, sizeof(char));

    return play_dec;

}
//second_function
