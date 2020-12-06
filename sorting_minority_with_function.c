#include <stdio.h>
#include <stdlib.h>

int CM[26] ={4,2,2,3,4,5,6,1,8,1,10,1,12,13,14,15,16,17,18,1,20,21,22,23,24,25} ;
int P[26] ={1,1,2,3,4,5,6,7,8,1,10,11,12,13,14,1,1,17,18,17,20,21,22,23,1,1} ;
int SC[26] ={4,1,2,3,4,5,6,7,8,9,10,11,12,1,14,15,16,17,1,19,20,21,22,23,24,25} ;
int S[26] ={} ;
int SM[26] ={} ;
int PC[26] ={} ;
int L[26] ={} ;

void fonction_tri (int PersCho[], int table[]){
    int e=0, i=0;
    int Mprece[26] = {0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0} ;

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

    fonction_tri(PersCho, P);


    return 0;
}
