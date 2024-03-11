

            j++;

        }
        i++;
        j = 0;

    }
    for (int x = 0 ; x< r; ++x)
    {
        for (int y= 0 ; y<c; ++y)
        {
            cout << m[x][y]<<" ";
        }
        cout<<endl;
    }
    for (int x = 1; x< r; x++)
    {
        for (int y =0; y<c; y++)
        {
            for (int i =1; i<r; i++)
            {
                for (int j = 0; j<c; j++)
                {
                    m[i][j] = m[i][j] + (- m[x][y]/m[i][i])*(m[i][i]);
                }
            }
        }
    }
    for (int x = 0 ; x< r; ++x)
    {
        for (int y= 0 ; y<c; ++y)
        {
            cout << m[x][y]<<" ";
        }
        cout<<endl;
    }