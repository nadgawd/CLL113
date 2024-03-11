#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    fstream fk;
    fk.open("input.txt",ios::in); 
    int n;
    fk>>n;
    double **A = new double*[n];
    for(int i=0;i<n;i++){
        A[i] = new double[n];
    }
    double *B = new double[n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            fk>>A[i][j];
        }
    }

    for(int i=0;i<n;i++){
        fk>>B[i];
    }
    fk.close();

    fstream sx;
    sx.open("output.txt",ios::out);

    double **AB = new double*[n];
    for(int i=0;i<n;i++){
        AB[i] = new double[n+1];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            AB[i][j] = A[i][j];
        }
    }
    for(int i=0;i<n;i++){
        AB[i][n] = B[i];
    }

    for(int k=0;k<n-1;k++){
        int p=k;
        double big = AB[k][k];
        for(int i=k+1;i<n;i++){
            if(AB[i][k]>big){
                big = AB[i][k];
                p=i;
            }
        }
        if(p!=k){
            for(int i=k;i<n+1;i++){
                swap(AB[k][i],AB[p][i]);
            }
        }
        for(int i=k+1;i<n;i++){
            double temp = AB[i][k]/AB[k][k];
            for(int j=k;j<n+1;j++){
                AB[i][j] = AB[i][j] - (AB[k][j] * temp);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            A[i][j] = AB[i][j];
        }
    }
    for(int i=0;i<n;i++){
        B[i] = AB[i][n];
    }
    double* X = new double[n];
    X[n-1] = B[n-1]/A[n-1][n-1];
    for(int i=n-2;i>=0;i--){
        int j=n-1;
        double sub=0;
        while(j>i){
            sub += A[i][j] * X[j];
            j--;
        }
            X[i] = (B[i]-sub)/A[i][i];
    }
    sx<<"X:"<<endl;
    for(int i=0;i<n;i++){
        sx<<X[i]<<endl;
    }
    sx.close();

    for(int i=0;i<n;i++){
        delete[] A[i];
    }
    for(int i=0;i<n;i++){
        delete[] A[i];
    }
    delete[] A;
    delete[] B;
    for(int i=0;i<n;i++){
        delete[] AB[i];
    }
    delete[] AB;
    delete[] X;
}
