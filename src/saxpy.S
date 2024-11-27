.intel_syntax noprefix

// void saxpy(size_t n, float alpha, const float x[n], float y[restrict n]);
.global saxpy

/*
    n -> rdi
    alpha -> xmm0 & xmm1
    x[n] -> rsi & xmm2
    y[n] -> rdx & xmm3
*/
saxpy:
    movaps xmm1, xmm0
    shufps xmm1, xmm1, 0x00

    mov rax, rdi
    shr rax, 2          // n / 4
    jz handle_remainder // n < 4 -> handle remainders

simd_loop:
    movups xmm2, [rsi]  // xmm2 stores x[]
    movups xmm3, [rdx]  // xmm3 stores y[]
    mulps xmm2, xmm1    // xmm2 = alpha * x
    addps xmm3, xmm2    // xmm3 = alpha * x + y
    movups [rdx], xmm3  // y = alpha * x + y

    add rsi, 16         // go to next 4 floats
    add rdx, 16
    dec rax
    jnz simd_loop
handle_remainder:
    mov rax, rdi
    and rax, 3          // n % 4    
    jz done

remainder_loop:
    movss xmm2, [rsi]   // xmm2 stores x
    movss xmm3, [rdx]   // xmm3 stores y
    mulss xmm2, xmm1    // xmm2 = x * alpha
    addss xmm3, xmm2    // xmm3 = alpha * x + y
    movss [rdx], xmm3   // y = alpha * x + y
    
    add rsi, 4
    add rdx, 4
    dec rax
    jnz remainder_loop

done:
    ret
