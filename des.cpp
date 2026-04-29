#include <iostream>
#include <string>
#include <vector>
using namespace std;

// TODO: giữ nguyên các hàm DES bạn đã có

string processDES(string block, string key, bool encrypt) {
    // TODO: gọi hàm DES encode/decode bạn đã viết
    return block; // placeholder
}

// chia block 64 bit + padding
vector<string> splitBlocks(string input) {
    vector<string> blocks;
    int n = input.size();

    for (int i = 0; i < n; i += 64) {
        string block = input.substr(i, 64);

        if (block.size() < 64) {
            block += string(64 - block.size(), '0'); // zero padding
        }

        blocks.push_back(block);
    }

    return blocks;
}

int main() {
    int mode;
    cin >> mode;

    if (mode == 1) {
        // DES encrypt
        string plaintext, key;
        cin >> plaintext >> key;

        vector<string> blocks = splitBlocks(plaintext);
        string result = "";

        for (auto &b : blocks) {
            result += processDES(b, key, true);
        }

        cout << result << endl;
    }
    else if (mode == 2) {
        // DES decrypt
        string ciphertext, key;
        cin >> ciphertext >> key;

        vector<string> blocks = splitBlocks(ciphertext);
        string result = "";

        for (auto &b : blocks) {
            result += processDES(b, key, false);
        }

        cout << result << endl;
    }
    else if (mode == 3) {
        // TripleDES encrypt
        string plaintext, k1, k2, k3;
        cin >> plaintext >> k1 >> k2 >> k3;

        string step1 = processDES(plaintext, k1, true);
        string step2 = processDES(step1, k2, false);
        string step3 = processDES(step2, k3, true);

        cout << step3 << endl;
    }
    else if (mode == 4) {
        // TripleDES decrypt
        string ciphertext, k1, k2, k3;
        cin >> ciphertext >> k1 >> k2 >> k3;

        string step1 = processDES(ciphertext, k3, false);
        string step2 = processDES(step1, k2, true);
        string step3 = processDES(step2, k1, false);

        cout << step3 << endl;
    }

    return 0;
}
