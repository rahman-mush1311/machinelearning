#include <bits/stdc++.h>
#include <string>
#include <math.h>

using namespace std;

vector<double> yNxN(vector <double> xN, double y)
{

    vector<double>xy;

    for(int i=0; i<xN.size(); i++)
    {
        double xyVal=xN[i]*y;
        //cout << xyVal << " ";
        xy.push_back(xyVal);
    }
    return xy;
}

double eSum(vector <double> w, vector <double> xN, double y)
{

    double epSum=0.0;

    for(int i=0; i<w.size(); i++)
    {
        epSum+=w[i]*xN[i];
        //cout << epSum << endl;
        //cout << w[i] << " " <<xN[i]<< endl;
    }
    epSum*=y;
    //cout << epSum << endl;
    return (1/(1+exp(-epSum)));

}
vector<double> epDivision(vector <double> xN, double epSum)
{

    vector<double>xy;

    for(int i=0; i<xN.size(); i++)
    {
        double xyVal=xN[i]*epSum;
        //cout << xyVal << " ";
        xy.push_back(xyVal);
    }
    return xy;
}
int main()
{
    vector<vector<double>>ds;
    vector<vector<double>>labels;

    int n, d;
    cin>>n>>d;

    for(int i=0; i<n; i++)
    {
        double element;
        vector<double>lst;
        for(int j=0; j<=d; j++)
        {
            if(j==0)
            {
                element=1.0;
                lst.push_back(element);
            }
            else
            {

                cin>>element;
                lst.push_back(element);
            }
        }
        ds.push_back(lst);

        cin>>element;
        vector<double>ele;
        ele.push_back(element);
        labels.push_back(ele);
    }
    vector <double> upperSum;
    double expSum=0.0;
    vector <double> w;
    vector <double> g;
    for(int i=0; i<=d; i++)
    {
        w.push_back(42);
        g.push_back(0.0);
    }

    /*for(int i=0; i<w.size(); i++){
        cout << w[i] << " ";
    }*/
    vector<vector<double>>xNyN;
    int it=0;
    while(it<300)
    {
        it++;
        for(int i=0; i<ds.size(); i++)
        {
            // cout << ds[i][0] << endl;
            double y=labels[i][0];
            //cout << y << " ";
            vector<double> xy;
            xy=(yNxN(ds[i],y));
            double epSum=eSum(w, ds[i],y);
            xy=epDivision(xy,epSum);
            xNyN.push_back(xy);

            for(int j=0; j<g.size(); j++)
            {
                g[j]+=ds[i][j]*y*epSum;
                //cout << g[j] << " ";
            }
            //cout << epSum << endl;
        }
        for(int i=0; i<g.size(); i++)
        {
            g[i]=-(g[i]/n);
            w[i]=w[i]-0.05*g[i];
            //cout << w[i] << endl;
        }
    }
    for(int i=0; i<w.size();i++){
        cout << w[i] << " ";
    }
    // cout << endl;
    /* for (int i=0; i<xNyN.size(); i++){

         for (int j=0; j<xNyN[i].size(); j++){
             cout << xNyN[i][j] << " ";
         }
         cout << endl;
     }*/
    //vector <double> expSum;
    /*for(int i=0; i<ds.size(); i++){
        double y=labels[i][0];
        //cout << y << endl;
        double sum=yNxN(ds[i],y);
        upperSum.push_back(sum);
        //cout << sum << endl;
    }*/
    /*for(int i=0; i<upperSum.size(); i++){
        cout << upperSum[i] << " ";
    }*/
    //cout << "dataset size: " << ds.size() << endl;
    /*for (int i=0; i<ds.size(); i++){3

        for (int j=0; j<ds[i].size(); j++){
            cout << ds[i][j] << " ";
        }
        cout << endl;
    }
    for (int i=0; i<labels.size(); i++){
        for (int j=0; j<labels[i].size(); j++){
            cout << labels[i][j] << " ";
        }
        cout << endl;
    }*/
    return 0;
}
