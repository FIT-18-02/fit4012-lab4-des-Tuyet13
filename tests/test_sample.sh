#!/usr/bin/env bash
set -euo pipefail

echo "=== Running DES functional validation test ==="

# 1. Biên dịch
g++ -std=c++17 -Wall -Wextra -pedantic des.cpp -o des_test

# 2. Định nghĩa dữ liệu test (Dựa trên expected ciphertext của bạn)
# Giả sử plaintext và key tương ứng tạo ra kết quả đó là:
MODE="1"
PLAINTEXT="0101010101010101010101010101010101010101010101010101010101010101"
KEY="0001001000110100010101100111100010011010101111001101111011110000"
EXPECTED="0111111010111111010001001001001100100011111110101111101011111000"

# 3. Chạy chương trình với input từ stdin
# Chúng ta chỉ lấy dòng cuối cùng (chuỗi nhị phân) để so sánh
OUTPUT=$(printf "%s\n%s\n%s\n" "$MODE" "$PLAINTEXT" "$KEY" | ./des_test)
ACTUAL=$(printf "%s\n" "$OUTPUT" | tail -n 1)

# 4. Kiểm tra kết quả
if [[ "$ACTUAL" != "$EXPECTED" ]]; then
  echo "[FAIL] Unexpected ciphertext output"
  echo "Expected: $EXPECTED"
  echo "Actual  : $ACTUAL"
  rm -f des_test
  exit 1
fi

echo "[PASS] Sample DES program produced the expected ciphertext."
rm -f des_test
