ENTRY(_start);

OUTPUT_FORMAT("elf64-x86-64", "elf64-x86-64",
	      "elf64-x86-64")
OUTPUT_ARCH(i386:x86-64)
ENTRY(_start)
SEARCH_DIR("=/usr/x86_64-linux-gnu/lib64"); 
SEARCH_DIR("=/usr/local/lib/x86_64-linux-gnu"); 
SEARCH_DIR("=/usr/local/lib64"); 
SEARCH_DIR("=/lib/x86_64-linux-gnu"); 
SEARCH_DIR("=/lib64"); 
SEARCH_DIR("=/usr/lib/x86_64-linux-gnu"); 
SEARCH_DIR("=/usr/lib64"); 
SEARCH_DIR("=/usr/x86_64-linux-gnu/lib"); 
SEARCH_DIR("=/usr/local/lib"); 
SEARCH_DIR("=/lib"); SEARCH_DIR("=/usr/lib");

SECTIONS {
    . = 0x08048000;

    .text ALIGN (0x1000) : {
        *(.text .stub .text.* .gnu.linkonce.t.*)
    }

    .data ALIGN (0x1000) : {
        *(.data .data.* .gnu.linkonce.d.*)
    }

    .bss ALIGN (0x1000) : {
        *(.bss .bss.*)
    }

    .part4_thE_World ALIGN (0x1000) : {
        *(.part4_thE_World)
    }

    .debug_info ALIGN(0x4) : { *(.debug_info) }
    .debug_abbrev ALIGN(0x4) : { *(.debug_abbrev) }
    .debug_line ALIGN(0x4) : { *(.debug_line) }
    .debug_str ALIGN(0x1) : { *(.debug_str) }
}
