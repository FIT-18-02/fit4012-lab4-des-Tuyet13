#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * PHẦN 1: CÁC HÀM LOGIC DES CỦA BẠN
 * Bạn hãy dán các hàm: hexToBin, binToHex, XOR, IP, InverseIP, 
 * KeyGenerator, DES_Encrypt, DES_Decrypt... vào đây.
 */

// Ví dụ một hàm placeholder để bạn biết chỗ dán
string des_logic_core(string block, string key, bool encrypt) {
    // Gọi hàm mã hóa hoặc giải mã 1 block 64-bit mà bạn đã làm ở Lab
    // return encrypt ? encrypt_64bit(block, key) : decrypt_64bit(block, key);
    return block; // Thay thế bằng logic thực tế của bạn
}

/**
 * PHẦN 2: XỬ LÝ CHƯƠNG TRÌNH THEO SUBMISSION CONTRACT
 */

// Hàm điều phối DES cho 1 block (64-bit)
string processDES(string block, string key, bool encrypt) {
    // Đảm bảo block và key đủ 64-bit trước khi đưa vào logic core
    return des_logic_core(block, key, encrypt);
}

// Q2: Chia block 64 bit + Zero padding
vector<string> splitBlocks(string input) {
    vector<string> blocks;
    int n = input.size();

    if (n == 0) return blocks;

    for (int i = 0; i < n; i += 64) {
        string block = input.substr(i, 64);

        if (block.size() < 64) {
            block += string(64 - block.size(), '0'); // Zero padding
        }
        blocks.push_back(block);
    }
    return blocks;
}

int main() {
    // Tắt đồng bộ để nhập xuất nhanh hơn cho CI
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int mode;
    if (!(cin >> mode)) return 0; // Đọc mode (1, 2, 3, 4)

    if (mode == 1) {
        // Q2: DES encrypt (Hỗ trợ nhiều block + Zero padding)
        string plaintext, key;
        cin >> plaintext >> key;

        vector<string> blocks = splitBlocks(plaintext);
        string result = "";

        for (auto &b : blocks) {
            result += processDES(b, key, true);
        }
        cout << result << endl; // In ra ciphertext cuối cùng
    }
    else if (mode == 2) {
        // Q3: DES decrypt
        string ciphertext, key;
        cin >> ciphertext >> key;

        vector<string> blocks = splitBlocks(ciphertext);
        string result = "";

        for (auto &b : blocks) {
            result += processDES(b, key, false);
        }
        cout << result << endl; // In ra plaintext cuối cùng
    }
    else if (mode == 3) {
        // Q4: TripleDES encrypt (EDE: E-K1, D-K2, E-K3)
        string plaintext, k1, k2, k3;
        cin >> plaintext >> k1 >> k2 >> k3;

        // TripleDES thường thực hiện trên block 64-bit theo yêu cầu lab
        string step1 = processDES(plaintext, k1, true);  // Encrypt K1
        string step2 = processDES(step1, k2, false);     // Decrypt K2
        string step3 = processDES(step2, k3, true);      // Encrypt K3

        cout << step3 << endl;
    }
    else if (mode == 4) {
        // Q4: TripleDES decrypt (D-K3, E-K2, D-K1)
        string ciphertext, k1, k2, k3;
        cin >> ciphertext >> k1 >> k2 >> k3;

        string step1 = processDES(ciphertext, k3, false); // Decrypt K3
        string step2 = processDES(step1, k2, true);      // Encrypt K2
        string step3 = processDES(step2, k1, false);     // Decrypt K1

        cout << step3 << endl;
    }

    return 0;
}
