#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // Sửa lỗi 'reverse' not declared (image_8b9e7b.png)

using namespace std;

// --- PHẦN 1: LOGIC DES CỐT LÕI (IP -> 16 Rounds -> FP) ---
// Bạn hãy đảm bảo hàm này xử lý đúng logic DES cho MỘT khối 64-bit
string des_logic_core(string block, string key, bool encrypt) {
    // TODO: Dán logic IP, 16 vòng Feistel và FP của bạn vào đây
    // Tạm thời trả về block để demo cấu trúc đa khối
    return block; 
}

// --- PHẦN 2: XỬ LÝ TRIPLE DES (3DES) ---
// Quy trình: Encrypt K1 -> Decrypt K2 -> Encrypt K3 (cho mã hóa)
string triple_des_block(string block, string k1, string k2, string k3, bool encrypt) {
    if (encrypt) {
        string res = des_logic_core(block, k1, true);
        res = des_logic_core(res, k2, false);
        return des_logic_core(res, k3, true);
    } else {
        string res = des_logic_core(block, k3, false);
        res = des_logic_core(res, k2, true);
        return des_logic_core(res, k1, false);
    }
}

// --- PHẦN 3: XỬ LÝ ĐA KHỐI & PADDING (Giải quyết triệt để Q2) ---
void solve() {
    int mode;
    string data, k1, k2, k3;

    // Đọc input theo đúng Submission Contract
    if (!(cin >> mode >> data)) return;

    // 1. Thực hiện Zero Padding ngay lập tức cho chuỗi data
    while (data.length() % 64 != 0) {
        data += '0';
    }

    // 2. Đọc khóa dựa trên Mode
    if (mode == 1 || mode == 2) {
        cin >> k1;
    } else {
        cin >> k1 >> k2 >> k3;
    }

    string final_result = "";

    // 3. Vòng lặp chia khối (Multi-block logic)
    for (size_t i = 0; i < data.length(); i += 64) {
        string block = data.substr(i, 64);
        
        if (mode == 1)      final_result += des_logic_core(block, k1, true);
        else if (mode == 2) final_result += des_logic_core(block, k1, false);
        else if (mode == 3) final_result += triple_des_block(block, k1, k2, k3, true);
        else if (mode == 4) final_result += triple_des_block(block, k1, k2, k3, false);
    }

    // 4. CHỈ in ra chuỗi nhị phân kết quả, không in chữ thừa
    cout << final_result << endl;
}

int main() {
    // Tăng tốc độ nhập xuất
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
