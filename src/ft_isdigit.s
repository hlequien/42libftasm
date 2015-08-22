	;; int ft_isdigit(char c)
	;; returns 1 if c is a digit
	;; returns 0 if not

	global ft_isdigit

ft_isdigit:
	cmp rdi, 48
	jb no
	cmp rdi, 57
	ja no
	mov rax, 1
	ret
no:
	mov rax, 0
	ret
