/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musipit <musipit@student.42kocaeli.com.tr> #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-22 09:10:36 by musipit           #+#    #+#             */
/*   Updated: 2026-02-22 09:10:36 by musipit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <unistd.h>

static char	*to_read_updater(char *to_read)
{
	char		*new_to_read;
	long long	i;

	i = 0;
	while (to_read[i] != '\n' && to_read[i] != '\0')
		i++;
	if (to_read[i] == '\0')
		return (spt_free(to_read));
	new_to_read = malloc(ft_strlen(to_read) - i);
	if (!new_to_read)
		return (spt_free(to_read));
	long long	j;
	j = 0;
	while (to_read[++i])
		new_to_read[j++] = to_read[i];
	new_to_read[j] = '\0';
	free(to_read);
	return (new_to_read);

}

static char *appointer(char *to_read)
{
	char		*line;
	long long	i;

	i = 0;
	if(!to_read[i])
		return (NULL);
	while (to_read[i] != '\n' && to_read[i] != '\0')
		i++;	
	if(to_read[i] == '\n')
		i++;
	line = malloc(i + 1);
	if(!line)
		return (NULL);
	i = 0;
	while (to_read[i] != '\n' && to_read[i] != '\0')
	{
		line[i] = to_read[i];
		i++;
	}
	if(to_read[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);

}
static char *spt_to_read(int fd, char *to_read)
{
	char		*txt;
	long long	txtlen;
	char	*temp;

	txtlen = 1;
	txt = malloc(BUFFER_SIZE + 1);
	if (!txt)
		return (spt_free(to_read));
	while(txtlen > 0 && !ft_strchr(to_read, '\n'))
	{
		txtlen = read(fd, txt, BUFFER_SIZE);
		if (txtlen == -1)
		{
			free(txt);
			return (spt_free(to_read));
		}
		txt[txtlen] = '\0';
		temp = ft_strjoin(to_read, txt);
		free(to_read);
		to_read = temp;
	}
	spt_free(txt);
	return(to_read);
}

char	*get_next_line(int fd)
{
	static char *to_read[MAX_FD];
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	to_read[fd] = spt_to_read(fd, to_read[fd]);
	if (!to_read[fd])
		return (NULL);
	line = appointer(to_read[fd]);
	if (!line)
	{
		spt_free(to_read[fd]);
		to_read[fd] = NULL;
		return (NULL);
	}
	to_read[fd] = to_read_updater(to_read[fd]);
	return(line);
	
}
