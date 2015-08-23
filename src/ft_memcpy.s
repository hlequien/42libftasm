	;; void *ft_memcpy(void *dest, void *src, size_t n)
	;; copy n bytes from src to dest
	;; returns dest

	global ft_memcpy

ft_memcpy:
	push rdi
	mov rax, rsi
	mov rcx, rdx
	rep movsb
	pop rdi
	mov rax, rdi
	ret
