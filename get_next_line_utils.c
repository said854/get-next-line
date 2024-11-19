#include "get_next_line.h"

size_t   ft_strlen(const char *str)
{
        size_t  len;

        if (!str)
                return (0);
        len = 0;
        while (str[len])
                len++;
        return (len);
}
void    ft_bzero(void *s, size_t n)
{
        size_t                  i;
        unsigned char   *ptr;

        ptr = (unsigned char *)s;
        i = 0;
        if (n == 0)
                return ;
        while (i < n)
        {
                ptr[i] = 0;
                i++;
        }
}
void    *ft_calloc(size_t count, size_t size)
{
        void    *ptr;
        ptr = malloc(count * size);
        if (ptr == NULL)
                return (NULL);
        ft_bzero(ptr, count * size);
        return (ptr);
}
char    *ft_strdup(const char *s1)
{
        int             i;
        char    *cpy;
        int             len;

        len = ft_strlen(s1);
        cpy = ft_calloc(len + 1, 1);
        if (!cpy)
                return (NULL);
        i = 0;
        while (s1[i])
        {
                cpy[i] = s1[i];
                i++;
        }
        cpy[i] = 0;
        return (cpy);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
        size_t  i;
        size_t  j;
        char    *result;

        result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
        if (!result)
                return (strdup(""));
        i = 0;
        while (s1 && s1[i])
        {
                result[i] = s1[i];
                i++;
        }
        j = 0;
        while (s2 && s2[j])
        {
                result[i + j] = s2[j];
                j++;
        }
        result[i + j] = '\0';
        return (result);
}

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;

	str = (char *)s;
	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i--;
	}
	return (0);
}
char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*ptr;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_strchr(set, s1[start]))
                start++;
	while (end >= start && ft_strchr(set, s1[end]))
		end--;
	ptr = ft_substr(s1, start, end - start + 1);
	return (ptr);
}
char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i++;
	}
	if (str[i] == (char)c)
		return (&str[i]);
	return (0);
}
