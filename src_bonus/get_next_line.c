/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 18:07:29 by wollio            #+#    #+#             */
/*   Updated: 2021/10/12 10:39:20 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

static char	*if_newline(char **buffer, char *line, int i)
{
	char	*tmp;

	line = ft_substr(*buffer, 0, i + 1);
	tmp = ft_strdup(&((*buffer)[i + 1]));
	free(*buffer);
	*buffer = tmp;
	if ((*buffer)[0] == '\0')
	{
		free(*buffer);
		*buffer = NULL;
	}
	return (line);
}

static char	*ft_return(char **buffer, int bytes)
{
	int		i;
	char	*line;

	line = NULL;
	if (bytes == 0 && *buffer == NULL)
		return (NULL);
	i = 0;
	while ((*buffer)[i] != '\n' && (*buffer)[i] != '\0')
		i++;
	if ((*buffer)[i] == '\n')
		line = if_newline(buffer, line, i);
	else
	{
		line = ft_strdup(*buffer);
		free(*buffer);
		*buffer = NULL;
	}
	return (line);
}

void	ft_append(char **buffer, char *buff)
{
	char	*tmp;

	tmp = ft_strjoin(*buffer, buff);
	free(*buffer);
	*buffer = tmp;
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		buff[BUFFER_SIZE + 1];
	int			bytes;

	bytes = 1;
	if (fd < 0)
		return (NULL);
	while (bytes > 0)
	{
		bytes = read (fd, buff, BUFFER_SIZE);
		if (bytes == 0)
			break ;
		if (bytes > 0)
			buff[bytes] = '\0';
		else if (bytes == -1)
			return (NULL);
		if (!buffer)
			buffer = ft_strdup(buff);
		else
			ft_append(&buffer, buff);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (ft_return(&buffer, bytes));
}

// int main()
// {

// 	int fd;
// 	int i;
// 	int line;

// 	line = 1;
// 	i = 1;
// 	fd = open("fd.txt", O_RDONLY);
// 	if (fd < 1)
// 		printf("%s", "###### Couldn't open file ######");

// 	while (i <= line)
// 	{
// 		printf("Call %d of get next line : %s\n",i ,  get_next_line(fd));
// 		i++;
// 	}
// 	close(fd);
// 	//system("leaks get_next_line");
// 	//fscanf(stdin, "c");
// 	return (0);
// }