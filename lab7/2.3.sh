p=$(mktemp)
gcc -std=c99 2.3.c -o $p
chmod +x $p
$p &
sleep 1
ps f | grep $p -B1 | grep -v grep  
