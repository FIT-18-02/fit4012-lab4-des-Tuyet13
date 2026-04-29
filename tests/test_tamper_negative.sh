#!/usr/bin/env bash
set -euo pipefail

echo "=== Running Tamper Negative Test (Bit Flip Attack) ==="

# 1. Biên dịch chương trình
g++ -std=c++17 -Wall -Wextra -pedantic des.cpp -o des

# 2. Định nghĩa dữ liệu ban đầu
PLAINTEXT="0101010101010101010101010101010101010101010101010101010101010101"
KEY="0001001000110100010101100111100010011010101111001101111011110000"

# 3. Thực hiện mã hóa để lấy Ciphertext sạch
ENCRYPT_INPUT="1
$PLAINTEXT
$KEY"
ORIGINAL_CIPHERTEXT=$(printf "$ENCRYPT_INPUT" | ./des)

echo "Original Ciphertext: $ORIGINAL_CIPHERTEXT"

# 4. Thực hiện Tamper: Đảo ngược (flip) bit đầu tiên của Ciphertext
# Nếu bit đầu là '0' thì biến thành '1', và ngược lại
FIRST_BIT=${ORIGINAL_CIPHERTEXT:0:1}
TAMPERED_BIT=$([ "$FIRST_BIT" == "0" ] && echo "1" || echo "0")
TAMPERED_CIPHERTEXT="${TAMPERED_BIT}${ORIGINAL_CIPHERTEXT:1}"

echo "Tampered Ciphertext: $TAMPERED_CIPHERTEXT"

# 5. Giải mã Ciphertext đã bị can thiệp
DECRYPT_INPUT="2
$TAMPERED_CIPHERTEXT
$KEY"
TAMPERED_OUTPUT=$(printf "$DECRYPT_INPUT" | ./des)

echo "Decrypted Output from Tampered Data: $TAMPERED_OUTPUT"

# 6. Kiểm tra kết quả
# Trong mã hóa khối, chỉ cần sai 1 bit bản mã, bản rõ sau khi giải mã sẽ sai khác hoàn toàn
if [[ "$TAMPERED_OUTPUT" != "$PLAINTEXT" ]]; then
    echo "PASS: Decrypted output is different from original plaintext (Tamper detected)."
else
    echo "FAIL: Decrypted output still matches original plaintext despite tampering!"
    exit 1
fi

echo "=== Tamper negative test completed successfully ==="
