/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumartin <aumartin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:02:20 by aumartin          #+#    #+#             */
/*   Updated: 2024/05/20 13:54:13 by aumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

/* #include <stdio.h>
#include <ctype.h>
int main ()
{
	printf("%d : %d\n", ft_tolower('A'), tolower('A'));
    printf("%d : %d\n", ft_tolower(65), tolower(65));
	return (0);
} */
