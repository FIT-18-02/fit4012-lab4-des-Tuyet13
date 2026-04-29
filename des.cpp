#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // Bước 1: Sửa lỗi thiếu thư viện cho hàm reverse

using namespace std;

// --- TIỆN ÍCH ---
string xor_strings(string a, string b) {
    string res = "";
    for (size_t i = 0; i < a.length(); i++) res += (a[i] == b[i] ? '0' : '1');
    return res;
}

// --- LOGIC DES 64-BIT ---
// Bạn hãy thay nội dung hàm này bằng thuật toán DES thực tế của bạn (IP -> 16 rounds -> FP)
string des_unit(string block, string key, bool encrypt) {
    // Đây là nơi thực hiện logic mã hóa/giải mã cho đúng 64 bit
    // Nếu logic IP/FP hoặc S-Box của bạn sai, Q2 sẽ báo FAIL vì không khớp bit kết quả
    string processed_block = block; 
    // ... (Logic IP, Feistel Rounds, FP của bạn) ...
    return processed_block;
}

// --- BƯỚC 3: XỬ LÝ ĐA KHỐI & PADDING (Sửa lỗi Q2) ---
string process_multi_block(string data, string key, int mode) {
    // Thực hiện Zero Padding ngay lập tức
    while (data.length() % 64 != 0) {
        data += '0';
    }

    string final_res = "";
    for (size_t i = 0; i < data.length(); i += 64) {
        string block = data.substr(i, 64);
        
        if (mode == 1) final_res += des_unit(block, key, true);
        else if (mode == 2) final_res += des_unit(block, key, false);
    }
    return final_res;
}

// --- BƯỚC 2: CHUẨN HÓA ĐỌC INPUT (Sửa lỗi Stdin) ---
int main() {
    // Tắt đồng bộ để tránh ký tự lạ chèn vào stream
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int mode;
    string data, k1, k2, k3;

    // Đọc theo đúng thứ tự: Mode -> Data (Plain/Cipher) -> Key(s)
    if (!(cin >> mode >> data)) return 0;

    if (mode == 1 || mode == 2) {
        cin >> k1;
        // In duy nhất chuỗi nhị phân kết quả (Không in chữ thừa)
        cout << process_multi_block(data, k1, mode) << endl;
    } 
    else if (mode == 3 || mode == 4) {
        cin >> k1 >> k2 >> k3;
        // Xử lý TripleDES (EDE) cho từng khối 64-bit sau khi đã pad data
        while (data.length() % 64 != 0) data += '0';
        string res_3des = "";
        for (size_t i = 0; i < data.length(); i += 64) {
            string block = data.substr(i, 64);
            if (mode == 3) { // Encrypt: E(k1) -> D(k2) -> E(k3)
                string t = des_unit(block, k1, true);
                t = des_unit(t, k2, false);
                res_3des += des_unit(t, k3, true);
            } else { // Decrypt: D(k3) -> E(k2) -> D(k1)
                string t = des_unit(block, k3, false);
                t = des_unit(t, k2, true);
                res_3des += des_unit(t, k1, false);
            }
        }
        cout << res_3des << endl;
    }

    return 0;
}
