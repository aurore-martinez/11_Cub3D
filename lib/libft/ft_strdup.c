/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumartin <aumartin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:19:27 by aumartin          #+#    #+#             */
/*   Updated: 2024/05/20 15:40:52 by aumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		len;

	len = ft_strlen(src) + 1;
	dest = malloc(sizeof(char) * len);
	if (dest == NULL)
		return (NULL);
	*dest = 0;
	ft_strcpy(dest, src);
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>
int main()
{
char *result = ft_strdup("Test abcabc");
printf("%s\n", result);
// printf("%s\n", strdup("Test abcabc"));
free(result);
}
*/
