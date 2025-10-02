int is_duplicate(char **argv, int argc)
{
    int i;
    int j;

    i = 1;
    while (i < argc)
    {
        j = i + 1;
        while (j < argc)
        {
            if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int is_number(char **argv, int argc)
{
    int i;
    int j;

    i = 1;
    while (i < argc)
    {
        j = 0;
        if (argv[i][j] == '-' || argv[i][j] == '+')
            j++;
        if (!argv[i][j])
            return (0);
        while (argv[i][j])
        {
            if (!ft_isdigit(argv[i][j]))
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int is_int_range(char **argv, int argc)
{
    int i;
    long num;

    i = 1;
    while (i < argc)
    {
        num = ft_atol(argv[i]);
        if (num < -2147483648 || num > 2147483647)
            return 0;
        i++;
    }
    return 1;
}

int error_check(char **argv, int argc)
{
    if (argc < 2 || !is_number(argv, argc) || !is_int_range(argv,argc) || is_duplicate(argv, argc))
    {
        write(2, "Error\n", 6);
        return (1);
    }
    return (0);
}
