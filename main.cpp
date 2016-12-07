#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <functional>

class solution {
public:
    std::vector<int> productExceptSelf(const std::vector<int> & nums) {
	std::vector<int> left, right;
	std::partial_sum(nums.begin(), nums.end(), std::inserter(left, left.begin()), std::multiplies<int>());
	std::transform(left.begin(), left.end(), nums.begin(), left.begin(),
		       [](int i, int j){
			   return i/j;
		       });
	std::cout << "Left product:\n";
	std::copy(left.begin(), left.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	
	std::partial_sum(nums.rbegin(), nums.rend(), std::inserter(right, right.begin()), std::multiplies<int>());
	std::reverse(right.begin(), right.end());
	std::transform(right.begin(), right.end(), nums.begin(), right.begin(),
		       [](int i, int j){
			   return i/j;
		       });
	std::cout << "Right product:\n";
	std::copy(right.begin(), right.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	std::vector<int> product;
	std::transform(left.begin(), left.end(), right.begin(), std::inserter(product, product.begin()),std::multiplies<int>());
	std::cout << "Product except self:\n";
	std::copy(product.begin(), product.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	return product;
    }
};

int main() {
    std::vector<int> nums{1,2,3,4};

    solution soln;
    auto prod = soln.productExceptSelf(nums);
}
