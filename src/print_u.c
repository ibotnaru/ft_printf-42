/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 17:57:35 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/08/13 00:50:56 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*width_on_prec_on_u(t_flags *all_fl, char *str_num)
{
	char	*buffer;
	int		num_len;
	int		buf_len;

	num_len = ft_strlen(str_num);
	if (all_fl->p_sz > num_len)
		buffer = ft_strjoin(put_zeroes(all_fl->p_sz,
					num_len), str_num);
	else
		buffer = ft_strdup(str_num);
	buf_len = ft_strlen(buffer);
	if (all_fl->width_size > buf_len)
	{
		if (all_fl->minus_flag == 1)
			buffer = ft_strjoin_free(buffer,
					put_spaces(all_fl->width_size, buf_len), 1);
		else
			buffer = ft_strjoin_free(put_spaces(all_fl->width_size,
						buf_len), buffer, 2);
	}
	else
		buffer = ft_strdup(buffer);
	return (buffer);
}

char	*width_on_prec_off_u(t_flags *all_fl, char *str_num)
{
	char	*buffer;
	int		num_len;

	num_len = ft_strlen(str_num);
	if (all_fl->width_size > num_len)
	{
		if (all_fl->zero_flag == 1)
		{
			buffer = ft_strjoin(put_zeroes(all_fl->width_size,
						num_len), str_num);
			return (buffer);
		}
		if (all_fl->minus_flag == 1)
			buffer = ft_strjoin(str_num,
					put_spaces(all_fl->width_size, num_len));
		else
			buffer = ft_strjoin(put_spaces(all_fl->width_size,
						num_len), str_num);
	}
	else
		buffer = ft_strdup(str_num);
	return (buffer);
}

char	*width_off_prec_on_u(t_flags *all_fl, char *str_num)
{
	char	*buffer;
	int		num_len;

	num_len = ft_strlen(str_num);
	if (all_fl->p_sz > num_len)
		buffer = ft_strjoin(put_zeroes(all_fl->p_sz,
					num_len), str_num);
	else
		buffer = ft_strdup(str_num);
	return (buffer);
}

char	*print_u(t_flags *all_fl, uint64_t number)
{
	char	*str_num;
	char	*buffer;
	int		num_len;

	str_num = ft_itoa_unsigned_long(number);
	num_len = ft_strlen(str_num);
	if (all_fl->width_flag == 0 && all_fl->p_fl == 0)
		buffer = ft_strdup(str_num);
	else if (all_fl->width_flag == 0 && all_fl->p_fl == 1)
		buffer = width_off_prec_on_u(all_fl, str_num);
	else if (all_fl->width_flag == 1 && all_fl->p_fl == 0)
		buffer = width_on_prec_off_u(all_fl, str_num);
	else
		buffer = width_on_prec_on_u(all_fl, str_num);
	return (buffer);
}

char	*return_buffer_u(va_list ap, t_flags *all_fl)
{
	char		*buffer;
	uint64_t	number;

	number = get_u_number(ap, all_fl);
	buffer = print_u(all_fl, number);
	return (buffer);
}
