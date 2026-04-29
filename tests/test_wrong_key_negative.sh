#!/usr/bin/env bash
set -euo pipefail

echo "=== Running Wrong Key Negative Test ==="

# 1. Biên dịch chương trình
g++ -std=c++17 -Wall -Wextra -pedantic des.cpp -o des

# 2. Định nghĩa dữ liệu
PLAINTEXT="0101010101010101010101010101010101010101010101010101010101010101"
CORRECT_KEY="0001001000110100010101100111100010011010101111001101111011110000"
WRONG_KEY="1111111111111111111111111111111111111111111111111111111111111111"

# 3. Thực hiện mã hóa với KHÓA ĐÚNG
ENCRYPT_INPUT="1
$PLAINTEXT
$CORRECT_KEY"
CIPHERTEXT=$(printf "$ENCRYPT_INPUT" | ./des)

echo "Original Plaintext: $PLAINTEXT"
echo "Ciphertext        : $CIPHERTEXT"

# 4. Thực hiện giải mã với KHÓA SAI
echo "Attempting decryption with WRONG KEY..."
DECRYPT_INPUT="2
$CIPHERTEXT
$WRONG_KEY"
WRONG_OUTPUT=$(printf "$DECRYPT_INPUT" | ./des)

echo "Decrypted Output (Wrong Key): $WRONG_OUTPUT"

# 5. Kiểm tra kết quả
# Kết quả giải mã với khóa sai phải khác với bản rõ ban đầu
if [[ "$WRONG_OUTPUT" != "$PLAINTEXT" ]]; then
    echo "PASS: Decrypted output does not match original plaintext (Wrong key test successful)."
else
    echo "FAIL: Decrypted output matches original plaintext despite using a wrong key!"
    exit 1
fi

echo "=== Wrong key negative test completed successfully ==="
