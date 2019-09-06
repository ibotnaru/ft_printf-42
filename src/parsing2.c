/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 14:51:46 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/08/12 18:40:08 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_and_store_flags(const char *format, t_flags *all_fl, int *i)
{
	while (format[*i] == '#' || format[*i] == '0' || format[*i] == ' ' ||
			format[*i] == '-' || format[*i] == '+')
	{
		if (format[*i] == '#')
			all_fl->hash_flag = 1;
		if (format[*i] == '+')
			all_fl->plus_flag = 1;
		if (format[*i] == '0')
			all_fl->zero_flag = 1;
		if (format[*i] == ' ')
			all_fl->space_flag = 1;
		if (format[*i] == '-')
			all_fl->minus_flag = 1;
		(*i)++;
	}
}

void	get_and_store_width(const char *format, t_flags *all_fl, int *i)
{
	if (format[*i] > '0' && format[*i] <= '9')
	{
		all_fl->width_flag = 1;
		all_fl->width_size = ft_atoi(&format[*i]);
	}
	while (format[*i] >= '0' && format[*i] <= '9')
		(*i)++;
}

void	get_and_store_precision(const char *format, t_flags *all_fl, int *i)
{
	if (format[*i] == '.')
		(*i)++;
	if (format[*i] > '0' && format[*i] <= '9')
	{
		all_fl->p_fl = 1;
		all_fl->p_sz = ft_atoi(&format[*i]);
	}
	while (format[*i] >= '0' && format[*i] <= '9')
		(*i)++;
}

void	get_and_store_l(const char *format, t_flags *all_fl, int *i)
{
	if (format[*i] == 'l')
	{
		if (format[*i + 1] == 'l')
		{
			all_fl->ll_flag = 1;
			*i = *i + 2;
		}
		else
		{
			all_fl->l_flag = 1;
			(*i)++;
		}
	}
	else if (format[*i] == 'L')
	{
		all_fl->big_l_flag = 1;
		(*i)++;
	}
}

void	get_and_store_h(const char *format, t_flags *all_fl, int *i)
{
	if (format[*i] == 'h')
	{
		if (format[*i + 1] == 'h')
		{
			all_fl->hh_flag = 1;
			*i = *i + 2;
		}
		else
		{
			all_fl->h_flag = 1;
			(*i)++;
		}
	}
}
