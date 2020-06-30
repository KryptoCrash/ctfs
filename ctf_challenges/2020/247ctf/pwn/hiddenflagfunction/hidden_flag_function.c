/* r2dec pseudo code output */
/* /home/whimpers/ctf_challenges/2020/247ctf/pwn/hiddenflagfunction/hidden_flag_function */

/* name: sym.chall @ 0x80485d4 */
uint32_t chall (void) {
    int32_t var_48h;
    int32_t var_4h;
    eax = _x86_get_pc_thunk_ax (ebx);
    eax += 0x1a20;
    ebx = eax;
    isoc99_scanf (*((eax - 0x18ed)), var_48h);
    ebx = var_4h;
    return eax;
}

/* name: main @ 0x8048603 */
int32_t main (int32_t arg_4h) {
    int32_t var_8h;
    ecx = &arg_4h;
    _x86_get_pc_thunk_bx (ecx, ebx, ebp);
    ebx += 0x19e9;
    eax = *((ebx - 4));
    eax = *(eax);
    setbuf (eax, 0);
    puts (*((ebx - 0x18ea)));
    chall ();
    eax = 0;
    esp = &var_8h;
    esp = ecx - 4;
    return eax;
}

/* name: sym.flag @ 0x8048576 */
uint32_t flag (void) {
    char * s;
    file* stream;
    int32_t var_4h;
    _x86_get_pc_thunk_bx (ebx);
    ebx += 0x1a7e;
    eax = fopen (*((ebx - 0x191e)), *((ebx - 0x1920)));
    stream = eax;
    fgets (s, 0x40, stream);
    eax = &s;
    printf (*((ebx - 0x1914)));
    ebx = var_4h;
    return eax;
}