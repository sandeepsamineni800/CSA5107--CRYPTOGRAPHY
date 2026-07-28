#include <stdio.h>
#include <ctype.h>

int main() {
    char plain[] = "abcdefghijklmnopqrstuvwxyz";
    char cipher[] = "cipherabdfgjklmnoqstuvwxyz";
    char text[100];

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);

    printf("Ciphertext: ");
    for (int i = 0; text[i]; i++) {
        if (isalpha(text[i])) {
            if (islower(text[i]))
                printf("%c", cipher[text[i] - 'a']);
            else
                printf("%c", toupper(cipher[text[i] - 'A']));
        } else
            printf("%c", text[i]);
    }

    return 0;
}