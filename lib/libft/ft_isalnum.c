/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumartin <aumartin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:55:43 by aumartin          #+#    #+#             */
/*   Updated: 2024/05/21 09:58:41 by aumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	else
		return (0);
}

/* #include <stdio.h>
#include <ctype.h>
int main()
{
	printf("%d : %d\n", ft_isalnum('a'), isalnum('a'));
	printf("%d : %d\n", ft_isalnum('\0'), isalnum('\0'));
	printf("%d : %d\n", ft_isalnum('1'), isalnum('1'));
	printf("%d : %d\n", ft_isalnum('N'), isalnum('N'));
	printf("%d : %d\n", ft_isalnum('\n'), isalnum('\n'));
	printf("%d : %d\n", ft_isalnum(126), isalnum(126));
	printf("%d : %d\n", ft_isalnum(87), isalnum(87));
} */
