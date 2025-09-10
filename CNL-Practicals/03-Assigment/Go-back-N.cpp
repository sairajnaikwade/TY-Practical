#include <iostream>
using namespace std;

// Go-Back-N Protocol Simulation
void goBackN() {
    int totalFrames, errorFrame;
 
    cout << "\nGo-Back-N Simulation\n";
    cout << "Enter number of frames to send: ";
    cin >> totalFrames;

    cout << "Enter the frame number where ACK is lost: ";
    cin >> errorFrame;

    // Input validation
    if (errorFrame < 1 || errorFrame > totalFrames) {
        cout << "Invalid frame number! Please enter a number between 1 and " << totalFrames << ".\n";
        return;
    }

    // Sending all frames
    cout << "\nSending Frames:\n";
    for (int i = 1; i <= totalFrames; i++) {
        cout << "Sending Frame " << i << endl;
    }

    // Acknowledgement simulation
    cout << "\nAcknowledgement:\n";
    for (int i = 1; i <= totalFrames; i++) {
        if (i == errorFrame) {
            cout << "Frame " << i << ": ACK not received\n";
            break;
        } else {
            cout << "Frame " << i << ": ACK received\n";
        }
    }

    // Resending from the error frame
    cout << "\nResending from Frame " << errorFrame << ":\n";
    for (int i = errorFrame; i <= totalFrames; i++) {
        cout << "Resending Frame " << i << ": ACK received\n";
    }
}

// Selective Repeat Protocol Simulation
void selectiveRepeat() {
    int totalFrames, errorFrame;

    cout << "\nSelective Repeat Simulation\n";
    cout << "Enter number of frames to send: ";
    cin >> totalFrames;

    cout << "Enter the frame number where ACK is lost: ";
    cin >> errorFrame;

    // Input validation
    if (errorFrame < 1 || errorFrame > totalFrames) {
        cout << "Invalid frame number! Please enter a number between 1 and " << totalFrames << ".\n";
        return;
    }

    // Sending all frames
    cout << "\nSending Frames:\n";
    for (int i = 1; i <= totalFrames; i++) {
        cout << "Sending Frame " << i << endl;
    }

    // Acknowledgement simulation
    cout << "\nAcknowledgement:\n";
    for (int i = 1; i <= totalFrames; i++) {
        if (i == errorFrame) {
            cout << "Frame " << i << ": ACK not received\n";
        } else {
            cout << "Frame " << i << ": ACK received\n";
        }
    }

    // Resending only the failed frame
    cout << "\nResending only Frame " << errorFrame << ": ACK received\n";
}

// Main menu
int main() {
    int choice;

    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Go-Back-N\n";
        cout << "2. Selective Repeat\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            goBackN();
        } else if (choice == 2) {
            selectiveRepeat();
        } else if (choice == 3) {
            cout << "Exiting program.\n";
        } else {
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 3);

    return 0;
}
