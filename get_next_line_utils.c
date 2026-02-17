#include "get_next_line.h"

size_t	ft_strlen(const char	*s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
char	*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*total_str;
	size_t	i;
	size_t	j;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	total_str = (char *)malloc(i + j + 1);
	if (!total_str)
		return (NULL);
	i = 0;
	while (*s1)
		total_str[i++] = *s1++;
	while (*s2)
		total_str[i++] = *s2++;
	total_str[i] = '\0';
	return (total_str);
}
