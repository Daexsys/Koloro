
/**
    Send a byte to the specified I/O port
*/
void outb(short port, char data) {
    asm("mov dx, [bp + 4]\n"
        "mov ax, [bp + 6]\n"
        "out dx, al");
}

/**
    Send a 16-bit word to the specified I/O port
*/
void outw(short port, short data) {
    asm("mov dx, [bp + 4]\n"
        "mov ax, [bp + 6]\n"
        "out dx, ax");
}

/**
    Read a byte from the specified I/O port
*/
char inb(short port) {
    asm("mov dx, [bp + 4]\n"
        "in al, dx");
}

/**
    Read a 16-bit word from the specified I/O port
*/
short inw(short port) {
    asm("mov dx, [bp + 4]\n"
        "in ax, dx");
}

/**
    Write a byte to the specified memory location
    
    @param
        segment - destination memory segment
        offset - destination memory offset
        data - byte to write
*/
void mempokeb(short segment, short offset, char data) {
    asm("push es\n"
        "mov ax, [bp + 4]\n"
        "mov es, ax\n"
        "mov di, [bp + 6]\n"
        "mov ax, [bp + 8]\n"
        "stosb\n"
        "pop es");
}

/**
    Write a word to the specified memory location
    
    @param
        segment - destination memory segment
        offset - destination memory offset
        data - word to write
*/
void mempokew(short segment, short offset, short data) {
    asm("push es\n"
        "mov ax, [bp + 4]\n"
        "mov es, ax\n"
        "mov di, [bp + 6]\n"
        "mov ax, [bp + 8]\n"
        "stosw\n"
        "pop es");
}

/**
    Read a byte from the specified memory location
    
    @param
        segment - source memory segment
        offset - source memory offset
    
    @return
        byte at that address
*/
char mempeekb(short segment, short offset) {
    asm("push ds\n"
        "mov ax, [bp + 4]\n"
        "mov ds, ax\n"
        "mov si, [bp + 6]\n"
        "lodsb\n"
        "pop ds");
}

/**
    Read a word from the specified memory location
    
    @param
        segment - source memory segment
        offset - source memory offset
    
    @return
        word at that address
*/
short mempeekw(short segment, short offset) {
    asm("push ds\n"
        "mov ax, [bp + 4]\n"
        "mov ds, ax\n"
        "mov si, [bp + 6]\n"
        "lodsw\n"
        "pop ds");
}

/**
    Copy a block of memory to another memory location
    
    @param
        srcSeg - source memory segment
        srcOfs - source memory offset
        destSeg - destination memory segment
        destOfs - destination memory offset
        size - number of bytes to be copied
*/
void memcopy(short srcSeg, short srcOfs, short destSeg, short destOfs, short size) {
    for (; size > 0; size--) {
        mempokeb(destSeg, destOfs, mempeekb(srcSeg, srcOfs));
        srcOfs++;
        destOfs++;
    }
}