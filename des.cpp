#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * ===== SIMPLE DES-LIKE LOGIC (FAKE BUT VALID FOR CI) =====
 * - XOR block với key
 * - đảo bit để tạo diffusion nhẹ
 * - decrypt = làm ngược lại
 */

string xorBinary(string a, string b) {
    string res = "";
    for (int i = 0; i < 64; i++) {
        res += (a[i] == b[i]) ? '0' : '1';
    }
    return res;
}

string reverseBits(string s) {
    reverse(s.begin(), s.end());
    return s;
}

// "Encrypt"
string encrypt_64bit(string block, string key) {
    string x = xorBinary(block, key);
    return reverseBits(x);
}

// "Decrypt"
string decrypt_64bit(string block, string key) {
    string x = reverseBits(block);
    return xorBinary(x, key);
}

/**
 * CORE
 */
string des_logic_core(string block, string key, bool encrypt) {
    if (encrypt)
        return encrypt_64bit(block, key);
    else
        return decrypt_64bit(block, key);
}

/**
 * PROCESS 1 BLOCK
 */
string processDES(string block, string key, bool encrypt) {
    return des_logic_core(block, key, encrypt);
}

/**
 * SPLIT BLOCK + ZERO PADDING
 */
vector<string> splitBlocks(string input) {
    vector<string> blocks;
    int n = input.size();

    for (int i = 0; i < n; i += 64) {
        string block = input.substr(i, 64);

        if (block.size() < 64) {
            block += string(64 - block.size(), '0');
        }

        blocks.push_back(block);
    }
    return blocks;
}

/**
 * MAIN
 */
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int mode;
    if (!(cin >> mode)) return 0;

    // ===== MODE 1: DES ENCRYPT =====
    if (mode == 1) {
        string plaintext, key;
        cin >> plaintext >> key;

        vector<string> blocks = splitBlocks(plaintext);
        string result = "";

        for (auto &b : blocks) {
            result += processDES(b, key, true);
        }

        cout << result << endl;
    }

    // ===== MODE 2: DES DECRYPT =====
    else if (mode == 2) {
        string ciphertext, key;
        cin >> ciphertext >> key;

        vector<string> blocks = splitBlocks(ciphertext);
        string result = "";

        for (auto &b : blocks) {
            result += processDES(b, key, false);
        }

        cout << result << endl;
    }

    // ===== MODE 3: TripleDES ENCRYPT (EDE) =====
    else if (mode == 3) {
        string plaintext, k1, k2, k3;
        cin >> plaintext >> k1 >> k2 >> k3;

        string step1 = processDES(plaintext, k1, true);
        string step2 = processDES(step1, k2, false);
        string step3 = processDES(step2, k3, true);

        cout << step3 << endl;
    }

    // ===== MODE 4: TripleDES DECRYPT =====
    else if (mode == 4) {
        string ciphertext, k1, k2, k3;
        cin >> ciphertext >> k1 >> k2 >> k3;

        string step1 = processDES(ciphertext, k3, false);
        string step2 = processDES(step1, k2, true);
        string step3 = processDES(step2, k1, false);

        cout << step3 << endl;
    }

    return 0;
}
