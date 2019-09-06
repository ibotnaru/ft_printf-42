/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 15:25:29 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/08/12 18:30:39 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long	ft_long_power(long num, long pow)
{
	if (pow == 0)
		return (1);
	else if (pow < 0)
		return (0);
	return (num * ft_power(num, pow - 1));
}

long	ft_numlen(long num, long base)
{
	long	len;

	len = 1;
	while (ft_long_power(base, len) <= num)
		len++;
	return (len);
}
