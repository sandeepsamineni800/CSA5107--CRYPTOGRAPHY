#include <stdio.h>
#include <string.h>

int main() {
    char text[100];
    int k;

    printf("Enter text: ");
    scanf("%s", text);

    printf("Enter key (1-25): ");
    scanf("%d", &k);

    printf("Encrypted text: ");

    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z')
            printf("%c", (text[i] - 'A' + k) % 26 + 'A');
        else if (text[i] >= 'a' && text[i] <= 'z')
            printf("%c", (text[i] - 'a' + k) % 26 + 'a');
        else
            printf("%c", text[i]);
    }

    return 0;
}