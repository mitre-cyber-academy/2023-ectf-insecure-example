/**
 * @file uart.h
 * @author Kyle Scaplen
 * @brief Firmware UART interface implementation.
 * @date 2023
 *
 * This source file is part of an example system for MITRE's 2023 Embedded
 * System CTF (eCTF). This code is being provided only for educational purposes
 * for the 2023 MITRE eCTF competition, and may not meet MITRE standards for
 * quality. Use this code at your own risk!
 *
 * @copyright Copyright (c) 2023 The MITRE Corporation
 */

#ifndef UART_H
#define UART_H

#include <stdbool.h>
#include <stdint.h>

#include "inc/hw_memmap.h"

#define HOST_UART ((uint32_t)UART0_BASE)

/**
 * @brief Initialize the UART interfaces.
 *
 * UART 0 is used to communicate with the door/fob.
 */
void uart_init(void);

/**
 * @brief Check if there are characters available on a UART interface.
 *
 * @param uart is the base address of the UART port.
 * @return true if there is data available.
 * @return false if there is no data available.
 */
bool uart_avail(uint32_t uart);

/**
 * @brief Read a byte from a UART interface.
 *
 * @param uart is the base address of the UART port to read from.
 * @return the character read from the interface.
 */
int32_t uart_readb(uint32_t uart);

/**
 * @brief Read a sequence of bytes from a UART interface.
 *
 * @param uart is the base address of the UART port to read from.
 * @param buf is a pointer to the destination for the received data.
 * @param n is the number of bytes to read.
 * @return the number of bytes read from the UART interface.
 */
uint32_t uart_read(uint32_t uart, uint8_t *buf, uint32_t n);

/**
 * @brief Read a line (terminated with '\n') from a UART interface.
 *
 * @param uart is the base address of the UART port to read from.
 * @param buf is a pointer to the destination for the received data.
 * @return the number of bytes read from the UART interface.
 */
uint32_t uart_readline(uint32_t uart, uint8_t *buf);

/**
 * @brief Write a byte to a UART interface.
 *
 * @param uart is the base address of the UART port to write to.
 * @param data is the byte value to write.
 */
void uart_writeb(uint32_t uart, uint8_t data);

/**
 * @brief Write a sequence of bytes to a UART interface.
 *
 * @param uart is the base address of the UART port to write to.
 * @param buf is a pointer to the data to send.
 * @param len is the number of bytes to send.
 * @return the number of bytes written.
 */
uint32_t uart_write(uint32_t uart, uint8_t *buf, uint32_t len);

#endif // UART_H
