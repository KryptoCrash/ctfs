/* r2dec pseudo code output */
/* /home/whimpers/ctf_challenges/2019/redpwnctf/pwn/penpal_world/penpal_world */
#include <stdint.h>
 

/* name: entry0 @ 0x7f0 */
void entry0 (int64_t arg3) {
    rdx = arg3;
    /* [14] -r-x section size 1362 named .text */
    ebp = 0;
    uint64_t (*reloc.__libc_start_main)(uint64_t*, uint64_t, void, uint64_t*, uint64_t*, void) (*(main), rsi, rsp, *(sym.__libc_csu_init), *(sym.__libc_csu_fini), rdx);
}

/* name: sym.deregister_tm_clones @ 0x820 */
uint64_t deregister_tm_clones (void) {
    rdi = loc__edata;
    rax = loc__edata;
    if (rax != rdi) {
        rax = *(reloc._ITM_deregisterTMCloneTable);
        if (rax == 0) {
            goto label_0;
        }
        void (*rax)() ();
    }
label_0:
    return rax;
}

/* name: sym.register_tm_clones @ 0x860 */
int64_t register_tm_clones (void) {
    rdi = loc__edata;
    rsi = loc__edata;
    rsi -= rdi;
    rsi >>= 3;
    rax = rsi;
    rax >>= 0x3f;
    rsi += rax;
    rsi >>= 1;
    if (rsi != 0) {
        rax = *(reloc._ITM_registerTMCloneTable);
        if (rax == 0) {
            goto label_1;
        }
        void (*rax)() ();
    }
label_1:
    return rax;
}

/* name: entry.fini0 @ 0x8b0 */
void entry_fini0 (void) {
    if (*(obj.completed.7697) == 0) {
        if (*(reloc.__cxa_finalize) != 0) {
            rdi = *(obj.__dso_handle);
            _plt_got ();
        }
        deregister_tm_clones ();
        *(obj.completed.7697) = 1;
        return;
    }
}

/* name: entry.init0 @ 0x8f0 */
void entry_init0 (void) {
    return register_tm_clones ();
}

/* name: sym.__libc_csu_fini @ 0xd40 */
void libc_csu_fini (void) {
}

/* name: sym.display @ 0xb2c */
int64_t display (void) {
    int64_t var_ch;
    int64_t canary;
    rax = *(fs:0x28);
    canary = *(fs:0x28);
    eax = 0;
    var_ch = 0;
    puts ("Which envelope #?");
    rax = &var_ch;
    rsi = rax;
    rdi = 0x00000dc3;
    eax = 0;
    isoc99_scanf ();
    eax = var_ch;
    if (eax >= 0) {
        eax = var_ch;
        if (eax <= 1) {
            goto label_2;
        }
    }
    puts ("swiper no swipey !");
    goto label_3;
label_2:
    eax = var_ch;
    rax = (int64_t) eax;
    rdx = rax*8;
    rax = obj_letters;
    rax = *((rdx + rax));
    puts (*((rdx + rax)));
label_3:
    rax = canary;
    rax ^= *(fs:0x28);
    if (eax != 1) {
        stack_chk_fail ();
    }
    return rax;
}

/* name: sym._fini @ 0xd44 */
void fini (void) {
    /* [15] -r-x section size 9 named .fini */
}

/* name: sym.create_card @ 0x93d */
int64_t create_card (void) {
    int64_t var_1ch;
    int64_t canary;
    rax = *(fs:0x28);
    canary = *(fs:0x28);
    eax = 0;
    var_1ch = 0;
    puts ("Which envelope #?");
    rax = &var_1ch;
    rsi = rax;
    rdi = 0x00000dc3;
    eax = 0;
    isoc99_scanf ();
    eax = var_1ch;
    if (eax < 0) {
        puts ("swiper no swipey !");
    } else {
        eax = var_1ch;
        if (eax > 1) {
            puts ("u so greedy dat when u step on da scale, u see ur credit card number >:O");
        } else {
            ebx = var_1ch;
            rax = malloc (0x48);
            rcx = rax;
            rax = (int64_t) ebx;
            rdx = rax*8;
            rax = obj_letters;
            *((rdx + rax)) = rcx;
        }
    }
    rax = canary;
    rax ^= *(fs:0x28);
    if (eax != 1) {
        stack_chk_fail ();
    }
    return rax;
}

