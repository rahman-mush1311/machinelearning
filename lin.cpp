#include <bits/stdc++.h>
#include <string>

using namespace std;

float labels[15];
float dataset[1015][15];
float transpose[15][1015];
float multiMatrix[15][30];
float inverseMatrix[15][30];
float inverseMultiMatrix[15][30];
float finalMatrix[15];

void inputVectors(int n, int d)
{

    for(int i=0; i<n; i++)
    {
        float element;
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

void matrixMultiplication(int n, int d)
{

    for (int i = 0; i <=d; i++)
    {
        for (int j = 0; j <=d; j++)
        {

            for (int k = 0; k <n; k++)
            {
                float val1= transpose[i][k];
                float val2 = dataset[k][j];
                multiMatrix[i][j] += val1*val2;
            }
        }
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

    float ratio =0.0;

    for(int i=0; i<d; i++)
    {
        if(multiMatrix[i][i]==0)
            multiMatrix[i][i]=1.0;
        for(int j=0; j<d; j++)
        {
            if(i!=j)
            {
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
            multiMatrix[i][j] = multiMatrix[i][j]/multiMatrix[i][i];
        }
    }
    for(int i=0; i<d; i++)
    {
        int k =-1;
        for(int j=d; j<2*d; j++)
        {
           inverseMatrix[i][++k]=multiMatrix[i][j];
        }
    }
}
void matrixInverseMultiplication(int n,int d)
{

    for (int i = 0; i <=d; i++)
    {
        for (int j = 0; j <=d; j++)
        {

            for (int k = 0; k <n; k++)
            {
                float val1= inverseMatrix[i][k];
                float val2 = transpose[k][j];
                inverseMultiMatrix[i][j] += val1*val2;
                //cout << val1 << " " << val2 << endl;
            }
        }
    }
}

void finalW(int d,int n)
{

    for (int i = 0; i <=d; i++)
    {
        for (int j = 0; j <n; j++)
        {
                float val1= inverseMultiMatrix[i][j];
                float val2 = labels[j];
                finalMatrix[i] += val1*val2;
                //cout << val1 << " " << val2 << endl;
        }
    }
}

int main()
{


    int n, d;
    cin>> n >> d;
    inputVectors(n,d);
    transposeMatrix(n,d);
    matrixMultiplication(n, d);
    matrixInverse(d+1);
    matrixInverseMultiplication(n,d);
    finalW(d,n);

    /*for(int i=0; i<n; i++)
        cout << labels[i] << endl;

        for(int sample=0; sample<n; sample++){
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
    }*/

   /* for(int sample=0; sample<=d; sample++)
    {

        for(int featureNo=0; featureNo<n; featureNo++)
        {
            cout << inverseMultiMatrix[sample][featureNo] << " ";
        }
        cout << endl;
    }*/
   /*  for(int sample=0; sample<=d; sample++)
    {

        for(int featureNo=0; featureNo<n; featureNo++)
        {
            cout << inverseMultiMatrix[sample][featureNo] << " ";
        }
        cout << endl;
    }*/
    for(int i=0; i<=d; i++)
        cout << finalMatrix[i] << " ";
    cout << endl;
return 0;
}
