#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>

extern char **getln();

int inputCheck(char ** args, char**infile);
int outputCheck(char ** args, char**outfile);
int checkAnd(char**args);

void sigHandler(int signal){
	int status;
	wait(&status);
}

int main() {
	int i=0;
	int j=0;
   	int child;
	int status;
	long int sum=0;
	char **args;
	char * input;
	char * output;
	char c;
	FILE * fp;
	
	sigset(SIGCHLD, sigHandler);

	while(1) {
        printf("mshell$>");
		args = getln();
        if(args[0]!=NULL){
			for(i = 0; args[i]!=NULL; i++){
				printf("%s\n", args[i]);
			}
	        if(strcmp(args[0], "exit")==0){
			    exit(0);
		    }
		    else if(strcmp(args[0], "add")==0){
				for(i=1; args[i]!=NULL; i++){
                    sum = sum + strtol(args[i], NULL, 0);
                }
                for(i=1; args[i]!=NULL; i++){
                    if(args[i+1]!=NULL)
                    printf("%s + ",args[i]);
                    else
                    printf("%s = %ld\n",args[i], sum);
                }
		    }
            else if(strcmp(args[0], "arg")==0){
                for(i=1; args[i]!= NULL; i++){
                    j++;
                }
                printf("argc=%d, args=", j);
                for(i=1; args[i]!=NULL; i++){
                    printf("%s,", args[i]);
                }
                printf("\n");
		    }
			else if(strcmp(args[0], "art")==0){
				if(inputCheck(args, &input)){
					fp = fopen(input, "r");
					c = fgetc(fp);
					while(c!=EOF){
						c = fgetc(fp);
						printf("%c", c);
					}
				}
				printf("\n");
				fclose(fp);
			}
            else{
                child = fork();
				if(child == 0){
					if(inputCheck(args, &input)){
						printf("\n");
                    	freopen(input, "r", stdin);
                	}
                	if(outputCheck(args, &output)){
                    	freopen(output, "w+", stdout);
                	}
                    execvp(args[0], args);
					exit(-1);
                }
				if(checkAnd(args))
				waitpid(child, &status, 0);
				
				wait(NULL);
            }
        }
	}
	return(0);
}
/*Checks if the > input redirection is contained as one of the arguments. if 
it is found it gets rid of > and moves the file name down to where > used to be.
if file is null or the > is not found returns 0. returns 1 if file input is found and
> is an argument.*/
int inputCheck(char ** args, char**infile){
	int i;
	for(i=0; args[i]!=NULL; i++){
		if(args[i][0] == '<'){
			if(args[i+1]!=NULL){
				strcpy(args[i], args[i+1]);
				free(args[i+1]);
				args[i+1] = NULL;
				*infile = args[i];
				if(*infile == NULL){
					return(0);
				}
				else{			
					return(1);
				}
			}
		}	
	}
	return(0);
}

/*Checks the input for > output redirector. if found, deletes the > and 
moves the string contents ahead down one. if the contents is null returns or > is not found,
returns 0. if its found and input is not invald returns 1.*/
int outputCheck(char ** args, char**outfile){
	int i;
	for(i=0; args[i]!=NULL; i++){
		if(args[i][0] == '>'){
			if(args[i+1]!=NULL){
				strcpy(args[i], args[i+1]);
				free(args[i+1]);
				args[i+1] = NULL;
				*outfile = args[i];
				if(*outfile == NULL){
					return(0);
				}
				else{			
					return(1);
				}
			}
		}	
	}
	return(0);
}

/*Checks for an & in the string.*/
int checkAnd(char**args){
	int i;

	for(i = 0; args[i]!=NULL; i++){
		if(args[i][0] == '&'){
			return(1);
		}
	}
	return(0);
}
