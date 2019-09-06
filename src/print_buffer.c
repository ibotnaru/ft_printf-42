/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 23:29:38 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/08/13 00:49:14 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*put_buffer(va_list ap, t_flags *all_fl)
{
	char	*buffer;

	if (all_fl->specifier == 'c')
		return (buffer = return_buffer_c(ap, all_fl));
	else if (all_fl->specifier == 's')
		return (buffer = return_buffer_s(ap, all_fl));
	else if (all_fl->specifier == 'd' || all_fl->specifier == 'i')
		return (buffer = return_buffer_d(ap, all_fl));
	else if (all_fl->specifier == 'o')
		return (buffer = return_buffer_o1(ap, all_fl));
	else if (all_fl->specifier == 'x')
		return (buffer = return_buffer_x1(ap, all_fl));
	else if (all_fl->specifier == 'X')
		return (buffer = return_buffer_xcapital1(ap, all_fl));
	else if (all_fl->specifier == 'u')
		return (buffer = return_buffer_u(ap, all_fl));
	else if (all_fl->specifier == 'p')
		return (buffer = return_buffer_p(ap, all_fl));
	else if (all_fl->specifier == '%')
		return (buffer = return_percent(all_fl));
	else if (all_fl->specifier == 'f')
		return (buffer = "Here should be float...");
	else
		return (NULL);
}

char		*return_percent(t_flags *all_fl)
{
	char	*buffer;

	buffer = NULL;
	if (all_fl->width_flag == 1)
	{
		if (all_fl->zero_flag == 1)
		{
			if (all_fl->minus_flag == 1)
				buffer = ft_strjoin("%", put_spaces(all_fl->width_size, 1));
			else
				buffer = ft_strjoin(put_zeroes(all_fl->width_size, 1), "%");
		}
		else if (all_fl->minus_flag == 1)
			buffer = ft_strjoin("%", put_spaces(all_fl->width_size, 1));
		else
			buffer = ft_strjoin(put_spaces(all_fl->width_size, 1), "%");
	}
	else
		buffer = "%";
	return (buffer);
}

int			ft_print_buffer(char *buffer)
{
	int		i;

	i = 0;
	while (buffer[i])
	{
		write(1, &buffer[i], 1);
		i++;
	}
	return (ft_strlen(buffer));
}
