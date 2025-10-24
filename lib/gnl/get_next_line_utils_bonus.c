/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   get_next_line_utils_bonus.c						:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: aumartin <aumartin@42.fr>				  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/06/07 11:40:39 by aumartin		  #+#	#+#			 */
/*   Updated: 2024/06/10 11:09:32 by aumartin		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*gnl_calloc(size_t size)
{
	char	*ptr;
	size_t	i;

	ptr = (char *)malloc(size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < size)
		ptr[i++] = '\0';
	return (ptr);
}

char	*gnl_cat(char *current_line, char *buffer)
{
	char	*new_line;
	int		i;
	int		j;

	if (!current_line)
	{
		current_line = gnl_calloc(1);
		if (!current_line)
			return (NULL);
	}
	new_line = gnl_calloc(gnl_strlen(current_line) + gnl_strlen(buffer) + 1);
	if (!new_line)
		return (free(current_line), NULL);
	i = 0;
	while (current_line[i])
	{
		new_line[i] = current_line[i];
		i++;
	}
	j = 0;
	while (buffer[j])
		new_line[i++] = buffer[j++];
	free(current_line);
	return (new_line);
}

int	gnl_strlen(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

int	gnl_find_newline(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*gnl_memmove(char *current_line)
{
	char	*new_line;
	int		i;
	int		j;

	if (!current_line)
		return (NULL);
	i = 0;
	while (current_line[i] && current_line[i] != '\n')
		i++;
	if (current_line[i] == '\n')
		i++;
	new_line = gnl_calloc(gnl_strlen(current_line + i) + 1);
	if (!new_line)
		return (NULL);
	j = 0;
	while (current_line[i])
		new_line[j++] = current_line[i++];
	free(current_line);
	return (new_line);
}
