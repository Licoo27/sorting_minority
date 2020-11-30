#include <stdio.h>
#include <stdlib.h>

int CM[26] ={4,2,2,3,4,5,6,1,8,9,10,1,12,13,14,15,16,17,18,1,20,21,22,23,24,25,26} ;
int P[26] ={} ;
int SC[26] ={} ;
int S[26] ={} ;
int SM[26] ={} ;
int PC[26] ={} ;
int L[26] ={} ;

int fonction_tri (){
    int e=0, i=0;
    int table[26]={} ;
    int PersCho[] ={} ;

    for(e=0; e<26; e++){
         if(table[e] < table[0])
            table[0] = table[e];
    }

    for(e=0; e<26; e++){
        if(table[e] == table[0]){
                PersCho[i-1] = e;
                i++;
                return PersCho[i-1];
            }
        }

}

int main()
{
    int e=0;
    int PersCho[] = {};

    while(e<26){
        e++;
        PersCho[e] = fonction_tri(CM);
    }

    printf("%d", PersCho[0]);

    return 0;
}
