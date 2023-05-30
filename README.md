<h1>42 ft_printf</h1>

The ft_printf project is a simplified version of the printf function in C that allows you to format and print to the standard output using specified format specifiers.
 THIS CODE HANDLE THE FOLLOWING FLAGS: cspdiuxXob% 
 o = octal
 b = binary
 p = pointer
 d = decimal
 i = integer
 u = unsigned integer
 x = hexadecimal
 X = hexadecimal
 c = character
 s = string
 % = percent

**Getting Started**

To get started with ft_printf, follow these steps:

`Download or clone the repository to your local machine by running the following command:`

     git clone https://github.com/SopadeGalinha/42-ft_printf.git

The repository contains the source code, along with a Makefile that can be used to compile the program.

To build the program, simply run the following command in the repository's root directory: `make`

This will generate the **ft_libftprintf.a** file, which can be linked to your C project.

## How to use it

To compile your code you can do:

    gcc yourmaincode.c libftprintf.a && ./a.out

Your program will now use the ft_printf function to format and print output based on the format specifiers you provide.

`Make sure to include the necessary header files in your main code, such as ft_printf.h, to access the function prototypes and definitions.`

