OUTPUT_ARCH(mips)
ENTRY(_start)

SECTIONS
{
    . = 0x00100000;
    .text : ALIGN(16)
    {
        build/relink/main.raw.o(.text)
    }

    . = 0x004c2580;
    .bss (NOLOAD) : ALIGN(16)
    {
        build/relink/main_bss.o(.bss)
    }

    _gp = 0x004c7270;

    /DISCARD/ :
    {
        *(.data)
        *(.reginfo)
        *(.MIPS.abiflags)
        *(.pdr)
        *(.gnu.attributes)
        *(.comment)
        *(.note*)
    }
}
