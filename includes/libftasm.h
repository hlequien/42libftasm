#ifndef LIBFTASM_H
#define LIBFTASM_H

#include <stdlib.h>

void ft_bzero(void *s, size_t n);
char *ft_strcat(char *dest, char *src);
int ft_isalpha(int c);
int ft_isdigit(int c);
int ft_isalnum(int c);
int ft_isprint(int c);
int ft_isascii(int c);
int ft_tolower(int c);
int ft_toupper(int c);
int ft_isupper(int c);
int ft_islower(int c);
size_t ft_strlen(char *s);
int ft_puts(char *s);
void *ft_memset(void *s, int c, size_t n);
void *ft_memcpy(void *dest, void *src, size_t n);
char *ft_strdup(char *s);
void *ft_memalloc(size_t n);
void ft_cat(int fd);

#endif
