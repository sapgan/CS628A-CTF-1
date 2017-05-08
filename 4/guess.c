#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

void Get_File_Size(char *filename) {
    char command[128];
    struct stat st;
    int i;
    snprintf(command, 128, "du -h '%s' 2> /dev/null", filename);

    for (i = 0; i < 100; i++) {
      if (filename[i] == '\0') break;
        if (filename[i] == '\'') {
            filename[i] = '\0';
            break;
        }
    }

    if(!stat(filename, &st)) {
        if(system(command)) {
            fprintf(stderr, "Error\n");
            exit(1);
        }
    }
    else {
        fprintf(stderr, "Invalid file name\n");
        exit(1);
    }
}


void main(){
    char file_name[100],user_name[100];
    int guess;
    

    getlogin_r(user_name, sizeof(user_name));

    int seed = 7;
    for (int i = 0; user_name[i]; i++) {
    	seed = seed*31 + user_name[i];
    }    

    printf("--------------------------------------\n");
    printf("Welcome to dew, the file size utility.\n");
    printf("   I have written it from scratch.\n");
    printf("--------------------------------------\n\n");
    printf("Enter file name: ");
    
    scanf("%99s", file_name);

    printf("\nI generated a random 32-bit number.\nYou have a 1 in 2^32 chance of guessing it. Good luck.\n");
    
    srand(seed);
    int secret = rand();
    printf("What is your guess?\n");
    scanf("%d", &guess);

    if(guess == secret){
        printf("Wow! You guessed it!\n");
        Get_File_Size(file_name);
    }else{
        printf("Hah! I knew you wouldn't get it.\n");
    }
}
