#include <bits/stdc++.h>
#include <string>

using namespace std;

int main()
{
    vector< vector<float> > dataSet;
    vector<float> features;
    float weightVector[11];

    int n, d;
    cin>> n >> d;

    for(int i=0; i<n; i++)
    {
        float element;
        for(int j=0; j<=d; j++)
        {
            if(i==0)
                weightVector[j]=0;

            cin>> element;
            if(j==d)
            {
                if(element<0)
                    element =0;
            }
            features.push_back(element);
        }
        dataSet.push_back(features);
        features.clear();
    }
    float bias =0.0;
    float learningRate = 0.0001;
    int noOfmisclassification = 0;

    for(int noOfit=0; noOfit<20000; noOfit++)
    {
        for(int i=0; i<n; i++)
        {
            float h=bias;
            for(int j=0; j<dataSet[i].size()-1; j++)
            {
                h+=weightVector[j]*dataSet[i][j];
            }
            if((h<=0)&& (dataSet[i][d] >0))
            {
                int y_= 0;
                int y=dataSet[i][d];
                for(int u=0; u<d; u++)
                {
                    float update = learningRate*dataSet[i][u];
                    weightVector[u]=weightVector[u]+learningRate*dataSet[i][u]*(y-y_);
                }
                bias+= learningRate*(y-y_);
                noOfmisclassification+=1;
            }
            else if ((h>0)&& (dataSet[i][d]==0))
            {
                int y_= 1;
                int y=dataSet[i][d];
                for(int u=0; u<d; u++)
                {
                    weightVector[u]=weightVector[u]+learningRate*dataSet[i][u]*(y-y_);
                }
                bias+= learningRate*(y-y_);
                noOfmisclassification+=1;
            }
        }
       // cout << "no of misclassified: " << noOfmisclassification << endl;
       /* if(noOfmisclassification==0)
            break;
        noOfmisclassification=0;*/
    }
    cout << bias << " ";
    for(int i=0; i<d; i++)
        cout << weightVector[i] << " ";
    cout << endl;
}
