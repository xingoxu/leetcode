var cache = {};
/**
* @param {string} word1
* @param {string} word2
* @return {number}
*/
var minDistance = function (word1, word2) {
  cache = {};
  return _minDistance(word1, word2, word1.length - 1, word2.length - 1);
};
var _minDistance = function (word1, word2, iterator1, iterator2) {
  if (iterator1 < 0 || iterator2 < 0) {
    let result = Math.abs(iterator1 - iterator2);
    cache[`${iterator1}-${iterator2}`] = result;
    return result;
  }
  if (cache[`${iterator1}-${iterator2}`]) return cache[`${iterator1}-${iterator2}`];

  let resultEquals = _minDistance(word1, word2, iterator1 - 1, iterator2 - 1);

  if (word1[iterator1] == word2[iterator2]) {
    cache[`${iterator1}-${iterator2}`] = resultEquals;
    return resultEquals;
  } else {
    let a = _minDistance(word1, word2, iterator1 - 1, iterator2);
    let b = _minDistance(word1, word2, iterator1, iterator2 - 1);
    let result = Math.min(a, b, resultEquals);
    cache[`${iterator1}-${iterator2}`] = result + 1;
    return result + 1;
  }
};

console.log(minDistance("sea", "eat"));