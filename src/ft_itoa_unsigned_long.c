/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned_long.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 14:40:29 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/08/08 22:53:52 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len_unsigned_long(uint64_t n)
{
	int		nbrc;
	int		len;

	len = 0;
	nbrc = n;
	while (nbrc != 0)
	{
		nbrc = nbrc / 10;
		len++;
	}
	return (len);
}

char		*ft_itoa_unsigned_long(uint64_t n)
{
	int		len;
	char	*str;

	len = ft_len_unsigned_long(n);
	if (!(str = malloc(sizeof(char*) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[len-- - 1] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}
