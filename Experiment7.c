#include <stdio.h>

int main() {
    char key[] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    char s[100];

    printf("Enter ciphertext: ");
    scanf("%s", s);

    for (int i = 0; s[i]; i++)
        if (s[i] >= 'A' && s[i] <= 'Z')
            printf("%c", 'A' + (strchr(key, s[i]) - key));
        else
            printf("%c", s[i]);

    return 0;
}