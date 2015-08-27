	;; int ft_puts(char *s);
	;; 	mov rdi, [rel line_feed]


section .data
	null_str db "(null)", 0x0
section .text
	extern ft_putstr
	global ft_puts

ft_puts:
	push rdi
	cmp rdi, 0
	jne is_ok
	lea rdi, [rel null_str]
is_ok:
	call ft_putstr
	push rax
	push 10
	mov rdi, rsp
	call ft_putstr
	pop rax
	pop rax
	pop rdi
	ret