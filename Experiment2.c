#include<stdio.h>
int main(){
    char text[100];
    char key[]="QWERTYUIOPASDFGHJKLZXCVBNM";
    printf("Enter the Plain text: ");
    scanf("%s", text);
    printf("Cipher Text: ");
    for(int i=0; text[i]!='\0'; i++){
        printf("%c", key[text[i]-'A']);
    }
    return 0;
}