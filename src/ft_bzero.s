	;; void ft_bzero(void *s, size_t n)
	;; set n bytes to 0 starting at s
global ft_bzero

ft_bzero:
	push rdi
	mov rcx, rsi
	mov al, 0x0
	rep stosb
	pop rdi
	ret
