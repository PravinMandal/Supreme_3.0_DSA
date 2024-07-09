for(int j=0 ; j<n-i ; j++)
        {
            if(j==0 )
            {
                cout<<i+1<<" ";
            }
            else if (i==0)
            {
                cout<<j+1<<" ";
            }
            else if( j==n-i-1)
            {
                cout<<n<<" ";
            }
            else
            {
                cout<<"  ";
            }
        }