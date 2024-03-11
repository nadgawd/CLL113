#include<iostream>
#include<fstream>
using namespace std;
int main(){
    fstream sx;
    sx.open("input2.txt",ios::in);
    int n;sx>>n;
//3
    double **A = new double*[n];
    for(int i=0;i<n;i++){
        A[i] = new double[n];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            sx>>A[i][j];
        }
    }
    double *B = new double[n];
    for(int i=0;i<n;i++){
        sx>>B[i];
    }
    sx.close();
//1 -1 2 1 1 1 2 -2 3
    fstream fk;
    fk.open("output2.txt",ios::out);
    fk<<"A:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            fk<<A[i][j]<<" ";
        }
        fk<<endl;
    }
    
//-8 -2 -20
    fk<<"B:"<<endl;
    for(int i=0;i<n;i++){
        fk<<B[i]<<endl;
    }
    double **I = new double*[n];
    for(int i=0;i<n;i++){
        I[i] = new double[n];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            I[i][j] = i==j ? 1 : 0;
        }
    }
    fk<<"I:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            fk<<I[i][j]<<" ";
        }
        fk<<endl;
    }
    double **ABI = new double*[n];
    for(int i=0;i<n;i++){
        ABI[i] = new double[2*n + 1];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ABI[i][j] = A[i][j];
        }
    }
    for(int i=0;i<n;i++){
        ABI[i][n] = B[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ABI[i][j+n+1] = I[i][j];
        }
    }
    fk<<"A|B|I:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<2*n+1;j++){
            fk<<ABI[i][j]<<" ";
        }
        fk<<endl;
    }
    for(int k=0;k<n;k++){
        int p=k;
        double pivot = ABI[k][k];
        if(pivot ==0){
            for(int i=k+1;i<n;i++){
                if(ABI[i][k]!=0){
                    pivot = ABI[i][k];
                    p = i;
                    break;
                }
            }
            if(p!=k){
                for(int i=0;i<2*n+1;i++){
                    swap(ABI[k][i],ABI[p][i]);
                }
            }
        }
        double denominator = ABI[k][k];
        for(int i=0;i<2*n+1;i++){
            ABI[k][i] = ABI[k][i]/denominator;
        }
        for(int i=0;i<n;i++){
            if(i==k){
                continue;
            }
        double temp = ABI[i][k]/ABI[k][k];
            for(int j=0;j<2*n+1;j++){
                ABI[i][j] = ABI[i][j] - temp * ABI[k][j];
            }
        }
    }
    double *X = new double[n];
    for(int i=0;i<n;i++){
        X[i] = ABI[i][n];
    }
    fk<<"X:"<<endl;
    for(int i=0;i<n;i++){
        fk<<X[i]<<endl;
    }
//-11, 5,4 
    double **A_inv = new double*[n];
    for(int i=0;i<n;i++){
        A_inv[i] = new double[n];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            A_inv[i][j] = ABI[i][j+n+1];
        }
    }
    fk<<"Inverse of A:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            fk<<A_inv[i][j]<<" ";
        }
        fk<<endl;
    }
    double **Product = new double*[n];
    for(int i=0;i<n;i++){
        Product[i] = new double[n];
    }    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                Product[i][j]+=A[i][k]*A_inv[k][j];
            }
            if(Product[i][j] < 1e-5){
                Product[i][j] = 0;
            }
        }
    }
    fk<<"matrix A multiplied by matrix B:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            fk<<Product[i][j]<<" ";
        }
        fk<<endl;
    }
    fk.close();
    for(int i=0;i<n;i++){
        delete[] A[i];
    }
    delete[] A;
    delete[] B;
    for(int i=0;i<n;i++){
        delete[] I[i];
    }
    delete[] I;
    for(int i=0;i<n;i++){
        delete [] ABI[i];
    }
    delete ABI;
    delete[] X;
    for(int i=0;i<n;i++){
        delete[] A_inv[i];
    }
    delete[] A_inv;
    for(int i=0;i<n;i++){
        delete[] Product[i];
    }
    delete[] Product;
}
