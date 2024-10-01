/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:36:47 by hugo-mar          #+#    #+#             */
/*   Updated: 2024/06/10 15:02:04 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	line = NULL;
	i = 1;
	while (i > 0)
	{
		if (!*buffer[fd])
		{
			i = read(fd, buffer[fd], BUFFER_SIZE);
			if (i == 0)
				return (line);
			if (i == -1)
				return (NULL);
			buffer[fd][i] = '\0';
		}
		line = ft_strjoin(line, buffer[fd]);
		ft_clean_buf(buffer[fd]);
		if (search_nl(line))
			break ;
	}
	return (line);
}

/* int main()
{
	char *line1, *line2, *line3;
	int fd1, fd2, fd3;
	int n = 10;

	fd1 = open ("file1.txt", O_RDONLY);
	if (fd1 == -1)
	{
		write (1, "Error opening file 1\n", 19);
		return (1);
	}
	fd2 = open ("file2.txt", O_RDONLY);
	if (fd2 == -1)
	{
		write (1, "Error opening file 2\n", 19);
		return (1);
	}
	fd3 = open ("file3.txt", O_RDONLY);
	if (fd3 == -1)
	{
		write (1, "Error opening file 3\n", 19);
		return (1);
	}
	while (n)
	{
		line1 = get_next_line (fd1);
		printf("FILE1\n%s\n", line1);
		free (line1);
		line2 = get_next_line (fd2);
		printf("FILE2\n%s\n", line2);
		free (line2);
		line3 = get_next_line (fd3);
		printf("FILE3\n%s\n", line3);
		free (line3);
		n--;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
} */
