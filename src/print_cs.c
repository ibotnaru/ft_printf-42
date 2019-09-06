/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 17:51:57 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/08/13 00:51:18 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*str_put_precision(int precision, char *str)
{
	char	*new_prec_buf;
	int		i;

	i = 0;
	if (precision < (int)ft_strlen(str))
	{
		new_prec_buf = ft_strnew(precision + 1);
		while (precision > 0)
		{
			new_prec_buf[i] = str[i];
			i++;
			precision--;
		}
		new_prec_buf[i] = '\0';
		return (new_prec_buf);
	}
	else
		return (NULL);
}

char	*return_buffer_s(va_list ap, t_flags *all_fl)
{
	char	*buffer;
	char	*str;

	str = va_arg(ap, char *);
	if (str == NULL)
		return ("(null)");
	if (all_fl->width_flag == 1 && all_fl->p_fl == 1)
		buffer = width_on_prec_on_s(all_fl, str);
	else if (all_fl->width_flag == 0 && all_fl->p_fl == 1)
		buffer = width_off_prec_on_s(all_fl, str);
	else if (all_fl->width_flag == 1 && all_fl->p_fl == 0)
		buffer = width_on_prec_off_s(all_fl, str);
	else
		buffer = ft_strdup(str);
	return (buffer);
}

char	*print_nullterm(t_flags *all_fl)
{
	int		i;
	char	*buffer;

	i = 0;
	buffer = malloc(sizeof(char) * (all_fl->width_size + 1));
	buffer[0] = '\0';
	i++;
	while (i < (all_fl->width_size))
	{
		buffer[i] = ' ';
		i++;
	}
	buffer[i] = '\0';
	all_fl->c_length = all_fl->width_size;
	return (buffer);
}

char	*return_buffer_c_init(va_list ap, char **buffer, char *ch)
{
	char		*character;

	*buffer = NULL;
	*ch = (char)va_arg(ap, int);
	character = ft_strnew(2);
	character[0] = *ch;
	character[1] = '\0';
	return (character);
}

char	*return_buffer_c(va_list ap, t_flags *all_fl)
{
	char	*buffer;
	char	*character;
	char	ch;

	character = return_buffer_c_init(ap, &buffer, &ch);
	if (all_fl->width_flag == 1 && all_fl->width_size > 1)
	{
		if (all_fl->minus_flag == 1)
		{
			if (ch == '\0')
				return (buffer = print_nullterm(all_fl));
			else
				buffer = ft_strjoin(character,
						put_spaces(all_fl->width_size, 1));
		}
		else
			buffer = ft_strjoin(put_spaces(all_fl->width_size, 1), character);
		all_fl->c_length = all_fl->width_size;
	}
	else
	{
		buffer = character;
		all_fl->c_length = 1;
	}
	return (buffer);
}
