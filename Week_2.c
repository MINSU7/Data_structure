#define _CER_SECURE_NO_WARNINGS
#include <stdio.h>
/*
//A,B,C : 'A','B','C'
//n : 원판 개수
int n = 8;

// recursive 함수
//_n : 옮길 원판
//_src
//_dst
//_temp
void perform_hanoi(int _n, char _src, char _dst, char _temp) {

	if (_n == 1) {
		printf("%d원판을 %c에서 %c로 이동\n", _n, _src, _dst);
		return 0;
	}
	perform_hanoi(_n - 1, _src, _temp, _dst); //내 위의 것들이 사라짐
	//제일 넒은 판일 목적지로 유유히 이동
	printf("%d원판을 %c에서 %c로 이동\n", _n, _src, _dst);
	perform_hanoi(_n - 1, _temp, _dst, _src);
}

int main() {

	//n : 원판이 몇 개 있나
	//'A' : src : 출발지
	//'C' : dst : 목적지
	//'B' : temp : 임시거처지
	perform_hanoi(n, 'A', 'B', 'C');


	return 0;
}
*/
/*
struct A {
	int a;
	float b;
};

typedef struct {
	int a;
	float b;
}A1;

struct C {
	struct A member1;
	A1 member2;
};

int main(void) {

	struct A k1;
	A1 k2;
	struct C k3; // 구조체 안에 구조체 넣기
	k1.a = 10;
	k1.b = 1.0;
	k2.a = 20;
	k2.b = 2.0;
	k3.member1.a - 10;
	k3.member2.a = 20;
	return 0;
}
*/

//다항식을 표현하는 방법
//배열에 계수를 저장
//최대 차수에 대한 정보를 저장
//coefficient == 계수
/*
int amx_degree = 2;
int coef[100] = { 0 }; // 계수만 저장.

struct POLY {
	int max_degree;
	int coef[100];
};

void showPolynomial(struct POLY _n) {

	// 계수, x, ^, 차수 +....

	for (int i = _n.max_degree; i >= 0; i--) {
		printf("%d * x ^ %d", _n.coef[i], i);
		if(i > 0)printf(" + ");
	}
	printf("\n");
	return;
}

int main() {
	// (2 * x ^ 2) + (3 * x) + 1
	struct POLY p1 = { 2,{1,3,2} };
	// 2 * x + 7
	struct POLY p2 = { 1,{7,2} };

	//p1 + p2
	// 2*x^2 + 5*x + 8
	showPolynomial(p1);
	showPolynomial(p2);
	return 0;
}
*/

//1번 문제
/*
struct POLY {
	int max_degree;
	int coef[100];
};

struct TERM {
	int coef;
	int degree;
};

struct ePOLY {
	int vaild_num;
	struct TERM terms[100];
};
//	struct ePOLY p3 = { 3,{{2,3},{3,1},{1,0}} };

void showEfficientPoly(struct ePOLY _p) {

	for (int i = 0; i < _p.vaild_num;i++) {
		printf("%d * x ^ %d", _p.terms[i].coef, _p.terms[i].degree);
		if (_p.terms[i].degree > 0)printf(" + ");
	}
	printf("\n");
	return;
}

void showPolynomial(struct POLY _n) {

	// 계수, x, ^, 차수 +....

	for (int i = _n.max_degree; i >= 0; i--) {
		printf("%d * x ^ %d", _n.coef[i], i);
		if (i > 0)printf(" + ");
	}
	printf("\n");
	return;
}

struct POLY addPoly(struct POLY _p1, struct POLY _p2) {
	struct POLY _return;
	if (_p1.max_degree > _p2.max_degree)_return.max_degree = _p1.max_degree;
	else _return.max_degree = _p2.max_degree;
	for (int i = _return.max_degree; i >= 0;i--) {
		_return.coef[i] = _p1.coef[i] + _p2.coef[i];
	}
	return _return;
}
struct ePOLY addEfficientPoly(struct ePOLY _p1, struct ePOLY _p2) {
	struct ePOLY _return;
	int arr[100] = { 0 }, cnt = 0,idx = 0;
	for (int i = 0; i < _p1.vaild_num; i++) {
		arr[_p1.terms[i].degree] += _p1.terms[i].coef;
	}
	for (int i = 0; i < _p2.vaild_num; i++) {
		arr[_p2.terms[i].degree] += _p2.terms[i].coef;
	}
	for (int i = 0; i < 100; i++) {
		if (arr[i] != 0)cnt++;
	}
	_return.vaild_num = cnt;
	for (int i = _p1.vaild_num + _p2.vaild_num - 1; i >= 0; i--) {
		if (arr[i] != 0) {
			_return.terms[idx].coef = arr[i];
			_return.terms[idx++].degree = i;
		}
	}
	return _return;
}

int main() {
	// (2 * x ^ 2) + (3 * x) + 1
	struct POLY p1 = { 2,{1,3,2} };
	// 2 * x + 7
	struct POLY p2 = { 1,{7,2} };

	struct ePOLY p3 = { 3,{{2,3},{3,1},{1,0}} };
	struct ePOLY p6 = { 2,{{6,2},{9,0}} };

	struct POLY p4 = addPoly(p1, p2);

	struct ePOLY p5 = addEfficientPoly(p3, p6);
	showEfficientPoly(p5);
	return 0;
}
*/


