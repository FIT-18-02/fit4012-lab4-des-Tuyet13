
# Lab 4 Report – DES / TripleDES

## 1. Mục tiêu
Hiểu và triển khai DES và TripleDES.

## 2. Cách làm
- Implement DES theo Feistel
- Thêm nhập từ bàn phím
- Chia block + zero padding
- Viết decrypt bằng đảo key
- Xây dựng TripleDES (EDE)

## 3. Kết quả

### Round-trip
encrypt → decrypt khôi phục dữ liệu

### Avalanche
Thay đổi 1 bit → ~50% bit output thay đổi

### Throughput
Encrypt 1000 block ~0.1s

## 4. Kết luận
Thuật toán hoạt động đúng và có tính khuếch tán tốt.
