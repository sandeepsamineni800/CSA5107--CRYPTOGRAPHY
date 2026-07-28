#include <stdio.h>
#include <string.h>

char key[5][5]={
{'M','F','H','I','K'},
{'U','N','O','P','Q'},
{'Z','V','W','X','Y'},
{'E','L','A','R','G'},
{'D','S','T','B','C'}
};

void find(char c,int *r,int *col){
    if(c=='J') c='I';
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            if(key[i][j]==c){
                *r=i;
                *col=j;
            }
}

int main(){
    char ct[200];
    int r1,c1,r2,c2;

    printf("Enter Ciphertext: ");
    fgets(ct,200,stdin);

    printf("Plaintext: ");

    for(int i=0;ct[i]&&ct[i+1];i+=2){
        if(ct[i]==' '){i--; continue;}

        find(ct[i],&r1,&c1);
        find(ct[i+1],&r2,&c2);

        if(r1==r2){
            printf("%c%c",key[r1][(c1+4)%5],key[r2][(c2+4)%5]);
        }
        else if(c1==c2){
            printf("%c%c",key[(r1+4)%5][c1],key[(r2+4)%5][c2]);
        }
        else{
            printf("%c%c",key[r1][c2],key[r2][c1]);
        }
    }
}