// https://leetcode.com/problems/product-of-array-except-self/
class Solution {
public:
  vector<int> productExceptSelf(vector<int>& numbers) {
    int numbersLength = (int)numbers.size();

    vector<int> products(numbersLength);
    products[numbersLength - 1] = numbers.back();
    for (int i = numbersLength - 2; i >= 0; i--) {
      products[i] = numbers[i] * products[i + 1];
    }

    int prefixProduct = 1;
    for (int i = 0; i < numbersLength; i++) {
      products[i] = prefixProduct;
      if (i < numbersLength - 1) {
        products[i] *= products[i + 1];
      }
      prefixProduct *= numbers[i];
    }

    return products;
  }
};