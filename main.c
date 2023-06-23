#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "playfair.h"
#include "bmp.h"

int main(){

    const char* text = "Hello world i am talking to you";
    const char* key = "CoMPuTeR";

    //reverse
    char* reversed = reverse(text);
    printf("%s\n", reversed);
    free(reversed);
    //reverse

    //vigenere_encrypt || vigenere_decrypt
    char* encrypted;
    encrypted = vigenere_encrypt(key, text);
    printf("%s\n", encrypted);

    char* decrypted;
    decrypted = vigenere_decrypt(key, encrypted);
    printf("%s\n", decrypted);
    //vigenere_encrypt || vigenere_decrypt

    //bit_encrypted || bit_decrypted
    unsigned char* bit_encrypted;
    bit_encrypted = bit_encrypt(text);
    for(int i=0; i < (int)strlen(text);i++) {
        printf("%x ", (unsigned char) bit_encrypted[i]);
    }
    printf("\n");

    char* bit_decrypted;
    bit_decrypted = bit_decrypt(bit_encrypted);
    for(int i=0; i < (int)strlen(text);i++) {
        printf("%c", (unsigned char) bit_decrypted[i]);
    }
    printf("\n");

    free(bit_decrypted);
    free(bit_encrypted);
    //bit_encrypted || bit_decrypted

    //bmp_encrypted || bmp_decrypted
    char* bmp_encrypted;
    bmp_encrypted = bmp_encrypt(key, text);
    for(int i=0; i<(int)strlen(text);i++) {
        printf("%x ", (unsigned char) bmp_encrypted[i]);
    }
    printf("\n");

    char* bmp_decrypted;
    bmp_decrypted = bmp_decrypt(key, bmp_encrypted);
    printf("%s", bmp_decrypted);
    printf("\n");

    free(bmp_encrypted);
    free(bmp_decrypted);
    //bmp_encrypted || bmp_decrypted

    //playfair_encrypted || playfair_decrypted

    //first check
    encrypted = playfair_encrypt("SeCReT", "Hello world");
    printf("%s", encrypted);
    printf("\n");
    decrypted = playfair_decrypt("SeCReT", encrypted);
    printf("%s", decrypted);
    printf("\n");
    //first check

    //second check
    encrypted = playfair_encrypt("world", "Hello");
    printf("%s", encrypted);
    printf("\n");
    decrypted = playfair_decrypt("world", encrypted);
    printf("%s", decrypted);
    printf("\n");
    //second check

    //third check
    encrypted = playfair_encrypt("Password", "Taxi please");
    printf("%s", encrypted);
    printf("\n");
    decrypted = playfair_decrypt("Password", encrypted);
    printf("%s", decrypted);
    printf("\n");
    //third check

    //fourth check
    encrypted = playfair_encrypt("please", "Taxxxiii");
    printf("%s", encrypted);
    printf("\n");
    decrypted = playfair_decrypt("please", encrypted);
    printf("%s", decrypted);
    printf("\n");
    //fourth check

    free(encrypted);
    free(decrypted);
    //playfair_encrypted || playfair_decrypted
}
