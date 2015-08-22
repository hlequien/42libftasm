	;; int ft_isalnum(char c)
	;; returns 1 if c is digit or alphabet
	;; returns 0 if not

	global ft_isalnum
	extern ft_isalpha
	extern ft_isdigit
ft_isalnum:
	call ft_isalpha
	cmp rax, 1
	je yes
	call ft_isdigit
yes:
	ret
	
