section .data
	msg db 'Hello My name is Muhammad Jilani!',0xA
	len_msg equ $ - msg

section .text
	global _start

_start:
	mov rax,1
	mov rdi,1
	mov rsi,msg
	mov rdx,len_msg
	syscall

	mov rdi,rax
	mov rax,60
	syscall
