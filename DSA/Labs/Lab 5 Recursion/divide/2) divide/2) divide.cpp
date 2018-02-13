int divide(int a, int b)
{
    if( b == 0 )
    {
        return 0;
    }
    else if(a-b == 0)
    {
       return 1;
    }
    else if( a < b)
    {
       return 0; // You will need to think of something better than this.
    }
    else
    {
        return ( 1 + divide(a-b, b) );
    }
}
