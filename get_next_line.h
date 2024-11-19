#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 50000
#endif


char *get_next_line(int fd);
size_t   ft_strlen(const char *str);
char    *ft_strjoin(char const *s1, char const *s2);
void    *ft_calloc(size_t count, size_t size);
char    *ft_strdup(const char *s1);
void    ft_bzero(void *s, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);




#endif