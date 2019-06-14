# ft_select
This is my version of the **[42](https://www.42.us.org/)** cadet project `ft_select` from the UNIX branch.

## Functions used
* `getenv()` obtains the current value of the environment variable given as a parameter

### Terminal
* `tcgetattr()` to get the parameters associated with the terminal _fd_ and store them in the termios structure
* `tcsetattr()` to set parameters in the termios structure to the terminal _fd_
```c
struct termios {
	tcflag_t	c_iflag;	/* input flags */
	tcflag_t	c_oflag;	/* output flags */
	tcflag_t	c_cflag;	/* control flags */
	tcflag_t	c_lflag;	/* local flags */
	cc_t		c_cc[NCCS];	/* control chars */
	long		c_ispeed;	/* input speed */
	long		c_ospeed;	/* output speed */
};
```
<details><summary><b>Input flags</b></summary>
</details>
<details><summary><b>Output flags</b></summary>
</details>
<details><summary><b>Control flags</b></summary>
</details>
<details><summary><b>Local flags</b></summary>

* `ECHOKE` visual erase for line kill
* `ECHOE` visually erase chars
* `ECHOK` echo NL after line kill
* `ECHO` enable echoing
* `ECHONL` echo NL even if ECHO is off
* `ECHOPRT` visual erase mode for hardcopy
* `ECHOCTL` echo control chars as ^(Char)
</details>
<details><summary><b>Control characters</b></summary>

Index into `c_cc[]` character array. [(Source)](https://unix.superglobalmegacorp.com/BSD4.4/newsrc/sys/termios.h.html)

|    | macro | enabled by | meaning
| -: | ----- | ---------- | -------
| 0  | `VEOF`     | `ICANON` | end-of-file (EOF) character
| 1  | `VEOL`     | `ICANON` | additional end-of-line (EOL) character
| 2  | `VEOL2`    | `ICANON` | yet another end-of-line character
| 3  | `VERASE`   | `ICANON` | erases the previous not-yet-erased character, but does not erase past EOF or beginning-of-line
| 4  | `VWERASE`  | `ICANON` | word erase
| 5  | `VKILL`    | `ICANON` | kill character: erases the input since the last EOF or beginning-of-line.
| 6  | `VREPRINT` | `ICANON` | reprint unread characters
| 7  | | | _spare 1_
| 8  | `VINTR`    | `ISIG` | interrupt character: send SIGINT signal.
| 9  | `VQUIT`    | `ISIG` | quit character: send SIGQUIT signal.
| 10 | `VSUSP`    | `ISIG` | suspend character: send SIGTSTP signal.
| 11 | `VDSUSP`   | `ISIG` | delayed suspend character: send SIGTSTP signal when the character is read by the user program.
| 12 | `VSTART`   | `IXON`, `IXOFF` | start character: restarts output stopped by the _stop_ character.
| 13 | `VSTOP`    | `IXON`, `IXOFF` | stop character: stop output until _start_ character typed.
| 14 | `VLNEXT`   | `IEXTEN`  | literal next: quotes the next input character, depriving it of a possible special meaning.
| 15 | `VDISCARD` | `IEXTEN`  | toggle: start/stop discarding pending output.
| 16 | `VMIN`     | `~ICANON` | minimum number of characters for noncanonical read
| 17 | `VTIME`    | `~ICANON` | timeout in deciseconds for noncanonical read
| 18 | `VSTATUS`  | `ICANON`  | status character: display status information at terminal. Also sends a SIGINFO signa to the foreground process group.
| 19 | | | _spare 2_
</details>
* `ioctl()` http://man7.org/linux/man-pages/man2/ioctl_tty.2.html
	* `TIOCGWINSZ` get window size
	* `TIOCSWINSZ` set window size
* `isatty()` 1 or 0 depending on if the _fd_ refers to a valid terminal type device
* `ttyname()` gets the related device name of the _fd_
* `ttyslot()` http://man7.org/linux/man-pages/man3/ttyslot.3.html

* http://man7.org/linux/man-pages/man3/termios.3.html
* https://en.wikibooks.org/wiki/Serial_Programming/termios

### Termcaps
* `tgetent()` sets up termcaps to work
* `tgetnum()` get the number of lines (`"li"`) or columns (`"co"`) in the terminal window
* `tgetstr()` returns the string entry for _id_
* `tgoto()` moves the curser
