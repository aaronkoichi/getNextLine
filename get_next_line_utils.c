/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:25:52 by zlee              #+#    #+#             */
/*   Updated: 2024/11/19 08:34:06 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	c;

	c = 0;
	while (s[c] != '\0')
		c++;
	return (c);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (*s == '\0' && c == '\0')
		return ((char *)s);
	else
		return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*total;
	int		len;
	int		count;
	int		count_two;

	count = 0;
	count_two = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	total = (char *)malloc((len + 1) * sizeof(char));
	if (!total)
		return (NULL);
	while (count < len && s1[count] != '\0')
	{
		total[count] = s1[count];
		count++;
	}
	while (count < len && s2[count_two] != '\0')
	{
		total[count++] = s2[count_two++];
	}
	total[count] = '\0';
	return (total);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*arr;
	int		i;

	i = -1;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (size > (size_t) -1 / nmemb)
		return (NULL);
	arr = malloc(nmemb * size);
	if (!arr)
		return (NULL);
	while (++i < (nmemb * size))
		arr[i] = 0;
	return (arr);
}

void	*ft_bzero(void *s, size_t n)
{
	unsigned char	*initial;
	size_t			count;

	count = 0;
	initial = s;
	while (count < n)
	{
		*initial = '\0';
		initial++;
		count++;
	}
	return (s);
}
