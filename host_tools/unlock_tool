#!/usr/bin/python3 -u

# @file unlock_tool
# @author Frederich Stine
# @brief host tool for monitoring an unlock
# @date 2023
#
# This source file is part of an example system for MITRE's 2023 Embedded
# CTF (eCTF). This code is being provided only for educational purposes for the
# 2023 MITRE eCTF competition, and may not meet MITRE standards for quality.
# Use this code at your own risk!
#
# @copyright Copyright (c) 2023 The MITRE Corporation

import socket
import argparse


# @brief Function to monitor unlocking car
# @param car_bridge, bridged serial connection to car
def unlock(car_bridge):

    # Connect car socket to serial
    car_sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    car_sock.connect(("ectf-net", int(car_bridge)))

    # Set timeout for if unlock fails
    car_sock.settimeout(5)

    # Try to receive data while unlocking - if empty, unlock failed
    unlock_received: bytes = b""
    while True:
        try:
            unlock_received += car_sock.recv(1)
        except socket.timeout:
            print("Socket timeout - finished receiving")
            break

    # If no data receive, unlock failed
    if len(unlock_received) == 0:
        print("Failed to unlock")
    # If data received, print out unlock message and features
    else:
        print(unlock_received)

    return 0


# @brief Main function
#
# Main function handles parsing arguments and passing them to unlock
# function.
def main():
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "--car-bridge", help="Port number of the socket for the car", required=True,
    )

    args = parser.parse_args()

    unlock(args.car_bridge)


if __name__ == "__main__":
    main()
