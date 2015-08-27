	;; void ft_cat(int fd);

	%define MACOS
	%ifdef MACOS
	%define MACH_SYSCALL(nb) 0x2000000 | nb
	%define READ	MACH_SYSCALL(3)
	%define WRITE	MACH_SYSCALL(4)
	%elifdef LINUX
	%define READ	0
	%define WRITE	1
	%endif
	%define BUFF_SIZE 100

	global ft_cat
	extern ft_putstr
	extern ft_memalloc
	extern ft_bzero
	extern free
	
ft_cat:
	push rdi
	mov rdi, BUFF_SIZE
	inc rdi
	call ft_memalloc
	mov rsi, rax
loop:
	pop rdi
	push rdi
	mov rdx, BUFF_SIZE
	mov rax, READ
	syscall
	cmp rax, 0
	je done
	mov rdi, rsi
	call ft_putstr
	mov rsi, BUFF_SIZE
	call ft_bzero
	mov rsi, rdi
	jmp loop
done:
	mov rdi, rsi
	call free
	pop rdi
	ret
	