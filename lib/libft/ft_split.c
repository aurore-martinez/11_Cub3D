/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquel <tjacquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:55:51 by aumartin          #+#    #+#             */
/*   Updated: 2025/06/13 12:09:36 by tjacquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_strs(char *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

char	*get_word(char *str, char c)
{
	int		len_word;
	char	*word;

	len_word = 0;
	while (str[len_word] && str[len_word] != c)
		len_word++;
	word = (char *)malloc(sizeof(char) * (len_word + 1));
	if (!word)
		return (NULL);
	ft_strlcpy(word, str, len_word + 1);
	return (word);
}

void	free_split(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	**ft_split(char *str, char c)
{
	int		count;
	int		index;
	char	**strings;

	count = count_strs(str, c);
	strings = (char **)ft_calloc(count + 1, sizeof(char *));
	if (!strings)
		return (NULL);
	index = 0;
	while (*str)
	{
		if (*str != c)
		{
		strings[index] = get_word(str, c);
			if (!strings[index])
				return (free_split(strings), NULL);
			index++;
			while (*str && *str != c)
				str++;
		}
		else
			str++;
	}
	strings[index] = NULL;
	return (strings);
}

/* #include <stdio.h>
int main() {
char **split = ft_split(",,,,coucou, salut,,,,azazaz", ',');
if (split == NULL) {
printf("Erreur Alloc.\n");
return 1;
}
int index = 0;
while (split[index] != NULL) {
printf("%s\n", split[index]);
index++;
}

int i = 0;
while (split[i] != NULL)
{
free(split[i]);
i++;
}
free(split);
return 0;
} */
