/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_negative.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 16:15:44 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/08/08 23:27:55 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_negative(int num)
{
	char	*str;

	if (num < 0)
	{
		num = num * (-1);
		str = ft_itoa(num);
	}
	else
		str = ft_itoa(num);
	return (str);
}
