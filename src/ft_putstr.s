	;; int ft_putstr(char *s)
	;; print s to stdin
	;; returns
	;; NB : on MacOS, write is index 4,
	;; 		Have to define this macro :
	;; 		%define MACH_SYSCALL(nb)	0x2000000 | nb
	;; 	on Linux, write is index 1

	%define MACOS
	%ifdef MACOS
	%define MACH_SYSCALL(nb) 0x2000000 | nb
	%define WRITE	MACH_SYSCALL(4)
	%elifdef LINUX
	%define WRITE	1
	%endif
	
	extern ft_strlen
	global ft_putstr

ft_putstr:
	push rdi
	call ft_strlen
	mov rsi, rdi
	mov rdi, 1
	mov rdx, rax
	mov rax, WRITE
	syscall
	pop rdi
	ret
