	;; char *ft_strcat(char *dest, char *src);
	;; concatenate dest and src, returns dest
	;; so src is appened to dest

	global ft_strcat
	
ft_strcat:
	push rdi
go_to_end_dest:
	mov al, [rdi]
	cmp al, 0
	je start_cat
	inc rdi
	jmp go_to_end_dest
	push rsi
start_cat:
	mov al, [rsi]
	mov [rdi], al
	cmp al, 0
	inc rsi
	inc rdi
	jne start_cat
	pop rdi
	pop rsi
	mov rax, rdi
	ret
