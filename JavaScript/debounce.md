# 防抖

## 原理

防抖（`debounce`）：

不管事件触发频率多高，一定在事件触发n秒后才执行，如果你在一个事件触发的n秒内又触发了这个事件，就以新的事件时间为准，n秒后才执行。  
总之，触发完事件n秒内不再触发事件，n秒后再执行。

![防抖和节流](http://www.conardli.top/docs/%E8%8A%82%E6%B5%81%E9%98%B2%E6%8A%96.gif)

## 应用场景

### 窗口大小变化，调整样式

```js
window.addEventListener('resize', debounce(handleResize, 200))
```

### 搜索框，输入后 300ms 后搜索

```js
debounce(fetchSelectData, 300)
```

### 表单验证， 输入 1000ms 后验证

```js
debounce(validator, 1000)
```

## 实现

注意考虑两个问题：

1. 在debounce函数中返回一个闭包，这里用的普通function，里面的setTimeout则用的箭头函数，这样做的意义是让this的指向准确，this的真是指向并非debounce的调用者，而是返回闭包的调用者。
2. 对传入闭包的参数进行透传：
```js
function debounce(event, time) {
    let timer = null
    return function(...args) {
        clearTimeout(timer)
        timer = setTimeout(() => {
            event.apply(this, args)
        }, time)
    }
}
```

有时候我们需要让函数立即执行一次，再等后面条件触发后等待n秒执行，我们给debounce函数一个flag用于标识是否立即执行。  
当定时器变量timer为空时，说明是第一次执行，我们立即执行它：
```js
function debounce(event, time, flag) {
    let timer = null
    reutrn function(...args) {
        clearTimeout(timer)
        if (falg && !timer) {
            event.apply(this, args)
        }
        timer = setTimeout(() => {
            event.apply(this, args)
        }, time)
    }
}
```
