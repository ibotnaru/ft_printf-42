/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:35:14 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/08/13 00:51:46 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*flag_zero_on_o(t_flags *all_fl, char *str_num)
{
	char	*buffer;

	if (all_fl->width_size > (int)ft_strlen(str_num) ||
			all_fl->p_sz > (int)ft_strlen(str_num))
	{
		if (all_fl->width_flag == 0 && all_fl->p_fl == 1)
			buffer = ft_strjoin(put_zeroes(all_fl->p_sz,
						ft_strlen(str_num)), str_num);
		else if (all_fl->width_flag == 1 && all_fl->p_fl == 0)
			buffer = ft_strjoin(put_zeroes(all_fl->width_size,
						ft_strlen(str_num)), str_num);
		else
		{
			buffer = ft_strjoin(put_zeroes(all_fl->p_sz,
						ft_strlen(str_num)), str_num);
			if (all_fl->width_size > all_fl->p_sz)
				buffer = ft_strjoin(put_spaces(all_fl->width_size,
							ft_strlen(buffer)), buffer);
			else
				buffer = ft_strdup(buffer);
		}
	}
	else
		buffer = ft_strdup(str_num);
	return (buffer);
}

char	*flag_hash_on2_o(t_flags *all_fl, char *str_num)
{
	char	*buffer;

	buffer = ft_strjoin(put_zeroes(all_fl->p_sz,
				ft_strlen(str_num)), str_num);
	if (all_fl->width_size > all_fl->p_sz)
		buffer = ft_strjoin(put_spaces(all_fl->width_size,
					ft_strlen(buffer)), buffer);
	else
		buffer = ft_strdup(buffer);
	return (buffer);
}

char	*flag_hash_on1_o(t_flags *all_fl, char *str_num)
{
	char	*buffer;

	if (all_fl->width_size > (int)ft_strlen(str_num) ||
			all_fl->p_sz > (int)ft_strlen(str_num))
	{
		if (all_fl->width_flag == 0 && all_fl->p_fl == 1)
			buffer = ft_strjoin(put_zeroes(all_fl->p_sz,
						ft_strlen(str_num)), str_num);
		else if (all_fl->width_flag == 1 && all_fl->p_fl == 0)
		{
			buffer = ft_strjoin("0", str_num);
			buffer = ft_strjoin(put_spaces(all_fl->width_size,
						ft_strlen(buffer)), buffer);
		}
		else
			buffer = flag_hash_on2_o(all_fl, str_num);
	}
	else
		buffer = ft_strjoin("0", str_num);
	return (buffer);
}

char	*flag_minus_on_o(t_flags *all_fl, char *str_num)
{
	char	*buffer;

	if (all_fl->width_size > (int)ft_strlen(str_num) ||
			all_fl->p_sz > (int)ft_strlen(str_num))
	{
		if (all_fl->width_flag == 0 && all_fl->p_fl == 1)
			buffer = ft_strjoin(put_zeroes(all_fl->p_sz,
						ft_strlen(str_num)), str_num);
		else if (all_fl->width_flag == 1 && all_fl->p_fl == 0)
			buffer = ft_strjoin(str_num,
					put_spaces(all_fl->width_size, ft_strlen(str_num)));
		else
		{
			buffer = ft_strjoin(put_zeroes(all_fl->p_sz,
						ft_strlen(str_num)), str_num);
			if (all_fl->width_size > all_fl->p_sz)
				buffer = ft_strjoin(buffer,
						put_spaces(all_fl->width_size, ft_strlen(buffer)));
			else
				buffer = ft_strdup(buffer);
		}
	}
	else
		buffer = ft_strdup(str_num);
	return (buffer);
}
