#include"read_input.h";

void read_input(){
    FILE *fp;

    char fname[]="signal.txt";
    int chr;

    fp= fopen(fname,"r");
    
    if(fp==NULL){
        printf("not open");
        exit();
    }
    else{
        fscanf(fp,"%s")
    }
    fclose(fp);
}