/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum = function (candidates, target) {
  candidates = candidates.sort((a, b) => a - b);
  return _combinationSum(candidates, target, Number.MAX_VALUE);
};

var _combinationSum = function (candidates, target, previous) {
  let result = [];
  if (target < candidates[0]) {
    // no answer;
    return [];
  }
  if (target == candidates[0]) {
    return [[target]];
  }
  for (let i = candidates.length - 1; i >= 0; i--) {
    if (candidates[i] > target || candidates[i] > previous) continue;
    if (candidates[i] == target) {
      result.push([candidates[i]]);
      continue;
    }

    let childResult = _combinationSum(candidates, target - candidates[i], candidates[i]);
    if (childResult.length <= 0) continue;
    let mapResult = childResult.map(x => x.concat([candidates[i]]));
    result = result.concat(mapResult);
  }
  return result;
}
