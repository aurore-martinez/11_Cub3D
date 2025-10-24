/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumartin <aumartin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:02:13 by aumartin          #+#    #+#             */
/*   Updated: 2024/05/20 13:54:15 by aumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

/* #include <stdio.h>
#include <ctype.h>
int main ()
{
	printf("%d : %d\n", ft_toupper('a'), toupper('a'));
    printf("%d : %d\n", ft_toupper(97), toupper(97));
	return (0);
} */
