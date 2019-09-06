/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_d_negative.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 22:32:03 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/07/24 12:40:24 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*width_off_prec_on_d_negative(t_flags *all_fl, char *str_num)
{
	char	*buffer;
	int		num_len;
	char	*zero_buf;

	num_len = ft_strlen(str_num);
	if (all_fl->p_sz > num_len)
	{
		zero_buf = put_zeroes(all_fl->p_sz, num_len);
		buffer = ft_strjoin(zero_buf, str_num);
		buffer = ft_strjoin_free("-", buffer, 2);
	}
	else
		buffer = ft_strjoin("-", str_num);
	return (buffer);
}

char	*width_on_prec_off_d_negative(t_flags *all_fl, char *str_num)
{
	char	*buffer;
	int		num_len;

	num_len = ft_strlen(str_num);
	if (all_fl->width_size > (num_len + 1))
	{
		if (all_fl->zero_flag == 1)
		{
			buffer = ft_strjoin(put_zeroes(all_fl->width_size,
						num_len + 1), buffer);
			buffer = ft_strjoin_free("-", buffer, 2);
			return (buffer);
		}
		buffer = ft_strjoin("-", str_num);
		if (all_fl->minus_flag == 1)
			buffer = ft_strjoin_free(buffer,
					put_spaces(all_fl->width_size, num_len + 1), 1);
		else
			buffer = ft_strjoin_free(put_spaces(all_fl->width_size,
						num_len + 1), buffer, 2);
	}
	else
		buffer = ft_strjoin("-", str_num);
	return (buffer);
}

char	*put_d_buff(t_flags *all_fl, char *buffer)
{
	char	*buffer2;
	int		buf_len;

	buf_len = ft_strlen(buffer);
	if (all_fl->minus_flag == 1)
		buffer2 = ft_strjoin_free(buffer,
				put_spaces(all_fl->width_size, buf_len), 1);
	else
		buffer2 = ft_strjoin_free(put_spaces(all_fl->width_size,
					buf_len), buffer, 2);
	return (buffer2);
}

char	*width_on_prec_on_d_negative(t_flags *all_fl, char *str_num)
{
	char	*buffer;
	int		num_len;

	num_len = ft_strlen(str_num);
	if (all_fl->width_size > num_len + 1)
	{
		if (all_fl->p_sz > num_len)
			buffer = ft_strjoin(put_zeroes(all_fl->p_sz, num_len), str_num);
		else
			buffer = ft_strdup(str_num);
		buffer = ft_strjoin_free("-", buffer, 2);
		buffer = put_d_buff(all_fl, buffer);
	}
	else
	{
		if (all_fl->p_sz > num_len)
		{
			buffer = ft_strjoin(put_zeroes(all_fl->p_sz, num_len), str_num);
			buffer = ft_strjoin_free("-", buffer, 2);
			return (buffer);
		}
		else
			buffer = ft_strjoin("-", str_num);
	}
	return (buffer);
}
