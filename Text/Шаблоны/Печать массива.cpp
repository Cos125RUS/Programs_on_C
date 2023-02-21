void print_array(int[], int);




void print_array(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i % 10 == 0 && i != 0)
            cout << endl;
        cout << setw(5) << array[i];
    }
    cout << endl << endl;
}