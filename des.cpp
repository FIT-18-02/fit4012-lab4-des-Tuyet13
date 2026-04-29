#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Dán toàn bộ logic DES (IP, 16 Rounds, FP) của bạn vào hàm này
string des_64bit(string block, string key, bool encrypt) {
    // Đảm bảo hàm này nhận 64 bit và trả về đúng 64 bit
    return block; // Thay bằng logic thật
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int mode;
    string data, k1, k2, k3;

    if (!(cin >> mode >> data)) return 0;

    // BẮT BUỘC: Bù Zero Padding cho đến khi đủ bội số của 64 bit
    while (data.length() % 64 != 0) {
        data += '0';
    }

    if (mode <= 2) cin >> k1;
    else cin >> k1 >> k2 >> k3;

    string final_res = "";
    for (size_t i = 0; i < data.length(); i += 64) {
        string block = data.substr(i, 64);
        if (mode == 1) final_res += des_64bit(block, k1, true);
        else if (mode == 2) final_res += des_64bit(block, k1, false);
        else if (mode == 3) {
            string res = des_64bit(block, k1, true);
            res = des_64bit(res, k2, false);
            final_res += des_64bit(res, k3, true);
        } else if (mode == 4) {
            string res = des_64bit(block, k3, false);
            res = des_64bit(res, k2, true);
            final_res += des_64bit(res, k1, false);
        }
    }

    // CHỈ IN RA CHUỖI NHỊ PHÂN CUỐI CÙNG
    cout << final_res << endl;

    return 0;
}
