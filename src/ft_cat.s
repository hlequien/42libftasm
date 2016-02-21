;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_cat2.s                                          :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: hlequien <hlequien@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2016/02/21 17:46:31 by hlequien          #+#    #+#              ;
;    Updated: 2016/02/21 18:15:12 by hlequien         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

	;; void ft_cat2(int fd)
	%define MACH_SYSCALL(nb) 0x2000000 | nb
	%define READ	MACH_SYSCALL(3)
	%define WRITE	MACH_SYSCALL(4)
	%define BUFF_SZ 0x100
	global ft_cat2
	extern ft_memalloc
	extern ft_bzero
	extern free

ft_cat2:
	push rdi
	mov rdi, BUFF_SZ
	call ft_memalloc
	push rax
ft_cat_loop:
	pop rdi
	pop r11
	push r11
	push rdi
	mov rsi, BUFF_SZ
	call ft_bzero
	mov rsi, rdi
	mov rdi, r11
	mov rdx, BUFF_SZ
	mov rax, READ
	syscall
	mov rdx, rax
	cmp rax, 0
	jbe done
	mov rdi, 1
	mov rax, WRITE
	syscall
	jmp ft_cat_loop
done:
	pop rdi
	call free
	pop rdi
	ret