/* name: sym.__libc_csu_init @ 0xcd0 */
void libc_csu_init (int64_t arg1, int64_t arg2, int64_t arg3) {
    rdi = arg1;
    rsi = arg2;
    rdx = arg3;
    r15 = rdx;
    r12 = obj___frame_dummy_init_array_entry;
    rbp = obj___do_global_dtors_aux_fini_array_entry;
    r13d = edi;
    r14 = rsi;
    rbp -= r12;
    rbp >>= 3;
    _init ();
    if (rbp == 0) {
        goto label_4;
    }
    ebx = 0;
    do {
        rdx = r15;
        rsi = r14;
        edi = r13d;
        uint64_t (*r12 + rbx*8)() ();
        rbx++;
    } while (rbp != rbx);
label_4:
}

/* name: sym.discard @ 0xa97 */
int64_t discard (void) {
    int64_t var_ch;
    int64_t canary;
    rax = *(fs:0x28);
    canary = *(fs:0x28);
    eax = 0;
    var_ch = 0;
    puts ("Which envelope #?");
    rax = &var_ch;
    rsi = rax;
    rdi = 0x00000dc3;
    eax = 0;
    isoc99_scanf ();
    eax = var_ch;
    if (eax >= 0) {
        eax = var_ch;
        if (eax <= 1) {
            goto label_5;
        }
    }
    puts ("swiper no swipey !");
    goto label_6;
label_5:
    eax = var_ch;
    rax = (int64_t) eax;
    rdx = rax*8;
    rax = obj_letters;
    rax = *((rdx + rax));
    free (*((rdx + rax)));
label_6:
    rax = canary;
    rax ^= *(fs:0x28);
    if (eax != 1) {
        stack_chk_fail ();
    }
    return rax;
}

/* name: main @ 0xbc1 */
int32_t main (void) {
    int64_t var_10h;
    signed int64_t var_ch;
    int64_t canary;
    rax = *(fs:0x28);
    canary = *(fs:0x28);
    eax = 0;
    var_10h = 0xffffffff;
    rax = stdout;
    setbuf (rax, 0);
    rax = stdin;
    setbuf (rax, 0);
    rax = stderr;
    setbuf (rax, 0);
    var_ch = 0;
    while (var_ch <= 0x21) {
        eax = 0;
        show_menu ();
        rax = &var_10h;
        rsi = rax;
        rdi = 0x00000dc3;
        eax = 0;
        isoc99_scanf ();
        eax = var_10h;
        if (eax != 2) {
            if (eax <= 2) {
                if (eax != 1) {
                } else {
                    if (eax != 3) {
                        if (eax == 4) {
                            goto label_7;
                        }
                        eax = 0;
                        create_card ();
                    } else {
                    } else {
                        eax = 0;
                        edit_card ();
                        goto label_8;
                    }
                }
                eax = 0;
                discard ();
                goto label_8;
label_7:
                eax = 0;
                display ();
                goto label_8;
            }
            puts ("omggg hacker");
        }
label_8:
        var_ch++;
    }
    eax = 0;
    rdx = canary;
    rdx ^= *(fs:0x28);
    if (var_ch != 0x21) {
        stack_chk_fail ();
    }
    return rax;
}

/* name: sym.show_menu @ 0x8fa */
void show_menu (void) {
    puts ("OPTIONS");
    puts ("1) Create a postcard");
    puts ("2) Edit a postcard");
    puts ("3) Discard a postcard");
    puts ("4) Read a postcard");
}

/* name: sym.edit_card @ 0x9ec */
int64_t edit_card (void) {
    size_t * nbyte;
    int64_t canary;
    rax = *(fs:0x28);
    canary = *(fs:0x28);
    eax = 0;
    nbyte = 0;
    puts ("Which envelope #?");
    rax = &nbyte;
    rsi = rax;
    rdi = 0x00000dc3;
    eax = 0;
    isoc99_scanf ();
    eax = nbyte;
    if (eax >= 0) {
        eax = nbyte;
        if (eax <= 1) {
            goto label_9;
        }
    }
    puts ("swiper no swipey !");
    goto label_10;
label_9:
    puts ("Write.");
    eax = nbyte;
    rax = (int64_t) eax;
    rdx = rax*8;
    rax = obj_letters;
    rax = *((rdx + rax));
    read (0, rax, 0x48);
label_10:
    rax = canary;
    rax ^= *(fs:0x28);
    if (eax != 1) {
        stack_chk_fail ();
    }
    return rax;
}

/* name: sym._init @ 0x740 */
int64_t init (void) {
    /* [11] -r-x section size 23 named .init */
    rax = *(reloc.__gmon_start);
    if (rax != 0) {
        void (*rax)() ();
    }
    return rax;
}
