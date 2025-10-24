/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumartin <aumartin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:57:12 by aumartin          #+#    #+#             */
/*   Updated: 2024/05/20 13:53:01 by aumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/* #include <stdio.h>
#include <string.h>
int main()
{
    char str[10] = "Hello";
    printf("str avant ft_bzero: %s\n", str);
    ft_bzero(str, 5);
    // bzero(str, 5);
    printf("str après ft_bzero: %s\n", str);
    return 0;
} */
