let matchCache = {};
function isMatch(t, p) {
  matchCache = {};
  return _isMatch(t, 0, p, 0);
}

function _isMatch(text, tStart, pattern, pStart) {
  if (pattern == '') return text == '';
  if (pStart >= pattern.length) return tStart >= text.length;

  if (matchCache[`${tStart}-${pStart}`])
    return matchCache[`${tStart}-${pStart}`];

  let first_match = (text != '' && tStart < text.length &&
    (pattern[pStart] == text[tStart] || pattern[pStart] == '.'));

  if ((pattern.length - pStart) >= 2 && pattern[pStart + 1] == '*') {
    matchCache[`${tStart}-${pStart}`] = (_isMatch(text, tStart, pattern, pStart + 2) ||
      (first_match && _isMatch(text, tStart + 1, pattern, pStart)));
    return matchCache[`${tStart}-${pStart}`];
  } else {
    matchCache[`${tStart}-${pStart}`] = first_match && _isMatch(text, tStart + 1, pattern, pStart + 1);
    return matchCache[`${tStart}-${pStart}`];
  }
}

console.log(isMatch('abc', 'ab*cc'));




// try to use DST to match
// but failed

// function computeArray(s) {
//   let result = [];
//   let step = 0;
//   for (let i = 0; i < s.length; i++) {
//     result.push({});
//     if (s[i] == '.') {
//       result[step].default = step + 1;
//     } else if (s[i] == '*') {
//       step--;
//       if (s[i - 1] == '.') {
//         result[step].default = step;
//       } else {
//         result[step][s[i - 1]] = step;
//         result[step].default = 0;
//       }
//       if (s[i + 1] && s[i + 1] != '.') {
//         result[step][s[i + 1]] = step + 1;
//         i++;
//       }
//     } else {
//       result[step][s[i]] = step + 1;
//       result[step].default = 0;
//     }
//     step++;
//   }
//   console.log(step);
//   return result;
// }



// console.log(computeArray('b.*bc')); // bbbbbbc
// // console.log(computeArray('ba*b*c*b')); // bbbbbb