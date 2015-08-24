	;; void ft_cat(int fd)
	;; read the file opened in file descriptor fd and prints it
	;; read (2) is used, index is :
	;; 	- 0 on linux
	;; 	- 3 on MacOS

	%define LINUX
	%ifdef MACOS
	%define MACH_SYSCALL(nb) 0x2000000 | nb
	%define READ	MACH_SYSCALL(3)
	%define WRITE	MACH_SYSCALL(4)
	%elifdef LINUX
	%define READ	0
	%define WRITE	1
	%endif
	
	global ft_cat
	extern ft_bzero
	extern ft_puts
	extern ft_memalloc
	extern free
ft_cat:
	push rdi
	mov rdi, 101
	call ft_memalloc
	mov rsi, rax
	mov rdx, 100
loop:	
	pop rdi
	mov rax, READ
	syscall
	cmp rax, 0
	je done
	push rdi
	mov rdi, rsi
	call ft_puts
	mov rdi, rsi
	mov rsi, rdx
	call ft_bzero
	mov rsi, rdi
	jmp loop
done:
	mov rdi, rsi
	call free
	ret
