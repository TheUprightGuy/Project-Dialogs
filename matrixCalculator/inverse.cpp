/*

if(_ADeterminant = 0)
{
    std::cout << "Matrix has no inverse." << endl;
}
else
{
    matrix inverse(matrix M){
        matrix I = identity(M.size());
        for(int K=0; K<rows; ++K){
            //one in the pivot
            double factor = M[K][K];
            M[K] /= factor;
            I[K] /= factor;
            //zeroing the column
            for(int L=0; L<rows; ++L){
                if( K==L ) continue;
                double coefficient = M[L][K];
                M[L] -= coefficient*M[K];
                I[L] -= coefficient*I[K];
            }
        }

    return I;
    }
}

*/