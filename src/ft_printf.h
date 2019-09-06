/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:19:10 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/08/13 00:04:22 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define HEX 16
# define OCTET 8
# include "libft/libft.h"
# include <stdio.h>
# include <stdarg.h>

typedef struct	s_color
{
	char		*color;
	char		*color_code;
}				t_color;

typedef struct	s_flags
{
	char		specifier;
	int			width_size;
	int			width_flag;
	int			p_sz;
	int			p_fl;
	int			hash_flag;
	int			zero_flag;
	int			minus_flag;
	int			plus_flag;
	int			space_flag;
	int			l_flag;
	int			ll_flag;
	int			h_flag;
	int			hh_flag;
	int			c_length;
	int			big_l_flag;
}				t_flags;

int				ft_printf(const char *format, ...);
char			*put_buffer(va_list ap, t_flags *all_fl);
int				ft_print_buffer(char	*buffer);
char			*put_zeroes_precision(t_flags *all_fl, int num_len);
char			*put_zeroes_flag(t_flags *all_fl, int num_len);
char			*put_zeroes(int len_flag, int len_strnum);
char			*put_sign(char sign);
char			*put_spaces_width(t_flags *all_fl, int num_len);
char			*put_spaces_flag(t_flags *all_fl, int num_len);
char			*put_spaces(int len_flag, int len_strnum);
char			*return_buffer_o3(t_flags *all_fl, char *str_num);
char			*return_buffer_o1(va_list ap, t_flags *all_fl);
char			*return_buffer_o2(t_flags *all_fl, char *str_num);
char			*return_buffer_x1(va_list ap, t_flags *all_fl);
char			*return_buffer_x3(t_flags *all_fl, char *str_num);
char			*return_buffer_x2(t_flags *all_fl, char *str_num);
char			*return_buffer_xcapital1(va_list ap, t_flags *all_fl);
char			*return_buffer_xcapital2(t_flags *all_fl, char *str_num);
char			*return_buffer_xcapital3(t_flags *all_fl, char *str_num);
char			*flag_zero_on(t_flags *all_fl, char *str_num);
char			*flag_hash_on1(t_flags *all_fl, char *str_num);
char			*flag_hash_on2(t_flags *all_fl, char *str_num);
char			*flag_minus_on(t_flags *all_fl, char *str_num);
char			*flag_minus_on2(t_flags *all_fl, char *str_num);
char			*flag_zero_and_hash_on(t_flags *all_fl, char *str_num);
char			*flag_zero_and_hash_on2(t_flags *all_fl, char *str_num);
char			*flag_hash_and_minus_on(t_flags *all_fl, char *str_num);
char			*flag_hash_and_minus_on2(t_flags *all_fl, char *str_num);
char			*flag_zero_on_o(t_flags *all_fl, char *str_num);
char			*flag_hash_on1_o(t_flags *all_fl, char *str_num);
char			*flag_hash_on2_o(t_flags *all_fl, char *str_num);
char			*flag_minus_on_o(t_flags *all_fl, char *str_num);
char			*flag_zero_and_hash_on_o(t_flags *all_fl, char *str_num);
char			*flag_zero_and_hash_on2_o(t_flags *all_fl, char *str_num);
char			*flag_hash_and_minus_on_o(t_flags *all_fl, char *str_num);
char			*flag_hash_and_minus_on2_o(t_flags *all_fl, char *str_num);
int64_t			get_d_number(va_list ap, t_flags *all_fl);
char			*return_buffer_s(va_list ap, t_flags *all_fl);
char			*width_on_prec_on_s(t_flags *all_fl, char *str);
char			*return_buffer_s(va_list ap, t_flags *all_fl);
char			*width_on_prec_on_s(t_flags *all_fl, char *str);
char			*str_put_precision(int precision, char *str);
char			*width_off_prec_on_s(t_flags *all_fl, char *str);
char			*width_on_prec_off_s(t_flags *all_fl, char *str);
char			*width_on_prec_on_minus_on_s(t_flags *all_fl,
						char *str, char *new_prec_buf);
char			*width_on_prec_on_minus_off_s(t_flags *all_fl,
						char *str, char *new_prec_buf);
char			*return_buffer_c(va_list ap, t_flags *all_fl);
char			*return_buffer_p(va_list ap, t_flags *all_fl);
char			*return_buffer_d(va_list ap, t_flags *all_fl);
char			*print_d_positive(t_flags *all_fl, int64_t number);
char			*print_d_negative(t_flags *all_fl, int64_t number);
char			*width_off_prec_off_d_positive(t_flags *all_fl,
						char *str_num);
char			*width_on_prec_off_d_positive(t_flags *all_fl,
						char *str_num);
char			*width_off_prec_on_d_positive(t_flags *all_fl,
						char *str_num, int num_len);
char			*width_on_prec_on_d_positive(t_flags *all_fl,
						char *str_num, int num_len);
char			*width_on_prec_on2_d_positive(t_flags *all_fl,
						char *str_num, int num_len);
char			*print_d_negative(t_flags *all_fl,
						int64_t number);
char			*width_off_prec_on_d_negative(t_flags *all_fl,
						char *str_num);
char			*width_on_prec_off_d_negative(t_flags *all_fl,
						char *str_num);
char			*width_on_prec_on_d_negative(t_flags *all_fl,
						char *str_num);
char			*put_d_buff(t_flags *all_fl, char *str_num);
uint64_t		get_u_number(va_list ap, t_flags *all_fl);
char			*return_buffer_u(va_list ap, t_flags *all_fl);
char			*print_u(t_flags *all_fl, uint64_t number);
char			*width_off_prec_on_u(t_flags *all_fl,
						char *str_num);
char			*width_on_prec_off_u(t_flags *all_fl,
						char *str_num);
char			*width_on_prec_on_u(t_flags *all_fl,
						char *str_num);
void			find_specifier2(t_flags *all_fl, const char *format, int *i);
void			find_specifier(t_flags *all_fl, const char *format, int *i);
int				final_print(va_list ap, const char *format, int *i);
void			get_and_store_flags(const char *format,
						t_flags *all_fl, int *i);
void			get_and_store_width(const char *format,
						t_flags *all_fl, int *i);
void			get_and_store_precision(const char *format,
						t_flags *all_fl, int *i);
void			get_and_store_h(const char *format,
						t_flags *all_fl, int *i);
void			get_and_store_l(const char *format,
						t_flags *all_fl, int *i);
void			parcing(const char *format, t_flags *all_fl, int *i);
char			*return_percent(t_flags *all_fl);
char			*itoa_filler_pointer(char *tab, intmax_t val,
						int base, int flag);
char			*ft_itoa_base_p(intmax_t value, int base);
intmax_t		ft_abs(intmax_t nbr);
char			*ft_itoa_base_o(uintmax_t value, int base);
char			*itoa_fill_un(char *str, uintmax_t value, int base);
char			*ft_itoa_base_ux(uintmax_t value, int base);
char			*change_to_capital(char *str);
char			*print_nullterm(t_flags *all_fl);
int				ft_print_colors(const char *format, int i);
void			itoa_filler_init(uintmax_t *tmp, uintmax_t value,
						int *size, int base);
long			ft_long_power(long num, long pow);
long			ft_numlen(long num, long base);
uint64_t		ft_power_p(uint64_t nb, int pow);
uint64_t		ft_long_power_p(uint64_t num, long pow);
uint64_t		ft_biglen(uint64_t num, int base);
char			*return_buffer_c_init(va_list ap, char **buffer, char *ch);

#endif
