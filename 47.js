var permuteUnique = function (nums) {
  if (nums.length === 0) return [[]];
  if (nums.length === 1) return [[nums[0]]];
  var result = [];
  var unique = [];
  for (var i = 0; i < nums.length; i++) {
    if (unique.indexOf(nums[i]) >= 0) {
      continue;
    } else {
      unique.push(nums[i]);
    }
    result = result.concat(permuteUnique(nums.filter((num, filterIndex) => filterIndex != i)).map(result => [nums[i]].concat(result)));
  }
  return result;
};