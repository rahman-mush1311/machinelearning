#include<bits/stdc++.h>
using namespace std;

int main(){
            int n,i,j;
            float ratio=0.0;
            float a[10][10];

         cout<<"Enter order of matrix: ";
		 cin>>n;

		 /* 2. Reading Matrix */
		 cout<<"Enter coefficients of Matrix: " << endl;
		 for(i=0;i<n;i++)
		 {
			  for(j=0;j<n;j++)
			  {
				   cout<<"a["<< i<<"]"<< j<<"]= ";
                   cin>>a[i][j];
			  }
		 }

		 /* Augmenting Identity Matrix of Order n */
		 for(i=0;i<n;i++)
		 {
			  for(j=0;j<n;j++)
			  {
				   if(i==j)
				   {
				    	a[i][j+n] = 1;
				   }
				   else
				   {
				    	a[i][j+n] = 0;
				   }
			  }
		 }

		 /* Applying Gauss Jordan Elimination */
		 for(i=0;i<n;i++)
		 {
			  if(a[i][i] == 0.0)
			  {
				   cout<<"Mathematical Error!";
				   exit(0);
			  }
			  for(j=0;j<n;j++)
			  {
				   if(i!=j)
				   {
                        ratio = a[j][i]/a[i][i];
					    for(int k=1;k<2*n;k++)
					    {
					     	a[j][k] = a[j][k] - ratio*a[i][k];
					    }
				   }
			  }
		 }
		 /* Row Operation to Make Principal Diagonal to 1 */
		 for(i=0;i<n;i++)
		 {
			  for(j=n;j<2*n;j++)
			  {
			   	a[i][j] = a[i][j]/a[i][i];
			  }
		 }
		 /* Displaying Inverse Matrix */
		 float in[10][10];
		 cout<< endl<<"Inverse Matrix is:"<< endl;
		 for(i=0;i<n;i++)
		 {
		     int k=0;
			  for(j=n;j<2*n;j++)
			  {
                in[i][k]=a[i][j];
                k++;
			   	cout<< a[i][j]<<"\t";
			  }
			  cout<< endl;
		 }
		 for(i=0;i<n;i++)
		 {
			  for(j=0;j<n;j++)
			  {
			   	cout<< in[i][j]<<"\t";
			  }
			  cout<< endl;
		 }
		 return(0);
}

