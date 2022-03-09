#include "thpe2.h"

double  mySqrt( double &stNum)
{
    int i = 0;
    double check;
    double low = 0;
    double mid;
    double max = stNum;
    if( max <= 0 )
    {
        return 0;
    }
    while( i <= 5000)
    {
        mid = (max + low) / 2;
        check = pow( mid, 2);
        if( (fabs(check - stNum)) < ERRORVALUE)
            {
                return mid;
            }
            if( (fabs(check - stNum)) > ERRORVALUE)
            {
                if( check > stNum)
                {
                    max = mid;
                    i++;
                }
                if( check < stNum)
                {
                    low = mid;
                    i++;
                }
            }
    }
    return 0;
}
