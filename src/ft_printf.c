/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 17:57:02 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/08/12 23:43:31 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			final_print(va_list ap, const char *format, int *i)
{
	int				result;
	char			*buffer;
	t_flags			all_flags;

	result = 0;
	buffer = NULL;
	ft_bzero(&all_flags, sizeof(t_flags));
	parcing(format, &all_flags, i);
	buffer = put_buffer(ap, &all_flags);
	if (all_flags.specifier == 'c')
	{
		write(1, buffer, all_flags.c_length);
		result = all_flags.c_length;
		return (result);
	}
	else
		ft_putstr(buffer);
	result = ft_strlen(buffer);
	return (result);
}

int			ft_printf(const char *format, ...)
{
	int				i;
	int				result;
	va_list			ap;

	i = 0;
	result = 0;
	va_start(ap, format);
	while (format[i] != '\0')
	{
		while (format[i] != '%' && format[i] != '\0')
		{
			ft_putchar(format[i]);
			result++;
			i++;
		}
		if (format[i] == '%')
		{
			i++;
			result = result + final_print(ap, format, &i);
		}
		if (format[i] != '\0')
			i++;
	}
	va_end(ap);
	return (result);
}
