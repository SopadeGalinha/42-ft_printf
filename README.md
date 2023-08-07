<h1 align=center>
	<b>ft_printf</b>
<h2 align=center>
	 <i>42cursus' project #3</i>
</h2>

<p align=center>
  The 'ft_printf' project presents an elevated iteration of the conventional "printf" function in the C programming language. This advanced version empowers developers to meticulously format and seamlessly print content to the standard output, all while leveraging a comprehensive range of meticulously defined format specifiers.

This code handles the following flags: `c`, `s`, `p`, `d`, `i`, `u`, `x`, `X`, `o`, `b`, and `%`.

- `o`: octal
- `b`: binary
- `p`: pointer
- `d`: decimal
- `i`: integer
- `u`: unsigned integer
- `x`: lowercase hexadecimal
- `X`: uppercase hexadecimal
- `c`: character
- `s`: string
- `%`: percent

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
