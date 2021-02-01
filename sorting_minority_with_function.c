#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define NB_STUDENT 26
#define NB_JOB 7

#define CM 0
#define P 1
#define SC 2
#define S 3
#define SM 4
#define PC 5
#define L 6



int arr[NB_JOB][NB_STUDENT] = {{0,0,0,1,1,0,0,0,0,1,1,2,0,0,1,1,1,1,0,0,0,0,1,0,2,0},   	    // CM
			       {1,1,0,1,0,1,1,1,0,0,0,1,0,0,0,1,0,1,1,1,1,1,1,0,1,0},               // P
			       {0,1,1,0,0,0,1,0,1,1,1,1,0,0,1,1,2,0,1,0,1,0,1,1,1,0},               // SC
			       {0,1,0,1,0,0,1,0,1,1,1,1,0,0,1,0,0,0,1,0,1,1,0,1,1,1},               // S
			       {1,1,1,0,1,0,1,1,0,0,0,0,0,1,1,1,1,0,1,1,1,0,1,1,1,0},               // SM
			       {0,1,1,1,0,0,1,1,0,0,0,0,1,1,1,1,1,2,0,0,1,0,0,0,0,0},               // PC
			       {0,0,0,1,0,2,0,1,0,1,0,1,1,1,0,0,0,1,0,1,0,1,1,0,1,1} };             // L

void fonction_tri (int persCho[NB_JOB], int arr[][NB_STUDENT])
{
  int j, i, k;
    for(i=0; i<NB_JOB; i++)
      {
	int lazy_student[NB_STUDENT];
	int min=arr[i][0];
	for(j=0;j<NB_STUDENT;j++)
	    if(arr[i][j]<min)
	      min = arr[i][j];
	int index = 0;
	for(j=0;j<NB_STUDENT;j++)
	    if(arr[i][j]==min)
	      {
		int prev=0;
		for(k=0;k<NB_JOB+i;k++)
		  if(persCho[k]==j)
		    prev=1;
		if(!prev)
		  lazy_student[index++]=j;
	      }
	persCho[NB_JOB+i]=lazy_student[rand()%index];

      }

}


int main()
{
  int persCho[NB_JOB*2]={4,5,8,9,12,16,21};

  fonction_tri(persCho, arr);

  int i;
  for(i=0; i<NB_JOB; i++)
    printf("job %d => student %d\n", i, persCho[NB_JOB+i]);

  return 0;
}
