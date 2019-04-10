
int bSearch(int *v, int size, int num)
{
    int first = 0, 
        last = size,
        //set to false at beggining. We can't assure the element is in the array.  
        found = 0,
        midPoint;

    while(first <= last && !found)
    {
        midPoint = (first + last) / 2;

        if(v[midPoint] == num)
            found = 1;
        else
            if(num < v[midPoint])
                last = --midPoint;
            else
                first = ++midPoint;
    }

    return found;
}