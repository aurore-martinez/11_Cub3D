/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumartin <aumartin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:30:57 by aumartin          #+#    #+#             */
/*   Updated: 2024/05/21 13:39:47 by aumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new;
	unsigned int	i;

	if (start >= ft_strlen(s))
		len = 0;
	else if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (start + i < ft_strlen(s) && i < len)
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

/* #include <stdio.h>

int	main()
{
	char	*result;

	result = ft_substr("Coucou Aurore", 7, 6);
	printf("%s : Aurore\n", result);
	free(result);

	result = ft_substr("Coucou Aurore", 20, 5);
	printf("%s : "" \n", result);
	free(result);

	result = ft_substr("Coucou", 1, 10);
	printf("%s : oucou\n", result);
	free(result);

	result = ft_substr("Coucou", 2, 0);
	printf("%s : "" \n", result);
	free(result);

	result = ft_substr("Coucou", 0, 3);
	printf("%s : Cou\n", result);
	free(result);

	result = ft_substr("Coucou Aurore", 3, 10);
	printf("%s : cou Aurore\n", result);
	free(result);

	result = ft_substr("", 0, 5);
	printf("%s : "" \n", result);
	free(result);

	result = ft_substr("Coucou", 0, 6);
	printf("%s : Coucou\n", result);
	free(result);

	return (0);
}
 */
