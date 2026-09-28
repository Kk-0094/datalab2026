/* WARNING: Do not include any other libraries here,
 * otherwise you will get an error while running test.py
 * You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 *
 * Using printf will interfere with our script capturing the execution results.
 * At this point, you can only test correctness with ./btest.
 * After confirming everything is correct in ./btest, remove the printf
 * and run the complete tests with test.py.
 */

 /*
 * bitAnd - x & y using only ~ and |
 * Example: bitAnd(4, 5) = 4
 * Legal ops: ~ |
 * Max ops: 7
 * Difficulty: 1
 */
int bitAnd(int x, int y) {
    int result;
    result=~((~x)|(~y));
    return result;
}
/*
 * bitXor - x ^ y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 7
 *   Difficulty: 1
 */
int bitXor(int x, int y) {
    int result;
    result=(~(~x&~y))&(~(x&y));
    return result;
}

/*
 * samesign - Determines if two integers have the same sign.
 *   0 is not positive, nor negative
 *   Example: samesign(0, 1) = 0, samesign(0, 0) = 1
 *            samesign(-4, -5) = 1, samesign(-4, 5) = 0
 *   Legal ops: >> << ! ^ && if else &
 *   Max ops: 12
 *   Difficulty: 2
 *
 * Parameters:
 *   x - The first integer.
 *   y - The second integer.
 *
 * Returns:
 *   1 if x and y have the same sign , 0 otherwise.
 */
int samesign(int x, int y) {
    if(!x){
        if(!y){
            return 1;
        }else{
            return 0;   
    }
}
    if(!y){
        return 0;
    }
    return   !((x^y)>>31);
}

/*
 * logtwo - Calculate the base-2 logarithm of a positive integer using bit
 *   shifting. (Think about bitCount)
 *   Note: You may assume that v > 0
 *   Example: logtwo(32) = 5
 *   Legal ops: > < >> << |
 *   Max ops: 25
 *   Difficulty: 4
 */
int logtwo(int v) {
    int result=0;

    int b16=v>0xFFFF;
    result=result|(b16<<4);
    v=v>>(b16<<4);

    int b8=v>0xFF;
    result=result|(b8<<3);
    v=v>>(b8<<3);

    int b4=v>0xF;
    result=result|(b4<<2);
    v=v>>(b4<<2);

    int b2=v>0x3;
    result=result|(b2<<1);
    v=v>>(b2<<1);

    int b0=v>0x1;
    result=result|b0;
    v=v>>b0;

    return result;
}

/*
 *  byteSwap - swaps the nth byte and the mth byte
 *    Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *              byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *    Note: You may assume that 0 <= n <= 3, 0 <= m <= 3
 *    Legal ops: ! ~ & ^ | + << >>
 *    Max ops: 17
 *    Difficulty: 2
 */
int byteSwap(int x, int n, int m) {
    int n_shift=n<<3;
    int m_shift=m<<3;
    int n_byte=(x>>n_shift)&0xFF;
    int m_byte=(x>>m_shift)&0xFF;
    x=x&~(0xFF<<n_shift)&~(0xFF<<m_shift);
    x=x|(n_byte<<m_shift)|(m_byte<<n_shift);
    return x;
}

/*
 * reverse - Reverse the bit order of a 32-bit unsigned integer.
 *   Example: reverse(0xFFFF0000) = 0x0000FFFF reverse(0x80000000)=0x1 reverse(0xA0000000)=0x5
 *   Note: You may assume that an unsigned integer is 32 bits long.
 *   Legal ops: << | & - + >> for while ! ~ (You can define unsigned in this function)
 *   Max ops: 30
 *   Difficulty: 3
 */
unsigned reverse(unsigned v) {
    v=((v>>1)&0x55555555)|((v&0x55555555)<<1);

    v=((v>>2)&0x33333333)|((v&0x33333333)<<2);

    v=((v>>4)&0x0F0F0F0F)|((v&0x0F0F0F0F)<<4);

    v=((v>>8)&0x00FF00FF)|((v&0x00FF00FF)<<8);

    v=(v>>16)|(v<<16);

    return v;
}

/*
 * logicalShift - shift x to the right by n, using a logical shift
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Note: You can assume that 0 <= n <= 31
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Difficulty: 3
 */
int logicalShift(int x, int n) {
    int mask=~(((1<<31)>>n)<<1);
    x=(x>>n)&mask;
    return x;
}

