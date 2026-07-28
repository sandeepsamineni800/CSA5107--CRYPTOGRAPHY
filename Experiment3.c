#include <stdio.h>
#include <string.h>
#include <ctype.h>

char m[5][5];

void keyMatrix(char key[]) {
    int used[26] = {0}, k = 0;
    used['J' - 'A'] = 1;

    for (int i = 0; key[i]; i++) {
        char c = toupper(key[i]);
        if (c == 'J') c = 'I';
        if (!used[c - 'A']) {
            used[c - 'A'] = 1;
            m[k / 5][k % 5] = c;
            k++;
        }
    }

    for (char c = 'A'; c <= 'Z'; c++) {
        if (!used[c - 'A']) {
            m[k / 5][k % 5] = c;
            k++;
        }
    }
}

int main() {
    char key[20];

    printf("Enter Key: ");
    scanf("%s", key);

    keyMatrix(key);

    printf("\nPlayfair Matrix:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            printf("%c ", m[i][j]);
        printf("\n");
    }

    printf("\n(Note: Encryption is done by taking plaintext in pairs using Playfair rules.)");

    return 0;
}