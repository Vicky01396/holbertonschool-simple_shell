#ifndef HEADER
#define HEADER
/*Libraries that the function usses*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
/*Prototypes of the function*/
extern char **environ;

char *_get_path(const char *env);
int main(void);
char **tokethis(char *buff);
int execve_(char *path, char **args);
void free_grid(char **grid);
char *findexpath(const char *command, char *path);
#endif
