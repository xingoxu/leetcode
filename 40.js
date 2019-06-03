/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum2 = function (candidates, target) {
  candidates = candidates.sort((a, b) => a - b);
  return _combinationSum(candidates, target);
};

var _combinationSum = function (candidates, target) {
  let result = [];
  if (target < candidates[0]) {
    // no answer;
    return [];
  }
  if (target == candidates[0]) {
    return [[target]];
  }
  for (let i = candidates.length - 1; i >= 0; i--) {
    if (candidates[i] > target) continue;
    if (candidates[i] == candidates[i + 1]) continue;
    if (candidates[i] == target) {
      result.push([candidates[i]]);
      continue;
    }

    let childResult = _combinationSum(candidates.slice(0, i), target - candidates[i]);
    if (childResult.length <= 0) continue;
    let mapResult = childResult.map(x => x.concat([candidates[i]]));
    result = result.concat(mapResult);
  }
  return result;
}

console.log(combinationSum2([2,5,2,1,2],
  5));