#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include "abr.h"
#include "global_defs.h"

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

// Choose a sort method
//#define AVL_METHOD
#define ABR_METHOD


#ifdef AVL_METHOD
#if defined(ABR_METHOD)
#error "Only one method may be defined (AVL_METHOD already defined)"
#endif
#endif


int main(){

    FILE* fp = fopen("step_1.csv", "r");

    if (!fp)
        printf("[ERROR] Can't open file\n");

    else {
        char buffer[MAX_LEN];

        int row = 0;
        int column = 0;

#ifdef AVL_METHOD
        pavl a = NULL;
#endif
#ifdef ABR_METHOD
        pabr a = NULL;
#endif

        float avg;
        float min;
        float max;
        int code;

        while (fgets(buffer,MAX_LEN, fp)) {
            column = 0;
            row++;

            if (row == 1)
                continue;

            char* value = strtok(buffer, ", ");


            while (value) {

                switch (column) {
                    case 0 :
                        code=atoi(value);
                        //printf("[INFO] Column 1 %d  ", code);
                        break;
                    case 1 :
                        avg=atof(value);
                        min = avg;
                        max = avg;
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
                        break;
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

#ifdef AVL_METHOD
            a = insertAVL(a,st);
#endif

#ifdef ABR_METHOD
            a = insertABR(a,st);
#endif

            //printf("\n");
        }

        fclose(fp);

        FILE* fp_step2 = fopen("step_2.csv", "w+");
        if (!fp_step2 ) {
            printf("Can't open file\n");
            return 0;
        }

#ifdef AVL_METHOD
        infixeAVL(a, fp_step2);
#endif

#ifdef ABR_METHOD
        infixeABR(a, fp_step2);
#endif

        fclose(fp_step2);

    }
    return 0;
}
