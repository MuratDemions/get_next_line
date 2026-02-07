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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	start_i;
	unsigned int	size;

	start_i = 0;
	size = 0;
	if (!s)
		return (NULL);
	while (start_i < start && s[start_i])
		start_i++;
	while (size < len && s[size + start_i])
		size++;
	substr = (char *)malloc(size + 1);
	if (!substr)
		return (NULL);
	substr[size] = '\0';
	while (size--)
		substr[size] = s[start_i + size];
	return (substr);
}
