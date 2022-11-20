/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouaarabe <ouaarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 03:05:44 by ouaarabe          #+#    #+#             */
/*   Updated: 2022/11/20 12:41:48 by ouaarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char *ft_stat(char *s)
{
	char *tmp;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	j = ft_strlen(s) - i + 1;
	while(s[i] && s[i] != '\n')
		i++;
	if (s[i] && s[i] == '\n')
		i++;
	tmp = ft_calloc(j, sizeof(char));
	if (!tmp)
		return(NULL);
	while(j--)
	{
		tmp[k] = s[i];
		i++;
		k++;
	}
	return (tmp);
}
char *ft_line(char *s)
{
	char *line;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while(s[i] && s[i] != '\n')
		i++;
	i++;
	line = ft_calloc(i + 1, sizeof(char));
	if (!line)
		return(NULL);
	while(i > j)
	{
		line[j] = s[j];
		j++;
	}
	// printf("[i : %zu]\n", i);
	// printf("[line : %s]", line);
	return (line);
}

char	*get_line(int fd, char *s)
{
	int	nbyte;
	char *buff;

	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
		return (NULL);
	nbyte = 1;
	while (!ft_strchr(s, '\n') && nbyte != 0)
	{
		nbyte = read(fd, buff, BUFFER_SIZE);
		// printf("[buff : %s]\n", buff);
		// printf("[nbyte : %d]\n", nbyte);
		if (nbyte == -1)
		{
			free (buff);
			return (NULL);
		}
		else if (nbyte == 0)
		{
			if (*buff == 0)
			{
				buff[nbyte] = '\0';
				free(buff);
				return (NULL);
			}
			break ;
		}
		buff[nbyte] = '\0';
		s = ft_strjoin(s, buff);
	}
	free(buff);
	return (s);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*s;

	// printf("[gs1 : %s\n] ", s);
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	s = get_line(fd, s);
		// printf("[s : %s]\n", s);
	if (!s)
		return (NULL);
	line = ft_line(s);
	if (!line)
		return (NULL);
	//  printf("[gline : %s] ", line);
	s = ft_stat(s);
	if (!s)
		return (NULL);
	// printf("[ss : %s\n] ", s);
	return(line);
}
