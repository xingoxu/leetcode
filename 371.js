// Runtime: 52 ms, faster than 65.10% of JavaScript online submissions for Sum of Two Integers.
// Memory Usage: 33.9 MB, less than 20.00% of JavaScript online submissions for Sum of Two Integers.

var getSum = function (a, b) {
  let result = [], reverse = false, upBit = 0;
  if (a < 0 && b < 0) {
    reverse = true;
    a = -a, b = -b;
  } else if (b < 0) {
    let tmp = b;
    b = a;
    a = tmp;
  }
  if (a < 0 && reverse == false) {
    if ((-a) > b) {
      reverse = true;
      b = -b, a = -a;
    }
  }
  for (let i = 0; i < 32; ++i) {
    let aBit = a & 1, bBit = b & 1;
    if ((aBit ^ bBit) == 0 && (aBit | bBit) == 1) {
      result.unshift(upBit == 1 ? 1 : 0);
      upBit = 1;
    } else if (upBit == 1 && (aBit | bBit) == 1) {
      result.unshift(0);
    } else {
      result.unshift((upBit | aBit | bBit));
      upBit = 0;
    }

    a = a >> 1;
    b = b >> 1;
  }
  return parseInt(result.join(''), 2) * (reverse ? -1 : 1);
};

