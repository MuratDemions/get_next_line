/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musipit <musipit@student.42kocaeli.com.tr> #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-22 09:09:38 by musipit           #+#    #+#             */
/*   Updated: 2026-02-22 09:09:38 by musipit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

char    *get_next_line_bonus(int fd);
size_t  ft_strlen(const char *s);
void    *spt_free(void *freeable_area);
char    *ft_strchr(const char *s, int c);
char    *ft_strjoin(char *s1, char *s2);

#endif
