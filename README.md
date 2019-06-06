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
     cc_t	c_cc[NCCS];	/* Control characters */
};
```
#### `c_iflag`
* `IGNBRK` ignore BREAK condition
* `BRKINT` map BREAK to SIGINTR
* `IGNPAR` ignore (discard) parity errors
* `PARMRK` mark parity and framing errors
* `INPCK` enable checking of parity errors
* `ISTRIP` strip 8th bit off chars
* `INLCR` map NL into CR
* `IGNCR` ignore CR
* `ICRNL` map CR to NL (ala CRMOD)
* `IXON` enable output flow control
* `IXOFF` enable input flow control
* `IXANY` any char will restart after stop
* `IMAXBEL` ring bell on input queue full
* `IUCLC` translate upper case to lower case
