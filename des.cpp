#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// === BƯỚC 1: HÀM MÃ HÓA DES CHO MỘT KHỐI 64-BIT ===
// Đây là nơi CI sẽ kiểm tra tính đúng đắn của thuật toán
string des_64bit_block_process(string block, string key, bool encrypt) {
    /* 
       QUY TRÌNH BẮT BUỘC:
       1. Initial Permutation (IP)
       2. Chia thành L (32-bit) và R (32-bit)
       3. Chạy 16 vòng Feistel (Sử dụng hàm f, S-boxes, P-boxes)
       4. Đổi chỗ L và R lần cuối (Final Swap)
       5. Final Permutation (FP / IP-1)
    */
    
    // TẠM THỜI: Bạn phải dán logic DES đã viết của mình vào đây.
    // Nếu chỉ return block, CI sẽ báo FAIL vì kết quả không đổi (giống image_8b9733.png)
    string ciphertext_block = block; // <--- THAY BẰNG KẾT QUẢ SAU KHI QUA FP
    
    return ciphertext_block;
}

// === BƯỚC 2: HÀM XỬ LÝ ĐA KHỐI & ZERO PADDING (GIẢI QUYẾT Q2) ===
void process_submission() {
    int mode;
    string data, k1, k2, k3;

    // Đọc input theo đúng thứ tự kịch bản test: Mode -> Plaintext -> Key
    if (!(cin >> mode >> data)) return;

    // A. THỰC HIỆN ZERO PADDING (Yêu cầu trọng tâm của Q2)
    // Nếu độ dài dữ liệu lẻ, bù thêm '0' vào cuối cho đến khi chia hết cho 64
    while (data.length() % 64 != 0) {
        data += '0';
    }

    // B. ĐỌC KHÓA THEO CHẾ ĐỘ
    if (mode == 1 || mode == 2) {
        cin >> k1;
    } else {
        cin >> k1 >> k2 >> k3;
    }

    string final_output = "";

    // C. CHIA KHỐI VÀ XỬ LÝ (Multi-block logic)
    for (size_t i = 0; i < data.length(); i += 64) {
        string block = data.substr(i, 64);
        
        if (mode == 1) { // DES Encrypt
            final_output += des_64bit_block_process(block, k1, true);
        } else if (mode == 2) { // DES Decrypt
            final_output += des_64bit_block_process(block, k1, false);
        } else if (mode == 3) { // 3DES Encrypt
            // E(k1) -> D(k2) -> E(k3)
            string r1 = des_64bit_block_process(block, k1, true);
            string r2 = des_64bit_block_process(r1, k2, false);
            final_output += des_64bit_block_process(r2, k3, true);
        } else if (mode == 4) { // 3DES Decrypt
            // D(k3) -> E(k2) -> D(k1)
            string r1 = des_64bit_block_process(block, k3, false);
            string r2 = des_64bit_block_process(r1, k2, true);
            final_output += des_64bit_block_process(r2, k1, false);
        }
    }

    // D. IN KẾT QUẢ (Chỉ in 1 dòng nhị phân duy nhất)
    cout << final_output << endl;
}

int main() {
    // Tối ưu hóa tốc độ nhập xuất
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    process_submission();

    return 0;
}
