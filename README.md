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
<details>
<summary>Modes</summary>

#### Input Modes (`c_iflag`)
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

#### Output Modes (`c_oflag`)
* `OPOST` enable following output processing
* `ONLCR` map NL to CR-NL (ala CRMOD)
* `OXTABS` expand tabs to spaces
* `ONOEOT` discard EOT's `^D' on output)
* `OCRNL` map CR to NL
* `OLCUC` translate lower case to upper case
* `ONOCR` No CR output at column 0
* `ONLRET` NL performs CR function

#### Control Modes (`c_cflag`)
* `CSIZE` character size mask
* `CS5` 5 bits (pseudo)
* `CS6` 6 bits
* `CS7` 7 bits
* `CS8` 8 bits
* `CSTOPB` send 2 stop bits
* `CREAD` enable receiver
* `PARENB` parity enable
* `PARODD` odd parity, else even
* `HUPCL` hang up on last close
* `CLOCAL` ignore modem status lines
* `CCTS_OFLOW` CTS flow control of output
* `CRTSCTS` same as CCTS_OFLOW
* `CRTS_IFLOW` RTS flow control of input
* `MDMBUF` flow control output via Carrier

#### Local Modes (`c_lflag`)
* `ECHOKE` visual erase for line kill
* `ECHOE ` visually erase chars
* `ECHO  ` enable echoing
* `ECHONL` echo NL even if ECHO is off
* `ECHOPRT` visual erase mode for hardcopy
* `ECHOCTL` echo control chars as ^(Char)
* `ISIG  ` enable signals INTR, QUIT, [D]SUSP
* `ICANON` canonicalize input lines
* `ALTWERASE` use alternate WERASE algorithm
* `IEXTEN` enable DISCARD and LNEXT
* `EXTPROC` external processing
* `TOSTOP` stop background jobs from output
* `FLUSHO` output being flushed (state)
* `NOKERNINFO` no kernel output from VSTATUS
* `PENDIN` XXX retype pending input (state)
* `NOFLSH` don't flush after interrupt
</details>
