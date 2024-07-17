// Link to this file: https://github.com/PiotrMydlowski/Matrix-Basic/blob/master/main.cpp
/*
Write a program which performs addition, subtraction, multiplication of matrices.
The dimensions of both the matrices would be specified by the user (dynamic memory allocation required).
Use of structure or a class to define the matrix would be a good idea.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

class cMatrix
{
public:
    int width;
    int height;
    float** data;

    cMatrix(int w, int h);
    cMatrix(const cMatrix& source);//copy constructor
    ~cMatrix();
    void mPrint();//print the elements to the console
    void mRandomize(int limit);//randomizes elements of the given matrix
};

cMatrix::cMatrix(int w, int h)//default constructor
{
    srand( time( NULL ) );
    width = w;
    height = h;
    data = new float* [height];
    for (int i = 0; i < height; i++)
    {
        data[i] = new float[width];
        for (int j = 0; j < width; j++)
        {
            data[i][j] = 0;
        }
    }
}

cMatrix::cMatrix(const cMatrix& source)//copy constructor
{
    srand( time( NULL ) );
    width = source.width;
    height = source.height;
    data = new float* [height];
    for (int i = 0; i < height; i++)
    {
        data[i] = new float[width];
        for (int j = 0; j < width; j++)
        {
            data[i][j] = source.data[i][j];
        }
    }
}

cMatrix::~cMatrix()//destructor deallocates memory
{
    for (int i = 0; i < height; i++)
    {
        delete data[i];
    }
    delete data;
}

void cMatrix::mPrint()//printing
{
    using namespace std;

    static int no = 1;// holds the number of matrix print for easier identification
    cout<<"Matrix print number: "<<no<<endl;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cout<<data[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
    no++;
}

void cMatrix::mRandomize(int limit)//randomizes elements in range 0 - (limit-1)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            data[i][j] = std::rand()%limit;
        }
    }
}

cMatrix matrixAdd(cMatrix* firstArg, cMatrix* secondArg, bool* errors)
//adds two given matrices, returns the result and gives report about error existence
{
    if ((firstArg->width!=secondArg->width)||(firstArg->height!=secondArg->height)){
        std::cout<<"Dimension mismatch. Addition."<<std::endl;
        *errors = true;
        cMatrix result = cMatrix(1, 1);
        return result;
    }
    std::cout<<"Addition."<<std::endl;
    cMatrix result = cMatrix(firstArg->width, firstArg->height);
    for (int i = 0; i < firstArg->height; i++)
    {
        for (int j = 0; j < firstArg->width; j++)
        {
            result.data[i][j] = firstArg->data[i][j] + secondArg->data[i][j];
        }
    }
    *errors = false;
    return result;
}

cMatrix matrixSubtract(cMatrix* firstArg, cMatrix* secondArg, bool* errors)
//subtracts firstArg - secondArg, returns the result and gives report about error existence
{
    if ((firstArg->width!=secondArg->width)||(firstArg->height!=secondArg->height)){
        std::cout<<"Dimension mismatch. Subtraction."<<std::endl;
        *errors = true;
        cMatrix result = cMatrix(1, 1);
        return result;
    }
    std::cout<<"Subtraction."<<std::endl;
    cMatrix result = cMatrix(firstArg->width, firstArg->height);
    for (int i = 0; i < firstArg->height; i++)
    {
        for (int j = 0; j < firstArg->width; j++)
        {
            result.data[i][j] = firstArg->data[i][j] - secondArg->data[i][j];
        }
    }
    *errors = false;
    return result;
}

cMatrix matrixMultiply(cMatrix* firstArg, cMatrix* secondArg, bool* errors)
//multiplies two given matrices, returns the result and gives report about error existence
{
    if (firstArg->width!=secondArg->height){
        std::cout<<"Dimension mismatch. Multiplication."<<std::endl;
        *errors = true;
        cMatrix result = cMatrix(1, 1);
        return result;
    }
    std::cout<<"Multiplication."<<std::endl;
    cMatrix result = cMatrix( secondArg->width, firstArg->height);
    for (int i = 0; i < result.height; i++)
    {
        for (int j = 0; j < result.width; j++)
        {
            //default data value is set to 0 in class constructor
            for (int k = 0; k < firstArg->width; k++){
                result.data[i][j] = result.data[i][j] + (firstArg->data[i][k] * secondArg->data[k][j]);
            }
        }
    }
    *errors = false;
    return result;
}

int main()
{
    using namespace std;

    bool errors;
    int w, h;

    cout<<"The width of the first matrix:"<<endl;//input dimensions of the first matrix
    cin>>w;
    if(!cin.good()){
        cout<<"Wrong input. End of program."<<endl;
        return 0;
    }
    cout<<"The height of the first matrix:"<<endl;
    cin>>h;
    if(!cin.good()){
        cout<<"Wrong input. End of program."<<endl;
        return 0;
    }
    cMatrix userMatrix = cMatrix(w, h);

    cout<<"The width of the second matrix:"<<endl;//input dimensions of the second matrix
    cin>>w;
    if(!cin.good()){
        cout<<"Wrong input. End of program."<<endl;
        return 0;
    }
    cout<<"The height of the second matrix:"<<endl;
    cin>>h;
    if(!cin.good()){
        cout<<"Wrong input. End of program."<<endl;//here a valid integer followed by some characters is read as correct
        return 0;
    }
    cMatrix userMatrix2 = cMatrix(w, h);

    userMatrix.mRandomize(5);
    userMatrix2.mRandomize(5);

    userMatrix.mPrint();
    userMatrix2.mPrint();

    cMatrix resultAdd = cMatrix(matrixAdd(&userMatrix, &userMatrix2, &errors));
    if(!errors){
        resultAdd.mPrint();
    }

    cMatrix resultSubtract = cMatrix(matrixSubtract(&userMatrix, &userMatrix2, &errors));
    if(!errors){
        resultSubtract.mPrint();
    }

    cMatrix resultMultiply = cMatrix(matrixMultiply(&userMatrix, &userMatrix2, &errors));
    if(!errors){
        resultMultiply.mPrint();
    }

    cout << "End of program." << endl;
    return 0;
}
