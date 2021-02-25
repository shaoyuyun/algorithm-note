# 数组乱序 - 洗牌算法

从最后一个元素开始，从数组中随机选出一个位置，交换，直到第一个元素。

```js
function disorder(array) {
    const length = array.length
    let current = length - 1
    let random
    while (current > -1) {
        random = Math.floor(length * Math.random())
        [array[current], array[random]] = [array[random], array[current]]
        current--
    }
    return array
}
```

## Fisher – Yates

原理很简单，就是遍历数组元素，然后将当前元素与以后随机位置的元素进行交换，从代码中也可以看出，这样乱序的就会更加彻底。

### JavaScript 实现
```js
function shuffle(a) {
    var j, x, i
    for (i = a.length; i; i--) {
        j = Math.floor(Math.random() * i)
        x = a[i - 1]
        a[i - 1] = a[j]
        a[j] = x
    }
    return a
}
```

### ES6 实现
```js
function shuffle(a) {
    for (let i = a.length; i; i--) {
        let j = Math.floor(Math.random() * i)
        [a[i - 1], a[j]] = [a[j], a[i - 1]]
    }
    return a
}
```
