#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "bmp.h"

//second_function
char* reverse(const char* text){

    if(text == NULL){
		return NULL;
	}

    int a;
    int txt = (int)strlen(text);
	char* rev_text = (char*)calloc(txt + 1, sizeof(char));

	for(a = 0; a < txt; a++){
		rev_text[a] = (char)toupper(text[txt - a - 1]);
	}
	rev_text[txt] = '\0';

	return rev_text;
}
//second_function

//third_function
char* vigenere_encrypt(const char* key, const char* text){

    if(key == NULL || text == NULL){
        return NULL;
    }

    for(int c = 0; c < strlen(key); c++){
        if(!isalpha(key[c])){
            return NULL;
        }
    }

    int a = 0;
    int b = 0;
    int letter;
    int txt = strlen(text);
    int kluch = strlen(key);
    char* enc_txt = (char*)malloc((1 + sizeof(char)) * txt);

	while(*text){
		if(!isalpha(*text)){
			enc_txt[b] = *text;
		}
		else{
			char alph = toupper(key[a % kluch]) - 'A';
			letter = isupper(text[a]) ? 'A' : 'A';
			enc_txt[b] = letter + ((toupper(*text) - letter + alph) % 26);
			a++;
		}
		b++;
		text++;
	}
	enc_txt[b] = '\0';

	return enc_txt;
}
//third_function

//fourth_function
char* vigenere_decrypt(const char* key, const char* text){

    if(key == NULL || text == NULL){
        return NULL;
    }

    for(int c = 0; c < strlen(key); c++){
        if(!isalpha(key[c])){
            return NULL;
        }
    }

    int a = 0;
    int b = 0;
    int letter;
    int txt = strlen(text);
    int kluch = strlen(key);
    char* dec_txt = (char*)malloc((1 + sizeof(char)) * txt);

	while(*text){
		if(!isalpha(*text)){
			dec_txt[b] = *text;
		}
		else{
			char alph = toupper(key[a % kluch]);
			letter = isupper(text[a]) ? 'A' : 'A';
			dec_txt[b] = letter + (((toupper(*text) - alph) + 26) % 26);
			a++;
		}
		b++;
		text++;
	}
	dec_txt[b] = '\0';

	return dec_txt;
}
//fourth_function

//fifth_function
unsigned char* bit_encrypt(const char* text){

    if(text == NULL){
        return NULL;
    }

    int a;
    int b;
    int c;
    int g;
    int j;
    int f;
    int txt = strlen(text);
    int encrypts[txt + 1][8];
    unsigned char* bitenc = calloc(txt + 1, sizeof(char));
    int i = text[txt];
    int dodatkova1, dodatkova2;

    for(a = 0; a < txt; a++){
        for(b = 0; b < 8; b++){
            encrypts[a][b] = (text[a] >> (7 - b)) & 1;
        }
    }

    for(c = 0; c < 8; c++){
        encrypts[txt][c] = (i >> (7 - c)) & 1;
    }

    for(g = 0; g < txt; g++){
        dodatkova1 = encrypts[g][0];
        dodatkova2 = encrypts[g][1];
        encrypts[g][0] = dodatkova2;
        encrypts[g][1] = dodatkova1;
        dodatkova1 = encrypts[g][2];
        dodatkova2 = encrypts[g][3];
        encrypts[g][2] = dodatkova2;
        encrypts[g][3] = dodatkova1;
    }

    for(g = 0; g < txt; g++){
        for(j = 0; j < 4; j++){
            encrypts[g][j+4] = encrypts[g][j+4] ^ encrypts[g][j];
        }
    }

    for(f = 0; f < txt; f++){
        bitenc[f] = 0;
    }

    /*memset(bitenc, 0, sizeof(bitenc));*/

    for(f = 0; f < txt; f++){
        bitenc[f] = 0;
        for(i = 0; i <= 7 ; i++){
            bitenc[f] |= encrypts[f][i] << (7 - i);
        }
    }

    return bitenc;
}
//fifth_function

//sixth_function
char* bit_decrypt(const unsigned char* text){

    if(text == NULL){
        return NULL;
    }

    int a;
    int b;
    int c;
    int g;
    int j;
    int f;
    int txt_1 = strlen((const char*)text);
    int encrypts_1[txt_1 + 1][8];
    char* bitenc_1 = calloc(txt_1 + 1, sizeof(char));
    int i = text[txt_1];
    int dodatkova1, dodatkova2;

    for(a = 0; a < txt_1; a++){
        for(b = 0; b < 8; b++){
            encrypts_1[a][b] = (text[a] >> (7 - b)) & 1;
        }
    }

    for(c = 0; c < 8; c++){
        encrypts_1[txt_1][c] = (i >> (7 - c)) & 1;
    }

    for(g = 0; g < txt_1; g++){
        for(j = 0; j < 4; j++){
            encrypts_1[g][j+4] = encrypts_1[g][j+4] ^ encrypts_1[g][j];
        }
    }

    for(g = 0; g < txt_1; g++){
        dodatkova1 = encrypts_1[g][0];
        dodatkova2 = encrypts_1[g][1];
        encrypts_1[g][0] = dodatkova2;
        encrypts_1[g][1] = dodatkova1;
        dodatkova1 = encrypts_1[g][2];
        dodatkova2 = encrypts_1[g][3];
        encrypts_1[g][2] = dodatkova2;
        encrypts_1[g][3] = dodatkova1;
    }

    for(f = 0; f < txt_1; f++){
        bitenc_1[f] = 0;
    }

    /*memset(bitenc, 0, sizeof(bitenc));*/

    for(f = 0; f < txt_1; f++){
        bitenc_1[f] = 0;
        for(i = 0; i <= 7 ; i++){
            bitenc_1[f] |= encrypts_1[f][i] << (7 - i);
        }
    }

    return bitenc_1;
}
//sixth_function

//seventh_function
unsigned char* bmp_encrypt(const char* key, const char* text){

    if(key == NULL || text == NULL){
        return NULL;
    }

	for(int c = 0; c < strlen(key); c++){
		if(!isalpha(key[c]))
			return NULL;
	}

    int a;
    int kluch_2 = strlen(key);
    char* rev_text_1;
    char* enc_txt_1;
    unsigned char* bitenc_1;

	for(a = 0; a < kluch_2; a++){
        if(strspn(key, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") != kluch_2){
            return NULL;
        }
	}

	rev_text_1 = reverse(text);
	enc_txt_1 = vigenere_encrypt(key, rev_text_1);
	bitenc_1 = bit_encrypt(enc_txt_1);
	free(rev_text_1);
	free(enc_txt_1);

	return bitenc_1;
}
//seventh_function

//eight_function
char* bmp_decrypt(const char* key, const unsigned char* text){

    if(key == NULL || text == NULL){
        return NULL;
    }

	for(int c = 0; c < strlen(key); c++){
		if(!isalpha(key[c]))
			return NULL;
	}

    int a;
    int kluch_3 = strlen(key);
    char* bitdec_1;
    char* dec_txt_1;
    char* rev_txt_2;

	for(a = 0; a < kluch_3; a++){
        if(strspn(key, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") != kluch_3){
            return NULL;
        }
	}

	bitdec_1 = bit_decrypt(text);
	dec_txt_1 = vigenere_decrypt(key,bitdec_1);
	rev_txt_2 = reverse(dec_txt_1);
	free(dec_txt_1);
	free(bitdec_1);

	return rev_txt_2;
}
//eight_function

int main(){
    const char* text = "Hello world i am talking to you";
char* reversed = reverse(text);
    printf("%s\n", reversed);
    free(reversed);
}
