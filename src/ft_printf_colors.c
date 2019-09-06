/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_colors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 01:27:07 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/08/12 23:25:32 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_color g_colors[] =
{
	{"{red}", "\033[0;31m"},
	{"{green}", "\033[0;32m"},
	{"{yellow}", "\033[0;33m"},
	{"{blue}", "\033[0;34m"},
	{"{purple}", "\033[0;35m"},
	{"{cyan}", "\033[0;36m"},
	{"{reset}", "\033[0;0m"},
	{NULL, NULL},
};

int		ft_print_colors(const char *format, int i)
{
	int		j;
	char	color[20];

	j = 0;
	while (format[i] != '}' && format[i] != '\0')
	{
		color[j] = format[i];
		if (format[i + 1] == '}')
			color[j + 1] = '}';
		i++;
		j++;
	}
	color[j + 1] = '\0';
	j = -1;
	while (g_colors[++j].color)
	{
		if (ft_strcmp(color, g_colors[j].color) == 0)
		{
			ft_putstr(g_colors[j].color_code);
			return (ft_strlen(color));
		}
	}
	ft_printf("\033[0m%s", color);
	return (((format[j] != '\0') ? ft_strlen(color) : 0));
}
