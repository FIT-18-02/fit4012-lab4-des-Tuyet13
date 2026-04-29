#!/usr/bin/env bash
set -euo pipefail

echo "=== Running DES sample test ==="

# 1. Biên dịch chương trình (Sử dụng tiêu chuẩn C++17 như yêu cầu)
g++ -std=c++17 -Wall -Wextra -pedantic des.cpp -o des

# 2. Input mẫu theo Submission Contract:
# Dòng 1: Mode (1 = DES encrypt)
# Dòng 2: Plaintext nhị phân (Ví dụ 64-bit)
# Dòng 3: Key nhị phân 64-bit
INPUT="1
0101010101010101010101010101010101010101010101010101010101010101
0001001000110100010101100111100010011010101111001101111011110000
"

# 3. Chạy chương trình và lấy kết quả
# Sử dụng printf để đảm bảo các dòng được gửi vào stdin chính xác
OUTPUT=$(printf "$INPUT" | ./des)

echo "Program output:"
echo "$OUTPUT"

# 4. Kiểm tra đầu ra có phải là chuỗi nhị phân (chỉ chứa ký tự 0 và 1) hay không
if [[ "$OUTPUT" =~ ^[01]+$ ]]; then
    echo "PASS: Output is valid binary"
else
    echo "FAIL: Output is not valid binary hoặc chứa ký tự lạ"
    exit 1
fi

echo "=== Test completed ==="
