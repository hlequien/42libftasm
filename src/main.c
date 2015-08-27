#include <libfts.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <ctype.h>

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

void ft_puts_c(char *s)

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
    c -= ('a' - 'A');
  return (c);
}

int ft_tolower_c(int c)
{
  if (c >= 'A' && c <= 'Z')
	  c += ('a' - 'A');
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

void ft_test_bzero(void)
{
	char *s;
	size_t sz;

	s = ft_strdup("abcde");
	sz = ft_strlen(s);
	ft_bzero(s, sz);
	while (sz--)
	{
		if (s[sz])
			write(1, "X", 1);
		else
			write(1, ".", 1);
	}
	write(1, "\n", 1);
}

void ft_test_int_ret(int (*f1)(int), int (*f2)(int))
{
  int c;
  int c_err;

  c = -1;
  while (c++ < 127)
    if (f1(c) == f2(c))
      write(1, ".", 1);
    else
	{
      write(1, &c, 1);
	  c_err = f1(c);
	  write(1, &c_err, 1);
	  c_err = f2(c);
	  write(1, &c_err, 1);
	}
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

  s1 = ft_strdup_c("abcdefgh");
  ft_putstr(s1);
  ft_putstr("\n");
  if (ft_memset(s1, 'z', ft_strlen(s1)) == s1)
    ft_putstr(".");
  else
    ft_putstr("X");
  ft_putstr("\n");
  ft_putstr(s1);
  ft_putstr("\n");    
}

void ft_test_memcpy(void)
{
  char *s1;
  char *s2;

  s1 = ft_strdup_c("abcdefgh");
  s2 = ft_strdup_c("zzzzzzzz");
  ft_puts(s1);
  ft_puts(s2);
  ft_memcpy(s2, s1, ft_strlen(s1) - 2);
  ft_puts(s1);
  ft_puts(s2);
  
}

void ft_test_strdup(void)
{
  char *s1;
  char *s2;

  s1 = ft_strdup("abcdefgh");
  s2 = ft_strdup_c("abcdefgh");
  if (ft_strequ_c(s1, s2))
    ft_putstr(".");
  else
    {
      ft_putstr("X");
      ft_puts(s1);
      ft_putstr(s2);
    }
  free(s1);
  free(s2);
  ft_putstr("\n");
}

void ft_test_memalloc(void)
{
  char *s;
  int n;

  n = 100;
  s = ft_memalloc(n);

  while (n--)
    if(s[n])
      ft_putstr("X");
    else
      ft_putstr(".");
  free(s);
  write(1, "\n", 1);
}

void ft_test_cat(void)
{
  int fd;

  ft_puts("ft_cat : start reading on stdin");
  ft_cat(0);
  ft_puts("ft_cat : read on stdin is over");
  ft_puts("ft_cat : let's try with a \"./ft_test.txt\" file");
  fd = open("./test.txt", O_RDONLY);
  if (fd != -1)
  {
	  ft_cat(fd);
	  if (fd > 2)
		  close (fd);
  }
  ft_puts("ft_cat : read on \"./test.txt\" is over");
  fd = open("./manpages", O_RDONLY);
  if (fd != -1)
  {
	  ft_cat(fd);
	  close(fd);
  }
}

int main(void)
{
  char *s1;
  char *s2;
  
  s1 = ft_strdup_c("abcde");
  ft_puts(s1);
  ft_bzero(s1, ft_strlen_c(s1));
  ft_puts(s1);
  free(s1);
  s1 = (char *)malloc(sizeof(char) * 11);
  ft_strcpy_c(s1, "abcde");
  s2 = ft_strdup_c("fghij");
  ft_puts(s1);
  ft_puts(s2);
  ft_strcat(s1, s2);
  ft_puts(s1);
  free(s1);
  free(s2);
  ft_puts("ft_isalpha");
  ft_test_int_ret(ft_isalpha, ft_isalpha_c);
  ft_puts("ft_isdigit");
  ft_test_int_ret(ft_isdigit, ft_isdigit_c);
  ft_puts("ft_isalnum");
  ft_test_int_ret(ft_isalnum, ft_isalnum_c);
  ft_puts("ft_isprint");
  ft_test_int_ret(ft_isprint, ft_isprint_c);
  ft_puts("ft_isascii");
  ft_test_int_ret(ft_isascii, ft_isascii_c);
  ft_puts("ft_isupper, comparison with original c funtion");
  ft_test_int_ret(ft_isupper, isupper);
  ft_puts("ft_islower, comparison with original c funtion");
  ft_test_int_ret(ft_islower, islower);
  ft_puts("ft_toupper, comparison with original c funtion");
  ft_test_int_ret(ft_toupper, toupper);
  ft_puts("ft_toupper, comparison with my c funtion");
  ft_test_int_ret(ft_toupper, ft_toupper_c);
  ft_puts("ft_tolower, comparison with original c funtion");
  ft_test_int_ret(ft_tolower, tolower);
  ft_puts("ft_tolower, comparison with my c funtion");
  ft_test_int_ret(ft_tolower, ft_tolower_c);
  ft_puts("ft_strlen");
  ft_test_strlen();
  ft_putstr("ft_puts");
  ft_putstr("\n");
  ft_putstr("ft_memset\n");
  ft_test_memset();
  ft_putstr("ft_memcpy\n");
  ft_putstr("\n");
  ft_test_memcpy();
  ft_putstr("ft_strdup\n");
  ft_test_strdup();
  ft_putstr("ft_memalloc\n");
  ft_test_memalloc();
//  ft_putstr("ft_cat\n");
//  ft_test_cat();
  ft_putstr("test de putstr\n");
  ft_putstr("test de ft_bzero");
  ft_test_bzero();
  ft_puts(NULL);
  puts(NULL);
  return (0);
}
