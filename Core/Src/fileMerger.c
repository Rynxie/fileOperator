#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fileMerger(char * filePath, char * mergeSize){
    FILE * result = fopen(filePath,"a");
        int partArg;
        sscanf(mergeSize, "%d" , &partArg);
        for (int i = 0; i < partArg; i++){
            char targetName[100];
            sprintf(targetName,"%s_part_%d",filePath,i);

            FILE * target = fopen(targetName,"r");

            int c;
            while((c = fgetc(target)) != EOF){
                fprintf(result,"%c",c);
            }
            fclose(target);
        }
        fclose(result);
        
}