#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

extern char **environ;

typedef struct list
{
	char *str;
	struct list *next;
} list_t;

char *_strchr(char *s, char c);
char *get_env(const char *name);
char *_strdup(const char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strncpy(char *dest, char *src, int n);
char **tokenize(char *buffer, const char *delim);

int _atoi(char *s);
int _which(char **str);
int _strlen(const char *s);
int execute(char **buffer);
int _strcmp(char *s1, char *s2);
int isdelim(char c, const char *delim);
int prompt(char **line, size_t *n, char ***tokens);
int _strncmp(const char *s1, const char *s2, size_t n);
int delete_nodeint_at_index(list_t **head, unsigned int index);

list_t *add_node_end(list_t **head, const char *str);
ssize_t read_line(char **line, size_t *n, FILE *stream);

void free_list(list_t *head);
void free_tokens(char **tokens);
void *_realloc(void *ptr, size_t old_size, size_t new_size);



/*Debug Functions*/
void print_array(char **array);
void print(char *str);
/*Debug Functions*/


#endif /*_SHELL_H_*/
