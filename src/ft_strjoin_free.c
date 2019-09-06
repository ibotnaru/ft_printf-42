/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 19:50:41 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/08/08 23:27:55 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			free_str(char *str1, char *str2)
{
	free(str1);
	free(str2);
}

char			*ft_strjoin_free(void *s1, void *s2, int indx)
{
	char	*mem;
	int		l1;
	int		l2;
	char	*str1;
	char	*str2;

	str1 = (char *)s1;
	str2 = (char *)s2;
	if (!str1 || !str2)
		return (NULL);
	l1 = ft_strlen(str1);
	l2 = ft_strlen(str2);
	mem = ft_strnew(l1 + l2);
	if (mem != NULL)
	{
		ft_strcpy(mem, str1);
		ft_strcpy(mem + l1, str2);
	}
	if (indx == 1)
		free(str1);
	else if (indx == 2)
		free(str2);
	else
		free_str(str1, str2);
	return (mem);
}
