/* 本节实现COO到CSR的转换
 * 	COO是一个简单的`val`,`row`,`col`三数组
 *	CSR是有`val`,`col`,`row_ptr`
 *
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
}
