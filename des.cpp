#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // Cần thiết để xử lý chuỗi và hàm reverse

using namespace std;

// Hàm mã hóa 1 khối 64-bit (Sinh viên dùng logic DES thật của mình ở đây)
string encryptBlock(string block, string key) {
    // Logic: IP -> 16 Rounds -> FP
    // Đảm bảo hàm này nhận 64 bit và trả về đúng 64 bit đã mã hóa
    return block; // Thay bằng logic thật
}

int main() {
    // Tối ưu nhập xuất cho môi trường chấm điểm tự động
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int mode;
    string data, key;

    // ĐỌC ĐÚNG THỨ TỰ: Mode -> Data -> Key
    if (!(cin >> mode >> data >> key)) return 0;

    if (mode == 1) { // Chế độ mã hóa DES (Yêu cầu của Q2)
        
        // --- BƯỚC 1: ZERO PADDING ---
        // Nếu độ dài không chia hết cho 64, bù thêm '0' vào cuối
        while (data.length() % 64 != 0) {
            data += '0';
        }

        string final_ciphertext = "";

        // --- BƯỚC 2: CHIA KHỐI VÀ MÃ HÓA (MULTI-BLOCK) ---
        for (size_t i = 0; i < data.length(); i += 64) {
            string block = data.substr(i, 64);
            
            // Gọi hàm mã hóa cho từng khối 64-bit
            final_ciphertext += encryptBlock(block, key);
        }

        // --- BƯỚC 3: IN KẾT QUẢ ---
        // Chỉ in duy nhất chuỗi nhị phân cuối cùng để script grep được
        cout << final_ciphertext << endl;
    }

    return 0;
}
