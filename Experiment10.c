#include <stdio.h>

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
    char pt[]="MUSTSEEYOUOVERCADOGANWESTCOMINGATONCE";
    int r1,c1,r2,c2;

    printf("Ciphertext: ");

    for(int i=0;pt[i];i+=2){
        find(pt[i],&r1,&c1);
        find(pt[i+1],&r2,&c2);

        if(r1==r2)
            printf("%c%c",key[r1][(c1+1)%5],key[r2][(c2+1)%5]);
        else if(c1==c2)
            printf("%c%c",key[(r1+1)%5][c1],key[(r2+1)%5][c2]);
        else
            printf("%c%c",key[r1][c2],key[r2][c1]);
    }
}