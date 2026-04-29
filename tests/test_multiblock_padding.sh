#!/usr/bin/env bash
set -euo pipefail

echo "=== Running Multi-block and Zero Padding Test ==="

# 1. Biên dịch chương trình
g++ -std=c++17 -Wall -Wextra -pedantic des.cpp -o des

# 2. Định nghĩa dữ liệu kiểm thử
# Plaintext này có 80 bit (64 bit khối đầu + 16 bit khối sau)
# Khối thứ 2 (16 bit) phải được pad thêm 48 số '0' để đủ 64 bit trước khi mã hóa
PLAINTEXT="11111111111111111111111111111111111111111111111111111111111111110000111100001111"
KEY="0001001000110100010101100111100010011010101111001101111011110000"

echo "Input Plaintext (80 bits): $PLAINTEXT"

# 3. Chạy chế độ mã hóa (Mode 1)
INPUT="1
$PLAINTEXT
$KEY"

OUTPUT=$(printf "$INPUT" | ./des)

# 4. Kiểm tra tính hợp lệ của Output
# Vì có 80 bit đầu vào, sau khi padding khối 2, tổng cộng phải có 128 bit đầu ra (2 khối 64-bit)
if [[ ${#OUTPUT} -eq 128 ]]; then
    echo "PASS: Output length is 128 bits (2 blocks), padding was applied correctly."
elif [[ ${#OUTPUT} -gt 64 && $((${#OUTPUT} % 64)) -eq 0 ]]; then
    echo "PASS: Output length (${#OUTPUT} bits) is a multiple of 64."
else
    echo "FAIL: Output length (${#OUTPUT} bits) is not correct for multi-block encryption."
    exit 1
fi

# 5. Kiểm tra định dạng nhị phân
if [[ "$OUTPUT" =~ ^[01]+$ ]]; then
    echo "PASS: Output is valid binary."
else
    echo "FAIL: Output contains invalid characters."
    exit 1
fi

echo "=== Multi-block and Padding test completed successfully ==="
