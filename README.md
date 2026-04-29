# DES / TripleDES Implementation – FIT4012 Lab 4

## 1. How to run

### Compile

```bash
g++ -std=c++17 -Wall -Wextra -pedantic des.cpp -o des
```

### Run

```bash
./des
```

---

## 2. Input / Đầu vào

Chương trình nhận dữ liệu từ **stdin** theo chế độ (mode):

```
1 = DES encrypt  
2 = DES decrypt  
3 = TripleDES encrypt  
4 = TripleDES decrypt  
```

### Mode 1: DES encrypt

Nhập:

* plaintext (chuỗi nhị phân, có thể dài hơn 64 bit)
* key (64 bit)

Chương trình sẽ:

* chia plaintext thành các block 64 bit
* block cuối nếu thiếu sẽ được **zero padding**

---

### Mode 2: DES decrypt

Nhập:

* ciphertext (chuỗi nhị phân)
* key (64 bit)

Chương trình sẽ:

* giải mã bằng DES
* sử dụng round keys đảo ngược

---

### Mode 3: TripleDES encrypt

Nhập:

* plaintext (64 bit)
* K1, K2, K3 (mỗi key 64 bit)

Thực hiện:

```
Ciphertext = E(K3, D(K2, E(K1, Plaintext)))
```

---

### Mode 4: TripleDES decrypt

Nhập:

* ciphertext (64 bit)
* K1, K2, K3

Thực hiện:

```
Plaintext = D(K1, E(K2, D(K3, Ciphertext)))
```

---

## 3. Output / Đầu ra

* In ra kết quả cuối cùng (ciphertext hoặc plaintext)
* Dạng chuỗi nhị phân
* Có thể in thêm thông tin trung gian nhưng kết quả cuối phải rõ ràng

---

## 4. Padding

* Sử dụng **zero padding**
* Nếu block cuối < 64 bit → thêm '0' cho đủ

Ví dụ:

```
Input: 10101
→ 101010000000000000... (đủ 64 bit)
```

### Hạn chế:

* Không phân biệt được đâu là dữ liệu thật và đâu là padding
* Không an toàn trong hệ thống thực tế

---

## 5. Cryptography Notes

### IV / Nonce

IV (Initialization Vector) hoặc nonce cần **duy nhất (unique)** cho mỗi lần mã hóa.
Nếu tái sử dụng IV/nonce, attacker có thể suy ra thông tin từ ciphertext.

---

### Padding

Padding cần thiết khi dùng block cipher như DES (CBC mode) vì dữ liệu phải chia hết block.
Nếu xử lý padding sai có thể dẫn đến lỗi hoặc bị khai thác (padding oracle attack).

---

### CBC / CTR / GCM (cơ bản)

* **CBC**: dùng IV, an toàn hơn ECB nhưng cần padding
* **CTR**: biến block cipher thành stream cipher, không cần padding
* **GCM**: vừa mã hóa vừa xác thực (có authentication tag), an toàn hơn

---

## 6. Tests

Repo bao gồm các test:

* DES sample test
* Encrypt/Decrypt round-trip
* Multi-block + padding
* Tamper test (negative)
* Wrong key test (negative)

---

## 7. Logs

Thư mục `logs/` chứa minh chứng chạy chương trình:

* output thực tế
* test cases
* kết quả đúng/sai

---

## 8. Ethics & Safe Use

* Chỉ dùng cho mục đích học tập
* Không sử dụng cho hệ thống thực tế
* Không dùng để tấn công hoặc khai thác
* Nếu tham khảo tài liệu/AI cần ghi nguồn

---

## 9. Summary

* Đã triển khai DES và TripleDES
* Hỗ trợ encrypt/decrypt
* Hỗ trợ multi-block và padding
* Có test và log minh chứng đầy đủ
