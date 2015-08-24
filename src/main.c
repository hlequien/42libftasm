#include <libftasm.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

size_t ft_strlen_c(char *s)
{
  size_t i;

  i = 0;
  if (s)
    while (s[i])
      i++;
  return (i);
}

char *ft_strdup_c(char *s)
{
  char *ret;
  size_t i;
  
  ret = NULL;
  if (s)
    if ((ret = (char *)malloc(sizeof(char) * (ft_strlen_c(s) + 1))))
      {
	i = 0;
	while (s[i])
	  {
	    ret[i] = s[i];
	    i++;
	  }
	ret[i] = '\0';
      }
  return (ret);
}

void ft_putendl_c(char *s)

{
  write(1, s, ft_strlen_c(s));
  write(1, "\n", 1);
}

char *ft_strcpy_c(char *s1, char *s2)
{
  char *ret;

  ret = s1;
  s1 += ft_strlen_c(s1);
  while (*s2)
    *s1++ = *s2++;
  *s1 = '\0';
  return (ret);
}

int ft_isalpha_c(int c)
{
  return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int ft_isdigit_c(int c)
{
  return (c >= '0' && c <= '9');
}

int ft_isalnum_c(int c)
{
  return (ft_isalpha(c) || ft_isdigit(c));
}

int ft_isprint_c(int c)
{
  return (c >= ' ' && c <= '~');
}
int ft_isascii_c(int c)
{
  return (c >= 0 && c <= 127);
}

int ft_toupper_c(int c)
{
  if (c >= 'a' && c <= 'z')
    c = c + ('a' - 'A');
  return (c);
}

int ft_tolower_c(int c)
{
  if (c >= 'A' && c <= 'Z')
    c = c - 32;
  return (c);
}

int ft_strequ_c(char *s1, char *s2)
{
  while (*s1 == *s2 && *s1)
    {
      s1++;
      s2++;
    }
  return (*s1 == *s2);
}

void ft_test_isalpha(void)
{
  int c;

  c = 'a' - 2;
  while (c++ <= 'z' + 1)
    if (ft_isalpha(c) == ft_isalpha_c(c))
      write(1, ".", 1);
    else
	printf("\n [%c] = ft_isalpha == %d", c, ft_isalpha(c));
  write(1, "\n", 1);
}

void ft_test_isalnum(void)
{
  int c;

  c = '0' -2;
  while (c++ <= 'z' + 1)
    if (ft_isalnum(c) == ft_isalnum_c(c))
      write(1, ".", 1);
    else
      write(1, &c, 1);
      //      printf("\n%c == %d", c, ft_isalnum(c));
}

void ft_test_isprint(void)
{
  int c;

  c = -1;
  while (c++ < 127)
      if (ft_isprint(c) == ft_isprint_c(c))
	write(1, ".", 1);
      else
	write(1, "X", 1);
}

void ft_test_isascii(void)
{
  int c;

  c = -25;
  while(c++ < 155)
    if (ft_isascii(c) == ft_isascii_c(c))
      write(1, ".", 1);
    else
      write(1, "X", 1);
}

void ft_test_int_ret(int (*f1)(int), int (*f2)(int))
{
  int c;

  c = -1;
  while (c++ < 127)
    if (f1(c) == f2(c))
      write(1, ".", 1);
    else
      write(1, "X", 1);
  write(1, "\n", 1);
}

void ft_test_strlen(void)
{
  char *s;

  s = ft_strdup_c("abcdefghijklmnopqrstuvwxyz");
  if (ft_strlen(s) == ft_strlen_c(s))
    write(1, ".", 1);
  else
    write(1, "X", 1);
  write(1, "\n", 1);
}

void ft_test_memset(void)
{
  char *s1;
  //  char *s2;

  s1 = ft_strdup_c("abcdefgh");
  ft_puts(s1);
  ft_puts("\n");
  //  s2 = ft_strdup_c(s1);
  if (ft_memset(s1, 'z', ft_strlen(s1)) == s1)
    ft_puts(".");
  else
    ft_puts("X");
  ft_puts("\n");
  ft_puts(s1);
  ft_puts("\n");    
}

void ft_test_memcpy(void)
{
  char *s1;
  char *s2;

  s1 = ft_strdup_c("abcdefgh");
  s2 = ft_strdup_c("zzzzzzzz");
  ft_puts(s1);
  ft_puts("\n");
  ft_puts(s2);
  ft_puts("\n");
  ft_memcpy(s2, s1, ft_strlen(s1) - 2);
  ft_puts(s1);
  ft_puts("\n");
  ft_puts(s2);
  ft_puts("\n");
  
}

void ft_test_strdup(void)
{
  char *s1;
  char *s2;

  s1 = ft_strdup("abcdefgh");
  s2 = ft_strdup_c("abcdefgh");
  if (ft_strequ_c(s1, s2))
    ft_puts(".");
  else
    {
      ft_puts("X");
      ft_putendl_c(s1);
      ft_puts(s2);
    }
  free(s1);
  free(s2);
  ft_puts("\n");
}

void ft_test_memalloc(void)
{
  char *s;
  int n;

  n = 100;
  s = ft_memalloc(n);

  while (n--)
    if(s[n])
      puts("X");
    else
      puts(".");
  free(s);
}

void ft_test_cat(void)
{
  int fd;
  fd = open("./test.txt", O_RDONLY);
  ft_cat(fd);
  close (fd);
}

int main(void)
{
  char *s1;
  char *s2;
  
  s1 = ft_strdup_c("abcde");
  ft_putendl_c(s1);
  ft_bzero(s1, ft_strlen_c(s1));
  ft_putendl_c(s1);
  free(s1);
  s1 = (char *)malloc(sizeof(char) * 11);
  ft_strcpy_c(s1, "abcde");
  s2 = ft_strdup_c("fghij");
  ft_putendl_c(s1);
  ft_putendl_c(s2);
  ft_strcat(s1, s2);
  ft_putendl_c(s1);
  free(s1);
  free(s2);
  ft_putendl_c("ft_isalpha");
  ft_test_int_ret(ft_isalpha, ft_isalpha_c);
  ft_putendl_c("ft_isdigit");
  ft_test_int_ret(ft_isdigit, ft_isdigit_c);
  ft_putendl_c("ft_isalnum");
  ft_test_int_ret(ft_isalnum, ft_isalnum_c);
  ft_putendl_c("ft_isprint");
  ft_test_int_ret(ft_isprint, ft_isprint_c);
  ft_putendl_c("ft_isascii");
  ft_test_int_ret(ft_isascii, ft_isascii_c);
  ft_putendl_c("ft_toupper");
  ft_test_int_ret(ft_toupper, ft_toupper_c);
  ft_putendl_c("ft_tolower");
  ft_test_int_ret(ft_tolower, ft_tolower_c);
  ft_putendl_c("ft_strlen");
  ft_test_strlen();
  ft_puts("ft_puts");
  ft_puts("\n");
  ft_puts("ft_memset\n");
  ft_test_memset();
  ft_puts("ft_memcpy\n");
  ft_puts("\n");
  ft_test_memcpy();
  ft_puts("ft_strdup\n");
  ft_test_strdup();
  ft_puts("ft_memalloc\n");
  ft_test_memalloc();
  ft_puts("ft_cat\n");
  ft_test_cat();
  return (0);
}
