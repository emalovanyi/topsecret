# Top Secret
<h3><strong>Implementation of the project</strong></h3>
The main goal of this work was learn the basics of dynamic memory management (allocation and deallocation). And also to learn how to work with bitwise operators and C language operations.<br>

# The Playfair cipher
The principle of the <strong>Playfair cipher</strong> is to split the text into pairs of characters. If both characters are pairs:
<ul>
  <li>on the same row of a 5x5 matrix, they are replaced by the letters to the right of them;</li>
  <li>in the same column of a 5x5 matrix, they are replaced by the letters below them;</li>
  <li>on different rows and columns of a 5x5 matrix, they are replaced by the letters at the intersections of the given columns and rows.</li>
</ul>
<strong>const char* text</strong> - a reference to a string that represents the text to encrypt. This text can consist of letters only, case-insensitive, or a space character. No other characters are allowed (they cannot be encrypted).<br>
<strong>const char* key</strong> - a reference to a string that represents the key that will be used to encrypt the text. The key is represented by a case-insensitive text. Individual letters cannot be repeated in the key (if they are, ensure that duplicates are removed in your implementation). Spaces in the key are ignored.<br>
<h3><strong>Functions Call Example</strong></h3>

```c
char *encrypted, *decrypted;

// even length of string
encrypted = playfair_encrypt("SeCReT", "Hello world");
printf("%s", encrypted);
// "Hello world" --> "HELXLOVORLDX"
// IS JZ JQ XN TK JC
decrypted = playfair_decrypt("SeCReT", encrypted);
printf("%s", decrypted);
// HELXLOVORLDX
free(encrypted);
free(decrypted);

// odd length of string
encrypted = playfair_encrypt("world", "Hello");
printf("%s", encrypted);
// "Hello" --> "HELXLO"
// JB RY DR
decrypted = playfair_decrypt("world", encrypted);
printf("%s", decrypted);
// HELXLO
free(encrypted);
free(decrypted);

// letter 'X' in message
encrypted = playfair_encrypt("Password", "Taxi please");
printf("%s", encrypted);
// "Taxi please" --> "TAXIPLEASE"
// UP YH AK DO OB
decrypted = playfair_decrypt("Password", encrypted);
printf("%s", decrypted);
// TAXIPLEASE
free(encrypted);
free(decrypted);

// multi 'X's in message
encrypted = playfair_encrypt("please", "Taxxxiii");
printf("%s", encrypted);
// "Taxxxiii" --> "TAXXXIIXIX"
// RS EE VJ JV JV
decrypted = playfair_decrypt("please", encrypted);
printf("%s", decrypted);
// TAXXXIIXIX
free(encrypted);
free(decrypted);
```
# Reverse
Your task is to create a function that returns a <strong>copy of the input string</strong> in reverse order with <strong>UPPERCASE letters</strong>.
<h3><strong>Functions Call Example</strong><br></h3>

```c
char* reversed = reverse("Hello world!");
printf("%s\n", reversed);
// "!DLROW OLLEH"
```
# The Vigenère cipher
The Vigenère cipher is an extension of the <strong>Caesar</strong> cipher in terms of the key that will be used in encryption and decryption.<br>
<strong>The meaning of the individual function parameters is as follows:</strong>
<ul>
  <li><strong>key</strong> - a string representing the key used to encrypt and decrypt the text. The key is represented as a single word and can only consist of characters of the alphabet, case-insensitive.</li>
  <li><strong>text</strong> - a string used for encryption and decryption, respectively.</li>
</ul>
<h3><strong>Functions Call Example</strong><br></h3>

```c
char* encrypted;

// basic test with long text
encrypted = vigenere_encrypt("CoMPuTeR", "Hello world!");
printf("%s\n", encrypted);
// "JSXAI PSINR!"
```
# Bit chaos
When encrypting, do the following: divide the character to be encrypted in half <strong>(4 bits + 4 bits)</strong>. Then divide the bits in the first half into pairs and swap the values in the pair with each other. Use the four bits thus created for the XOR operation on the remaining <strong>4 bits</strong>.<br>
Your task is to create functions with which you will be able to <strong>encrypt</strong> and <strong>decrypt</strong> the specified sequence of bytes.
<h3><strong>Functions Call Example</strong><br></h3>

```c
unsigned char* encrypted;

// basic test with long text
encrypted = bit_encrypt("Hello world!");
for(int i=0; i < 12;i++) {
    printf("%x ", encrypted[i]);
    //80 9c 95 95 96 11 bc 96 b9 95 9d 10
}
free(encrypted);
```
# BMP code
To <strong>encrypt</strong> the string, do the following:
<ul>
  <li>first, reverse() the input string with the reverse() function.</li>
  <li>then hash the resulting string with the vigenere_encrypt() function.</li>
  <li>further hash the resulting string with the bit_encrypt function.</li>
</ul>
To <strong>decrypt</strong> the specified sequence of bytes, do exactly the opposite.<br>
Your task is to create functions to <strong>encode</strong> and <strong>decode</strong> the text using the BMP cipher.<br>
The meaning of the individual function parameters is as follows:
<ul>
  <li>key - a string representing the key used to <strong>encrypt</strong> and <strong>decrypt</strong> the text. The key can consist of characters only, and the size does not matter.</li>
  <li>text - a string used for <strong>encryption</strong> and <strong>decryption</strong>, respectively.</li>
</ul>
<h3><strong>Functions Call Example</strong><br></h3>

```c
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
```
