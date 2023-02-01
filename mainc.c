#include <mainc.h>






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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <getopt.h>





#define MAX_LEN 1024

int main(){
    FILE* fp = fopen("results.csv", "r");

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

            while (value) {
              switch (column) {
                case 0 :
                  printf("[INFO] Column 1 %d  ", atoi(value));
                case 1 :
                  printf("[INFO] Column 2 %f  ", atof(value));
                case 2 :
                  printf("[INFO] Column 3 %f  ", atof(value));
                case 3 :
                  printf("[INFO] Column 4 %f  ", atof(value));
                }
               

                value = strtok(NULL, ", ");
                column++;
            }

            printf("\n");
        }

        fclose(fp);
    }
    return 0;
}