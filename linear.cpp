
#include <bits/stdc++.h>
#include <string>

using namespace std;

double labels[10015];
double dataset[10015][15];
double transpose[15][10015];
double multiMatrix[15][30];
double inverseMatrix[15][30];
double inverseMultiMatrix[15][30];
double finalMatrix[10015];

void inputVectors(int n, int d)
{

    for(int i=0; i<n; i++)
    {
        double element;
        for(int j=0; j<=d; j++)
        {
            if(j==0)
                dataset[i][j]=1.0;
            else
            {

                cin>>dataset[i][j];
            }
        }
        cin>>labels[i];
    }
}

void transposeMatrix(int n, int d)
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <=d; ++j)
        {
            transpose[j][i] = dataset[i][j];
        }

}

void matrixMultiplication(int n,int d)
{
    for(int i = 0; i <=d; i++)
        for(int j = 0; j <=d; j++)
            for(int k = 0; k < n; k++)
            {
                double val1= transpose[i][k];
                double val2 = dataset[k][j];
                multiMatrix[i][j] += val1*val2;
            }
}

void matrixInverse(int d)
{
//cout << "called" << endl;

    for(int i=0; i<d; i++)
    {
        for(int j=0; j<d; j++)
        {
            if(i==j)
            {
                multiMatrix[i][j+d] = 1.0;
            }
            else
            {
                multiMatrix[i][j+d] = 0.0;
            }
        }
    }

    double ratio=0.0;
    for(int i=0; i<d; i++)
    {
        for(int j=0; j<d; j++)
        {

            if(i!=j)
            {
                if(multiMatrix[i][i]==0)
                {
                    multiMatrix[i][i]=1.0;
                }
                ratio = multiMatrix[j][i]/multiMatrix[i][i];

                for(int k=0; k<2*d; k++)
                {
                    multiMatrix[j][k] = multiMatrix[j][k] - ratio*multiMatrix[i][k];
                }
            }
        }
    }
    for(int i=0; i<d; i++)
    {
        for(int j=d; j<2*d; j++)
        {
            if(multiMatrix[i][i]==0)
            {
                multiMatrix[i][i]=1.0;
            }

            multiMatrix[i][j] = multiMatrix[i][j]/multiMatrix[i][i];

        }
    }
    for(int i=0; i<d; i++)
    {
        int k =0;
        for(int j=d; j<2*d; j++)
        {
            inverseMatrix[i][k]=multiMatrix[i][j];
            k++;
        }
    }
}
void matrixInverseMultiplication(int n,int d)
{

    for (int i = 0; i <=d; i++)
    {
        for (int j = 0; j <n; j++)
        {

            for (int k = 0; k <=d; k++)
            {
                double val1= inverseMatrix[i][k];
                double val2 = transpose[k][j];
                inverseMultiMatrix[i][j] += val1*val2;
                //cout << val1 << " " << val2 << endl;
            }
        }
    }
}
void finalW(int n,int d)
{
    //cout << " called " << endl;

    for (int i = 0; i <=d; i++)
    {
        for (int j = 0; j <n; j++)
        {
            double val1= inverseMultiMatrix[i][j];
            double val2 = labels[j];
            finalMatrix[i] += val1*val2;
            //cout << val1 << " " << val2 << endl;
        }
        // cout << i<< " "<< finalMatrix[i] << " ";
    }
    //cout << endl;
}

int main()
{


    int n, d;
    cin>> n >> d;
    inputVectors(n,d);
    transposeMatrix(n,d);
    matrixMultiplication(n,d);
    matrixInverse(d+1);
    matrixInverseMultiplication(n,d);
    finalW(n,d);

    /*  for(int sample=0; sample<n; sample++){
            for(int featureNo=0; featureNo<=d; featureNo++){
            cout << dataset[sample][featureNo] << " ";
        }
        cout << endl;
    }

     for(int sample=0; sample<=d; sample++){
            for(int featureNo=0; featureNo<n; featureNo++){
            cout << transpose[sample][featureNo] << " ";
        }
        cout << endl;
    }


     for(int sample=0; sample<=d; sample++){
            for(int featureNo=0; featureNo<=d; featureNo++){
            cout << multiMatrix[sample][featureNo] << " ";
        }
        cout << endl;
    }
    for(int sample=0; sample<=d; sample++){
            for(int featureNo=0; featureNo<=d; featureNo++){
            cout << inverseMatrix[sample][featureNo] << " ";
        }
        cout << endl;
    }
    for(int sample=0; sample<=d; sample++){
            for(int featureNo=0; featureNo<n; featureNo++){
            cout << inverseMultiMatrix[sample][featureNo] << " ";
        }
        cout << endl;
    }*/
    for(int i=0; i<=d; i++)
    {
        if(i==0)
        {
            cout << finalMatrix[i];
        }
        else
        {
            cout << " " << finalMatrix[i];
        }
    }
    // cout << endl;


    return 0;
}
