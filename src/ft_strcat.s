	;; char *ft_strcat(char *dest, char *src);
	;; concatenate dest and src, returns dest
	;; so src is appened to dest

	global ft_strcat
	
ft_strcat:
	push rdi
	push rsi
go_to_end_dest:
	mov al, [rdi]
	cmp al, 0
	je start_cat
	inc rdi
	jmp go_to_end_dest
start_cat:
	mov al, [rsi]
	mov [rdi], al
	cmp al, 0
	je end_cat
	inc rsi
	inc rdi
	jmp start_cat
end_cat:
	pop rsi
	pop rdi
	mov rax, rdi
	ret
