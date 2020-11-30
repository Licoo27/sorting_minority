#include <stdio.h>
#include <stdlib.h>

int e=0, i=0;
int CM[26] ={4,2,2,3,4,5,6,7,1,9,10,1,12,13,14,15,16,17,18,1,20,21,22,23,24,25,26,1} ;
int P[26] ={} ;
int SC[26] ={} ;
int S[26] ={} ;
int SM[26] ={} ;
int PC[26] ={} ;
int L[26] ={} ;
int PersCho[] ={} ;

int main()
{


    for (e=0; e<26; e++){
         if(CM[e] < CM[0])
            CM[0] = CM[e];
        }


    for(e=0; e<26; e++){
        if(CM[e] == CM[0]){
            PersCho[i-1] = e;
            i++;

        }
    }

    printf("%d", PersCho[1]);

    return 0;
}
