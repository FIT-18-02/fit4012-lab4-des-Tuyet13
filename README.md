## 3. Input / Đầu vào
* **Chế độ (Mode)**: Chương trình nhận một số nguyên từ 1 đến 4 để chọn chức năng: 1 (DES Encrypt), 2 (DES Decrypt), 3 (3DES Encrypt), 4 (3DES Decrypt).
* **Plaintext/Ciphertext**: Nhập dưới dạng chuỗi nhị phân (0 và 1) từ bàn phím. Chương trình hỗ trợ chuỗi có độ dài bất kỳ.
* **Khóa (Key)**: 
    * Với DES: Nhập 1 chuỗi nhị phân 64-bit.
    * Với TripleDES: Nhập lần lượt 3 chuỗi nhị phân K1, K2, K3 (mỗi khóa 64-bit).

## 4. Output / Đầu ra
* **Kết quả**: In ra chuỗi nhị phân hoàn chỉnh sau khi đã thực hiện mã hóa hoặc giải mã.
* **Chi tiết**: Kết quả hiển thị rõ ràng để bộ chấm tự động (CI) có thể đối chiếu.

## 5. Padding đang dùng
* **Cơ chế**: Zero Padding.
* **Cách thực hiện**: Nếu khối dữ liệu cuối cùng không đủ 64-bit, chương trình sẽ tự động bù thêm các ký tự '0' vào cuối cho đến khi đủ độ dài 64-bit.
* **Hạn chế**: Zero padding có thể gây nhầm lẫn nếu dữ liệu gốc thực tế cũng kết thúc bằng các số 0.
