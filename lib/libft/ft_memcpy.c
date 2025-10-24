/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumartin <aumartin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:00:21 by aumartin          #+#    #+#             */
/*   Updated: 2024/05/27 12:52:26 by aumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
		i++;
	}
	return (dst);
}

/* #include <stdio.h>
#include <string.h>

int main() {
    char src[] = "Coucou ca va?";
    char dst1[20];
    char dst2[20];

    ft_memcpy(dst1, src, strlen(src) + 1);
    memcpy(dst2, src, strlen(src) + 1);
    printf("ft_memcpy: %s\n", dst1);
    printf("memcpy:    %s\n", dst2);

    ft_memcpy(dst1, src, 5);
    memcpy(dst2, src, 5);
    dst1[5] = '\0';
    dst2[5] = '\0';
    printf("ft_memcpy (partial): %s\n", dst1);
    printf("memcpy (partial):    %s\n", dst2);

    return 0;
} */
