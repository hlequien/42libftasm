	;; char *ft_strdup(char *s)
	;; returns the copy of s in a new string

	global ft_strdup
	extern ft_memcpy
	extern ft_strlen
	extern malloc
ft_strdup:
	push rdi
	call ft_strlen
	mov rdi, rax
	add rdi, 1
	push rdi
	call malloc
	pop rdx
	pop rsi
	mov rdi, rax
	call ft_memcpy
	mov rdi, rsi
	ret
	
