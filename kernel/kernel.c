/*
 * kernel.c
 * Copyright 2017, Ketan Gupta <ketan19972010@gmail.com>
 *
 * This file is a part of Exylus.
 */

#include "idt.h"
#include "irq.h"
#include "gdt.h"
#include "tty.h"

void kernel_main()
{
	init_gdt();
	init_idt();
	init_irq();

	terminal_initialize();
	terminal_writestring("  ______            _           \n");
	terminal_writestring(" |  ____|          | |          \n");
	terminal_writestring(" | |__  __  ___   _| |_   _ ___ \n");
	terminal_writestring(" |  __| \\ \\/ / | | | | | | / __|\n");
	terminal_writestring(" | |____ >  <| |_| | | |_| \\__ \\\n");
	terminal_writestring(" |______/_/\\_\\\\__, |_|\\__,_|___/\n");
	terminal_writestring("               __/ |            \n");
	terminal_writestring("              |___/             \n");

	terminal_writestring("\n");
	terminal_writestring("Firing an exception!\n");
	asm volatile ("int $0x0");

	terminal_writestring("Firing an IRQ!\n");
	asm volatile ("int $0x21");
}
