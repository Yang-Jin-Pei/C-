/* 目标：
 *	实现采用CSR的矩阵乘法
 *
 * 原理：
 * 	y[i]的数值为y[i] += A.val[j]*x[A.col[j]]
 *	y向量的第j行数据由Ax计算，这里的i
 */
#include<iostream>
#include<vector>

struct CSR {
	int n_div = 0;
	std::vector<double> val;
	std::vector<int> col;
	std::vector<int> row_ptr;
};
void SpMV (const CSR& A, const std::vector<double>& x, std::vector<double>& y) {
	y.assign(A.n_div,0.0);
	for (int i = 0; i < A.n_div; ++i) {
		for (int j = A.row_ptr[i]; j < A.row_ptr[i+1]; ++j) {
			y[i] += A.val[j]*x[A.col[j]];
		}
	}

};

int main () {
	CSR A { 3, {1,2,3}, {0, 1, 0}, {0, 1, 2, 3}};
	std::vector<double> y;
	std::vector<double> x = {1,2,3};
	SpMV(A,x,y);
	for (const auto& yi : y) {
		std::cout << yi << std::endl;
	}
	return 0;
}
