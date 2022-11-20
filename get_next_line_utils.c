/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouaarabe <ouaarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 03:05:50 by ouaarabe          #+#    #+#             */
/*   Updated: 2022/11/20 10:32:40 by ouaarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*memory;
	size_t	i;

	i = 0;
	memory = malloc(count * size);
	if (!memory)
		return (NULL);
	while (i < count * size)
		memory[i++] = 0;
	return (memory);
}

size_t	ft_strlen(const	char *s)
{
	const char	*c;

	c = s;
	while (*c)
		c++;
	return ((size_t)(c - s));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	ls1;
	size_t	ls2;
	char	*result;
	ssize_t i = -1;
	ssize_t j = -1;

	// if (!s1 || !s2)
	// 	return (NULL);
	if (!s1)
		return (strdup(s2));
	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	result = ft_calloc((ls1 + ls2 + 1),sizeof(char));
	if (result == NULL)
		return (NULL);
	while (s1[++i])
			result[i] = s1[i];
	while(s2[++j])
		result[i + j] = s2[j];
		return (result);
	printf("[joined : %s] ", result);
	return (NULL);
}

char	*ft_strchr(const char *str, int c)
{
	size_t	len;
	size_t	i;
	if (!str)
		return (0);
	len = ft_strlen(str);
	i = 0;
	while (i < len)
	{
		if (str[i] == (unsigned char)c)
			return ((char *)(&str[i]));
		i++;
	}
	return (0);
}
