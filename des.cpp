#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // Sửa lỗi trong hình image_8b9e7b.png: Cần thư viện này để dùng hàm reverse

using namespace std;

// --- PHẦN 1: CÁC HÀM TIỆN ÍCH ---

// Đảo ngược chuỗi bit
string reverseBits(string s) {
    reverse(s.begin(), s.end()); // Hàm reverse nằm trong thư viện <algorithm>
    return s;
}

// --- PHẦN 2: LOGIC DES CỐT LÕI ---
// Sinh viên dán logic IP, Feistel, KeyGenerator... thực tế vào đây.
string des_logic_core(string block, string key, bool encrypt) {
    // Placeholder: Hàm này phải xử lý đúng 1 khối 64-bit
    // logic của bạn: IP -> 16 rounds -> FP
    return block; 
}

// --- PHẦN 3: XỬ LÝ ĐA KHỐI & PADDING (Sửa lỗi Q2 trong image_8bf1c7.png) ---

string process_multi_block(string data, string key, int mode) {
    // 1. Thực hiện Zero Padding (Q2 yêu cầu)
    // Nếu độ dài không chia hết cho 64, bù thêm ký tự '0' vào cuối
    while (data.length() % 64 != 0) {
        data += '0';
    }

    string final_result = "";
    bool is_encrypt = (mode == 1 || mode == 3);

    // 2. Chia thành từng khối 64-bit để mã hóa/giải mã
    for (size_t i = 0; i < data.length(); i += 64) {
        string block = data.substr(i, 64);
        
        if (mode == 1 || mode == 2) {
            // DES đơn
            final_result += des_logic_core(block, key, is_encrypt);
        }
    }
    return final_result;
}

int main() {
    // Tăng tốc nhập xuất để tránh lỗi time-limit trên CI
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int mode;
    string data, key, k1, k2, k3;

    // Đọc đầu vào theo đúng "Submission Contract"
    if (!(cin >> mode)) return 0;
    if (!(cin >> data)) return 0;

    if (mode == 1 || mode == 2) {
        cin >> key;
        cout << process_multi_block(data, key, mode) << endl;
    } 
    else if (mode == 3 || mode == 4) {
        cin >> k1 >> k2 >> k3;
        // Logic TripleDES: E(K1) -> D(K2) -> E(K3)
        // Áp dụng process_multi_block tương tự cho 3 bước
        string res = data;
        // Thực hiện tuần tự các bước 3DES cho toàn bộ chuỗi data đã pad
        // ... (Sinh viên triển khai logic TripleDES tại đây)
    }

    return 0;
}
