	;; int ft_tolower(int c)
	;; returns lower case counterpart of c
	;; if it doesn't exist, returns c

	global ft_tolower
	extern ft_isupper

ft_tolower:
	call ft_isupper
	cmp rax, 0
	je no
	mov rax, rdi
	sub rax, 32
	ret
no:
	mov rax, rdi
	ret
