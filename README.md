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
     <summary><h3>Control characters</h3></summary>

0. `VEOF` end-of-file (EOF) character
1. `VEOL` additional end-of-line (EOL) character
2. `VEOL2` yet another end-of-line character
3. `VERASE` erases the previous not-yet-erased character, but does not erase past EOF or beginning-of-line
4. `VWERASE` word erase
5. `VKILL` kill character; erases the input since the last EOF or beginning-of-line
6. `VREPRINT` reprint unread characters
7. ?
8. `VINTR` interrupt character; send SIGINT signal
9. `VQUIT` quit character; send SIGQUIT signal
10. `VSUSP` suspend character; send SIGTSTP signal
11. ?
12. `VSTART` start character: restarts output stopped by the _stop_ character
13. `VSTOP` stop character: stop output until _start_ character typed
14. `VLNEXT` literal next: quotes the next input character, depriving it of a possible special meaning
15. `VDISCARD` toggle: start/stop discarding pending output
16. `VMIN` minimum number of characters for noncanonical read
17. `VTIME` timeout in deciseconds for noncanonical read
</details>
