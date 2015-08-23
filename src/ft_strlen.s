	;; size_t ft_strlen(char *s)
	;; returns s lenght

	global ft_strlen

ft_strlen:
	push rdi
	mov rcx, 0
loop:
	mov al, [rdi]
	cmp al, 0
	je done
	inc rcx
	inc rdi
	jmp loop
done:
	mov rax, rcx
	pop rdi
	ret
