var rearrangeBarcodes = function (barcodes) {
  return _rearrangeBarcodes(barcodes, true);
};

var _rearrangeBarcodes = function (barcodes, twice) {
  let length = barcodes.length;
  for (let i = 0; i < length - 1; i++) {
    let now = barcodes[i];
    let j = i + 1;

    if (barcodes[j] == now) {
      j = findAfter(barcodes, j);
      if (j == -1) {
        j = findBefore(barcodes, i);
      }
      twice == false && console.log(i, j);
    }

    if (j !== i + 1) {
      let temp = barcodes[j];
      barcodes[j] = barcodes[i + 1];
      barcodes[i + 1] = temp;
    }
  }

  console.log(barcodes);
  if (twice)
    _rearrangeBarcodes(barcodes, false);

  // for (let i = length - 1; i > 0; i--) {
  //   let now = barcodes[i];
  //   let j = i - 1;

  //   if (barcodes[j] == now) {
  //     j = findAfter(barcodes, i);
  //     if (j == -1) {
  //       j = findBefore(barcodes, i - 1);
  //     }
  //   }

  //   if (j !== i - 1) {
  //     let temp = barcodes[j];
  //     barcodes[j] = barcodes[i - 1];
  //     barcodes[i - 1] = temp;
  //   }
  // }

  return barcodes;
}

function findAfter(barcodes, pos) {
  let init = barcodes[pos];
  for (let i = pos + 1; i < barcodes.length; i++) {
    if (init != barcodes[i]) return i;
  }
  return -1;
}
function findBefore(barcodes, pos) {
  let init = barcodes[pos];
  for (let i = pos - 1; i >= 0; i--) {
    if (init != barcodes[i]) return i;
  }
  return -1;
}

console.log(rearrangeBarcodes([4,3,8,4,4,4,8,3,3,3]));