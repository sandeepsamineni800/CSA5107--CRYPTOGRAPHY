#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(){
    char text[100], key[100];

    printf("Enter Plain Text: ");
    scanf("%s", text);

    printf("Enter Key: ");
    scanf("%s", key);

    int len = strlen(key);

    printf("Encrypted Text: ");

    for(int i = 0; text[i] != '\0'; i++) {
        char ch = toupper(text[i]);
        char k = toupper(key[i % len]);

        if (isalpha(ch))
            printf("%c", ((ch - 'A' + k - 'A') % 26) + 'A');
        else
            printf("%c", ch);
    }

    return 0;
}