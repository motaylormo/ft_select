/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 13:31:35 by mtaylor           #+#    #+#             */
/*   Updated: 2019/06/11 13:31:37 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	handle_kill(int sig)
{
	termcaps_delete();
	terminal_restore();
	exit(128 + sig);
}

/*
**	ctrl-Z
*/

static void	handle_suspend(int sig)
{
	if (sig != SIGTSTP)
		return ;
	termcaps_delete();
	terminal_restore();
	signal(SIGTSTP, SIG_DFL);
	ioctl(STDERR_FILENO, TIOCSTI, "\x1A");
}

/*
**	fg
*/

static void	handle_resume(int sig)
{
	if (sig != SIGCONT)
		return ;
	terminal_setup();
	print_choices();
}

static void	handle_resize(int sig)
{
	if (sig != SIGWINCH)
		return ;
	termcaps_delete();
	print_choices();
}

void		signal_catcher(void)
{
	signal(SIGABRT, handle_kill);
	signal(SIGTERM, handle_kill);
	signal(SIGINT, handle_kill);
	signal(SIGTSTP, handle_suspend);
	signal(SIGCONT, handle_resume);
	signal(SIGWINCH, handle_resize);
}
