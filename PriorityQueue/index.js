const Queue = require('./PriorityQueue.js');

var queue = new Queue();
queue.enqueue(5, 24);
queue.enqueue(5, 32);
queue.enqueue(3, 16);
queue.enqueue(3, 45);
queue.enqueue(1, 20);
queue.enqueue(1, 53);
queue.enqueue(2, 14);
queue.enqueue(2, 27);

queue.print();
queue.draw();

while (queue.hasData()) {
    var result = queue.dequeue();
    console.log(result[0] + "[" + result[1] + "]");
}