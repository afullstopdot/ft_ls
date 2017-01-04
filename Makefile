# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amarquez <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/09 10:14:55 by amarquez          #+#    #+#              #
#    Updated: 2016/11/17 13:43:35 by amarquez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftls.a
CC = gcc
FLAGS = -Wextra -Werror -Wall
HELP = helper_func/
ARG_M = src/commandline_mngmnt/
RDD = src/readdir/
LF = $(RDD)/long_format/
INC = ./includes/

H_SRC = $(HELP)d_strlen.c $(HELP)mem_for_str_split.c $(HELP)str_dup.c \
	  $(HELP)str_join.c $(HELP)str_len.c $(HELP)str_new.c $(HELP)str_split.c\
	  $(HELP)str_chr.c $(HELP)print.c $(HELP)swap.c $(HELP)sort_algos.c\
	  $(HELP)remove_dup.c $(HELP)dir_size.c $(HELP)add_color.c \
	  $(HELP)list_len.c $(HELP)str_cmp.c $(HELP)reverse.c $(HELP)itoa.c\
	  $(HELP)str_ncpy.c $(HELP)default_args.c $(HELP)check_args.c\
	  $(HELP)is_dir.c $(HELP)clean.c $(HELP)clean_l.c $(HELP)split_dir.c\
	  $(HELP)put_char.c $(HELP)put_str.c $(HELP)error_msg.c

H_OBJ = d_strlen.o mem_for_str_split.o str_dup.o str_join.o str_len.o str_new.o\
		str_split.o str_chr.o print.o swap.o sort_algos.o remove_dup.o dir_size.o\
		add_color.o list_len.o str_cmp.o reverse.o itoa.o str_ncpy.o \
		default_args.o check_args.o is_dir.o clean.o clean_l.o split_dir.o\
		put_char.o put_str.o error_msg.o
S_SRC = $(ARG_M)clean_args.c $(ARG_M)validate_opts.c $(ARG_M)init_args.c\
		$(ARG_M)init_filelist.c $(RDD)get_dir_contents.c $(RDD)read_link.c\
		$(LF)read_file.c $(LF)file_rights.c $(LF)file_type.c $(RDD)file_exists.c\
		$(LF)file_nlink.c $(LF)file_users.c $(LF)file_date.c $(LF)file_total.c\
		$(RDD)read_directory.c $(RDD)read_f.c
S_OBJ = clean_args.o validate_opts.o init_args.o get_dir_contents.o read_link.o\
		read_file.o file_rights.o file_exists.o file_type.o file_nlink.o\
		file_users.o file_date.o init_filelist.o read_directory.o read_f.o\
		file_total.o
all: $(NAME)

$(NAME):
	@$(CC) $(FLAGS) -c $(H_SRC) $(S_SRC) -I $(INC)
	@ar rc $(NAME) $(S_OBJ) $(H_OBJ)
	@ranlib $(NAME)
	@rm -rf $(S_OBJ) $(H_OBJ)
	@$(CC) $(FLAGS) main.c -o ft_ls -I $(INC) -L . -lftls
	@echo "program created"

clean:
	@rm -rf $(S_OBJ) $(H_OBJ)
	@echo "object files cleaned"

fclean: clean
	@rm -rf $(NAME) ft_ls
	@echo "libftls removed."

re: fclean all

norm:
	@norminette helper_func
	@norminette src
	@norminette main.c
	@norminette includes
