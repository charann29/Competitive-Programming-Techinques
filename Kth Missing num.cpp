#include <bits/stdc++.h>
using namespace std;

// -------------IF SORTED I can use binary search with the complexity of O(N)-----------

int findKthMissing(int[] arr, int k)
{
    if (arr[0] > k)
    {
        int lo = 0;
        int hi = arr.length() - 1;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if (arr[mid] - (mid + 1) < k)
            {
                closestMid = mid + 1;
                lo = mid + 1;
            }
            else
                hi = mid - 1;
        }
        return k + closestMid;
    }
}

// -------------------------------------------A basic Approch !!--------------------

int num = k;
for (int a : arr)
{ /*This is a foreach loop in cpp*/

    if (a <= num)
        num++;
    else
        break;
}
return num;

/* How is it working?? = let's take 0 3 5 7 as input k= 5 (required missing num) then I'll assign num =5;
and later on if the element in the array greater I'll break the loop else i'll increment the num value this will end up at the required missing number in O(n) complexity!*/

// -----------------------------------------Extended Approach using while and condition prefined-----------

int idx = 0;
int i = 0;
while (i < arr.length() && (arr[idx] - arr[idx + 1]) < k)
{
    idx = i + 1;
    i++;
    /* As it is a zero based indexing I'll add one repetedly till k (the difference between two adjacent elements become zero) and then I'll go dor the next element*/
}

return (k + idx);