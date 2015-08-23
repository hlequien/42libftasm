	;; void *ft_memset(void *s, int c, size_t n)
	;; fill memory with c value from s to s + n
	;; returns s

	global ft_memset

ft_memset:
	push rdi
	mov rcx, rdx
	mov rax, rsi
	rep stosb
	pop rdi
	mov rax, rdi
	ret
