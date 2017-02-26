# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljoly <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/30 19:22:44 by ljoly             #+#    #+#              #
#    Updated: 2017/02/06 17:17:46 by ljoly            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: $(NAME) all clean fclean re

NAME = libftprintf.a
SRCS_LIB = deal_flags_char.c deal_flags_int.c deal_with_it_bro.c \
	  deal_with_it_bro_2.c ft_printf.c get_specs.c initialize_struct.c \
	  put_blanks_and_zeros.c print_char_c.c print_int_d_i.c print_str_s.c \
	  print_percent.c print_long_ld.c print_long_long_lld.c print_short_hd.c \
	  print_signed_char_hhd.c print_intmax_t_jd.c deal_flags_unsigned.c \
	  print_unsigned_int_u.c print_unsigned_long_lu.c \
	  print_unsigned_short_hu.c print_unsigned_char_hhu.c \
	  print_unsigned_long_long_llu.c print_uintmax_t_ju.c deal_flags_hex_get.c\
	  deal_flags_hex_print.c print_hex_x.c print_hex_long_lx.c \
	  print_hex_long_long_llx.c print_hex_short_hx.c print_hex_char_hhx.c \
	  print_pointer_p.c deal_flags_oct_get.c deal_flags_oct_print.c \
	  print_oct_o.c print_oct_char_hho.c print_oct_short_ho.c \
	  print_oct_long_lo.c print_oct_long_long_llo.c print_wchar_t_lc.c \
	  print_wchar_t_ls.c print_binary_b.c print_binary_char_hhb.c \
	  print_binary_short_hb.c print_binary_long_lb.c \
	  print_binary_long_long_llb.c

OBJ_LIB = $(SRCS_LIB:.c=.o)

HEADER = -I./includes

RED=\033[1;31m
GREEN=\033[1;32m
NC=\033[0m

FLAGS = -Wall -Werror -Wextra

LIBFT = ./libft/libft.a

SRCS_PATH = srcs
OBJ_PATH = ./
SRCS = $(addprefix $(SRCS_PATH)/,$(SRCS_LIB))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_LIB))

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@cp $(LIBFT) $(NAME)
	@ar rc $(NAME) $(OBJ)
	@echo "$(GREEN)[✓]$(NC) Library $(NAME) built..."
	@ranlib $(NAME)
	@echo "$(GREEN)[✓]$(NC) Library $(NAME) indexed"

$(OBJ): %.o: $(SRCS_PATH)/%.c
	@gcc $(FLAGS) -o $@ -c $< $(HEADER)

$(LIBFT) :
	@make -C libft/ fclean
	@make -C libft/

clean:
	@rm -f $(OBJ)
	@rm -f $(OBJ_LIB)
	@make -C libft/ clean
	@echo "$(RED)[-]$(NC) Objects cleaned"

fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean
	@echo "$(RED)[-]$(NC) Library $(NAME) cleaned"

re: fclean all
