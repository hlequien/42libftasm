	;; int ft_isprint(char c)
	;; returns 1 if c is printable
	;; returns 0 if not

	global ft_isprint

ft_isprint:
	cmp rdi, 32
	jb no
	cmp rdi, 126
	ja no
	mov rax, 1
	ret
no:
	mov rax, 0
	ret
