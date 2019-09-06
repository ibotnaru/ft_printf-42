/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 18:57:14 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/08/12 18:57:47 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uint64_t	ft_power_p(uint64_t nb, int pow)
{
	if (pow == 0)
		return (1);
	else if (pow < 0)
		return (0);
	return (nb * ft_power_p(nb, pow - 1));
}

uint64_t	ft_long_power_p(uint64_t num, long pow)
{
	if (pow == 0)
		return (1);
	else if (pow < 0)
		return (0);
	return (num * ft_power_p(num, pow - 1));
}

uint64_t	ft_biglen(uint64_t num, int base)
{
	uint64_t	len;

	len = 1;
	while (ft_long_power_p(base, len) <= num)
		len++;
	return (len);
}
