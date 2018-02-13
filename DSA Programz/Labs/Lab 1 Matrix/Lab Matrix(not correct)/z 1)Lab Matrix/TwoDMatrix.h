#ifndef TWODMATRIX_H
#define TWODMATRIX_H
class TwoDMatrix
{
private:
	int ** matrix; // A pointer to the 2-D array of integers (to be allocated dynamically)
	int rows; // Number of rows in the matrix
	int columns;
public:
	TwoDMatrix();
	TwoDMatrix(int row,int col);
	~TwoDMatrix();
	bool get(int i, int j, int& val);
	bool set(int i, int j, int val);
	void display();
	void transpose();
	void add (const TwoDMatrix& first, const TwoDMatrix& second);
	void displaySubMatrix (int r1, int r2, int c1, int c2);
	TwoDMatrix(TwoDMatrix&ref);
	TwoDMatrix operator=(TwoDMatrix &ref);
	TwoDMatrix operator[](int m1);
	void multiply (const TwoDMatrix& first, const TwoDMatrix& second);
};
#endif