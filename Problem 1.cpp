/*
The below algorithm is a modification of [Boyer–Moore majority vote algorithm]{https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm}
Start with two empty candidate slots and two counters set to 0.
for each item:
    if it is equal to either candidate, increment the corresponding count
    else if there is an empty slot (i.e. a slot with count 0), put it in that slot and set the count to 1
    else reduce both counters by 1
At the end, make a second pass over the array to check whether the candidates really do have the required count.
*/


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

