# 字符串

## 字符串的基本应用

### 替换空格

请实现一个函数，将一个字符串中的每个空格替换成"`%20`"。例如，当字符串为`We Are Happy`，则经过替换之后的字符串为`We%20Are%20Happy`。

```js
function replaceSpace(str) {
    return str.split(' ').join('%20')
}
function replaceSpace2(str) {
    return str.replace(/\s/g, '%20')
}
```

### 拓展

允许出现多个空格，多个空格用一个`%20`替换

```js
function replaceSpace(str) {
    return str.replace(/\s+/g, '%20')
}
```

### 字符串翻转

```js
function reverseSentence(str) {
    return str.split(' ').reverse().join(' ')
}
```

### 左旋转字符串

字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。比如输入字符串"`abcdefg`"和数字`2`，该函数将返回左旋转2位得到的结果"`cdefgab`"。

将两个str进行拼接，直接从第n位开始截取，就相当于将前面n个数字移到末尾。

```js
function leftRotateString(str, n) {
    if (str && n !== null) {
        return (str + str).substr(n, str.length)
    } else {
        return ''
    }
}
```


