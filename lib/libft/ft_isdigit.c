/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumartin <aumartin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:55:31 by aumartin          #+#    #+#             */
/*   Updated: 2024/05/21 09:56:58 by aumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/* #include <stdio.h>
#include <ctype.h>
int main()
{
	printf("%d : %d\n", ft_isdigit('7'), isdigit('7'));
	printf("%d : %d\n", ft_isdigit('\0'), isdigit('\0'));
	printf("%d : %d\n", ft_isdigit('1'), isdigit('1'));
	printf("%d : %d\n", ft_isdigit('N'), isdigit('N'));
	printf("%d : %d\n", ft_isdigit('\n'), isdigit('\n'));
	printf("%d : %d\n", ft_isdigit(127), isdigit(127));
	printf("%d : %d\n", ft_isdigit(33), isdigit(33));
} */
