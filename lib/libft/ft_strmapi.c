/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumartin <aumartin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:28:18 by aumartin          #+#    #+#             */
/*   Updated: 2024/05/28 14:07:34 by aumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*new;

	if (!f)
		return (NULL);
	new = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new[i] = (*f)(i, s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}

/* char add_index(unsigned int i, char c)
{
	return (c + i);
}

#include <stdio.h>
int	main()
{
	char *strmapi_result = ft_strmapi("abcde", &add_index);
	printf("ft_strmapi: %s\n", strmapi_result);
	free(strmapi_result);
	return (0);
} */
