/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_restore.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 14:49:20 by mtaylor           #+#    #+#             */
/*   Updated: 2019/06/13 14:49:21 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	error_and_exit(char *str)
{
	ft_dprintf(STDERR_FILENO, "%s: %s\n", ERROR_MSG, str);
	exit(1);
}

/*
**	Termios:
**		What to wait for before read returns:
**			VTIME = 0	No minimum time (timer unused)
**			VMIN = 1	Minimun 1 char
**		~ICANON				Noncanonical mode, enables VMIN/VTIME
**		~(ECHO | ECHONL)	Echo off, echo newline off
**		ISIG				Make sure ISIG is on
**
**	Termcaps:
**		vi	make cursor invisible
*/

void		terminal_setup(void)
{
	char			*term_ptr;
	struct termios	newtio;

	if (!(term_ptr = getenv("TERM")))
		error_and_exit("environment TERM missing");
	if (!isatty(TERM_FD))
		error_and_exit("terminal not found");
	tcgetattr(TERM_FD, &newtio);
	newtio.c_lflag &= ~ICANON;
	newtio.c_cc[VMIN] = 1;
	newtio.c_cc[VTIME] = 0;
	newtio.c_lflag &= ~(ECHO | ECHONL);
	newtio.c_lflag &= ISIG;
	tcsetattr(TERM_FD, 0, &newtio);
	tgetent(NULL, term_ptr);
	ft_putstr_fd(tgetstr("vi", NULL), STDERR_FILENO);
	signal_catcher();
}

/*
**	ve	make cursor appear normal (undo cursor_invisible/cursor_visible)
*/

void		terminal_restore(void)
{
	static struct termios	oldtio;
	static int				flag = 0;

	if (flag == 0)
	{
		tcgetattr(0, &oldtio);
		flag = 1;
	}
	else
	{
		ft_putstr_fd(tgetstr("ve", NULL), STDERR_FILENO);
		tcsetattr(0, 0, &oldtio);
	}
}
