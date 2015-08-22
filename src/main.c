#include <libftasm.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static size_t ft_strlen_c(char *s)
{
  size_t i;

  i = 0;
  if (s)
    while (s[i])
      i++;
  return (i);
}

static char *ft_strdup_c(char *s)
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

static void ft_putendl_c(char *s)
{
  write(1, s, ft_strlen_c(s));
  write(1, "\n", 1);
}

static char *ft_strcpy_c(char *s1, char *s2)
{
  char *ret;

  ret = s1;
  s1 += ft_strlen_c(s1);
  while (*s2)
    *s1++ = *s2++;
  *s1 = '\0';
  return (ret);
}

int ft_isalpha_c(char c)
{
  return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

static int ft_isalnum_c(char c)
{
  return (ft_isalpha(c) || (c <= '9' && c >= 0));
}

static int ft_isprint_c(char c)
{
  return (c >= ' ' && c <= '~');
}
static int ft_isascii_c(int c)
{
  return (c >= 0 && c <= 127);
}
static void ft_test_isalpha(void)
{
  char c;

  c = 'a' - 2;
  while (c++ <= 'z' + 1)
    if (ft_isalpha(c) == ft_isalpha_c(c))
      write(1, ".", 1);
    else
	printf("\n [%c] = ft_isalpha == %d", c, ft_isalpha(c));
  write(1, "\n", 1);
}

static void ft_test_isalnum(void)
{
  char c;

  c = '0' -2;
  while (c++ <= 'z' + 1)
    if (ft_isalnum(c) == ft_isalnum_c(c))
      write(1, ".", 1);
    else
      write(1, &c, 1);
      //      printf("\n%c == %d", c, ft_isalnum(c));
}

static void ft_test_isprint(void)
{
  char c;

  c = -1;
  while (c++ < 127)
      if (ft_isprint(c) == ft_isprint_c(c))
	write(1, ".", 1);
      else
	write(1, "X", 1);
}

static void ft_test_isascii(void)
{
  int c;

  c = -25;
  while(c++ < 155)
    if (ft_isascii(c) == ft_isascii_c(c))
      write(1, ".", 1);
    else
      write(1, "X", 1);
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
  ft_test_isalpha();
  ft_test_isalnum();
  ft_test_isprint();
  ft_test_isascii();
  return (0);
}
