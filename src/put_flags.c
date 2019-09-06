/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:21:34 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/07/25 20:48:14 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*put_zeroes(int len_flag, int len_strnum)
{
	char	*zeroes_buf;
	int		how_many_zeroes;
	int		i;

	zeroes_buf = NULL;
	if (len_flag > len_strnum)
	{
		how_many_zeroes = len_flag - len_strnum;
		zeroes_buf = ft_strnew(how_many_zeroes + 1);
		i = 0;
		while (how_many_zeroes > 0)
		{
			zeroes_buf[i] = '0';
			i++;
			how_many_zeroes--;
		}
		zeroes_buf[i] = '\0';
		return (zeroes_buf);
	}
	else
		return ("");
}

char	*put_spaces(int len_flag, int len_strnum)
{
	char	*spaces_buf;
	int		how_many_spaces;
	int		i;

	if (len_flag > len_strnum)
	{
		how_many_spaces = len_flag - len_strnum;
		spaces_buf = ft_strnew(how_many_spaces + 1);
		i = 0;
		while (how_many_spaces > 0)
		{
			spaces_buf[i] = ' ';
			i++;
			how_many_spaces--;
		}
		spaces_buf[i] = '\0';
		return (spaces_buf);
	}
	else
		return ("");
}
