# Assignment 3: Sliding Window Protocol Simulation (Go-Back-N & Selective Repeat)

## Overview

This assignment demonstrates the working of two important error-control protocols in computer networks: **Go-Back-N** and **Selective Repeat**. The provided C++ program simulates the transmission of data frames, handling lost acknowledgments, and retransmission strategies for both protocols.

## Problem Statement

Write a C/C++/Java program to simulate Go-Back-N and Selective Repeat Modes of Sliding Window protocol.

## How it Works

- **Go-Back-N:**
  - All frames are sent sequentially.
  - If an ACK for a frame is lost, all frames from the error frame onwards are retransmitted.
- **Selective Repeat:**
  - All frames are sent sequentially.
  - If an ACK for a frame is lost, only that specific frame is retransmitted.

The program provides a menu-driven CLI that lets the user choose which protocol to simulate, enter the number of frames, and specify which frame encounters a lost ACK.

## Features

- Interactive CLI for selecting protocol and entering simulation parameters.
- Clear display of frame transmission and acknowledgment status.
- Realistic retransmission logic for both Go-Back-N and Selective Repeat.
- Input validation to ensure realistic scenarios.

## Usage

### 1. Compile the Program

```bash
g++ sliding_window.cpp -o sliding_window
```

### 2. Run the Program

```bash
./sliding_window
```

### 3. Sample Run

**Go-Back-N Example:**
```
--- Menu ---
1. Go-Back-N
2. Selective Repeat
3. Exit
Enter your choice: 1

Go-Back-N Simulation
Enter number of frames to send: 5
Enter the frame number where ACK is lost: 3

Sending Frames:
Sending Frame 1
Sending Frame 2
Sending Frame 3
Sending Frame 4
Sending Frame 5

Acknowledgement:
Frame 1: ACK received
Frame 2: ACK received
Frame 3: ACK not received

Resending from Frame 3:
Resending Frame 3: ACK received
Resending Frame 4: ACK received
Resending Frame 5: ACK received
```

**Selective Repeat Example:**
```
--- Menu ---
1. Go-Back-N
2. Selective Repeat
3. Exit
Enter your choice: 2

Selective Repeat Simulation
Enter number of frames to send: 5
Enter the frame number where ACK is lost: 3

Sending Frames:
Sending Frame 1
Sending Frame 2
Sending Frame 3
Sending Frame 4
Sending Frame 5

Acknowledgement:
Frame 1: ACK received
Frame 2: ACK received
Frame 3: ACK not received
Frame 4: ACK received
Frame 5: ACK received

Resending only Frame 3: ACK received
```

## Code Explanation

- **Main Menu:** Lets users select which protocol to simulate.
- **goBackN Function:** Implements Go-Back-N logic by resending all frames after the lost ACK.
- **selectiveRepeat Function:** Implements Selective Repeat logic by resending only the frame with the lost ACK.
- **Input Validation:** Ensures error frame is within the valid range.

## References

- [Go-Back-N ARQ (Wikipedia)](https://en.wikipedia.org/wiki/Go-Back-N_ARQ)
- [Selective Repeat ARQ (Wikipedia)](https://en.wikipedia.org/wiki/Selective_Repeat_ARQ)
- Data Communication and Networking, Forouzan (for protocol theory and diagrams)

## Notes

- This simulation assumes a single lost ACK for demonstration. For real-world scenarios, additional logic may be required.
- Window size is not explicitly handled, but the retransmission logic mimics practical protocol behavior.
- You can extend the program to handle multiple lost ACKs or variable window sizes for further experimentation.

---
