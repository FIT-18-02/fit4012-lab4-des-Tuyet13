#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // BẮT BUỘC phải có để dùng hàm reverse

using namespace std;

// Hàm đảo ngược chuỗi (sửa lỗi trong hình image_8bf1c7.png)
string reverseBits(string s) {
    reverse(s.begin(), s.end());
    return s;
}

// Giả lập hàm mã hóa/giải mã DES 1 khối (Sinh viên thay thế bằng logic thực tế của mình)
string processDESBlock(string block, string key, bool encrypt) {
    // Logic 16 vòng Feistel, IP, FP... thực hiện ở đây
    // Để minh họa và test Q2, hàm này trả về chuỗi tạm thời (giả định)
    return block; 
}

// Logic TripleDES (EDE: Encrypt K1 -> Decrypt K2 -> Encrypt K3)
string processTripleDES(string block, string k1, string k2, string k3, bool encrypt) {
    if (encrypt) {
        string out1 = processDESBlock(block, k1, true);
        string out2 = processDESBlock(out1, k2, false);
        return processDESBlock(out2, k3, true);
    } else {
        string out1 = processDESBlock(block, k3, false);
        string out2 = processDESBlock(out1, k2, true);
        return processDESBlock(out2, k1, false);
    }
}

int main() {
    // Tối ưu tốc độ nhập xuất để không lỗi time-limit trong CI
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int mode;
    string data, k1, k2, k3;

    // 1. Đọc Mode
    if (!(cin >> mode)) return 0;

    // 2. Đọc Data (Plaintext/Ciphertext)
    if (!(cin >> data)) return 0;

    // 3. Đọc Key (Tùy theo mode)
    if (mode == 1 || mode == 2) {
        cin >> k1;
    } else if (mode == 3 || mode == 4) {
        cin >> k1 >> k2 >> k3;
    }

    // --- XỬ LÝ ZERO PADDING (Giải quyết lỗi Q2 trong image_8bf1c7.png) ---
    while (data.length() % 64 != 0) {
        data += '0';
    }

    string final_output = "";

    // --- XỬ LÝ MULTI-BLOCK ---
    for (size_t i = 0; i < data.length(); i += 64) {
        string block = data.substr(i, 64);
        
        if (mode == 1)      final_output += processDESBlock(block, k1, true);
        else if (mode == 2) final_output += processDESBlock(block, k1, false);
        else if (mode == 3) final_output += processTripleDES(block, k1, k2, k3, true);
        else if (mode == 4) final_output += processTripleDES(block, k1, k2, k3, false);
    }

    // 4. In kết quả cuối cùng (Chỉ in chuỗi nhị phân, không in chữ thừa)
    cout << final_output << endl;

    return 0;
}
