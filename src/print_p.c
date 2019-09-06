/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 00:18:07 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/08/13 00:51:08 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*return_buffer_p(va_list ap, t_flags *all_fl)
{
	char		*buffer;
	intmax_t	add_p;

	add_p = va_arg(ap, unsigned long);
	buffer = ft_itoa_base_p(add_p, 16);
	buffer = ft_strjoin("0x", buffer);
	if (all_fl->width_flag == 1)
	{
		if (all_fl->minus_flag == 1)
			buffer = ft_strjoin(buffer,
				put_spaces(all_fl->width_size, ft_strlen(buffer)));
		else
			buffer = ft_strjoin(put_spaces(all_fl->width_size,
				ft_strlen(buffer)), buffer);
	}
	return (buffer);
}

intmax_t	ft_abs(intmax_t nbr)
{
	if (nbr < 0)
		nbr = -nbr;
	return (nbr);
}

char		*itoa_filler_pointer(char *tab, intmax_t val, int base, int flag)
{
	uintmax_t		tmp;
	int				size;
	char			*str;

	size = 0;
	tmp = ft_abs(val);
	while (tmp /= base)
		size++;
	size = size + flag + 1;
	str = (char *)malloc(sizeof(char) * size + 1);
	str[size] = '\0';
	if (flag == 1)
		str[0] = '-';
	while (size > flag)
	{
		str[size - 1] = tab[ft_abs(val % base)];
		size--;
		val = val / base;
	}
	return (str);
}

char		*ft_itoa_base_p(intmax_t value, int base)
{
	char		*str;
	char		*tab;
	int			flag;

	flag = 0;
	tab = "0123456789abcdef";
	if (value < 0 && base == 10)
		flag = 1;
	str = itoa_filler_pointer(tab, value, base, flag);
	return (str);
}
