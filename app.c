#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]){
    

    if(strcmp(argv[1],"split") == 0){
        //arg 1 mod 2 dosya adı 3 part boyutları
        FILE * target = fopen(argv[2], "r");

        int index = 0;
        int sizeArg;
        sscanf(argv[3], "%d" , &sizeArg);

        int size = (sizeArg * 1024 * 1024) / sizeof(char);
        
        int c;
        int loopIndex = 0;
        
        FILE * result;
        while((c = fgetc(target)) != EOF){
            if(loopIndex == 0){
                    char resultName[100];
                    sprintf(resultName,"%s_part_%d",argv[2],index);
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
    if(strcmp(argv[1],"merge")==0){
        //arg 1 mod 2 dosya adı 3 part sayısı
        FILE * result = fopen(argv[2],"a");
        int partArg;
        sscanf(argv[3], "%d" , &partArg);
        for (int i = 0; i < partArg; i++){
            char targetName[100];
            sprintf(targetName,"%s_part_%d",argv[2],i);

            FILE * target = fopen(targetName,"r");

            int c;
            while((c = fgetc(target)) != EOF){
                fprintf(result,"%c",c);
            }
            fclose(target);
        }
        fclose(result);
        



    }

    return EXIT_SUCCESS;
}
