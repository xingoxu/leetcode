// or use hash function to hash char and to get O(M*N)

/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function(strs) {
  let map = {};
  for (let str of strs) {
    let key = [].slice.call(str).sort().join('');
    if (map[key]) {
      map[key].push(str);
    } else {
      map[key] = [str];
    }
  }
  return Object.values(map);
};