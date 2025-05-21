# Project Notes: Nano Board Setup

## First Step: Getting the Nano Boards Working

The initial observation is peculiar. The microcontroller chip is labelled as **ATmega328PB**, yet the bootloader corresponds to **ATmega328B**. There is a mismatch when verifying with AVRDUDE:

- **AVRDUDE in Bootloader mode**: Reports the chip as ATmega328P.
- **AVRDUDE with USBASP programmer**: Reports the chip as ATmega328PB.

It appears that some Chinese manufacturers are using an incorrect bootloader.

### Resolution

- Flashed the correct **OptiBootloader**, enabling the specification of the correct chip for GCBASIC.
- Confirmed the boards are **ATmega328PB** with a **16MHz external clock**.

---

## First Program

### Overview

The following program demonstrates the functionality of the Nano board configured for **ATmega328PB** with a **16MHz external clock**.

### Notes

- Ensure the bootloader reports the microcontroller as **ATmega328PB**, not **ATmega328P** when using AVRDUDE in serial bootloader mode.
- Using AVRDUDE with USBASP programmer, the correct chip details (**ATmega328PB**) are verified.
- Manufacturers may provide Nano boards with an incorrect bootloader. Flashing the correct **OptiBootloader** is essential for proper configuration.

---

### Code

```gcbasic
    // A program for GCBASIC
    // ---------------------------------------------------------------------------------
    // This program initializes the Nano board with Mega328PB and 16MHz external clock.
    //
    // Notes:
    // - The chip clearly states ATmega328PB, the bootloader must report for ATmega328PB.
    // - Using AVRDUDE:
    //   * In serial bootloader mode, must report as ATmega328PB not report ATmega328P.
    //   * Using USBASP programmer, it reports ATmega328PB.
    // - Some Chinese manufacturers are using an incorrect bootloader.
    // - Flash the correct OptiBootloader, which enables specifying the correct chip for GCBASIC.
    // - These boards are confirmed as ATmega328PB with a 16MHz external clock.
    //
    // @author  Evan Venn
    // @licence GPL
    // @version 1.0
    // @date    17/04/2025
    // ********************************************************************************

    // Set microcontroller type and clock speed
    #chip  MEGA328PB, 16
    #option Explicit

    // Define pin constants
    #Define LED     portb.5

    // Use Volatile to ensure the compiler does not try to optimize the code
    #option Volatile LED
    // Set direction of LED as output
    Dir LED out

    // USART settings for USART1
    #define USART_BAUD_RATE 9600
    #define USART_TX_BLOCKING

    // ----- Main body of program commences here.

    wait 3 s      // To give you time to connect the terminal

    // Clear terminal with form feed and newlines
    HserSend 1
    HserSend 1
    HserSend 10
    HserSend 13
    HserSend 10
    HserSend 13

    // Display welcome information and chip details
    HSerPrintStringCRLF "GCBASIC 2025"
    HSerPrintStringCRLF "Program #010 - prove the basic microntroller capability"
    HSerPrintStringCRLF CHIPNAMESTR
    HSerPrintStringCRLF ""

    // Main program loop
    Do
        wait 100 ms
        HSerSend "."  // Send a period character to show activity
        LED = ! LED   // Toggle LED state
    Loop