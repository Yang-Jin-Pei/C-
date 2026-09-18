/* 本节实现COO到CSR的转换
 * 	COO是一个简单的`val`,`row`,`col`三数组
 *	CSR是有`val`,`col`,`row_ptr`
 * 先假设面对的是COO按照顺序的填充
 *
 *
 */
#include<iostream>
#include<vector>
struct CSR {
        int n_div = 0;
        std::vector<double> val;
        std::vector<int> col;
        std::vector<int> row_ptr;
};

struct COO {
	int n_div = 0; 
	std::vector<double> val;
	std::vector<int> col;
	std::vector<int> row;
};

CSR trans1 (const COO& A_COO) {
	// 确定矩阵维度，非零元素数量
	int ndiv = A_COO.n_div;
	int nnz = A_COO.val.size();
	
	// 初始化CSR
	CSR A_CSR;
	A_CSR.n_div = A_COO.n_div;
	A_CSR.val.assign(nnz,0.0);
	A_CSR.col.assign(nnz,0);
	A_CSR.row_ptr.assign(ndiv+1,0);

	// 统计每行有多少个非零元素
	std::vector<int> count(ndiv,0);
	for (int i = 0; i < nnz; ++i) {
       		++count[A_COO.row[i]];
	}

	// 设置row_ptr
	for (int i = 0; i < ndiv; ++i) {
		A_CSR.row_ptr[i + 1] = A_CSR.row_ptr[i] + count[i];
	}

	// 设置列和数值，这两个是一一对应
	std::vector<int> cursor = A_CSR.row_ptr; // 指向下一个未填充数字 
	for (int i = 0; i < nnz; ++i) {
		int r = A_COO.row[i];	// 找到元素矩阵中非零元素i所在行
		int dst = cursor[r]++;
		A_CSR.val[dst] = A_COO.val[i];
		A_CSR.col[dst] = A_COO.col[i];
	}
	return A_CSR;
}

int main () {
	COO A_COO{3, {1, 3, 5, 7},{0,1,2,1},{0,2,1,0}};
	CSR A_CSR = trans1(A_COO);
	// COO输出：
	std::cout << "COO数值为：" << std::endl;
	for (const auto& i : A_COO.val) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
	std::cout << "COO列为：" << std::endl;
	for (const auto& i : A_COO.col) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
	std::cout << "COO行为：" << std::endl;
	for (const auto& i : A_COO.row) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
	// CSR输出：
	std::cout << "CSR数值为：" << std::endl;
	for (const auto& i : A_CSR.val) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
	std::cout << "CSR列为：" << std::endl;
	for (const auto& i : A_CSR.col) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
	std::cout << "CSR行指向为：" << std::endl;
	for (const auto& i : A_CSR.row_ptr) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
}
