/** **********************************************************************
 * @file
 ************************************************************************/
#include "thpe2.h"

/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *  
 *  This function returns the square root of any number above 0.
 *
 *  @param[in] stNum a real number above 0 to be passed into the function.
 *
 *  @returns A double value that is the square root of the stNum.
 *
 *
 *  @par Example
 *  @verbatim
    
    double value;
    value = mySqrt( 4) // will return 2.0
    value = mySqrt( 9) // will return 3.0
    value = mySqrt( 435) // will return 20.8566536146

    @endverbatim
 ************************************************************************/
double  mySqrt( double stNum)
{
    int i = 0;
    double check;
    double low = 0;
    double mid;
    double max = stNum;
    if( stNum < 1 && stNum > 0)
    {
        max = 1;
    }
    if( max <= 0 )
    {
        return 0;
    }
    while( i <= ITERATIONMAX)
    {
        mid = (max + low) / 2;
        //cout << mid << endl;
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


/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *  
 *  This function returns the cube root of any number above 0.
 *
 *  @param[in] stNum a real number above 0 to be passed into the function.
 *
 *  @returns A double value that is the cube root of the stNum.
 *
 *
 *  @par Example
 *  @verbatim
    
    double value;
    value = myCbrt( 64) // will return 4
    value = myCbrt( 125) // will return 5
    value = myCbrt( .015625) // will return .250

    @endverbatim
 ************************************************************************/

double  myCbrt( double stNum)
{
    int i = 0;
    double check;
    double low = 0;
    double mid;
    double max = stNum;
    if( stNum < 1 && stNum > 0)
    {
        max = 1;
    }
    if( max <= 0 )
    {
        return 0;
    }
    while( i <= ITERATIONMAX)
    {
        mid = (max + low) / 2;
        //cout << mid << endl;
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


/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *  
 *  This function returns the value of a logarithm of any base and argument. Both base and arg must be a double number above 1.
 *
 *  @param[in] arg a real number above 1 to be passed into the function.
 *  @param[in] base a real number above 1 to be passed into function.
 *
 *  @returns A double value evaluated using the base and argument
 *
 *
 *  @par Example
 *  @verbatim
    
    double value;
    value = myLog( 1024, 2 ) // will return 10
    value = myLog( 8, 16) // will return .75
    value = myLog( 10, 10) // will return 1

    @endverbatim
 ************************************************************************/


double myLog( double arg, double base)
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
    while( j <= ITERATIONMAX)
    {
        mid = (high + low) / 2;
        //cout << mid << endl;
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

/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *  
 *  This is a non-valued function that copies the contents from one array to another.
 *
 *  @param[in] copy an empty array to which the contents will be copied to.
 *  @param[in] start an array filled with contents to be copied.
 *  @param[in] size the size of both arrays.
 *
 *
 *
 *  @par Example
 *  @verbatim
 
    double start[4] = {1, 2, 3, 4}
    double copy[4];
    copyArray( copy, start, 4) // copy[4] = {1, 2, 3, 4}

    @endverbatim
 ************************************************************************/


void copyArray( double copy[], double start[], int size)
{
    int i = 0;
    for( i = 0; i <= size - 1; i++)
    {
        copy[i] = start[i];
    }
}


/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *  
 *  This is a non-valued function that initializes an array to a value.
 *
 *  @param[in] array an empty array that is being initialized
 *  @param[in] size the size of the array
 *  @param[in] value the number to be initialized into the array.
 *
 *
 *
 *  @par Example
 *  @verbatim
 
    double array[4];
    double value = 19;
    initialArray( array, 4, 19) 
    array[4] = { 19, 19, 19, 19};

    @endverbatim
 ************************************************************************/


void initialArray( double array[], int size, double value)
{
    int i = 0;
    for( i = 0; i <= size -1; i++)
    {
        array[i] = value;
    }
}


/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *  
 *  This is a valued function that will sum up the contents of an array and return that sum.
 *
 *  @param[in] array the array filled with values to be summed up.
 *  @param[in] size the size of the array.
 *
 *
 *  @returns a double value that represents the sum of all the elements within the array.
 *
 *
 *  @par Example
 *  @verbatim
 
    double array[5] = {1, 2, 3, 4, 5};
    double sum = sumArray( array, 5); //sum == 15

    @endverbatim
 ************************************************************************/


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



/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *  
 *  This is a valued function which will sum up the contents of an array and then average them.
 *
 *  @param[in] array an array filled with real numbers.
 *  @param[in] size the size of the array
 *
 *
 *  @returns a double value that represents the average of all the elements within the array..
 *
 *
 *  @par Example
 *  @verbatim
 
    double array[4] = {1, 2, 3, 4};
    double sum;
    sum  = averageArray( array, 4); //will return 2.5
    
    @endverbatim
 ************************************************************************/


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


/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *  
 *  This is a valued function which will search an array for its lowest value and return the index within that array
 *
 *  @param[in] array an array filed with real numbers.
 *  @param[in] size the size of both arrays.
 *
 *
 *  @returns an integer value that represents the index of the array that holds the lowest value within the array.
 *
 *  @par Example
 *  @verbatim
 
    double array[5] = {1, 2, 3, 4, 5};
    int location;
    location = minLocation( array, 5); //will return 0 for the 0th position within array.

    @endverbatim
 ************************************************************************/


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


/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *  
 *  This is a valued function which will search an array for its lowest value and return that value.
 *
 *  @param[in] array an array filed with real numbers.
 *  @param[in] size the size of both arrays.
 *
 *
 *  @returns a double value that represents the lowest value found in the array.
 *
 *
 *  @par Example
 *  @verbatim
 
    double array[5] = {1, 2, 3, 4, 5};
    double value;
    value = minValue( array, 5); //will return 1 because 1 is smallest number in array.

    @endverbatim
 ************************************************************************/


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


/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *  
 *  This is a valued function which will search an array for its greatest value and return the index within that array
 *
 *  @param[in] array an array filed with real numbers.
 *  @param[in] size the size of both arrays.
 *
 *
 *  @returns an integer value that represents the index of the array that holds the highest value.
 *
 *
 *  @par Example
 *  @verbatim
 
    double array[5] = {1, 2, 3, 4, 5};
    int location;
    location = maxLocation( array, 5); //will return 4 for the 4th position within array.

    @endverbatim
 ************************************************************************/


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


/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *  
 *  This is a valued function which will search an array for its greatest value and return that value.
 *
 *  @param[in] array an array filed with real numbers.
 *  @param[in] size the size of both arrays.
 *
 *
 *  @returns an double value that represents the highest value found within an array.
 *
 *
 *  @par Example
 *  @verbatim
 
    double array[5] = {1, 2, 3, 4, 5};
    double value;
    value = maxValue( array, 5); //will return 5 because it is the highest value within array.

    @endverbatim
 ************************************************************************/

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


/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *  
 *  This is a valued function which will search an array for a value and increment a counter every time it finds that counter.
 *
 *  @param[in] array an array filed with real numbers.
 *  @param[in] size the size of both arrays.
 *  @param[in] findVal the real number to be searched.
 *
 *
 *  @returns an integer value that represents how many times the value is found in an array.
 *
 *  @par Example
 *  @verbatim
 
    double array[5] = {3, 2, 3, 4, 5};
    double findVal = 3;
    int count = countIf( array, 5, 3); // will return 2. 3 appears twice.

    @endverbatim
 ************************************************************************/


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


/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *  
 *  This is a non-valued function that sorts an array in either ascending or descending order.
 *
 *  @param[in] array an array filed with real numbers.
 *  @param[in] size the size of both arrays.
 *  @param[in] order a string value to determine how to sort the array.
 *
 *
 *  
 *
 *
 *  @par Example
 *  @verbatim
 
    double array[5] = {5, 4, 3, 2, 1};
    string order = "ASC";
    mySort( array, 5, order); // array[5] = {1, 2, 3, 4, 5};
    
    double array[5] = {1, 2, 3, 4, 5};
    string order = "DSC";
    mySort( array, 5, "DSC"); // array[5] = {5, 4, 3, 2, 1};

    @endverbatim
 ************************************************************************/

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
    return;
}


/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *  
 *  This is a valued function which will search an array for a value and return the index of this value, returns -1 if its not found.
 *
 *  @param[in] array an array filed with real numbers.
 *  @param[in] size the size of both arrays.
 *  @param[in] findVal the real number being searched for in the array.
 *
 *
 *
 *  @returns an integer value that represents the index of the array.
 *
 *  @par Example
 *  @verbatim
 
    double array[5] = {1, 2, 3, 4, 5};
    double findVal = 3
    int location  = linearSearch( array, 5, findVal); // will return 2 because 3 is in the 2nd position of the array.

    @endverbatim
 ************************************************************************/

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



/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *  
 *  This is a valued function which will search an array for a value and return the index of this value, returns -1 if its not found. This will sort the function in ascending order then search.
 *
 *  @param[in] array an array filed with real numbers.
 *  @param[in] size the size of both arrays.
 *  @param[in] findVal the real number being searched for in the array.
 *
 *
 *  @returns an integer value that represents the index of the array.
 *
 *  @par Example
 *  @verbatim
 
    double array[5] = {3, 4, 5, 6, 3};
    double findVal = 3
    int location  = binarySearch( array, 5, findVal); // will return 0, becuase 3 is in the 0th position. 

    @endverbatim
 ************************************************************************/

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


/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *  
 *  This is a valued function which will find the factorial of a number
 *
 *  @param[in] number a number to evaluate the factorial of.
 *
 *  @returns a double value that is the evaluation of the number.
 *
 *  @par Example
 *  @verbatim
 
    double number = 5;
    doulbe answer = factorial( number); // will return 120.

    @endverbatim
 ************************************************************************/

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



/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *  
 *  This is a valued function which will evaluate the sine function at a certain value.
 *
 *  @param[in] rads the real number in radians to be evaluated;
 *
 *
 *  @returns a double value that represents the evaluation of the number for sine.
 *
 *  @par Example
 *  @verbatim
 
    double rads = 0;
    double value = mySin( rads); //will return 0, sin(0) = 0
    
    double rads = PI/2;
    double value = mySin( rads); //will return 1, sin(PI/2) = 1

    @endverbatim
 ************************************************************************/

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


/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *  
 *  This is a valued function which will evaluate the sine function at a certain value in degrees.
 *  This function will convert the value to radians and then evaluate.
 *
 *  @param[in] degrees the real number in degrees to be evaluated;
 *
 *
 *  @returns a double value of the number being evaluated in the function.
 *
 *  @par Example
 *  @verbatim
 
    double degrees = 0;
    double value = mySinD( degrees); //will return 0, sin(0) = 0
    
    double degrees = 90;
    double value = mySinD( degrees); //will return 1, sin(90) = 1

    @endverbatim
 ************************************************************************/


double mySinD( double degrees)
{
    double rads;
    double ans;
    rads = (degrees * PI) / 180;
    ans = mySin( rads);
    return ans;
}



/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *  
 *  This is a valued function which will evaluate the cosine function at a certain value.
 *
 *  @param[in] rads the real number in radians to be evaluated;
 *
 *
 *  @returns a double value of the number being evaluated in the function.
 *
 *  @par Example
 *  @verbatim
 
    double rads = 0;
    double value = myCos( rads); //will return 1, cos(0) = 1
    
    double rads = PI/2;
    double value = myCos( rads); //will return 0, cos(PI/2) = 0

    @endverbatim
 ************************************************************************/

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



/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *  
 *  This is a valued function which will evaluate the cosine function at a certain value in degrees.
 *  This function will convert the value to radians and then evaluate.
 *
 *  @param[in] degrees the real number in degrees to be evaluated;
 *
 *
 *  @returns a double value of the number being evaluated in the function.
 *
 *  @par Example
 *  @verbatim
 
    double degrees = 0;
    double value = myCosD( degrees); //will return 1, cos(0) = 1
    
    double degrees = 90;
    double value = myCosD( degrees); //will return 0, cos(90) = 0

    @endverbatim
 ************************************************************************/

double myCosD( double degrees)
{
    double rads;
    double ans;
    rads = (degrees * PI) / 180;
    ans = myCos( rads);
    return ans;
}


/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *  
 *  This is a valued function which will evaluate the tangent function at a certain value.
 *
 *  @param[in] rads the real number in radians to be evaluated;
 *
 *
 *  @returns a double value of the number being evaluated in the function.
 *
 *  @par Example
 *  @verbatim
 
    double rads = 0;
    double value = myTan( rads); //will return 0, tangent(0) = 0
    
    double rads = PI/4;
    double value = myTan( rads); //will return 1, tangent(PI/4) = 1

    @endverbatim
 ************************************************************************/

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


/** **********************************************************************
 *  @author Nicholas K Wilk
 *
 *  @par Description
 *  
 *  This is a valued function which will evaluate the tangent function at a certain value in degrees.
 *  This function will convert the value to radians and then evaluate.
 *
 *  @param[in] degrees the real number in degrees to be evaluated;
 *
 * 
 *  @returns a double value of the number being evaluated in the function.
 *
 *  @par Example
 *  @verbatim
 
    double degrees = 0;
    double value = myTanD( degrees); //will return 0, tan(0) = 0
    
    double degrees = 45;
    double value = myTanD( degrees); //will return 1, tan(45) = 1

    @endverbatim
 ************************************************************************/

double myTanD( double degrees)
{
    double rads;
    double ans;
    rads = (degrees * PI) / 180;
    ans = myTan( rads);
    return ans;
}



