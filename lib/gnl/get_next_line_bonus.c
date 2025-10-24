/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   get_next_line_bonus.c							  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: aumartin <aumartin@42.fr>				  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/06/07 11:45:28 by aumartin		  #+#	#+#			 */
/*   Updated: 2024/06/10 11:08:56 by aumartin		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*stored_lines[OPEN_MAX];
	char		*line_to_return;
	int			eol;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	line_to_return = NULL;
	eol = -1;
	stored_lines[fd] = read_and_store(&eol, fd, stored_lines[fd]);
	if (!stored_lines[fd])
		return (NULL);
	line_to_return = extract_line(&eol, stored_lines[fd], line_to_return);
	if (!line_to_return)
		return (NULL);
	stored_lines[fd] = gnl_memmove(stored_lines[fd]);
	if (stored_lines[fd] && *stored_lines[fd] == '\0')
	{
		free(stored_lines[fd]);
		stored_lines[fd] = NULL;
	}
	return (line_to_return);
}

char	*read_and_store(int *end_of_line, int fd, char *stored_line)
{
	char	*buffer;
	int		rd;

	buffer = gnl_calloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(stored_line), NULL);
	rd = 1;
	while (*end_of_line == -1 && rd > 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
			return (free(stored_line), free(buffer), NULL);
		buffer[rd] = '\0';
		if (rd > 0)
			stored_line = gnl_cat(stored_line, buffer);
		*end_of_line = gnl_find_newline(stored_line);
	}
	free(buffer);
	return (stored_line);
}

char	*extract_line(int *end_of_line, char *stored_line, char *line_to_return)
{
	int		i;

	if (!stored_line)
		return (NULL);
	line_to_return = gnl_calloc(gnl_strlen(stored_line) + 1);
	if (!line_to_return)
		return (NULL);
	i = 0;
	while (stored_line[i] && stored_line[i] != '\n')
	{
		line_to_return[i] = stored_line[i];
		i++;
	}
	if (stored_line[i] == '\n')
	{
		line_to_return[i++] = '\n';
		*end_of_line = i;
	}
	line_to_return[i] = '\0';
	return (line_to_return);
}
