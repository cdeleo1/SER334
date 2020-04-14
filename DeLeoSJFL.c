/**
* Shortest Job First (SJF) implementation.
*
* Completion time: 2 hours
*
* @author Cristi DeLeo
* @version 20200413
*/

////////////////////////////////////////////////////////////////////////////////
//INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUF_MAX_SIZE 10

pid_t t_pid;

////////////////////////////////////////////////////////////////////////////////
//TYPEDEFS
typedef struct {
    int pid;
    float at, wt, bt, ta, st;
    bool isComplete;
} process;

////////////////////////////////////////////////////////////////////////////////
//FUNCTIONS
void procdetail(int i, process p[], char buffer[]) {
    p[i].pid = atoi(buffer);
    p[i].at = i + 1;
    p[i].bt = i + 1;
    p[i].isComplete = false;
}

void sort(process p[], int i, int start) {
     int k = 0, j;
     process temp;
     for (k = start; k<i; k++)
     {
          for (j = k+1; j<i; j++)
          {
               if(p[k].bt < p[j].bt)
                    continue;
               else
               {
                    temp = p[k];
                    p[k] = p[j];
                    p[j] = temp;
               }
          }
     }
}

////////////////////////////////////////////////////////////////////////////////
//MAIN
int main(int argc, char *argv[]) {

    int n = 0; // NUMBER OF PROCESSES
    int i; // LOOP COUNTER FOR NUMBER OF PROCESSES TO ADD TO p[n]
    int k = 0, j = 0;
    float avgwt = 0.0, avgta = 0.0, tst = 0.0;

    FILE *fp;
    char buff[255];
    
    // OPEN FILE | OPTION: READ ONLY
    fp = fopen("./data.txt", "r");    

    while ( fgets(buff, 255, (FILE*)fp) ) {
        n++;
        printf("%d: %s\n", n, buff );
    }

    n = n - 1;
    
    // CLOSE FILE
    fclose(fp);

    // CREATE PROCESS ARRAY FOR LENGTH OF NUMBER OF PROCESSES 
    process p[n];

    // OPEN FILE | OPTION: READ ONLY
    fp = fopen("./data.txt", "r"); 

    // GET PROCESS DETAILS FROM FILE
    for (i = 0; i<n; i++) {
        fscanf(fp, "%s", buff);
        printf("%d : %s\n", (i + 1), buff );
        procdetail(i, p, buff);
    }

    // CLOSE FILE
    fclose(fp);

    for (i = 0; i<n; i++) {
          if (p[i].isComplete == true)
               continue;
          else {
               k = i;
               while (p[i].at<=tst && i<n)
                    i++;
               sort (p,i,k);
               i = k;
               if(p[i].at<=tst)
                    p[i].st = tst;
               else
                    p[i].st = p[i].at;
               p[i].st = tst;
               p[i].isComplete = true;
               tst += p[i].bt;
               p[i].wt = p[i].st - p[i].at;
               p[i].ta = p[i].bt + p[i].wt;
               avgwt += p[i].wt;
               avgta += p[i].ta;
          }
    }

     avgwt /= n;
     avgta /= n;

     printf("Process Schedule Table: \n");
     printf("\tProcess ID\tArrival Time\tBurst Time\tWait Time\tTurnaround Time\n");

    for (i = 0; i<n; i++) {
        printf("\t%d\t\t%f\t%f\t%f\t%f\n", p[i].pid,p[i].at, p[i].bt, p[i].wt, 
                p[i].ta);
    }

    printf("\nAverage wait time: %f", avgwt);
    printf("\nAverage turnaround time: %f\n", avgta);

    return 0;
}