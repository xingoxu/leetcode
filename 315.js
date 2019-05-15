// O(n^2)
// TODO: should be written in O(nlogn)

var countSmaller = function (nums) {
  let result = [];
  for (let i = (nums.length - 1); i >= 0; i--) {
    let count = 0;
    for (let j = i; j < nums.length; j++) {
      if (nums[j] < nums[i]) {
        count++;
      }
    }
    result.unshift(count);
  }
  return result;
};

console.log(countSmaller([5, 2, 6, 1]));