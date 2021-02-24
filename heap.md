# 堆

堆在底层实际上是一颗完全二叉树，可以用数组实现
* 每个节点元素值不小于其子节点 - 最大堆
* 每个节点元素值不大于其子节点 - 最小堆

> 堆在处理某些特殊场景时可以大大降低代码的时间复杂度，例如在庞大的数据中找到最大的几个数或者最小的几个数，可以借助堆来完成这个过程。

## 堆的基本应用

### 堆的构建

#### 大顶堆

从第一个非叶子节点开始依次对数组中的元素进行下沉操作

* 和孩子节点的最大值`max`比较
* 大于`max` —— 不需要再下沉
* 小于`max` —— 和`max`交换位置 - 继续和下一层孩子节点比较，直到队列末尾

```js
function ajustMaxHeap(arrar, index, length) {
    for (let i = 2 * index + 1; i < length; i = 2 * i + 1) {
        if (i + 1 < length && array[i + 1] > array[i]) {
            i++
        }
        if (array[index] >= [array[i]]) {
            break
        } else {
            [array[index], array[i]] = [array[i], array[index]]
            index = i
        }
    }
}

function createMaxHeap(arr, length) {
    for (let i = Math.floor(length / 2) - 1; i >= 0; i--) {
        adjustMaxHeap(arr, i, length)
    }
    return arr
}
```

#### 小顶堆

从第一个非叶子节点开始依次对数组中的元素进行下沉操作

* 和孩子节点的最小值`min`比较
* 小于`min` —— 不需要再下沉
* 大于`min` —— 和`min`交换位置 - 继续和下一层孩子节点比较，直到队列末尾

```js
function ajustMinHeap(arrar, index, length) {
    for (let i = 2 * index + 1; i < length; i = 2 * i + 1) {
        if (i + 1 < length && array[i + 1] < array[i]) {
            i++
        }
        if (array[index] < [array[i]]) {
            break
        } else {
            [array[index], array[i]] = [array[i], array[index]]
            index = i
        }
    }
}

function createMinHeap(arr, length) {
    for (let i = Math.floor(length / 2) - 1; i >= 0; i--) {
        adjustMinHeap(arr, i, length)
    }
    return arr
}
```

### 堆的插入

* 由于堆属于优先队列，只能从末尾添加
* 添加后有可能破坏堆的结构，需要从上到下进行调整
* 如果元素小于父元素，上浮

以小顶堆为例：

```js
function minHeapAdd(array = [], element) {
    array.push(element)
    if (array.length > 1) {
        let index = array.length - 1
        let target = Math.floor((index - 1) / 2)
        while (target >= 0) {
            if (array[index] < array[target]) {
                [array[index], array[target]] = [array[target], array[index]]
                index = target
                target = Math.floor((index - 1) / 2)
            } else {
                break
            }
        }
    }
    return array
}
```

### 堆的移除

* 由于堆属于优先队列，只能从头部移除
* 移除头部后，使用末尾元素填充头部，开始头部下沉操作

以小顶堆为例：

```js
function minHeapPop(array = []) {
    let result = null
    if (array.length > 1) {
        result = array[0]
        array[0] = array.pop()
        ajustMinHeap(array, 0, array.length)
    } else if (array.length === 1) {
        return array.pop()
    }
    return result
}
```

### 封装

```js
function Heap(type = 'min') {
    this.type = type
    this.value = []
}

Heap.prototype.create = function() {
    const length = this.value.length
    for (let i = Math.floor((length / 2) - 1); i >= 0; i--) {
        this.adjust(i, length)
    }
}

Heap.prototype.adjust = function(index, length) {
    const array = this.value
    for (let i = 2 * index + 1; i < length; i = 2 * i + 1) {
        if (i + 1 < length) {
            if ((this.type === 'max' && array[i + 1] > array[i]) || (this.type === 'min' && array[i + 1] < array[i])) {
                i++
            }
        }
        if ((this.type === 'max' && array[index] < array[i]) || (this.type === 'min' && array[index] > array[i])) {
            [array[index], array[i]] = [array[i], array[index]]
            index = i
        } else {
            break
        }
    }
}

Heap.prototype.add = function(element) {
    const array = this.value
    array.push(element)
    if (array.length > 1) {
        let index = array.length - 1
        let target = Math.floor((index - 1) / 2)
        while (target >= 0) {
            if ((this.type === 'max' && array[index] > array[target]) || (this.type === 'min' && array[index] < array[target])) {
                [array[index], array[target]] = [array[target], array[index]]
                index = target
                target = Math.floor((index - 1) / 2)
            } else {
                break
            }
        }
    }
}

Heap.prototype.pop = function() {
    const array = this.value
    let result = null
    if (array.length > 1) {
        result = array[0]
        array[0] = array.pop()
        this.adjust(0, array.length)
    } else if (array.length === 1) {
        return array.pop()
    }
    return result
}

var heap = new Heap('max')
heap.add(6)
heap.add(10)
console.log(heap.value)
console.log(heap.pop())
console.log(heap.value)
```
