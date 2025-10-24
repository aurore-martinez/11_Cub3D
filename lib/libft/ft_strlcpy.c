/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumartin <aumartin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:01:53 by aumartin          #+#    #+#             */
/*   Updated: 2024/05/23 15:46:31 by aumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	i = 0;
	while (src[i] && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize > 0)
		dst[i] = '\0';
	return (src_len);
}

/* #include <stdio.h>
#include <string.h>
int main()
{
    char src[] = "Test test test";
    char dst[20];
    size_t copied;
    size_t copied_2;

    copied = ft_strlcpy(dst, src, sizeof(dst));
    copied_2 = strlcpy(dst, src, sizeof(dst));
    printf("Chaîne de destination : %s\n", dst);
    printf("Nombre de caractères copiés %zu : %zu\n", copied, copied_2);

    return 0;
} */
