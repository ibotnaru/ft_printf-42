/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_d_positive2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 21:18:34 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/07/25 15:19:26 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*width_on_prec_on2_d_positive(t_flags *all_fl,
		char *str_num, int num_len)
{
	char	*buffer;

	if (all_fl->p_sz > num_len)
	{
		buffer = ft_strjoin(put_zeroes(all_fl->p_sz,
					num_len), str_num);
		if (all_fl->plus_flag == 1 || all_fl->space_flag == 1)
		{
			if (all_fl->plus_flag == 1)
				buffer = ft_strjoin_free("+", buffer, 2);
			else
				buffer = ft_strjoin_free(" ", buffer, 2);
		}
	}
	else
		buffer = ft_strdup(str_num);
	return (buffer);
}

char	*width_on_prec_on_d_positive(t_flags *all_fl,
		char *str_num, int num_len)
{
	char	*buffer;

	if (all_fl->width_size > num_len)
	{
		if (all_fl->p_sz > num_len)
			buffer = ft_strjoin(put_zeroes(all_fl->p_sz, num_len), str_num);
		else
			buffer = ft_strdup(str_num);
		if (all_fl->plus_flag == 1 || all_fl->space_flag == 1)
		{
			if (all_fl->plus_flag == 1)
				buffer = ft_strjoin_free("+", buffer, 2);
			else
				buffer = ft_strjoin_free(" ", buffer, 2);
		}
		if (all_fl->minus_flag == 1)
			buffer = ft_strjoin_free(buffer,
					put_spaces(all_fl->width_size, ft_strlen(buffer)), 1);
		else
			buffer = ft_strjoin_free(put_spaces(all_fl->width_size,
						ft_strlen(buffer)), buffer, 2);
	}
	else
		buffer = width_on_prec_on2_d_positive(all_fl, str_num, num_len);
	return (buffer);
}
