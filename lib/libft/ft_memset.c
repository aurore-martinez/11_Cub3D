/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumartin <aumartin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:56:20 by aumartin          #+#    #+#             */
/*   Updated: 2025/04/04 10:53:10 by aumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	/* if(!s)
			return (NULL);
	*/

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(s + i) = (unsigned char) c;
		i++;
	}
	return (s);
}

/* #include <stdio.h>
#include <string.h>
int main()
{
    char str[10];
    printf("str avant ft_memset: %s\n", str);
    ft_memset(str, 'A', 5);
    // memset(str, 'A', 5);
    printf("str après ft_memset: %s\n", str);
    return 0;
} */
