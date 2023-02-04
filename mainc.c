#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include "abr.h"
#include "avl.h"
#include "global_defs.h"


enum {
  SUCCESS = 0,
  ERROR_OPTION = 1,
  ERROR_INPUT_FILE = 2,
  ERROR_OUTPUT_FILE = 3,
  ERROR_OTHER = 4
};


#define MAX_LEN 1024

// Choose a sort method
//#define AVL_METHOD
#define ABR_METHOD


#ifdef AVL_METHOD
#if defined(ABR_METHOD)
#error "Only one method may be defined (AVL_METHOD already defined)"
#endif
#endif



int main(int argc, char const *argv[]){

    int sort= atoi(argv[1]);
    const char* file1 = argv[2];
    int temp_option = atoi(argv[3]);
    
    

    FILE* fp = fopen(file1,"r");
    
    if (!fp){
        printf("[ERROR] Can't open file\n");
        return ERROR_INPUT_FILE;
    }
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
                        return ERROR_OTHER;
                }
                value = strtok(NULL, ", ");
                column++;
                
            }
            
            Station st = {
                    .codes = code,
                    .avg = avg,
                    .min = avg,
                    .max = avg,
            };

#ifdef AVL_METHOD
            a = insertAVL(a,st);
#endif

#ifdef ABR_METHOD
            if(temp_option == 1){
                a = insertt1ABR(a,st);
            }
            
            if(temp_option == 4){
                a = insertp1ABR(a,st);
            }
#endif
   
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
    int linenumber = 1;
#ifdef ABR_METHOD
        infixeABR(a, fp_step2,&linenumber);
#endif

        fclose(fp_step2);

    }
    return 0;
}
