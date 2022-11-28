#ifndef MAIN_H_
#define MAIN_H_

/*
 * libraries - to be included
 */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <sys/wait.h>

/*
 * prototypes - function protos below
 */

/* defined in tokenizer.c */
char *dupstr(char *fire);
int tok_num(char *str, char *delims);
char **tokstr(char *line, char *delims);
int substrLen(char *str, char *delims);
ssize_t readlineSI(char **line, size_t *n, FILE *inbound);

#endif
