/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 10:15:31 by amarquez          #+#    #+#             */
/*   Updated: 2016/11/17 13:19:15 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/dir.h>
# include <dirent.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <time.h>
# include <unistd.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>

# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define RESET   "\x1b[0m"

struct					s_multi
{
	int					a;
	int					t;
	int					r;
	int					l;
};

struct					s_filelist
{
	char				*dir_name;
	struct s_filelist	*next;
};

struct					s_arguments
{
	int					flags;
	int					files;
};

struct					s_ls
{
	char				*flag;
	int					argc;
	struct s_filelist	*file_args;
	struct s_arguments	*args_details;
	struct s_multi		*active;
};

void					cmd_nf(char *str);
void					print_dir_name(char *str);
int						str_len(const char *str);
int						d_strlen(char **str);
void					mem_for_str_split(char ***r, char *str, char delim);
char					*str_dup(char *str);
char					*str_join(char *s1, char *s2);
char					*str_new(size_t size);
char					**str_split(char *str, char d);
char					*str_chr(const char *s, int c);
void					print_p(char **str);
void					swap(char *a, char *b);
void					swap_d(char **a, char **b);
void					swap_s(struct s_filelist **a, struct s_filelist **b);
void					sort_str(char **txt);
void					sort_char(char **txt);
char					*remove_dup(char *str);
size_t					dir_size(struct s_ls *ls, char *dir);
void					clean(char **content, char *str);
void					clean_l(char **str, char *dir);
char					*add_color(char *str, char *color);
void					sort_str(char **txt);
char					*link_info(char *name, char *dir);
int						count(struct s_filelist *dirs);
int						str_cmp(char *s1, char *s2);
void					sort_time(char **content, int n);
void					sort_struct(struct s_filelist *txt);
void					sort_struct_t(struct s_filelist *txt);
int						file_exist(char *name);
char					*ft_itoa(int n);
char					*str_ncpy(char *dst, char *src, unsigned int n);
void					default_args(int *args, char ***argv);
int						ft_multiple_args(int argc, char **argv);
int						check_if_dir(int argc, char **argv);
int						is_dir(char *path);
char					**str_rev(char **str);
struct s_filelist		*struct_rev(struct s_filelist *node);
char					*split_dir(char *dir_n, char *dir);
void					create_new_args(int *argc, char ***argv);
int						validate_args(int argc, char **argv);
struct s_ls				*init(int argc, char **argv);
char					**get_contents(struct s_ls *ls, char *dir);
char					*get_full_info(char *name);
char					*file_type(struct stat *st);
char					*file_total(char **dirs);
char					*file_rights(struct stat *st);
char					*file_nlink(struct stat *st);
char					*file_users(struct stat *st);
char					*file_date(struct stat *st);
struct s_filelist		*init_filelist(int c, char **v, struct s_multi *active);
char					**read_dir(struct s_ls *ls, char *dir, size_t size);
char					**read_file(struct s_ls *ls, char *dir);
void					put_char(char c);
void					put_str(char const *str);
void					put_str_e(char const *str);
#endif
