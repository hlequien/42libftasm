	;; int ft_isupper(char c)
	;; returns 1 if c is upper case
	;; returns 0 if not

	global ft_isupper

ft_isupper:
	cmp rdi, 65
	jb no
	cmp rdi, 90
	ja no
	mov rax, 1
	ret
no:
	mov rax, 0
	ret
