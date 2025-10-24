/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumartin <aumartin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:33:56 by aumartin          #+#    #+#             */
/*   Updated: 2024/05/21 14:05:28 by aumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	size_t	i;
	size_t	j;

	joined = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!joined)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		joined[i + j] = s2[j];
		j++;
	}
	joined[i + j] = '\0';
	return (joined);
}

/*
#include <stdio.h>
int main()
{
	char *result = ft_strjoin("Salut Aurore," , "comment ca va ?");
	if (result == NULL)
	{
		printf("Erreur Aurore\n");
		return (1);
	}
	printf("%s : Salut Aurore,comment ca va ?\n", result);
	free(result);

	char *result2 = ft_strjoin("", "Aurore");
	if (result2 == NULL)
	{
		printf("Erreur d'allocation\n");
		return (1);
	}
	printf("%s : Aurore\n", result2);
	free(result2);

	char *result3 = ft_strjoin("Salut", "");
	if (result3 == NULL)
	{
		printf("Erreur d'allocation\n");
		return (1);
	}
	printf("%s : Salut\n", result3);
	free(result3);

	char *result4 = ft_strjoin("", "");
	if (result4 == NULL)
	{
		printf("Erreur d'allocation\n");
		return (1);
	}
	printf("%s : "" \n", result4);
	free(result4);

	char *intermediate = ft_strjoin("Salut", " ");
	char *result5 = ft_strjoin(intermediate, "Aurore");
	free(intermediate);
	intermediate = result5;
	result5 = ft_strjoin(intermediate, ", comment");
	free(intermediate);
	intermediate = result5;
	result5 = ft_strjoin(intermediate, " ça va");
	free(intermediate);
	intermediate = result5;
	result5 = ft_strjoin(intermediate, " ?");
	free(intermediate);

	if (result5 == NULL)
	{
		printf("Erreur d'allocation\n");
		return (1);
	}
	printf("%s : Salut Aurore, comment ça va ?\n", result5);
	free(result5);

	return (0);
}
 */
