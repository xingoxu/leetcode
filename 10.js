function computeArray(s) {
  let result = [];
  let step = 0;
  for (let i = 0; i < s.length; i++) {
    result.push({});
    if (s[i] == '.') {
      result[step].default = step + 1;
    } else if (s[i] == '*') {
      if (s[i - 1] == '.') {
        result[step].default = step;
      } else {
        result[step].default = step + 1;
        result[step][s[i - 1]] = step;
      }
      if (s[i + 1] && s[i + 1] != '.') {
        result[step][s[i + 1]] = step + 1;
      }
    } else {
      result[step][s[i]] = step + 1;
      result[step].default = 0;
    }
    step++;
  }
  return result;
}



console.log(computeArray('a*'));