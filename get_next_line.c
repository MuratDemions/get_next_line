#include "get_next_line.h"

static void *spt_free(void *freeable_area)
{
	free(freeable_area);
	return (NULL);
}

static void *spt_to_read(int fd, char *to_read)
{
	char		*txt;
	long long	txtlen;

	txtlen = 1;
	txt = malloc(BUFFER_SIZE + 1);
	if (!txt)
		return (spt_free(to_read));
	while(txtlen > 0 && !ft_strchr(to_read, '\n'))
	{
		txtlen = read(fd, txt, BUFFER_SIZE);
		if (txtlen == -1)
		{
			spt_free(txt);
			return (spt_free(to_read));
		}
		txt[txtlen] = '\0';
		to_read = ft_strjoin(to_read, txt);
		if(!to_read)
		{
			spt_free(txt);
			return(spt_free(to_read));
		}
	}
	spt_free(txt);
	return(to_read);
}

char	*get_next_line(int fd)
{
	static char *to_read;
	char *line;

	if(!fd || !BUFFER_SIZE)
		return (NULL);
	to_read = spt_to_read(fd, to_read);
	if(!to_read)
		return (NULL);	
}
