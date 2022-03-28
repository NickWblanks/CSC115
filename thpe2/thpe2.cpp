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

void initialArray( double array[], int size, double value)
{
    int i = 0;
    for( i = 0; i <= size -1; i++)
    {
        array[i] = value;
    }
}


double sumArray( double array[], int size)
{
    int i;
    double sum = 0;
    for( i = 0; i <= size -1; i++)
    {
        sum = (array[i]) + sum;
    }
    return sum;
}



double averageArray( double array[], int size)
{
    int i;
    double sum = 0;
    double avg = 0;
    for( i = 0; i <= size -1; i++)
    {
        sum = (array[i]) + sum;
    }
    avg = sum / size;
    return avg;
}


int minLocation( double array[], int size) //finds the index with the lowest value and returns the index
{ 
    int i = 0;
    int min = 0;
    for( i = 0; i < size - 1; i++)
    {
        if( array[min] > array[ i + 1])
        {
            min = i + 1;
        }
    }
    return min;
}



double minValue( double array[], int size) //finds the index with the lowest value and returns that value
{
    int i = 0;
    int min = 0;
    for( i = 0; i < size - 1; i++)
    {
        if( array[min] > array[ i + 1])
        {
            min = i + 1;
        }
    }
    return array[min];
}


int maxLocation( double array[], int size) //finds the index with the highest value and returns that index
{
    int i = 0;
    int max = 0;
    for( i = 0; i < size - 1; i++)
    {
        if( array[max] < array[i + 1])
        {
            max = i + 1;
        }
    }
    return max;
}


double maxValue( double array[], int size)  //finds the index with the highest value and returns that value
{
    int i = 0;
    int max = 0;
    for( i = 0; i < size - 1; i++)
    {
        if( array[max] < array[ i + 1])
        {
            max = i + 1;
        }
    }
    return array[max];
}



int countIf( double array[], int size, double findVal)
{
    int i = 0;
    int count = 0;
    for( i = 0; i <= size - 1; i++)
    {
        if( array[i] == findVal)
        {
            count++;
        }
    }
    return count;
}


void mySort( double array[], int size, string order)
{
    bool swapped = true;
    int i;
    int j;
    if( order == "ASC")
    {
        for( i = 0; i < size - 1 && swapped == true; i++)
            {
                swapped = false;
                for( j = 0; j < size - 1 - i; j++)
                    {
                        if( array[j] > array[ j + 1])
                            {
                                swap( array[j + 1], array[j]);
                                swapped = true;
                            }
                    }
            }
    }
    if( order == "DSC")
    {
        for( i = 0; i < size - 1 && swapped == true; i++)
            {
                swapped = false;
                for( j = 0; j < size - 1 - i; j++)
                    {
                        if( array[j] < array[ j + 1])
                            {
                                swap( array[j + 1], array[j]);
                                swapped = true;
                            }
                    }
            }
    }
}
        

int linearSearch( double array[], int size, double findVal)
{
    int i;
    for( i = 0; i < size; i++)
    {
        if( array[i] == findVal)
        {
            return i;
        }
    }
    return -1;
}


int binarySearch( double array[], int size, double findVal)
{
    mySort( array, size, "ASC");
    int low = 0;
    int high = size - 1;
    int mid;
    while( low <= high)
    {
        mid = (low + high) / 2;
        if( array[mid] == findVal)
        {
            return mid;
        }
        if( array[mid] < findVal)
        {
            low = mid + 1;
        }
        if( array[mid] > findVal)
        {
            high = mid - 1;
        }
    }
    return -1;
}


double factorial( int number)
{
    int i;
    double sum = 1;
    for( i = 1; i <= number; i++)
    {
        sum = sum * i;
    }
    return sum;
}


double mySin( double rads)
{
    bool swapsign = true;
    int i = 0;
    int number = 1;
    double fac = factorial( number);
    double end = 0;
    for( i = 0; i <= TERMS; i++) 
    {
        if( swapsign == true)
        {
            //cout << "+" << pow( rads, number) << " / " << fac << fixed << endl;
            end  = end + (pow( rads, number) / fac);
            swapsign = false;
            number = number + 2;
            fac = factorial( number);
        }
        else if( swapsign == false)
        {
            //cout << "-" << pow( rads, number) << " / " << fac << fixed << endl;
            end  = end - (pow( rads, number) / fac);
            swapsign = true;
            number = number + 2;
            fac = factorial( number);
        }
    }
    return end;
}


double mySinD( double degrees)
{
    double rads;
    double ans;
    rads = (degrees * PI) / 180;
    ans = mySin( rads);
    return ans;
}


double myCos( double rads)
{
    bool swapsign = true;
    int i;
    int number = 0;
    double fac = factorial( number);
    double end = 0;
    for( i = 0; i <= TERMS; i++)
    {
        if( swapsign == true)
        {
            //cout << "+" << pow( rads, number) << " / " << fac << endl;
            end  = end + (pow( rads, number) / fac);
            swapsign = false;
            number = number + 2;
            fac = factorial( number);
        }
        else if( swapsign == false)
        {
            //cout << "-" << pow( rads, number) << " / " << fac << endl;
            end  = end - (pow( rads, number) / fac);
            swapsign = true;
            number = number + 2;
            fac = factorial( number);
        }
    }
    //cout << end << endl;
    return end;
}


double myCosD( double degrees)
{
    double rads;
    double ans;
    rads = (degrees * PI) / 180;
    ans = myCos( rads);
    return ans;
}


double myTan( double rads)
{
    double sin;
    double cos;
    double tan;
    sin = mySin( rads);
    cos = myCos( rads);
    tan = sin / cos;
    return tan;
}



