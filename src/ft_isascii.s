	;; int ft_isascii(int c)
	;; returns 1 if c is an ascii char (0-127 range)
	;; returns 0 if not

	global ft_isascii

ft_isascii:
	cmp rdi, 0
	jb no
	cmp rdi, 127
	ja no
	mov rax, 1
	ret
no:
	mov rax, 0
	ret
