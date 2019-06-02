var findSubstring = function (s, words) {
  if (words.length <= 0) return [];
  let wordLength = words[0].length;
  if (s.length < wordLength * words.length) return [];

  let dict = {}, result = [];
  for (let i = 0; i < words.length; i++) {
    let word = words[i];
    if (dict[word]) dict[word]++;
    else dict[word] = 1;
  }
  outer: for (let i = 0; i <= (s.length - wordLength * words.length); i++) {
    let copyDict = {
      ...dict
    };
    for (let j = 0; j < wordLength * words.length; j = j + wordLength) {
      let current = s.substr(j + i, wordLength);
      if (copyDict[current]) copyDict[current]--;
      else continue outer;
    }
    result.push(i);
  }
  return result;
}

console.log(findSubstring("wordgoodgoodgoodbestword", ["word","good","best","good"]))