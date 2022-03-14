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


double  myCbrt( double &stNum)
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
        check = pow( mid, 3);
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



double myLog( int base, double arg)
{
    double high = 1;
    double low = 0;
    double mid;
    double check;
    double exp;
    int i = 0;
    int j = 0;
    if( arg <= 0)
    {
        return 0;
    }
    while( i != 1)
    {
        exp = pow( base, high);
        if( exp > arg)
        {
           low = high -1;
           i++;
        }
        else
        {
            high = high + 1;
        }
    }
    while( j <= 5000)
    {
        mid = (high + low) / 2;
        check = pow( base, mid);
        if(( fabs(check - arg)) < ERRORVALUE)
            {
                return mid;
            }
            if(( fabs(check - arg)) > ERRORVALUE)
            {
                if( check > arg)
                {
                    high = mid;
                    j++;
                }
                if( check < arg )
                {
                    low = mid;
                    j++;
                }
            }
    }
    return 0;
}


void copyArray( double copy[], double start[], int size)
{
    int i = 0;
    for( i = 0; i <= size - 1; i++)
    {
        copy[i] = start[i];
    }
}

