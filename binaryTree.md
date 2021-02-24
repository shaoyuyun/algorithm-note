# 二叉树

树是用来模拟具有树状结构性质的数据集合。根据它的特性可以分为非常多的种类，对于我们来讲，掌握二叉树这种结构就足够了，它也是树最简单、应用最广泛的种类。  
二叉树是一种典型的树树状结构。如它名字所描述的那样，二叉树是每个节点最多有两个子树的树结构，通常子树被称作“左子树”和“右子树”。

## 二叉树的基本操作

### 基本结构

插入、遍历、深度

```js
function Node(data, left, right) {
    this.data = data
    this.left = left
    this.right = right
}

Node.prototype = {
    show: function() {
        console.log(this.data)
    }
}

function Tree() {
    this.root = null
}

Tree.prototype = {
    insert: function(data) {
        var node = new Node(data, null, null)
        if (!this.root) {
            this.root = node
            return
        }
        var current = this.root
        var parent = null
        while(current) {
            parent = current
            if (data < parent.data) {
                current = current.left
                if (!current) {
                    parent.left = node
                    return
                }
            } else {
                current = current.right
                if (!current) {
                    parent.right = node
                    return
                }
            }
        }
    },
    preOrder: function(node) {
        if (node) {
            node.show()
            this.preOrder(node.left)
            this.preOrder(node.right)
        }
    },
    middleOrder: function(node) {
        if (node) {
            this.middleOrder(node.left)
            node.show()
            this.middleOrder(node.right)
        }
    },
    laterOrder: function(node) {
        if (node) {
            this.laterOrder(node.left)
            this.laterOrder(node.right)
            node.show()
        }
    },
    getMin: function() {
        var current = this.root
        while(current) {
            if (!current.left) {
                return current
            }
            current = current.left
        }
    },
    getMax: function() {
        var current = this.root
        while(current) {
            if (!current.right) {
                return current
            }
            current = current.right
        }
    },
    getDeep: function(node, deep = 0) {
        if (node === null) {
            return deep
        }
        deep++
        var dLeft = this.getDeep(node.left, deep)
        var dRight = this.getDeep(node.right, deep)
        return Math.max(dLeft, dRight)
    },
    getNode: function(data, node) {
        if (node) {
            if (data === node.data) {
                return node
            } else if (data < node.data) {
                return this.getNode(data, node.left)
            } else if (data > node.data) {
                return this.getNode(data, node.right)
            }
        } else {
            return null
        }
    }
}
```

```js
var t = new Tree()
var arr = [3, 8, 1, 2, 5, 7, 6, 0]
arr.forEach(node => {
    t.insert(node)
})
console.log(t)
t.middleOrder(t.root)
console.log(t.getMin(), t.getMax())
console.log(t.getDeep(t.root, 0))
console.log(t.getNode(5, t.root))
```

#### 二分查找

二分查找的必须是有序的线性表  
和线性表的中点值进行比较，如果小就继续在小的序列中查找，如果大就在大的序列中查找，如此递归直到找到相同的值返回

```js
function binarySearch(data, arr, start, end) {
    if (start > end) {
        return -1
    }
    var mid = Math.floor((start + end) / 2)
    if (data === arr[mid]) {
        return mid
    } else if (data < arr[mid]) {
        return binarySearch(data, arr, start, mid - 1)
    } else if (data > arr[mid]) {
        return binarySearch(data, arr, mid + 1, end)
    }
}
var arr = [0, 1, 1, 1, 2, 3, 5, 6, 8, 12, 23, 23, 25]
console.log(binarySearch(23, arr, 0, arr.length - 1))
```

## 二叉树的遍历

### 二叉树的中序遍历

示例：

输入：`[1, null, 2, 3]`  
输出：`[1, 3, 2]`

#### 递归实现

```js
var inorderTraversal = function(root, array = []) {
    if (root) {
        inorderTraversal(root.left, array)
        array.push(root.val)
        inorderTraversal(root.right, array)
    }
    return array
}
```

### 二叉树的前序遍历

示例：

输入：`[1, null, 2, 3]`  
输出：`[1, 3, 2]`

#### 递归实现

```js
var preorderTraversal = function(root, array = []) {
    if (root) {
        array.push(root.val)
        preorderTraversal(root.left, array)
        preorderTraversal(root.right, array)
    }
    return array
}
```

### 二叉树的后序遍历

示例：

输入：`[1, null, 2, 3]`  
输出：`[1, 3, 2]`

#### 递归实现

```js
var postorderTraversal = function(root, array = []) {
    if (root) {
        postorderTraversal(root.left, array)
        postorderTraversal(root.right, array)
        array.push(root.val)
    }
    return array
}
```
