#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

extern char **environ;

char *_strchr(char *s, char c);
char *_strdup(char *str);
int _atoi(char *s);
char *_strcpy(char *dest, char *src);
char *_strncpy(char *dest, char *src, int n);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
ssize_t read_line(char **line, size_t *n, FILE *stream);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **tokenize(char *buffer, const char *delim);
int isdelim(char c, const char *delim);
int prompt(char **line, size_t *n);
int execute(char **buffer, char **environ);
void free_tokens(char **tokens);

/*Debug Functions*/
void print_array(char **array);
void print(char *str);
/*Debug Functions*/


#endif /*_SHELL_H_*/
