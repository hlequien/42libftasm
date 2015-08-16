#include <libftasm.h>
#include <unistd.h>
#include <stdlib.h>

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

int main(void)
{
  char *s;

  s = ft_strdup_c("abcde");
  write(1, s, ft_strlen_c(s));
  write(1, "\n", 1);
  ft_bzero(s, ft_strlen_c(s));
  write(1, s, ft_strlen_c(s));
  write(1, "\n", 1);
  
  return (0);
}
