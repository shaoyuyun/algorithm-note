# 栈和队列

在之前的数组中，我们可以通过索引随机访问元素，但在某些情况下，我们可能需要限制数据的访问顺序，于是有了两种限制访问顺序的数据结构：栈（先进后出）、队列（先进先出）

## 栈和队列的基本操作

### 包含 min 函数的栈

定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O(1)）

1. 定义两个栈，一个用于存储数据，另一个用于存储每次数据进栈时栈的最小值
2. 每次数据进栈时，将此数据和最小值栈的栈顶元素比较，将两者比较的较小值再次存入最小值栈
3. 数据栈出栈，最小值栈也出栈
4. 这样最小值栈的栈顶永远是当前栈的最小值

以数据[3, 4, 2, 7, 9, 0]为例，让这组数字依次入栈，则栈和其对应的最小值栈如下：

* [0, 9, 7, 2, 4, 3]
* [0, 2, 2, 2, 3, 3]

```js
var dataStack = []
var minStack = []

function push(node) {
    dataStack.push(node)
    if (minStack.length === 0 || node < min()) {
        minStack.push(node)
    } else {
        minStack.push(min())
    }
}
function pop() {
    minStack.pop()
    return dataStack.pop()
}
function top() {
    var length = dataStack.length
    return length > 0 && dataStack[length - 1]
}
function min() {
    var length = minStack.length
    return length > 0 && minStack[length - 1]
}
```

### 用两个栈实现队列

用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。

栈1：

用于入队列存储

栈2：

出队列时将栈1的数据依次出栈，并入栈到栈2中  
栈2出栈即栈1的底部数据即队列要出的数据。

注意:

栈2为空才能补充栈1的数据，否则会打乱当前的顺序。

```js
const stack1 = []
const stack2 = []

function push(node) {
    stack1.push(node)
}
function pop() {
    if (stack2.length === 0) {
        while (stack1.length > 0) {
            stack2.push(stack1.pop())
        }
    }
    return stack2.pop() || null
}
```

### 扩展：用两个队列实现一个栈

```js
const queue1 = []
const queue2 = []

function push(x) {
    if (queue1.length === 0) {
        queue1.push(x)
        while (queue2.length) {
            queue1.push(queue2.shift())
        }
    } else if (queue2.length === 0) {
        queue2.push(x)
        while (queue1.length) {
            queue2.push(queue1.shift())
        }
    }
}
function pop() {
    if (queue1.length !== 0) {
        return queue1.shift()
    } else {
        return queue2.shift()
    }
}
```
