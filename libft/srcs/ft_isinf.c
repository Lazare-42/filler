int ft_isinf(double x)
{
    union { unsigned long u; double f; } ieee754;
    ieee754.f = x;
    return (( (unsigned)(ieee754.u >> 32) & 0x7fffffff ) == 0x7ff00000 &&
           ( (unsigned)ieee754.u == 0 ));
}
