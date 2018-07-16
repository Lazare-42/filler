int ft_isnan(double x)
{
    union { unsigned long u; double f; } ieee754;
    ieee754.f = x;
    return ( (unsigned)(ieee754.u >> 32) & 0x7fffffff ) +
           ( (unsigned)ieee754.u != 0 ) > 0x7ff00000;
}
