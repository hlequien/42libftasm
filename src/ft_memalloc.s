	;; void *ft_memalloc(size_t n)
	;; allocate n-bytes memory range and returns a pointer to it
	;; memory is wiped, filled with 0

	global ft_memalloc
	extern malloc
	extern ft_bzero

ft_memalloc:
	push rdi
	call malloc
	mov rdi, rax
	pop rsi
	call ft_bzero
	mov rax, rdi
	mov rdi, rsi
	ret
