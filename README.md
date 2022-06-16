# Monty Scripting Language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

## Technologies
* Scripts written in Bash 4.3.11(1)
* C files are compiled using `gcc 4.8.4`
* C files are written according to the C90 standard
* Tested on Ubuntu 20.04 LTS
* Monty byte codes havt the `.m` extension

## Compliation and output
The code will be complied this way
`gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty`
The code would be run the way
`./monty <filename>`
The file name should have the extension `.m`

## Resources
- []() - This helped me get the basic understanding of the an interpreter before undergoing the project
- []() - This helped me proceed with the creation of an interperter

## New Knowledge
- Using the new defined structure in a header file, It can be accessed anywhere in a using the `extern` specifier
	typedef struct new_struct
	{
		int n;
		unsigned int n;
	} global;

	extern global global_struct;
