/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_d_u_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 13:14:14 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/08/08 23:27:55 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int64_t		get_d_number(va_list ap, t_flags *all_fl)
{
	int64_t	number;

	if (all_fl->hh_flag == 1)
		number = (signed char)(va_arg(ap, int));
	else if (all_fl->h_flag == 1)
		number = (short)(va_arg(ap, int));
	else if (all_fl->ll_flag == 1)
		number = (long long)(va_arg(ap, long long));
	else if (all_fl->l_flag == 1)
		number = (long)(va_arg(ap, long));
	else
		number = (int)(va_arg(ap, int));
	number = (int64_t)number;
	return (number);
}

uint64_t	get_u_number(va_list ap, t_flags *all_fl)
{
	uint64_t	number;

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
	number = (uint64_t)number;
	return (number);
}
