int Solution::repeatedNumber(const vector<int> &A) {
    int c1 = 0, c2 = 0;
    int a, b, n = A.size();
    for(int i: A)
    {
        if(i != b && (c1 == 0 || i == a) )
        {
            c1++;
            a = i;
        }
        else if(i != a && (c2 == 0 || i == b) )
        {
            c2++;
            b = i;
        }
        else
        {
            c1--;
            c2--;
        }
    }
    c1 = 0, c2 = 0;
    for(int i: A)
    {
        if(i == a)
            c1++;
        else if(i == b)
            c2++;
    }
    if(c1 > n/3)
        return a;
    else if(c2 > n/3)
        return b;
    else
        return -1;
}

