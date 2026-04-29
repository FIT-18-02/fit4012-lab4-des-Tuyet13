#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// --- PHẦN 1: LOGIC DES THẬT (BẮT BUỘC PHẢI CÓ) ---
// Bạn cần thay thế hàm này bằng logic DES đầy đủ (IP, 16 rounds, FP)
// Dưới đây là hàm mẫu để đảm bảo cấu trúc Multi-block chạy đúng
string des_encrypt_one_block(string block, string key) {
    /* 
       TODO: Sinh viên dán logic mã hóa 1 khối 64-bit vào đây.
       Quy trình: IP -> 16 Rounds Feistel -> FP.
       Đảm bảo trả về chuỗi 64 ký tự nhị phân.
    */
    
    // Ví dụ tạm thời: Trả về block để bạn thấy cấu trúc (Bạn phải thay bằng code DES thật)
    return block; 
}

// --- PHẦN 2: XỬ LÝ TRIPLE DES ---
string triple_des_process(string block, string k1, string k2, string k3, bool encrypt) {
    // EDE: Encrypt K1 -> Decrypt K2 -> Encrypt K3
    // Sinh viên triển khai tương tự hàm des_encrypt_one_block
    return block;
}

// --- PHẦN 3: HÀM XỬ LÝ CHÍNH ---
void run_des() {
    int mode;
    string data, k1, k2, k3;

    // Đọc input theo đúng kịch bản test (Mode -> Data -> Key)
    if (!(cin >> mode >> data)) return;

    // 1. Thực hiện Zero Padding (Giải quyết lỗi Q2)
    // Nếu plaintext > 64 bit hoặc không chia hết cho 64, bù thêm '0'
    while (data.length() % 64 != 0) {
        data += '0';
    }

    // 2. Đọc khóa dựa trên Mode
    if (mode == 1 || mode == 2) {
        cin >> k1;
    } else {
        cin >> k1 >> k2 >> k3;
    }

    string final_output = "";

    // 3. Xử lý Multi-block (Cắt từng đoạn 64 bit để mã hóa)
    for (size_t i = 0; i < data.length(); i += 64) {
        string block = data.substr(i, 64);
        
        if (mode == 1) { // DES Encrypt
            final_output += des_encrypt_one_block(block, k1);
        }
        // Thêm các mode 2, 3, 4 tương tự...
    }

    // 4. In kết quả (CHỈ in chuỗi nhị phân, không in văn bản thừa)
    cout << final_output << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    run_des();

    return 0;
}