/*
//2차원 배열을 이용한 matrix 표현

// 전역변수로 배열표현
// 5 x 5

#define ROWS 5 // macro definition
#define COLS 5

int mat[ROWS][COLS] = { 
	{1,1,1,1,1},
	{2,2,2,2,2},
	{3,3,3,3,3},
	{4,4,4,4,4},
	{5,5,5,5,5} };

//transpose된 행렬이 저장되는 곳.
int tr_mat[COLS][ROWS] = { 0 };

// 행열의 값을 행우선으로 출력해주는 함수
//_rows = 행의 갯수
//_cols = 열의 갯수
// _rows X _cols 행렬을 출력한다.

void showMatrix(int *_mat, int _rows, int _cols) {
	for (int _r = 0; _r < _rows; _r++) {
		for (int _c = 0; _c < _cols; _c++) {
			printf("%d ", *(_mat + _r * COLS + _c));
		}
		printf("\n");
	}
}

//void showMatrix(int _mat[][5], int _rows, int _cols) {
//	for (int _r = 0; _r < _rows; _r++) {
//		for (int _c = 0; _c < _cols; _c++) {
//			printf("%d ", mat[_r][_c]);
//		}
//		printf("\n");
//	}
//}

void transpose_matrix(int * src, int * tgt, int _rows,int _cols) {
	for (int _r = 0; _r < _rows; _r++) {
		for (int _c = 0; _c < _cols; _c++) {
			*(tgt + _c * ROWS + _r) = *(src + _r * COLS + _c);
			// write                     //read
		}
	}
}

int main() {

	showMatrix(mat, ROWS, COLS);
	transpose_matrix(mat,tr_mat,ROWS, COLS);
	showMatrix(tr_mat,ROWS,COLS);

	return 0;
}

*/

//10 x 10
//(0, 0, 11)
//(7, 3, 12)

struct element { // 각 행렬의 요소를 저장하는 구조체
	int row;
	int col;
	int value;
};

struct sparse_mat {
	struct element e[10];
	int rows;
	int cols;
	int num;
};

//void showMatrix(struct sparse_mat _m) {
//	int cnt = 0;
//	for (int i = 0; i < _m.rows; i++) {
//		for (int j = 0; j < _m.cols; j++) {
//			if (_m.e[cnt].row == i && _m.e[cnt].col == j) {
//				printf("%d ", _m.e[cnt++].value);
//			}
//			else {
//				printf("0 ");
//			}
//		}
//		printf("\n");
//	}
//
//}

void showMatrix(struct sparse_mat _m) {
	for (int i = 0; i < _m.rows; i++) {
		for (int j = 0; j < _m.cols; j++) {
			int flag = 0;
			for (int k = 0; k < _m.num; k++) {
				if (_m.e[k].row == i && _m.e[k].col == j) {
					printf("%d ", _m.e[k].value);
					flag = 1;
					break;
				}
			}
			if (!flag) {
				printf("0 ");
			}
		}
		printf("\n");
	}

}


int main() {

	struct sparse_mat kmat;
	kmat.rows = 10;
	kmat.cols = 10;
	kmat.num = 2;

	//kmat.e[0] = {0,0,11}  // 구조체를 선언할 때는 가능하나 선언 끝나면 불가능함.

	kmat.e[0].row = 0;
	kmat.e[0].col = 0;
	kmat.e[0].value = 11;

	kmat.e[1].row = 7;
	kmat.e[1].col = 3;
	kmat.e[1].value = 12;

	showMatrix(kmat);

	return 0;
}

//m에서의 행과 열의 개수를 뽑아낸다.
// row = m.rows, col = m.cols
//m에서 유효한 요소의 개수를 뽑아낸다.
//valid = m.num
//nested for-loop 수행하기
//찍을 위치를 결정
//(r,c)에 유호한 값이 있나?
//있다고 하면 출력
//없다고 하면 0출력