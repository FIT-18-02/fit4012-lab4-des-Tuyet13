#!/usr/bin/env bash
set -euo pipefail

echo "=== Running DES Encrypt -> Decrypt Round-trip Test ==="

# 1. Biên dịch chương trình
g++ -std=c++17 -Wall -Wextra -pedantic des.cpp -o des

# 2. Định nghĩa dữ liệu kiểm thử
PLAINTEXT="0101010101010101"
KEY="0001001000110100010101100111100010011010101111001101111011110000"

# 3. Bước 1: Thực hiện mã hóa (Mode 1)
# Input cho mã hóa: Mode, Plaintext, Key
ENCRYPT_INPUT="1
$PLAINTEXT
$KEY"

CIPHERTEXT=$(printf "$ENCRYPT_INPUT" | ./des)
echo "Ciphertext: $CIPHERTEXT"

# 4. Bước 2: Thực hiện giải mã (Mode 2) từ kết quả vừa thu được
# Input cho giải mã: Mode, Ciphertext, Key
DECRYPT_INPUT="2
$CIPHERTEXT
$KEY"

FINAL_OUTPUT=$(printf "$DECRYPT_INPUT" | ./des)
echo "Decrypted Output: $FINAL_OUTPUT"

# 5. So sánh kết quả cuối cùng với bản rõ ban đầu
# Lưu ý: Vì dùng Zero Padding nên ta chỉ so sánh phần đầu tương ứng với độ dài PLAINTEXT
if [[ "$FINAL_OUTPUT" == "$PLAINTEXT"* ]]; then
    echo "PASS: Decrypted text matches the original plaintext."
else
    echo "FAIL: Decrypted text does not match original plaintext!"
    echo "Expected: $PLAINTEXT"
    echo "Got     : $FINAL_OUTPUT"
    exit 1
fi

echo "=== Round-trip test completed successfully ==="