/*
 * leftBitCount - returns count of number of consective 1's in left-hand (most) end of word.
 *   Examples: leftBitCount(-1) = 32, leftBitCount(0xFFF0F0F0) = 12,
 *             leftBitCount(0xFE00FF0F) = 7
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 50
 *   Difficulty: 4
 */
int leftBitCount(int x) {
    int count=0;
    int check;

    check=!((x>>16)+1);
    count=count+(check<<4);
    x=x<<(check<<4);

    check=!((x>>24)+1);
    count=count+(check<<3);
    x=x<<(check<<3);

    check=!((x>>28)+1);
    count=count+(check<<2);
    x=x<<(check<<2);

    check=!((x>>30)+1);
    count=count+(check<<1);
    x=x<<(check<<1);

    check=!((x>>31)+1);
    count=count+(check);
    x=x<<(check);

    count=count+((x>>31)&1);

    return count;


}

/*
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but it is to be interpreted as
 *   the bit-level representation of a single-precision floating point values.
 *   Legal ops: if else while for & | ~ + - >> << < > ! ==
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned float_i2f(int x) {
    if (x == 0) return 0;

    unsigned sign = x & 0x80000000;
    unsigned u = x;
    if (sign) u = ~u + 1;

    int e = 31;
    int t = u;
    while (t > 0) {
        t = t << 1;
        e = e - 1;
    }

    unsigned exp = e + 127;
    unsigned mantissa;

    if (e < 24) {
        mantissa = (u << (23 - e)) & 0x7FFFFF;
    } else {
        int shift = e - 23;
        mantissa = (u >> shift) & 0x7FFFFF;
        unsigned rest = u & ((1 << shift) - 1);
        unsigned half = 1 << (shift - 1);

        if (rest > half) {
            mantissa = mantissa + 1;
        } else if (rest == half) {
            if (mantissa & 1) mantissa = mantissa + 1;
        }

        if (mantissa == 0x800000) {
            mantissa = 0;
            exp = exp + 1;
        }
    }

    return sign | (exp << 23) | mantissa;
}
/*
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: & >> << | if > < >= <= ! ~ else + ==
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned floatScale2(unsigned uf) {
        unsigned sign=uf&0x80000000;
        unsigned exp=(uf>>23)&0xFF;
        unsigned frac=uf&0x7FFFFF;

        if(exp==0xFF) return uf;
        

        if(exp==0)
        {
            if(frac==0) return uf;
            frac<<=1;
            if(frac&0x800000)
            {
                exp=1;
                frac&=0x7FFFFF;
            }
        }else{
            exp++;
            if(exp==0xFF)
            {
                frac=0;
            }
        }
        return sign|(exp<<23)|frac;
}

/*
 * float64_f2i - Convert a 64-bit IEEE 754 floating-point number to a 32-bit signed integer.
 *   The conversion rounds towards zero.
 *   Note: Assumes IEEE 754 representation and standard two's complement integer format.
 *   Parameters:
 *     uf1 - The lower 32 bits of the 64-bit floating-point number.
 *     uf2 - The higher 32 bits of the 64-bit floating-point number.
 *   Returns:
 *     The converted integer value, or 0x80000000 on overflow, or 0 on underflow.
 *   Legal ops: >> << | & ~ ! + - > < >= <= if else
 *   Max ops: 60
 *   Difficulty: 3
 */
int float64_f2i(unsigned uf1, unsigned uf2) {
    unsigned sign = uf2 >> 31;
    unsigned e = (uf2 >> 20) & 0x7FF;

    if (e >= 0x7FF) return 0x80000000;
    if (e < 1023) return 0;

    int E = e - 1023;
    if (E >= 31) return 0x80000000;

    unsigned h = uf2 & 0xFFFFF;
    unsigned value;

    if (E <= 20) {
        value = (1 << E) | (h >> (20 - E));
    } else {
        value = (1 << E) | (h << (E - 20)) | (uf1 >> (52 - E));
    }

    if (sign) {
        if (value >= 0x80000000) return 0x80000000;
        int result = value;
        return -result;
    } else {
        if (value > 0x7FFFFFFF) return 0x80000000;
        int result = value;
        return result;
    }
}

/*
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 *
 *   Legal ops: < > <= >= << >> + - & | ~ ! if else &&
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned floatPower2(int x) {

    if(x>=128)
    {
        return 0x7F800000;
    }

    if(x>=-126)
    {
        unsigned exp=x+127;
        return exp<<23;
    }

    if(x>=-149)
    {
        unsigned frac=1<<(x+149);
       return frac;
    }

    return 0;


}
