# CTF problems

## Ideas
* "safe" libc functions `strncpy`, `strncat` etc.
* Defeat NX with ROP
* Defeat ASLR by leaking addresses with format string
* Defeat canary by:
	* Leaking with format string
	* Directly overwriting return address
* GOT attack
