# Assignment 2: Error Detection and Correction for ASCII Codes Using Hamming Codes

## Overview

This assignment demonstrates how Hamming(7,4) codes can be used for error detection and correction in digital communication. The provided C++ program allows the user to input 4 data bits, encodes them using Hamming Code, simulates transmission, and performs error correction if a single-bit error is detected in the received code.

## Problem Statement

Write a C/C++ program for error detection and correction for 7/8 bits ASCII codes using Hamming Codes.

## How it Works

- **Encoding:**  
  The program takes 4 data bits (representing part of an ASCII code) and generates a 7-bit Hamming code by calculating parity bits and placing them in appropriate positions.
- **Transmission Simulation:**  
  The user supplies the received 7-bit code, which may have one bit in error.
- **Error Detection and Correction:**  
  The program calculates parity checks to locate a single-bit error and corrects it, then displays the corrected code and original data bits.

## Features

- Interactive CLI for entering data and received bits.
- Displays the encoded Hamming code.
- Detects and locates single-bit errors using syndrome calculation.
- Corrects the error and outputs the corrected code and recovered data bits.

## Usage

### 1. Compile the Program

```bash
g++ Hamming-Code.cpp -o hamming_code
```

### 2. Run the Program

```bash
./hamming_code
```

### 3. Sample Run

```
Enter 4 data bits (left to right):
Bit 1: 1
Bit 2: 0
Bit 3: 1
Bit 4: 1

Encoded Hamming(7,4) code: 0 1 1 0 0 1 1

Enter received 7-bit code (left to right):
Bit 1: 0
Bit 2: 1
Bit 3: 1
Bit 4: 1   <-- suppose bit 4 is changed (error introduced)
Bit 5: 0
Bit 6: 1
Bit 7: 1

Error detected at position: 4
Corrected code: 0 1 1 0 0 1 1

Original Data (D1 D2 D3 D4): 1 0 1 1
```

## Code Explanation

- **Data Bits:** Positions 3, 5, 6, and 7 in the code array.
- **Parity Bits:** Positions 1, 2, and 4 (index 0, 1, 3).
- **Syndrome Calculation:**  
  Parity checks produce a binary number identifying the error position.
- **Correction:**  
  If an error is detected, the program flips the erroneous bit.

## References

- [Hamming Code (Wikipedia)](https://en.wikipedia.org/wiki/Hamming_code)
- [ASCII Table](https://www.ascii-code.com/)
- Data Communication and Networking, Forouzan (for theory and background)


## Notes

- This implementation demonstrates Hamming(7,4), suitable for 4-bit chunks. For full 7/8-bit ASCII, extension to Hamming(8,4) or similar is needed.
- Only single-bit error detection and correction is supported.
- Can be adapted for string or ASCII encoding by expanding logic.
