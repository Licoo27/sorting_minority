#include <stdio.h>
#include <stdlib.h>

int CM[26] ={0,0,0,0,1,1,0,0,0,0,1,1,1,0,0,1,1,1,1,0,0,0,0,1,0,1} ;
int P[26] ={0,1,1,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,1,1,1,1,1,1,0,1} ;
int SC[26] ={0,0,0,1,0,0,0,1,0,0,1,1,1,0,0,1,1,2,0,1,0,0,0,1,1,0} ;
int S[26] ={0,0,1,0,1,0,0,1,0,1,0,1,1,0,0,1,0,0,0,1,0,0,1,0,1,1} ;
int SM[26] ={0,0,1,1,0,1,0,1,1,0,0,0,0,0,1,1,0,1,0,1,0,1,0,1,1,1} ;
int PC[26] ={0,0,1,0,0,0,0,1,1,0,0,0,0,1,1,0,1,1,2,0,0,1,0,0,0,0} ;
int L[26] ={0,0,0,0,0,0,2,0,0,0,1,0,1,1,1,0,0,0,1,0,1,0,0,1,0,1} ;

void fonction_tri (int PersCho[], int table[]){
    int e=0, i=0;
    int Mprece[26] = {0,0,1,0,0,0,0,1,0,0,0,0,1,0,1,0,0,1,0,1,0,0,0,0,1,0} ;

    for(e=0; e<26; e++){
         if(table[e] < table[0])
            table[0] = table[e];
    }

    for(e=0; e<26; e++){
        if(table[e] == table[0] && Mprece[e] == 0){
            PersCho[i-1] = e;
            i++;
        }
    }

    for(e=0; e<26;e++){
        if(PersCho[e] > PersCho[e-1] && PersCho[e]<=26 && PersCho[e]>0)
            printf("%d\n", PersCho[e]);

    }
}


int main()
{
    int PersCho[] = {};

    fonction_tri(PersCho, CM);


    return 0;
}
