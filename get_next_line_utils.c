#include "get_next_line.h"

void *spt_free(void *freeable_area)
{
	free(freeable_area);
	return (NULL);
}

size_t	ft_strlen(char const	*s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*total_str;
	size_t	total_len;
	size_t	i;

	total_len = ft_strlen(s1) + ft_strlen(s2);
	total_str = (char *)malloc(total_len + 1);
	if (!total_str)
		return (spt_free(s1));
	i = 0;
	while (s1 && *s1)
	{
		total_str[i] = *s1++;
		i++;
	}
	while (s2 && *s2)
	{
		total_str[i] = *s2++;
		i++;
	}
	total_str[i] = '\0';
	return (total_str);
}
