/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:11:46 by claghrab          #+#    #+#             */
/*   Updated: 2025/01/30 21:34:28 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*append_line(char *last)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!last)
		return (NULL);
	while (last[i] && last[i] != '\n')
		i++;
	if (last[i] == '\0')
	{
		new = dupl(last);
		return (new);
	}
	new = malloc((i + 2));
	if (!new)
		return (NULL);
	while (j <= i)
	{
		new[j] = last[j];
		j++;
	}
	new[j] = '\0';
	return (new);
}

char	*append_last(char *last)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!last)
		return (NULL);
	while (last[i] && last[i] != '\n')
		i++;
	if (last[i] == '\0')
	{
		free(last);
		return (NULL);
	}
	new = malloc(sizeof(char) * (ft_strlen(last) - i));
	if (!new)
		return (free(last), NULL);
	i++;
	while (last[i])
		new[j++] = last[i++];
	new[j] = '\0';
	return (free(last), new);
}

char	*handle_read(char *buffer, char *last, ssize_t read_bytes)
{
	if (read_bytes == 0)
	{
		if (ft_strlen(last) == 0)
		{
			free(last);
			last = NULL;
		}
		return (free(buffer), buffer = NULL, last);
	}
	if (read_bytes == -1)
		return (free(buffer), free(last), buffer = NULL, last = NULL, NULL);
	return (last);
}

char	*mini_read(int fd, char *last)
{
	char	*buffer;
	int		nl;
	ssize_t	read_bytes;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	nl = -1;
	read_bytes = 1;
	while (read_bytes > 0 && nl < 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free(buffer), free(last), buffer = NULL, last = NULL, NULL);
		buffer[read_bytes] = '\0';
		nl = tonl(buffer, '\n');
		if (nl < 0)
			last = ft_join(last, buffer);
		else
			return (last = ft_join(last, buffer), free(buffer), buffer = NULL,
				last);
		if (!last)
			return (free(buffer), NULL);
	}
	return (last = handle_read(buffer, last, read_bytes), last);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*last;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	last = mini_read(fd, last);
	if (!last)
		return (free(last), last = NULL, NULL);
	line = append_line(last);
	last = append_last(last);
	if (!last || ft_strlen(last) == 0)
		return (free(last), last = NULL, line);
	return (line);
}
