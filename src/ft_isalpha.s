	;; int isalpha(char c)
	;; returns 1 if c is an ascii letter
	;; returns 0 if c is not

	global ft_isalpha

ft_isalpha:
	mov al, rdi
	cmp al, 65
	jnae no
	cmp al, 123
	jnbe no
	cmp al, 90
	ja yes
	cmp al, 97
	jbe yes
no:
	mov rax, 0
	ret
yes:
	mov rax, 1
	ret
