This is my version of the **[42](https://www.42.us.org/)** cadet project `ft_select` from the UNIX branch.

# ft_select

## Functions used
### Termios
* `tcgetattr()` to get the parameters associated with the terminal _fd_ and store them in the termios structure
* `tcsetattr()` to set parameters in the termios structure to the terminal _fd_
```c
struct termios {
	tcflag_t	c_iflag;	/* Input modes */
	tcflag_t	c_oflag;	/* Output modes */
	tcflag_t	c_cflag;	/* Control modes */
	tcflag_t	c_lflag;	/* Local modes */
	cc_t		c_cc[NCCS];	/* Control characters */
};
```
