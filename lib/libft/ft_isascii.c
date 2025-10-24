/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumartin <aumartin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:55:53 by aumartin          #+#    #+#             */
/*   Updated: 2024/05/20 13:53:17 by aumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/* #include <stdio.h>
#include <ctype.h>
int main()
{
	printf("%d : %d\n", ft_isascii('a'), isascii('a'));
	printf("%d : %d\n", ft_isascii('\0'), isascii('\0'));
	printf("%d : %d\n", ft_isascii('1'), isascii('1'));
	printf("%d : %d\n", ft_isascii('N'), isascii('N'));
	printf("%d : %d\n", ft_isascii('\n'), isascii('\n'));
	printf("%d : %d\n", ft_isascii(126), isascii(126));
	printf("%d : %d\n", ft_isascii(87), isascii(87));
    printf("%d : %d\n", ft_isascii(243), isascii(243));
    printf("%d : %d\n", ft_isascii(0), isascii(0));
} */
