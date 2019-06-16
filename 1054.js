class PriorityQueue {
  /**
   * 
   * @param {number[]} array 
   */
  constructor(array) {
    let map = {};
    array.forEach(num => {
      if (map[num])
        ++map[num];
      else
        map[num] = 1;
    });
    this._priorityQueue = Object.entries(map).sort(([keyA, timesA], [keyB, timesB]) => {
      return timesB - timesA;
    });

  }
  pop() {
    return this._priorityQueue.shift();
  }
  add([key, times]) {
    this._priorityQueue.push([key, times]);
    this._priorityQueue.sort(([keyA, timesA], [keyB, timesB]) => {
      return timesB - timesA;
    });
  }
  empty() {
    return this._priorityQueue.length == 0;
  }
}

/**
 * @param {number[]} barcodes
 * @return {number[]}
 */
var rearrangeBarcodes = function(barcodes) {
  let pq = new PriorityQueue(barcodes);
  let lastAdding, result = [];
  while (!pq.empty()) {
    let [key,times] = pq.pop();
    result.push(Number(key));
    --times;
    if (lastAdding) {
      pq.add(lastAdding);
    }
    if (times != 0)
      lastAdding = [key, times];
    else
      lastAdding = null;
  }
  if (lastAdding) {
    result.push(Number(key));
  }
  return result;
};


console.log(rearrangeBarcodes([1,1,1,2,2,2]));