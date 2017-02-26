/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 15:31:30 by ljoly             #+#    #+#             */
/*   Updated: 2017/02/07 14:12:54 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <wchar.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"

/*
** structure aliases
*/

# define SPEC specs->specifier
# define MOD specs->modifier
# define FLAGS specs->flags
# define WIDTH specs->width
# define IS_PRECISION specs->is_precision
# define PRECISION specs->precision
# define LEFT_Z specs->left_zeros
# define LEFT_B specs->left_blanks
# define RIGHT_B specs->right_blanks
# define FILL_L specs->to_fill_left
# define FILL_R specs->to_fill_right
# define HEX_UPPER specs->hex_upper

/*
** array of modifiers
*/

# define NO_MOD 0
# define MOD_H 1
# define MOD_L 2
# define MOD_J 3
# define MOD_Z 4
# define MOD_HH 5
# define MOD_LL 6

/*
** array of flags
*/

# define SHARP FLAGS[0]
# define SPACE FLAGS[1]
# define MINUS FLAGS[2]
# define PLUS FLAGS[3]
# define ZERO FLAGS[4]

/*
** storing format specifications
*/

typedef struct	s_specs
{
	char		specifier;
	char		no_specifier;
	char		flags[6];
	int			width;
	int			is_precision;
	int			precision;
	int			modifier;
	int			left_zeros;
	int			left_blanks;
	int			right_blanks;
	int			to_fill_left;
	int			to_fill_right;
	int			hex_upper;
}				t_specs;

/*
** functions
*/

int				ft_printf(const char *format, ...);

void			ft_get_specifier(char **frmt, t_specs *specs);
void			ft_initialize_struct(t_specs *specs);
void			ft_get_flags(char *frmt, t_specs *specs);
void			ft_get_width(char *frmt, t_specs *specs);
void			ft_get_precision(char *frmt, t_specs *specs);
void			ft_get_modifier(char *frmt, t_specs *specs);

size_t			ft_handle_spec(va_list *arg, t_specs *specs);
size_t			ft_handle_mod_z(va_list *arg, t_specs *specs);

size_t			ft_print_percent(t_specs *specs);
size_t			ft_print_char(va_list *arg, t_specs *specs);
size_t			ft_print_str(va_list *arg, t_specs *specs);
size_t			ft_print_pointer(va_list *arg, t_specs *specs);
size_t			ft_print_int(va_list *arg, t_specs *specs);
size_t			ft_print_short(va_list *arg, t_specs *specs);
size_t			ft_print_long(va_list *arg, t_specs *specs);
size_t			ft_print_long_long(va_list *arg, t_specs *specs);
size_t			ft_print_unsigned_int(va_list *arg, t_specs *specs);
size_t			ft_print_unsigned_char(va_list *arg, t_specs *specs);
size_t			ft_print_unsigned_long(va_list *arg, t_specs *specs);
size_t			ft_print_unsigned_short(va_list *arg, t_specs *specs);
size_t			ft_print_unsigned_long_long(va_list *arg, t_specs *specs);
size_t			ft_print_intmax_t(va_list *arg, t_specs *specs);
size_t			ft_print_uintmax_t(va_list *arg, t_specs *specs);
size_t			ft_print_signed_char(va_list *arg, t_specs *specs);
size_t			ft_print_hex_lower(va_list *arg, t_specs *specs);
size_t			ft_print_hex_upper(va_list *arg, t_specs *specs);
size_t			ft_print_hex_lower_short(va_list *arg, t_specs *specs);
size_t			ft_print_hex_upper_short(va_list *arg, t_specs *specs);
size_t			ft_print_hex_lower_char(va_list *arg, t_specs *specs);
size_t			ft_print_hex_upper_char(va_list *arg, t_specs *specs);
size_t			ft_print_hex_lower_long(va_list *arg, t_specs *specs);
size_t			ft_print_hex_upper_long(va_list *arg, t_specs *specs);
size_t			ft_print_hex_lower_long_long(va_list *arg, t_specs *specs);
size_t			ft_print_hex_upper_long_long(va_list *arg, t_specs *specs);
size_t			ft_print_oct(va_list *arg, t_specs *specs);
size_t			ft_print_oct_short(va_list *arg, t_specs *specs);
size_t			ft_print_oct_char(va_list *arg, t_specs *specs);
size_t			ft_print_oct_long(va_list *arg, t_specs *specs);
size_t			ft_print_oct_long_long(va_list *arg, t_specs *specs);
size_t			ft_print_pointer(va_list *arg, t_specs *specs);
size_t			ft_print_wchar(va_list *arg, t_specs *specs);
size_t			ft_print_wstr(va_list *arg, t_specs *specs);
size_t			ft_print_binary_b(va_list *arg, t_specs *specs);
size_t			ft_print_binary_char(va_list *arg, t_specs *specs);
size_t			ft_print_binary_short(va_list *arg, t_specs *specs);
size_t			ft_print_binary_long(va_list *arg, t_specs *specs);
size_t			ft_print_binary_long_long(va_list *arg, t_specs *specs);

void			ft_char_flags_left(int size, t_specs *specs);
void			ft_char_flags_right(int size, t_specs *specs);
size_t			ft_char_print_left(t_specs *specs);
size_t			ft_char_print_right(t_specs *specs);
int				ft_int_size(ssize_t nb);
void			ft_int_flags_left(ssize_t i, int size, int precision,
				t_specs *specs);
void			ft_int_flags_right(int size, t_specs *specs);
size_t			ft_int_print_left(ssize_t i, t_specs *specs);
size_t			ft_int_print_right(t_specs *specs);
int				ft_uint_size(size_t nb);
void			ft_uint_flags_left(int size, int precision, t_specs *specs);
void			ft_uint_flags_right(int size, t_specs *specs);
size_t			ft_uint_print_left(t_specs *specs);
size_t			ft_uint_print_right(t_specs *specs);
int				ft_hex_size(size_t x);
void			ft_hex_flags_left(int size, int precision, t_specs *specs);
void			ft_hex_flags_right(int size, t_specs *specs);
size_t			ft_hex_print_left(t_specs *specs);
size_t			ft_hex_print_right(t_specs *specs);
int				ft_oct_size(size_t o);
void			ft_oct_flags_left(int size, int precision, t_specs *specs);
void			ft_oct_flags_right(int size, t_specs *specs);
size_t			ft_oct_print_left(int size, t_specs *specs);
size_t			ft_oct_print_right(t_specs *specs);
int				ft_binary_size(size_t b);

void			ft_print_blanks(int n);
void			ft_print_zeros(int n);

#endif
