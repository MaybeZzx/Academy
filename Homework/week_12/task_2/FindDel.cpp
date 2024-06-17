unsigned int FindDel(unsigned int a, unsigned int b)
{
    if (a == 0)
        return b;
    else if (b == 0)
        return a;
    else if (a > b)
        return FindDel(b, a % b);
    else
        return FindDel(a, b % a);
}