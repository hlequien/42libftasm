	;; int ft_toupper(int c)
	;; returns upper counterpart of c
	;; if c is already upper nor a alphabet letter
	;; c is returned

	global ft_toupper
	extern ft_islower
	
ft_toupper:
	mov rcx, rdi
	call ft_islower
	cmp rax, 0
	je no
	mov rax, rcx
	sub rax, 32
	ret
no:
	mov rax, rdi
	ret
