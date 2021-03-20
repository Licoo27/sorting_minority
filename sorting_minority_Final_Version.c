#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define NB_STUDENT 25
#define NB_JOB 7

#define CM 0
#define P 1
#define SC 2
#define S 3
#define SM 4
#define PC 5
#define L 6

int arr[NB_JOB][NB_STUDENT] = { {1,1,1,1,1,1,0,0,1,1,2,1,1,1,1,1,1,1,1,1,1,1,2,1,0},           // CM
                            {1,1,1,1,1,1,1,0,1,0,1,0,0,0,1,1,1,1,1,1,1,1,1,0,1},               // P
                            {1,1,1, 0,1,1,1,1,1,1,1,1,1,1,1,2,1,1,0,1,1,1,1,1,0},               // SC
                            {1,1,1,0,1,1,0,1,1,1,1,0,1,1,1,0,1,0,1,1,1,1,1,1,0},               // S
                            {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0},               // SM
                            {1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,2,0,1,1,1,1,1,0,0},               // PC
                            {1,1,1,1,2,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,1,0,1,1,0}                // L
};

void fonction_tri (int persCho[NB_JOB*2], int arr[][NB_STUDENT])
{
    int j, i, k;
    for(i=0; i<NB_JOB; i++)// for each job
    {
        //find the min of job done
        int min=1000;
        for(j=0; j<NB_STUDENT; j++)
            if(arr[i][j]<min)
            {
                int prev=0;
                for(k=0; k<NB_JOB+i; k++) //check if not chosen
                    if(persCho[k]==j)
                        prev=1;
                if(!prev)
                    min = arr[i][j];
            }

        int lazy_student[NB_STUDENT];//array of student with a min of job done
        int index = 0;
        for(j=0; j<NB_STUDENT; j++) //find student with the min that have not yet been chosen
            if(arr[i][j]==min)
            {
                int prev=0;
                for(k=0; k<NB_JOB+i; k++) //check if not chosen
                    if(persCho[k]==j)
                        prev=1;
                if(!prev)//add to the list of lazy student
                    lazy_student[index++]=j;
            }

        persCho[NB_JOB+i]=lazy_student[rand()%index];

    }

}

void f_next(int persCho[NB_JOB], int arr[][NB_STUDENT])
{
    int index[7]= {};
    for(int i=0; i<NB_JOB; i++)
    {
        index[i] = persCho[NB_JOB+i];
        arr[i][index[i]]++;
        persCho[i]=index[i];
    }
}

void f_display(int arr[][NB_STUDENT])
{
    int i, j;
    for(i=0; i<NB_STUDENT; i++)
    {
        printf("\nstudent %02d ", i);
        for(j=0; j<NB_JOB; j++)
            printf("%d ",arr[j][i]);
    }
    printf("\n");
}

int main()
{
    srand(time(NULL));
    int persCho[NB_JOB*2]= {24,23,11,9,21,16,13};
    int j=0;
    f_display(arr);
    while(j<=10)
    {
        fonction_tri(persCho, arr);

        printf("WEEK %d\n\n", j);
        for(int i=0; i<NB_JOB; i++)
            printf("job %d --> student %d\n", i, persCho[NB_JOB+i]);

        f_next(persCho, arr);
        j++;
    }
    f_display(arr);
    return 0;
}
