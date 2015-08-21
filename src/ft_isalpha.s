	;; int isalpha(char c)
	;; returns 1 if c is an ascii letter
	;; returns 0 if c is not

	global ft_isalpha

ft_isalpha:
	cmp rdi, 65
	jb no
	cmp rdi, 122
	ja no
	cmp rdi, 90
	jbe yes
	cmp rdi, 97
	jae yes
no:
	mov rax, 0
	ret
yes:
	mov rax, 1
	ret
