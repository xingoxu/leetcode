function computeArray(s) {
  let alphabetSet = new Set(s);
  let result = [];
  for (let i = 0; i <= s.length; i++) {
    result.push({});
    for (let a of alphabetSet) {
      let k = min(s.length + 1, i + 2);
      do {
        k = k - 1;
      } while (!isEndMatch(s.substring(0, k), `${s.substring(0, i)}${a}`))

      result[i][a] = k;
    }
  }
  return result;
}

function min(a, b) {
  return a > b ? b : a;
}

function isEndMatch(end, all) {
  if (end.length > all.length) {
    return false;
  }
  if (end.length == 0) return true;
  let endI = end.length - 1;
  let allI = all.length - 1;
  while (all[allI] == end[endI] && endI >= 0) {
    endI--;
    allI--;
  }
  return endI == -1;
}

console.log(computeArray('ababaca'));