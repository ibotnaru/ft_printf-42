/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 15:32:45 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/08/12 18:18:02 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*itoa_fill_un(char *str, uintmax_t value, int base)
{
	int				len;
	uintmax_t		tmp;
	char			*rest;

	len = 0;
	tmp = value;
	while (tmp /= base)
		len++;
	len += 1;
	rest = (char *)malloc(sizeof(char) * (len + 1));
	rest[len] = '\0';
	while (len > 0)
	{
		rest[len - 1] = str[value % base];
		len--;
		value /= base;
	}
	return (rest);
}

char		*ft_itoa_base_o(uintmax_t value, int base)
{
	char		*str;
	char		*rest;

	str = "0123456789abcdef";
	rest = itoa_fill_un(str, value, base);
	return (rest);
}

void		itoa_filler_init(uintmax_t *tmp,
				uintmax_t value, int *size, int base)
{
	*size = 0;
	*tmp = value;
	while (*tmp /= base)
		(*size)++;
	*size = *size + 1;
}

char		*itoa_filler_b(char *tab, uintmax_t value, int base)
{
	uintmax_t		tmp;
	int				size;
	char			*str;

	itoa_filler_init(&tmp, value, &size, base);
	str = (char *)malloc(sizeof(char) * size + 1);
	str[size] = '\0';
	while (size > 0)
	{
		str[size - 1] = tab[value % base];
		size--;
		value = value / base;
	}
	return (str);
}

char		*ft_itoa_base_ux(uintmax_t value, int base)
{
	char		*str;
	char		*rest;

	str = "0123456789abcdef";
	rest = itoa_filler_b(str, value, base);
	return (rest);
}
