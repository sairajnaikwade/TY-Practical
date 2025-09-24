#include <iostream>
#include <bitset>
#include <cstdint>
using namespace std;

void readIPaddress(int ip[]) {
    char dot;
    for (int i = 0; i < 4; ++i) {
        cin >> ip[i];
        if (i < 3) cin >> dot;
    }
}

void printDecimal(const int ip[]) {
    for (int i = 0; i < 4; ++i) {
        cout << ip[i];
        if (i < 3) cout << ".";
    }
}

void printBinary(const int ip[]) {
    for (int i = 0; i < 4; ++i) {
        cout << bitset<8>(ip[i]);
        if (i < 3) cout << ".";
    }
}

int countOnes(const int mask[]) {
    int cnt = 0;
    for (int i = 0; i < 4; ++i)
        for (int b = 0; b < 8; ++b)
            cnt += (mask[i] >> b) & 1;
    return cnt;
}

void calculateSubnetAddress(const int ip[], const int mask[], int subnet[]) {
    for (int i = 0; i < 4; ++i) subnet[i] = ip[i] & mask[i];
}

void calculateBroadcast(const int subnet[], const int mask[], int broadcast[]) {
    for (int i = 0; i < 4; ++i) broadcast[i] = subnet[i] | (~mask[i] & 255);
}

void incrementIP(int ip[]) { // +1 with carry
    for (int i = 3; i >= 0; --i) {
        if (ip[i] < 255) { ip[i]++; break; }
        ip[i] = 0;
    }
}

void decrementIP(int ip[]) { // -1 with borrow
    for (int i = 3; i >= 0; --i) {
        if (ip[i] > 0) { ip[i]--; break; }
        ip[i] = 255;
    }
}

void noOfHost(const int mask[]) {
    int prefix = countOnes(mask);
    int hostBits = 32 - prefix;
    unsigned long long totalHosts = 0;

    // Classic rule: usable = 2^h - 2 (0 if h <= 1)
    if (hostBits >= 2) totalHosts = (1ULL << hostBits) - 2ULL;

    cout << "\n\nTotal number of usable hosts: " << totalHosts;
}

void totalNoOfSubnets(const int ip[], const int mask[]) {
    int prefix = countOnes(mask);

    // Largest standard boundary: nearest multiple of 8 (octet boundary)
    int baseBoundary = (prefix / 8) * 8;

    int borrowedBits = prefix - baseBoundary;
    unsigned long long totalSubnets = (borrowedBits >= 0) ? (1ULL << borrowedBits) : 0ULL;

    cout << "\nTotal Subnets: " << totalSubnets;
}


void calculateHostRange(const int subnet[], const int mask[]) {
    int broadcast[4];
    calculateBroadcast(subnet, mask, broadcast);

    int prefix = countOnes(mask);
    int hostBits = 32 - prefix;

    if (hostBits <= 1) {
        cout << "\n\nNo usable host range for /" << prefix << " (point-to-point or single-host).";
        return;
    }

    int firstHost[4], lastHost[4];
    for (int i = 0; i < 4; ++i) { firstHost[i] = subnet[i]; lastHost[i] = broadcast[i]; }

    incrementIP(firstHost);
    decrementIP(lastHost);

    cout << "\n\nBroadcast Address (Decimal): ";
    printDecimal(broadcast);
    cout << "\nBroadcast Address (Binary):  ";
    printBinary(broadcast);

    cout << "\n\nFirst Host Address: ";
    printDecimal(firstHost);
    cout << "\nFirst Host (Binary): ";
    printBinary(firstHost);

    cout << "\n\nLast Host Address: ";
    printDecimal(lastHost);
    cout << "\nLast Host (Binary): ";
    printBinary(lastHost);
}

int main() {
    int ip[4], mask[4], subnet[4];

    cout << "Enter IP address (e.g. 192.168.1.10): ";
    readIPaddress(ip);
    cout << "Enter Subnet mask (e.g. 255.255.255.0): ";
    readIPaddress(mask);

    cout << "\nYou entered IP (Decimal): ";
    printDecimal(ip);
    cout << "\nYou entered IP (Binary):  ";
    printBinary(ip);

    cout << "\n\nSubnet Mask (Decimal):   ";
    printDecimal(mask);
    cout << "\nSubnet Mask (Binary):    ";
    printBinary(mask);

    //Compute subnet BEFORE printing it
    calculateSubnetAddress(ip, mask, subnet);
    cout << "\n\nSubnet Address (Decimal): ";
    printDecimal(subnet);
    cout << "\nSubnet Address (Binary):  ";
    printBinary(subnet);

    noOfHost(mask);
    totalNoOfSubnets(ip, mask);
    calculateHostRange(subnet, mask);

    cout << endl;
    return 0;
}
