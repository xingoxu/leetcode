// Dynamic Programming
// TODO: find a smaller O

var longestPalindrome = function (s) {
  map = new Map();
  var x = _longestPalindrome(s, 0, s.length - 1);
  debugger;
  if (x[1] < x[0]) {
    return "";
  } else {
    return s.substring(x[0], x[1] + 1);
  }
};
var map = new Map();
function _longestPalindrome (s, start, end) {
  if (start > end) {
    return [0, 0];
  }
  let stringLength = end - start + 1;
  if (stringLength <= 1) {
    return [start, end];
  }
  if (map.get(`${start}-${end}`)) {
    return map.get(`${start}-${end}`);
  }

  let answer1 = getSingleLongestPalindrome(s, start, end - 1);
  let answer2 = getSingleLongestPalindrome(s, start + 1, end);
  let answer3 = getSingleLongestPalindrome(s, start, end);

  let max = findMax(answer1, answer2, answer3);
  // let max = answer3;
  let maxSize = max[1] - max[0];
  if (maxSize >= stringLength - 1) {
    map[`${start}-${end}`] = max;
    return max;
  }

  let left = _longestPalindrome(s, start, stringLength % 2 == 0 ? end - 2 : (end - 2 + 1));
  let right = _longestPalindrome(s, start + 2, end);
  max = findMax(max, left, right);
  // let maxSize = max[1] - max[0];
  map.set(`${start}-${end}`, max);
  return max;
}

function getSingleLongestPalindrome(s, originLeft, originRight) {
  var stringLength = originRight - originLeft + 1;
  var left = stringLength % 2 == 0 ? Math.floor(stringLength / 2) - 1 : Math.floor(stringLength / 2);
  left = originLeft + left;
  var right = stringLength % 2 == 0 ? Math.floor(stringLength / 2) : Math.floor(stringLength / 2) + 1;
  right = originRight + 1 - Math.floor(right);

  while (left >= originLeft && right <= originRight) {
    if (s[left] != s[right]) {
      let result = [left + 1, right - 1];
      return result;
    }
    left--;
    right++;
  }
  let result = [originLeft, originRight];
  return result;
}

function findMax(a, b, c)
{
  let sizeA = a[1] - a[0];
  let sizeB = b[1] - b[0];
  let sizeC = c[1] - c[0];
  return ((sizeA > sizeB ? sizeA : sizeB) > sizeC) ? (sizeA > sizeB ? a : b) : c;
}

let a = "ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg";
console.log(longestPalindrome(a));