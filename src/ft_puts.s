	;; int ft_puts(char *s);
	;; 	mov rdi, [rel line_feed]


section .data
	line_feed db 0xa, 0x0

section .text
	extern ft_putstr
	global ft_puts

ft_puts:
	call ft_putstr
	push rdi
	push rax
	lea rdi, [rel line_feed]
	call ft_putstr
	pop rax
	pop rdi
	ret