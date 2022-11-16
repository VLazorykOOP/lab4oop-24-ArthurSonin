#include <iostream>
#include "Lab4Exmaple.h"
#include "ComplexVector.h"
#include "ComplexMatrix.h"
#include "MyAssoc.h"



int mainExample1() {

	/// <summary>
	/// ������ : A,B,C,D,F  -  ������� ���������� ����� 
	///         a,b,c - ��������� �����.
	/// ��������� ����� : F = A+B-B*c+C/b+D*a        
	/// </summary>
	/// <returns></returns>
	ComplexDouble a(1.0, 2), b, c;
#if defined(_MSC_VER)
	b._Val[_RE] = 2.3;
	b._Val[_IM] = 3.1;
	c = 4.1;
#else 
	b.real(2.3);
	b.imag(3.1);
	c.real(4.1);
#endif	
	ComplexDouble r(2.7, 2.1);
	ComplexVector A(3,r), B(3,a), C(3,b), D(3), F(1);
	D[0] = a; 
	D[1] = b; 
	D[2] = ComplexDouble(3.1, 1);
	F[0] = (1, 3);
	F[1] = 3.2;
	cout <<" Begin data "  << endl;
	cout << " a= " << a << " b= " << b << " c " << c << endl;
	cout << " A  \n" << A;
	cout << " B  \n" << B;
	cout << " C  \n" << C;
	cout << " D  \n" << D;

	F = A + B - B * c + C / b + D * a;
	
	cout << " \n F =   \n" << F;
	return 2;
}



/// <summary>
	/// ������ : A,B,C,D,F  -  ������� ���������� �����
	///          a,b,c  -  ������� ���������� ����� 
	///          _a,_b,_c - ��������� �����.
	/// ��������� ����� : F = A+B*_a-B*_c+C/_b; 
	///                   c = F*a + D*c         
	/// </summary>
	/// <returns></returns>

int mainExample2() {
	ComplexMatrix A(5, 5);
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++) A[i][j] = RandComplexDouble();
	cout << endl;
	cout << "Matrix A \n"<<A;

	
	return 3;
}
int mainExample3() {
	cout << " End begin \n";
	uint Flight[5] = { 12,32,23,43,43 };
	MyTime MTime[5] = { {9,10}, {10,30}, {10,30}, {10,30} , {15,35} };
	MyAssoc dbase(5, Flight, MTime);
	dbase.TableFlight();
	MyTime r = { 10,30 }, ro;
	uint fli = 32;
	ro = dbase[fli];
	cout << " Test : MyTime operator[](uint&s  )  " << "Flight " << fli << " time   " <<
		ro << endl;
	cout << " Test : uint	operator[](MyTime&s)  " << " time  " << r << " light  " <<
		dbase[r] << endl;
	cout << " Flight with time :   9   to  11 \n";
	dbase(9, 11);
	cout << " End test \n";
	return 4;
}

