p=$(mktemp)
gcc 2.2.c -o $p

$p &
sleep 1
ps f | grep $p -B1 -A0 | grep -v grep  
