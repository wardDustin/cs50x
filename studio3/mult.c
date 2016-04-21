int mult (int a, int b)
{
    if (b==1)
        return a;
    else if (b>=0)
        return a + mult (a, b-1);
    else
    {
        a += mult (a, 0-b-1);
        return 0 - a;
    }
}