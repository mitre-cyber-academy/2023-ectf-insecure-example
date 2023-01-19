# Example Fob Firmware
The firmware is split into a few files that may be of interest to you,
although you are free to change any and all files in this directory as long as
functional and build requirements are met:

* `firmware.c`: Implements the main functionality of the firmware, including `main()`
* `uart.{c,h}`: Implements a UART interface to the host, reading and writing raw
  bytes.
* `board_link.{c,h}`: Implements a UART interface between the two developent boards
  with packet structures for communications.
* `feature_list.h`: Includes definitions for utilizing the feature list included
  with the build process in EEPROM. This file should not need to be modified.

We have also included the Tivaware driver library for working with the
microcontroller peripherals. You can find Tivaware in `lib/tivaware` and will
find the following files to be of interest:

* `startup_gcc.c`: Implements the system startup code, including initializing
  the stack and jumping to the `main`. There is a good chance that you will not
  need to change `startup_gcc.c`, but some advanced designs may require it.
* `bootloader.ld`: The linker script to set up memory regions. There is a good
  chance that you will not need to change `bootloader.ld`, but some advanced
  designs may require it.
* `makedefs`: The common definitions included when compiling the Tivaware
  library and your firmware. If you want to specific optimizations and
  compiler options to both Tivaware and the bootloader, add/change them here.
  Otherwise, those options can be added to `bootloader/Makefile`.

## On Adding Crypto
To aid with development, we have included Makefile rules and example code for using
[tiny-AES-c](https://github.com/kokke/tiny-AES-c) (see line 46 of the Makefile and
lines 21 and 207 of bootloader.c). You are free to use the library for your crypto
or simply use build process as a template for another crypto library of your choice.

If you choose to use a different crypto library, we recommend using the following
steps to integrate it into your system. **NOTE: All added libraries must compile
from the `all` rule of `bootloader/Makefile` to follow the functional requirements.**
1. Find a crypto library suitable for your embedded system. **Make sure it does not
   require any system calls or dynamic memory allocation (i.e. malloc), as the
   bootloader runs on bare metal without an operating system**
2. Uncommennt the `EXAMPLE_AES=foo` line in the Makefile
3. Run the included tests of the library to verify it works properly on your machine
   before you integrate it with your code
