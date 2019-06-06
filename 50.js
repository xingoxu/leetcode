/**
 * lots of solution
 * just want to know which one is the interviwer want me to answer the question
 */

/**
 * @param {number} x
 * @param {number} n
 * @return {number}
 */
var myPow = function(x, n) {
  if (n == 0) return 1;
  if (n == 1) return x;
  if (n < 0) {
    n = -n;
    x = 1 / x;
  }
  return n % 2 == 1 ? x * myPow(x * x, Math.floor(n / 2)) : myPow(x * x, Math.floor(n / 2));
};

console.log(myPow(2, 10));