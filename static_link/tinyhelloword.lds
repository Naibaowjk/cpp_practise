ENTRY(nomain)

SECTIONS
{
    . = 0x084800 + SIZEOF_HEADERS;

    tinytext : { *(.text) *(.data) *(.rodata)}
    /DISCARD/ : { *(.comment)}
}