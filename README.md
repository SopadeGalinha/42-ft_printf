<h1 align="center">
  <b>ft_printf</b>
</h1>


<h2 align="center">
  <i>42cursus Project #3</i>
</h2>

<p align="center">
  This project is an advanced implementation of the standard <b>printf</b> function in the C programming language, designed to provide developers with enhanced formatting capabilities and seamless content printing to the standard output.
</p>

<div align=center>
<h2>
	Final Score & Evaluations
</h2>
<p align="center">
  <img src="https://github.com/SopadeGalinha/42-ft_printf/assets/75684404/4724fb0b-0d92-4519-8271-de946bcd64df" alt="Imagem do ft_printf">
  <img src="https://github.com/SopadeGalinha/42-ft_printf/assets/75684404/7a23d315-2982-40c3-90a5-1e1c4996099e" alt="Imagem do ft_printf">
  <img src="https://github.com/SopadeGalinha/42-ft_printf/assets/75684404/0e0199d4-796a-4b45-a92a-45dc59d7509a" alt="Imagem do ft_printf">

</p>

## Project Overview

The `ft_printf` project introduces an evolved version of the traditional printf function. It equips developers with a wide array of meticulously defined format specifiers, enabling precise content arrangement and efficient output printing. This project supports the following specifiers:

| Conversion  | Description														 			| Project 		|
|-------|-----------------------------------------------------------------------------------|---------------|
| **c** | Single ascii character         													|Mandatory		|
| **s** | String of characters NULL terminated												|Mandatory		|
| **p** | Pointer location converted to hexadecimal value									|Mandatory		|
| **d** | Decimal number 																	|Mandatory		|
| **i** | Integer in decimal base                 											|Mandatory		|
| **u** | Unsigned integer in decimal base                									|Mandatory		|
| **x** | Unsigned number printed in lowercase hexadecimal base                				|Mandatory		|
| **X** | Unsigned number printed in uppercase hexadecimal base                				|Mandatory		|
| **%** | The '%' ascii character                 											|Mandatory		|
| **o** | Unsigned number printed in octal base                 							|Extra			|
| **b** | Unsigned number printed in binary base                 							|Extra			|


Each specifier is crafted to meet specific formatting needs, providing versatility in displaying various types of data.

</div>

**Getting Started**

To get started with `ft_printf`, follow these steps:

1. Download or clone the repository to your local machine by running the following command:

```shell
git clone https://github.com/SopadeGalinha/42-ft_printf.git
```

The repository contains the source code, along with a Makefile that can be used to compile the program.

2. To build the program, navigate to the repository's root directory and run the following command:

```shell
make
```

This will generate the `ft_libftprintf.a` file, which can be linked to your C project.

**How to use it**

To compile your code, you can use the following command:

```shell
gcc your_main_code.c libftprintf.a && ./a.out
```

Your program will now use the `ft_printf` function to format and print output based on the format specifiers you provide.

Make sure to include the necessary header files in your main code, such as `ft_printf.h`, to access the function prototypes and definitions.
