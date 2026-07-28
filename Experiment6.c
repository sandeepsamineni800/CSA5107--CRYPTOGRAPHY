#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char cipher[1000];

    printf("Enter Ciphertext: ");
    fgets(cipher, sizeof(cipher), stdin);

    int a_inv = 9;   // Inverse of 3 mod 26
    int b = 15;

    printf("Recovered Plaintext: ");

    for (int i = 0; cipher[i] != '\0'; i++) {
        if (isupper(cipher[i])) {
            int c = cipher[i] - 'A';
            int p = (a_inv * (c - b + 26)) % 26;
            printf("%c", p + 'A');
        }
        else if (islower(cipher[i])) {
            int c = cipher[i] - 'a';
            int p = (a_inv * (c - b + 26)) % 26;
            printf("%c", p + 'a');
        }
        else {
            printf("%c", cipher[i]);
        }
    }

    return 0;
}