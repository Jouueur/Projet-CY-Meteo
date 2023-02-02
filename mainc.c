#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include "avl.h"
#include "abr.h"

// Les valeurs de retour possibles du programme
/*enum {
  SUCCESS = 0,
  ERROR_OPTION = 1,
  ERROR_INPUT_FILE = 2,
  ERROR_OUTPUT_FILE = 3,
  ERROR_OTHER = 4
};

int main()
{
        FILE *gp;
        //define GNUPLOT_PATH "/usr/bin/gnuplot"
        gp = popen(!/usr/bin/gnuplot, "w");
        if(gp == NULL){
            fprintf(stderr, "Oops, I can't find %s.", "/usr/bin/gnuplot");
             exit(EXIT_FAILURE);
        }
        fprintf(gp, "cd '~/Desktop'\n load \"config\"\n");
          fflush(gp); 
          getchar();
          pclose(gp);
 
exit(SUCCESS);
}  */







#define MAX_LEN 1024

int main(){
    
    FILE* fp = fopen("results.csv", "r");
    pavl a = NULL;
  
    if (!fp)
        printf("[ERROR] Can't open file\n");

    else {
        char buffer[MAX_LEN];

        int row = 0;
        int column = 0;

        while (fgets(buffer,MAX_LEN, fp)) {
            column = 0;
            row++;

            if (row == 1)
                continue;

            char* value = strtok(buffer, ", ");

           
            float avg=0;
            float min=0;
            float max=0;
            int code=0;

            while (value) {

                switch (column) {
                    case 0 :
                        code=atoi(value);
                        //printf("[INFO] Column 1 %d  ", atoi(value));
                        break;
                    case 1 :
                        avg=atof(value);
                        //printf("[INFO] Column 2 %f  ", atof(value));
                        break;
                    case 2 :
                        min=atof(value);
                        //printf("[INFO] Column 3 %f  ", atof(value));
                        break;
                    case 3 :
                        max=atof(value);
                        //printf("[INFO] Column 4 %f  ", atof(value));
                        break;
                    default:
                        printf("[ERROR] Swtich");
                }

              

              value = strtok(NULL, ", ");
              column++;
            }

            Station st = {
              .codes = code,
              .avg = avg,
              .min = min,
              .max = max,
            };

            duplicateAVL(a,st);

            printf("\n");
        }

        fclose(fp);

        FILE* fp_step2 = fopen("step_2.csv", "a+");
        if (!fp_step2 ) {
          printf("Can't open file\n");
          return 0;
        }
        infixeAVL(a, fp_step2 );

        fclose(fp_step2 );

    }
    return 0;
}

