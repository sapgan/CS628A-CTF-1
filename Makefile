SHELL := /bin/bash

SRC := 0/baby_steps.c 1/drunk_coder.c 2/el-ess.c 3/feedback.c 4/guess.c
TARGETS := $(SRC:%.c=%) 5/doge 5/doge.S

# CFLAGS := -m32 -fno-stack-protector -U_FORTIFY_SOURCE -mpreferred-stack-boundary=4 -w
CFLAGS := -m32 -U_FORTIFY_SOURCE -mpreferred-stack-boundary=4 -w

.PHONY: all clean
all: $(TARGETS)

clean:
	rm $(TARGETS)

# TODO: check if FLAG is empty
0/baby_steps: CFLAGS += -DFLAG='"$(FLAG)"'

#NX stack,stack canary,no optimization
1/drunk_coder: CFLAGS += -O0 -fstack-protector

# enable executable stack and canary protection
3/feedback: CFLAGS += -z execstack -fstack-protector

# fix the stack so that ret2libc is a bit easier
# the stack of hello_doge will look like:
# 	[ retaddr ] [ "name" ]
# 	by writing addr of `exit` and `/bin/sh`
# 	ret2libc can be performed
5/doge: 5/doge.S
	L=$$(grep -n 'call[[:space:]]*hello_doge' $< | cut -d':' -f1); L=$$((L-1)); sed -i "$${L}s/16/0x1c/" $<
	${CC} -m32 -o $@  $<

5/doge.S: 5/doge.c
	${CC} ${CFLAGS} -fno-asynchronous-unwind-tables -masm=intel -S -o $@ $<
