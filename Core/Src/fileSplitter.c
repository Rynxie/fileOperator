#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fileSplitter(char * filePath, char * sizeARG){
    FILE * target = fopen(filePath, "r");

    int index = 0;
    int sizeArg;
    sscanf(sizeARG, "%d" , &sizeArg);

    int size = (sizeArg * 1024 * 1024) / sizeof(char);
            
    int c;
    int loopIndex = 0;
            
    FILE * result;
    while((c = fgetc(target)) != EOF){
        if(loopIndex == 0){
                char resultName[100];
                sprintf(resultName,"%s_part_%d",filePath,index);
                result = fopen(resultName, "a");

        } 
        fprintf(result, "%c",c);

        loopIndex++;
                
        if(loopIndex == size){
            index++;
            loopIndex = 0;
            fclose(result);
        }

    }
    fclose(target);
}