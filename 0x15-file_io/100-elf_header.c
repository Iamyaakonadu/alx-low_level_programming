#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

/**
*check_elf - it checks if a file is an ELF file
*@e_ident: pointer to an array containing the ELF magic numbers
*/
void check_elf(unsigned char *e_ident)
{
	int  hint;

	for (hint = 0; hint < 4; hint++)
	{
		if (e_ident[hint] != 127 &&
				e_ident[hint] != 'E' &&
				e_ident[hint] != 'L' &&
				e_ident[hint] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}
/**
*print_magic - it prints magic numbers of an ELF header
*@e_ident: pointer to an array containing the ELF magic numbers
*
*Description: magic num. are separated by spaces
*/
void print_magic(unsigned char *e_ident)
{
	int hint;

	printf("Magic");

	for (hint = 0; hint < EI_NIDENT; hint++)
	{
		printf("%02x", e_ident[hint]);

		if (hint == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}
/**
*print_class - it prints the class of an ELF header
*@e_ident: pointer to an array of ELF class
*/
void print_class(unsigned char *e_ident)
{
	printf("Class:");

	switch (e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF#@\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x.\n", e_ident[EI_CLASS]);
	}
}
/**
*print_data - it prints the data of ELF header
*@e_ident: pointerto an array of ELF class
*/
void print_data(unsigned char *e_ident)
{
	printf("Data:");

	switch (e_ident[EI_DATA])
	{
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}
/**
*print_version - it prints version of an ELFheader
*@e_ident: pointer to an array of ELF version
*/
void print_version(unsigned char *e_ident)
{
	printf("Version: %d", e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
		case EV_CURRENT:
			printf("(current)\n");
			break;
		default:
			printf("\n");
			break;
	}
}
/**
*print_osabi - it prints OS/ABI of an ELF header
*@e_ident: pointer to an array of ELF version
*/
void print_osabi(unsigned char *e_ident)
{
	printf("OS/ABI:");

	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - system V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - freeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_ARM:
			printf("Arm\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("standalone app\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_OSABI]);
			;
	}
}
/**
*print_abi - it prints ABI version of an ELF header
*@e_ident: pointer to an arry of ELF ABI version
*/
void print_abi(unsigned char *e_ident)
{
	printf("ABI version:%d\n", e_ident[EI_ABIVERSION]);
}
/**
*print_type - it prints the type of an ELF header
*@e_type: ELF type
*@e_ident: pointer to an array of ELF class
*/
void print_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("Type:");

	switch (e_type)
	{
		case ET_NONE:
			printf("NONE (None)\n");
			break;
		case ET_REL:
			printf("REL (Relocation file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("Dyn (shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (core file)\n");
			break;
		default:
			printf("<unknown: %x>\n", e_type);
			;
	}
}
/**
*print_entry - it prints entry point of an ELF header
*@e_entry: address of the ELF entry point
*@e_ident: pointer to an array of ELF class
*/
void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("Entry point address: ");

	if (e_ident[EI_DATA == ELFDATA2MSB])
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) | ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}
/**
*close_elf - it closes an ELF file
*@elf: the file descriptor
*
*Description: if the file cannot be closed, exit code 98
*/
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", elf);
		exit(98);
	}
}
/**
*main - it displays the info inside the ELF header at the start of an ELF file
*@argc: no. arguments supplied to the program
*@argv: array of pointers to the arguments
*
*Return: 0 (success)
*
*Description: if file is not an ELF or the function fails, exit code 98.
*/
int main(int __attribute__((__unused__))argc, char *argv[])
{
	Elf64_Ehdr *header;
	int a, b;

	a = open(argv[1], O_RDONLY);
	if (a == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(a);
		dprintf(STDERR_FILENO, "Error: can't read file %s\n", argv[1]);
		exit(98);
	}
	b = read(a, header, sizeof(Elf64_Ehdr));
	if (b == -1)
	{
		free(header);
		close_elf(a);
		dprintf(STDERR_FILENO, "Error: '%s': No such file\n", argv[1]);
		exit(98);
	}

	check_elf(header->e_ident);
	printf("ELF Header:\n");
	print_magic(header->e_ident);
	print_class(header->e_ident);
	print_data(header->e_ident);
	print_version(header->e_ident);
	print_osabi(header->e_ident);
	print_abi(header->e_ident);
	print_type(header->e_type, header->e_ident);
	print_entry(header->e_entry, header->e_ident);

	free(header);
	close_elf(a);
	return (0);
}
