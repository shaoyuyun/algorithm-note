#  手动实现 ES5 继承

有下面两个类，下面实现`Man`继承`People`：

```js
function People() {
    this.type = 'prople'
}

People.prototype.eat = function() {
    console.log('吃东西啦')
}

function Man(name) {
    this.name = name
    this.color = 'black'
}
```

## 原型继承

将父类指向子类的原型。

```js
Man.prototype = new People()
```

缺点：原型是所有子类实例共享的，改变一个其他也会改变。

## 构造继承

在子类构造函数中调用父类构造函数

```js
function Man(name) {
    People.call(this)
}
```

缺点：不能继承父类原型，函数在构造函数中，每个子类实例不能共享函数，浪费内存。

## 组合继承

使用构造继承继承父类参数，使用原型继承继承父类函数

```js
function Man(name) {
    People.call(this)
}

Man.prototype = People.prototype
```

缺点：父类原型和子类原型是同一个对象，无法区分子类真正是由谁构造。

## 寄生组合继承

在组合继承的基础上，子类继承一个由父类原型生成的空对象。

```js
function Man(name) {
    People.call(this)
}

Man.prototype = Object.create(People.prototype, {
    constructor: {
        value: Man
    }
})
```

## inherits 函数：

```js
function inherits(ctor, superCtor) {
    ctor.super_ = superCtor
    ctor.prototype = Object.create(superCtor.prototype, {
        constructor: {
            value: ctor,
            enumerable: false,
            writable: true,
            configurable: true
        }
    })
}
```

使用：

```js
function Man() {
    People.call(this)
    //...
}
inherits(Man, People)

Man.prototype.fun = ...
```

## 扩展

### 构造函数实现继承

```js
function Parent() {
    this.name = 'parent'
}
function Child() {
    Parent.call(this)
    this.age = 22
}
var child = new Child()
console.log(child) // Child { name: 'parent', age: 22 }

// 缺点：不能继承父类的原型
Parent.prototype.say = function() {
    console.log('say hi!')
}
console.log(child) // Child { name: 'parent', age: 22 }
```

### 原型继承

```js
function Parent() {
    this.name = 'parent'
    this.skills = ['eat', 'work', 'fly']
}
function Child() {
    this.age = 22
}
Child.prototype = new Parent()

var child = new Child()

Parent.prototype.say = function() {
    console.log('say hi!')
}

console.log(child) // Child { age: 22 }
console.log(child.name) // parent
console.log(child.say()) // say hi!

// 缺点：子类修改后会影响其他所有实例
var child2 = new Child()
child.skills.push('run')
console.log(child.skills) // ['eat', 'work', 'fly', 'run']
console.log(child2.skills) // ['eat', 'work', 'fly', 'run']
```

### 组合继承

```js
function Parent() {
    this.name = 'parent'
    this.skills = ['eat', 'work', 'fly']
}
function Child() {
    Parent.call(this) // 缺点：这里构造函数执行了一次
    this.age = 22
}
Child.prototype = new Parent() // 缺点：这里函数执行又构造了一次

var child = new Child()
Parent.prototype.say = function() {
    console.log('say hi!')
}
var child2 = new Child()
child.skills.push('run')
console.log(child.say()) // say hi!
console.log(child.skills) // ['eat', 'work', 'fly', 'run']
console.log(child2.say()) // say hi!
console.log(child2.skills) // ['eat', 'work', 'fly']
````

### 组合继承优化方式1

```js
function Parent() {
    this.name = 'parent'
    this.skills = ['eat', 'work', 'fly']
}
function Child() {
    Parent.call(this)
    this.age = 22
}
Child.prototype = Parent.prototype // 优化点：这里直接引用原型

var child = new Child()
Parent.prototype.say = function() {
    console.log('say hi!')
}
var child2 = new Child()
child.skills.push('run')
console.log(child.say()) // say hi!
console.log(child.skills) // ['eat', 'work', 'fly', 'run']
console.log(child2.say()) // say hi!
console.log(child2.skills) // ['eat', 'work', 'fly']

// 缺点：无法判断子类是由谁构造的
console.log(child instanceof Child, child instanceof Parent) // true true
console.log(child.constructor) // 指向 Parent 并不是我们想要的
````

### 组合继承优化方式2

```js
function Parent() {
    this.name = 'parent'
    this.skills = ['eat', 'work', 'fly']
}
function Child() {
    Parent.call(this)
    this.age = 22
}
Child.prototype = Object.create(Parent.prototype) // 优化点：这里用 Object.creat() 创造中间对象来隔离
Child.prototype.constructor = Child // 优化点：这里将 constructor 赋值

var child = new Child()
Parent.prototype.say = function() {
    console.log('say hi!')
}
var child2 = new Child()
child.skills.push('run')
console.log(child.say()) // say hi!
console.log(child.skills) // ['eat', 'work', 'fly', 'run']
console.log(child2.say()) // say hi!
console.log(child2.skills) // ['eat', 'work', 'fly']

// 这是最终完美版 ES5 实现的继承！
console.log(child instanceof Child, child instanceof Parent) // true false
console.log(child.constructor) // 指向 Child 完美！
```

### ES6 继承

```js
class Parent {
    constructor() {
        this.name = 'parent',
        this.skills = ['eat', 'work', 'fly']
    }
    say() {
        console.log('say hi!')
    }
}
class Child extends Parent {
    constructor() {
        super()
        this.age = 22
    }
}

var child = new Child()
var child2 = new Child()
child.skills.push('run')
console.log(child.say()) // say hi!
console.log(child.skills) // ['eat', 'work', 'fly', 'run']
console.log(child2.say()) // say hi!
console.log(child2.skills) // ['eat', 'work', 'fly']
console.log(child.constructor) // 指向 Child
```
