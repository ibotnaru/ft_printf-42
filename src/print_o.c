/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:34:29 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/08/12 20:38:09 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*return_buffer_o2(t_flags *all_fl, char *str_num)
{
	char	*buffer;

	if (all_fl->width_flag == 1 && all_fl->p_fl == 1)
	{
		buffer = ft_strjoin(put_zeroes(all_fl->p_sz,
					ft_strlen(str_num)), str_num);
		if (all_fl->width_size > all_fl->p_sz)
			buffer = ft_strjoin(put_spaces(all_fl->width_size,
						ft_strlen(buffer)), buffer);
		else
			buffer = ft_strdup(buffer);
	}
	else if (all_fl->width_flag == 1 && all_fl->p_fl == 0)
		buffer = ft_strjoin(put_spaces(all_fl->width_size,
					ft_strlen(str_num)), str_num);
	else if (all_fl->p_fl == 1 && all_fl->width_flag == 0)
		buffer = ft_strjoin(put_zeroes(all_fl->p_sz,
					ft_strlen(str_num)), str_num);
	else
		buffer = ft_strdup(str_num);
	return (buffer);
}

char	*return_buffer_o3(t_flags *all_fl, char *str_num)
{
	char	*buffer;

	buffer = NULL;
	if (all_fl->hash_flag == 1 && all_fl->minus_flag == 1)
		buffer = flag_hash_and_minus_on_o(all_fl, str_num);
	else if (all_fl->hash_flag == 1 && all_fl->zero_flag == 1)
		buffer = flag_zero_and_hash_on_o(all_fl, str_num);
	else if (all_fl->zero_flag == 1)
		buffer = flag_zero_on_o(all_fl, str_num);
	else if (all_fl->hash_flag == 1)
		buffer = flag_hash_on1_o(all_fl, str_num);
	else if (all_fl->minus_flag == 1)
		buffer = flag_minus_on_o(all_fl, str_num);
	else
		buffer = return_buffer_o2(all_fl, str_num);
	return (buffer);
}

char	*return_buffer_o1(va_list ap, t_flags *all_fl)
{
	char		*str_num;
	char		*buffer;
	uintmax_t	number;

	if (all_fl->hh_flag == 1)
		number = (unsigned char)(va_arg(ap, int));
	else if (all_fl->h_flag == 1)
		number = (unsigned short)(va_arg(ap, int));
	else if (all_fl->ll_flag == 1)
		number = (unsigned long long)(va_arg(ap, long long int));
	else if (all_fl->l_flag == 1)
		number = (unsigned long)(va_arg(ap, long int));
	else
		number = (unsigned int)(va_arg(ap, int));
	number = (uintmax_t)number;
	buffer = NULL;
	str_num = ft_itoa_base_o(number, 8);
	if (number == 0)
		all_fl->hash_flag = 0;
	buffer = return_buffer_o3(all_fl, str_num);
	return (buffer);
}
