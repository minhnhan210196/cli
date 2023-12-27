/*
 * main.c
 *
 *  Created on: Sep 20, 2023
 *      Author: MinhNhan
 */


#include "shell.h"
#include "stdio.h"
#include "stdint.h"
#include "string.h"

char buff[1024];

int console_putc(char c) {
  return putchar(c);
}

int console_puts(char* s){
	return printf(s);
}
char* console_get_line(void){
	return gets(buff);
}

char console_getc(void) {
	return getchar();
}

int main(int argc, char **argv) {
	sShellImpl shell_impl = { .send_char = console_putc, };
	shell_boot(&shell_impl);
	while (1) {
		char *str = console_get_line();
		shell_receive_line(str);
	}
}
