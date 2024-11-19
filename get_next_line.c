/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 07:48:44 by zlee              #+#    #+#             */
/*   Updated: 2024/11/19 10:39:51 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_spt_result(char *result)
{
	int		result_s;
	int		index;
	char	*temp_result;

	index = -1;
	result_s= 0;
	while (result[result_s] != '\n')
		result_s++;
	temp_result = ft_calloc(result_s + 2, sizeof(char));
	if (!temp_result)
		return (NULL);
	while (++index < result_s + 1)
		temp_result[index] = result[index];
	free(result);
	result = temp_result;
	return (result);
}

static char	*read_buffer(int fd)
{
	char	*temp_buffer;
	char	*result;
	int		size;
	char	*temp;

	temp = NULL;
	result = ft_calloc(1, 1);
	if (!result)
		return (NULL);
	temp_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp_buffer)
		return (NULL);
	size = read(fd, temp_buffer, BUFFER_SIZE);
	while (size > 0)
	{
		temp = ft_strjoin(result, temp_buffer);
		free(result);
		result = temp;
		temp_buffer = ft_bzero(temp_buffer, BUFFER_SIZE);
		if (ft_strchr(result, '\n'))
			break ;
		size = read(fd, temp_buffer, BUFFER_SIZE);
	}
	free(temp_buffer);
	return (result);
}

char	*ft_mk_buffer(char *buffer, char *result)
{
	int	result_s;
	int	buf_len;
	int	i;

	i = -1;
	buf_len = 0;
	result_s = 0;
	while (result[result_s] != '\n')
		result_s++;
	buf_len = ft_strlen(result) - result_s + 1;
	buffer = malloc((buf_len + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (++i < buf_len)
		buffer[i] = result[result_s + i + 1];
	buffer[i] = '\0';
	return (buffer);
}

static char	*ft_buf_prep(char **result, char **buffer)
{
	char	*temp;

	if (*result == NULL)
		*result = ft_calloc(1, 1);
	temp = ft_strjoin(*buffer, *result);
	if (!temp)
		return (*result);
	free(*buffer);
	free(*result);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*result;
	char		*buf_remain;
	char		*temp;

	result = NULL;
	buf_remain = NULL;
	if (fd < 0)
		return (NULL);
	result = read_buffer(fd);
	if (buffer)
		result = ft_buf_prep(&result, &buffer);
	if (*result == 0)
	{
		free(result);
		return (NULL);
	}
	if (ft_strchr(result, '\n'))
	{
		buffer = ft_mk_buffer(buffer, result);
		temp = ft_spt_result(result);
		result = temp;
	}
	return (result);
}
