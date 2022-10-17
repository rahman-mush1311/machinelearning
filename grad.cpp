
#include <bits/stdc++.h>


using namespace std;

int main()
{
    int d;
    float lr = 0.001;
    float w[15];
    float l[15];
    float g[15];
    cin >>d;

    for(int i=0; i<d; i++)
    {
        cin >> l[i];

    }
    for(int i=0; i<d; i++)
    {
        cin >> g[i];
        int mini=l[i];
        int maxi=g[i];
        int rnd=mini + rand() % ( maxi - mini + 1 );
        w[i]=rnd*1.0;
    }
    int it=0;
    float prev=1000000;

    while(it<10000)
    {

        for(int i=0; i<d; i++)
        {
            cout << w[i]<< " ";

        }
        cout << endl;
        cout << flush;
        float f;
        float fx[15];
        cin>>f;
        prev=f;
        if (prev<f){
            lr=lr*1.01;
        }
        else{
            lr=lr*0.5;
        }
        int flag=0;
        for(int i=0; i<d; i++)
        {
            cin >> fx[i];
            float updated=w[i]-lr*fx[i];
            if((updated>=l[i]) && (updated<=g[i]))
                w[i]=updated;
        }

        it++;
    }
    return 0;
}
