var divide = function(dividend, divisor) {
  let isDividendMinus = dividend < 0;
  let isDivisorMinus = divisor < 0;
  isDividendMinus && (dividend = 0 - dividend);
  isDivisorMinus && (divisor = 0 - divisor);

  let divisor8 = divisor + divisor + divisor + divisor + divisor + divisor + divisor + divisor;

  let result = 0;
  while (dividend >= divisor8) {
    dividend -= divisor8;
    result+=8;
  }
  while (dividend >= divisor) {
    dividend -= divisor;
    result += 1;
  }
  let needMinus = (isDividendMinus ^ isDivisorMinus) ? -1 : 1;
  result = result * needMinus;
  if (result > 2147483647) result = 2147483647;
  if (result < -2147483648) result = -2147483648;
  return result;
};

console.log(divide(2147483647,1));