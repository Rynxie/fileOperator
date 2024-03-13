#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileSplitter.h"
#include "fileMerger.h"


int main(int argc, char *argv[]){
    
    if(argc < 3){
        printf("Lütfen app 'DOSYA ADI' 'DOSYA BOYUTU' şeklinde çalıştırınz");
        return EXIT_FAILURE;
    }

    if(strcmp(argv[1],"split") == 0){
        
        fileSplitter(argv[2],argv[3]);
    }
    if(strcmp(argv[1],"merge")==0){
        
        fileMerger(argv[2],argv[3]);

    }

    return EXIT_SUCCESS;
}
