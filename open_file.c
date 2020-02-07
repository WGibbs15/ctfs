#include <stdio.h> 
#include <stdlib.h> // For exit() 
  
int main(int argc, char** argv, char** envp) 
{ 
    FILE *fptr; 
  
    char *filename=".dockerenv";
	char c; 

    while (envp != 0) {
        puts(envp[0]);
        envp++;
    }
  
  
    // Open file 
    fptr = fopen(filename, "r"); 
    if (fptr == NULL) 
    { 
        printf("Cannot open file \n"); 
        exit(0); 
    } 
  
    // Read contents from file 
    c = fgetc(fptr); 
    while (c != EOF) 
    { 
        printf ("%c", c); 
        c = fgetc(fptr); 
    } 
  
    fclose(fptr); 
    return 0; 
}
