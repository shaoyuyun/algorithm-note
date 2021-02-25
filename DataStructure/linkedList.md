# 链表

链表是用一组任意存储的单元来存储线性表的数据元素。一个对象存储着本身的值和下一个元素的指针。  
1. 需要遍历才能查询到元素，查询慢。
2. 插入元素只需断开链接并重新赋值，插入快。

## 链表的基本应用

### 从尾到头打印链表

遍历链表，不断找到当前节点的`next`节点，为`null`时说明是最后一个节点，停止遍历。  
因为是从尾到头的顺序，所以可以使用一个队列来存储打印结果，每次从队头插入。

```js
function ListNode(node) {
    this.val = node
    this.next = null
}

function printListFromTailToHead(head) {
    const array = []
    while (head) {
        array.unshift(head.val)
        head = head.next
    }
    return array
}
```

### 反转链表

以链表的头部节点作为基准节点，将基准节点的下一个节点挪到头部作为头结点。  
当基准节点的`next`为`null`时，则其已成为最后一个节点，链表已经反转完成。

```js
var reverseList = fnuction(head) {
    let currentNode = null
    let headNode = head
    while (head && head.next) {
        currentNode = head.next
        head.next = currentNode.next
        currentNode.next = headNode
        headNode = currentNode
    }
    return headNode
}
```

### 合并两个排序的链表

输入两个单调递增的链表，输出两个链表合并后的链表，要求此链表单调不减。

链表头部节点比较，选择较小的作为头结点。  
小节点的`next`等于小节点的`next`和大节点中小的那一个。  
如此递归。  
返回小节点。  
考虑代码的鲁棒性，也是递归的终止条件，两个`head`为`null`的情况，取对方节点返回。

```js
function Merge(pHead1, pHead2) {
    if (!pHead1) {
        return pHead2
    }
    if (!pHead2) {
        return pHead1
    }
    let head
    if (pHead1.val < pHead2.val) {
        head = pHead1
        head.next = Merge(pHead1.next, pHead2)
    } else {
        head = pHead2
        head.next = Merge(pHead1, pHead2.next)
    }
    return head
}
```

### 约瑟夫环

`0, 1, ..., n-1`这`n`个数字排成一个圆圈，从数字`0`开始，每次从这个圆圈里删除第`m`个数字。求这个圆圈里剩下的最后一个数字。

用链表模拟一个环：
1. 用链表模拟一个环
2. 模拟游戏场景
3. 记录头结点的前一个节点`current`，以保证我们找到的要删除的节点是`current.next`
4. 每次循环`m`次找到目标节点删除，直到链表只剩下一个节点
5. 时间复杂度`O(m*n)`，空间复杂度`O(n)`

```js
function LastRemaining(n, m) {
    if (n < 1 || m < 1) {
        return -1
    }
    const head = {
        val: 0
    }
    let current = head
    for (let i = 1; i < n; i++) {
        current.next = {
            val: i
        }
        current = current.next
    }
    current.next = head
    while (current.next !== current) {
        for (let i = 0; i < m - 1; i++) {
            current = current.next
        }
        current.next = current.next.next
    }
    return current.val
}
```
