```bash
#!/usr/bin/env bash
set -euo pipefail

echo "=== Running DES sample test ==="

# Compile
g++ -std=c++17 -Wall -Wextra -pedantic des.cpp -o des

# Input mẫu (mode 1 - DES encrypt)
INPUT="1
0101010101010101
0101010101010101
"

# Chạy chương trình
OUTPUT=$(printf "$INPUT" | ./des)

echo "Program output:"
echo "$OUTPUT"

# Kiểm tra output có phải binary không (basic check)
if [[ "$OUTPUT" =~ ^[01]+$ ]]; then
    echo "PASS: Output is valid binary"
else
    echo "FAIL: Output is not valid binary"
    exit 1
fi

echo "=== Test completed ==="
```
