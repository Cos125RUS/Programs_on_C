void fill_array(int[], int);






void fill_array(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        array[i] = 1 + rand() % 99;
    }
}