#include <stdio.h>
#include <ctype.h>

int gcd(int a, int b) {
    while (b) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    char text[100];
    int a, b;

    printf("Enter Plain Text: ");
    scanf("%s", text);

    printf("Enter a and b: ");
    scanf("%d%d", &a, &b);

    if (gcd(a, 26) != 1) {
        printf("Invalid value of a! (gcd(a,26) must be 1)\n");
        return 0;
    }

    printf("Encrypted Text: ");

    for (int i = 0; text[i]; i++) {
        char ch = toupper(text[i]);
        if (isalpha(ch))
            printf("%c", ((a * (ch - 'A') + b) % 26) + 'A');
        else
            printf("%c", ch);
    }

    return 0;
}