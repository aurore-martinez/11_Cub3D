/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumartin <aumartin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:56:00 by aumartin          #+#    #+#             */
/*   Updated: 2024/05/20 13:53:29 by aumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

/* #include <stdio.h>
#include <ctype.h>
int main()
{
	printf("%d : %d\n", ft_isprint('a'), isprint('a'));
	printf("%d : %d\n", ft_isprint('\0'), isprint('\0'));
	printf("%d : %d\n", ft_isprint('1'), isprint('1'));
	printf("%d : %d\n", ft_isprint('N'), isprint('N'));
	printf("%d : %d\n", ft_isprint('\n'), isprint('\n'));
	printf("%d : %d\n", ft_isprint(126), isprint(126));
	printf("%d : %d\n", ft_isprint(87), isprint(87));
    printf("%d : %d\n", ft_isprint(243), isprint(243));
    printf("%d : %d\n", ft_isprint(0), isprint(0));
} */
