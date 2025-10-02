long ft_atol(const char *str)
{
    long result = 0;
    int sign = 1;

    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }

    while (*str)
    {
        if (*str < '0' || *str > '9') // rakam değilse dur
            break;
        result = result * 10 + (*str - '0');
        str++;
    }

    return sign * result;
}
