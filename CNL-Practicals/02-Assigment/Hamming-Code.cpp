#include<iostream>
using namespace std;

int main() {
    int data[4];      
    int code[7];      

    cout << "Enter 4 data bits (left to right):\n";
    for (int i = 0; i < 4; i++) {
        cout << "Bit " << i+1 << ": ";
        cin >> data[i];
    }

    code[2] = data[0]; //bits are placed in positions 3, 5, 6, and 7 (index starts from 0)
    code[4] = data[1]; 
    code[5] = data[2]; 
    code[6] = data[3]; 

    code[0] = code[2] ^ code[4] ^ code[6]; 
    code[1] = code[2] ^ code[5] ^ code[6]; 
    code[3] = code[4] ^ code[5] ^ code[6]; 

    cout << "\nEncoded Hamming(7,4) code: ";
    for (int i = 0; i < 7; i++) {
        cout << code[i] << " ";
    }
    cout << endl;

    int received[7];
    cout << "\nEnter received 7-bit code (left to right):\n";
    for (int i = 0; i < 7; i++) {
        cout << "Bit " << i+1 << ": ";
        cin >> received[i];
    }

    int p1 = received[0] ^ received[2] ^ received[4] ^ received[6];
    int p2 = received[1] ^ received[2] ^ received[5] ^ received[6];
    int p4 = received[3] ^ received[4] ^ received[5] ^ received[6];
    int error_pos = p4 * 4 + p2 * 2 + p1 * 1;

    if (error_pos == 0) {
        cout << "\nNo error detected in the received code.\n";
    } else {
        cout << "\nError detected at position: " << error_pos << endl;
        received[error_pos - 1] ^= 1; 
        cout << "Corrected code: ";
        for (int i = 0; i < 7; i++) {
            cout << received[i] << " ";
        }
        cout << endl;
    }

    cout << "\nOriginal Data (D1 D2 D3 D4): ";
    cout << received[2] << " " << received[4] << " " << received[5] << " " << received[6] << endl;

    return 0;
}
