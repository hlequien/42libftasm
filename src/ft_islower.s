	;; int ft_islower(char c)
	;; returns 1 if c is lower case
	;; returns 0 if not
	global ft_islower

ft_islower:
	cmp rdi, 97
	jb no
	cmp rdi, 122
	ja no
	mov rax, 1
	ret
no:
	mov rax, 0
	ret
