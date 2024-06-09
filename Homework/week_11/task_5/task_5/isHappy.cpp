int isHappy(unsigned int num)
{
    if (num < 100000 || num > 999999)
        return -1;
    return ((num / 100000) + ((num / 10000) % 10) + ((num / 1000) % 10)) == (((num / 100) % 10) + ((num / 10) % 10) + (num % 10));
}