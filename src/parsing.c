/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 22:08:09 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/08/11 02:23:28 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			find_specifier2(t_flags *all_fl, const char *format, int *i)
{
	if (format[*i] == 'X')
		all_fl->specifier = 'X';
	else if (format[*i] == 'u')
		all_fl->specifier = 'u';
	else if (format[*i] == 'p')
		all_fl->specifier = 'p';
}

void			find_specifier(t_flags *all_fl, const char *format, int *i)
{
	if (format[*i] == 'c')
		all_fl->specifier = 'c';
	else if (format[*i] == 's')
		all_fl->specifier = 's';
	else if (format[*i] == 'd')
		all_fl->specifier = 'd';
	else if (format[*i] == 'i')
		all_fl->specifier = 'i';
	else if (format[*i] == 'o')
		all_fl->specifier = 'o';
	else if (format[*i] == 'x')
		all_fl->specifier = 'x';
	else if (format[*i] == '%')
		all_fl->specifier = '%';
	else if (format[*i] == 'f')
		all_fl->specifier = 'f';
	else if (format[*i] == 'X' || format[*i] == 'p' || format[*i] == 'u')
		find_specifier2(all_fl, format, i);
}

void			parcing(const char *format, t_flags *all_fl, int *i)
{
	get_and_store_flags(format, all_fl, i);
	get_and_store_width(format, all_fl, i);
	get_and_store_precision(format, all_fl, i);
	get_and_store_l(format, all_fl, i);
	get_and_store_h(format, all_fl, i);
	find_specifier(all_fl, format, i);
}

char			*flag_hash_on2(t_flags *all_fl, char *str_num)
{
	char	*buffer;

	buffer = ft_strjoin(put_zeroes(all_fl->p_sz, ft_strlen(str_num)), str_num);
	buffer = ft_strjoin_free("0x", buffer, 2);
	if (all_fl->width_size > all_fl->p_sz)
		buffer = ft_strjoin_free(put_spaces(all_fl->width_size,
					ft_strlen(buffer)), buffer, 2);
	else
		buffer = ft_strdup(buffer);
	return (buffer);
}
