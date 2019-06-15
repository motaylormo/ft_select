/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 14:59:52 by mtaylor           #+#    #+#             */
/*   Updated: 2019/06/01 14:59:54 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "../libft/libft.h"
# include "unix_text.h"

/*
**	ALLOWED FUNCTIONS
**	    <fcntl.h>	open()
**	   <unistd.h>	close(), write(), read()
**					isatty(), ttyname(), ttyslot()
**	<sys/ioctl.h>	ioctl()
**	   <stdlib.h>	getenv()
**	  <termios.h>	tcsetattr(), tcgetattr()
**	  <termcap.h>	tgetent(), getflag(), tgetnum(), tgetstr(), tgoto(), tputs()
**	   <stdlib.h>	malloc(), free()
**					exit()
**	   <signal.h>	signal()
*/
# include <unistd.h>
# include <sys/ioctl.h>
# include <stdlib.h>
# include <termios.h>
# include <termcap.h>
# include <fcntl.h>
# include <stdlib.h>
# include <signal.h>

# define TERM_FD 0
# define KEY_SEQ_BUF_SIZE 10

# define HIGHLIGHT B_WHT ON_GRN
# define SELECTED GRN UNDERLINE
# define MIN_BETWEEN_COLS 3

# define NAME "ft_select"
# define ERROR_MSG (NAME ": error")
# define USAGE ("usage: " NAME " choice1 [choice2] [choice_etc]\n")

typedef struct s_node	t_node;
struct	s_node
{
	char	*data;
	int		s;
	t_node	*next;
	t_node	*prev;
};

typedef struct s_list	t_list;
struct	s_list
{
	t_node	*first;
	t_node	*curr;
	int		count;
	int		maxlen;
};

/*
**	t_key is used only in get_key().
**		It allows me to combine the keys' ASCII sequences
**		and enum codes together in a single table.
*/

typedef struct s_key	t_key;
struct	s_key
{
	char	*seq;
	int		enumcode;
};

enum	e_keys{
	key_left,
	key_right,
	key_select,
	key_return,
	key_esc,
	key_delete
};

void	print_choices(void);
int		handle_key(void);
void	signal_catcher(void);
void	termcaps_delete(void);
void	terminal_setup(void);
void	terminal_restore(void);

/*
**	list_struct
*/
void	argv_to_list(int argc, char **argv);
void	delete_node(t_list *list, t_node *n);

/*
**	singletons and similiar
*/
int		window_width(void);
t_list	*list_singleton(t_list *arg);
int		prev_print_rows(int cols, int rows);

#endif
