/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh42.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 19:53:41 by amazie            #+#    #+#             */
/*   Updated: 2014/06/19 19:04:29 by tmerlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH42_H
# define SH42_H

# define ER_MALLOC	 1
# define ER_TERMCAPS 2
# define K0			 key[0]
# define K1			 key[1]
# define K2			 key[2]
# define K3			 key[3]
# define H_LIMIT	 100
# define CMD 		 7
# define FILE 		 8
# define OPTION 	 9
# define UNKNOW 	 -1

typedef struct		s_chara
{
	char			c;
	struct s_chara	*prev;
	struct s_chara	*next;
}					t_chara;

typedef struct		s_cursor
{
	t_chara			*start;
	t_chara			*current;
	t_chara			*end;
}					t_cursor;

typedef struct		s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}					t_env;

typedef struct		s_hist
{
	char			*line;
	struct s_hist	*prev;
	struct s_hist	*next;
}					t_hist;

typedef struct		s_lex
{
	int				token;
	char			*name;
	struct s_lex	*next;
}					t_lex;

typedef struct		s_pars_cmd
{
	char			*cmd;
	char			*r_in;
	char			*r_out;
	char			*r_new_out;
}					t_pars_cmd;

typedef struct		s_pars
{
	int				token;
	t_pars_cmd		*cmd;
	struct s_pars	*left;
	struct s_pars	*right;
}					t_pars;

typedef struct		s_glob
{
	t_env			*env;
	t_hist			*hist;
	t_hist			*pos;
	t_chara			*chara;
	t_lex			*lex;
	char			*user;
	char			*pwd;
	int				exit_sh;
	int				ex_return;
}					t_glob;

int					isexist(char *tmp, int type, int key);
char				**bin(char *cmd, char *path_env);
char				**write_env(char **str);
char				**new_env(char **str);
int					isex(char **newenv, char *str);
int					grep_cmd(char **str);
void				exec_env(char **str, int *i, int isnew_env, char **env);
int					env(char **str);
void				set_glob(char *name, char *value, int i);
int					ft_access(char *path);
int					cd(char **cmd);
int					unset_env(char **cmd, int i);
void				add_env(t_env **temp, char *name, char *value);
int					set_env(char **cmd, int i);
int					builtin(t_pars_cmd *cmd);
int					isaccess(char **cmd, int type, int key);
char				**build_env(t_env *env);
void				recurs_pipe(t_pars *three, int input, int *result);
void				exec_cmd(t_pars_cmd *cmd, int input, int *result, int type);
void				exec(t_pars_cmd *cmd, int type1);
void				exec_pipe(t_pars *three, int *result);
int					open_file(char *str, int type);
t_pars				*add_three_cmd(t_lex *temp);
t_pars				*add_three(int token);
void				free_lst_lex(t_lex **lst);
void				free_three(t_pars **three);
int					parse_error(t_lex *temp, int token);
int					redirec_check(t_lex *lst);
int					exec_pars(t_pars *three, int result, int token);
int					parser(t_lex **lst);
int					prior_tok(int param);
void				lexer(char *line, t_lex *lst);
void				free_lst(t_lex **lst);
void				init_token(char *test[8]);
int					is_token(char *line, int *param);
int					is_word(char *line, int *param);
void				add_word(t_lex **lst, int *param, char *line);
void				add_token(t_lex **lst, int *param);
void				add_lst(t_lex **lst, t_lex **new_lst);
int					prompt(void);
void				init_signal(void);
void				termcaps_error(char *var_env);
struct termios		*singleton_term(void);
void				init_term(void);
void				exit_term(void);
char				*ft_getcwd(void);
char				*ft_getenv(char *name);
t_env				*init_env(char **env);
t_glob				*glob(void);
char				*lst_to_str(t_chara *lst);
char				*get_line(void);
t_chara				*new_chara_lst(char c);
void				add_char(char c);
t_chara				*new_chara_lst(char c);
void				add_chara_lst(t_cursor *lst, char c);
void				init_cursor_lst(void);
t_cursor			*lst_cursor(void);
t_cursor			*new_cursor_lst(void);
int					term_putchar(int c);
void				malloc_error(char *func);
void				signal_eof(int sig);
void				history_up(void);
void				history_down(void);
void				add_history(t_hist **hist, char *str);
void				cursor_move(char key[4]);
void				move_end(t_cursor *lst);
void				move_home(t_cursor *lst);
void				move_left(t_cursor *lst);
void				move_right(t_cursor *lst);
void				backspace_input(t_cursor *lst);
void				delete_cmdline(t_cursor *lst);
void				delete_input(t_cursor *lst);
void				erase_backspace(t_cursor *lst);
void				erase_input(t_cursor *lst);
void				ft_deltab_str(char ***c_env);
int					build_echo(char **str);
int					at_exit(char **cmdline);

#endif
