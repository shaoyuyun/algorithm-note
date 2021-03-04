# 前端跳槽面试必备技巧

## 一面/二面

### 页面布局

假设高度已知，请写出三栏布局，其中左栏、右栏宽度为`300px`，中间自适应

#### 浮动解决

```css
.left {
	float: left;
	width: 300px;
}
.right {
	float: right;
	width: 300px;
}
.center {
	background: red;
}
```

#### 绝对定位

```css
.left {
	position: absolute;
	left: 0;
	width: 300px;
}
.right {
	position: absolute;
	right: 0;
	width: 300px;
}
.center {
	position: absolute;
	left: 300px;
	right: 300px;
	background: red;
}
```

#### Flex

```css
.parent {
	display: flex;
}
.left {
	width: 300px;
}
.right {
	width: 300px;
}
.center {
	flex: 1; // flex: 1 1 0;
	background: red;
}
```

#### Table

```css
.parent {
	display: table;
}
.left {
	display: table-cell;
	width: 300px;
}
.right {
	display: table-cell;
	width: 300px;
}
.center {
	display: table-cell;
	background: red;
}
```

#### Grid

```css
.parent {
	display: grid;
	grid-template-rows: 100px;
	grid-template-columns: 300px auto 300px;
}
.left {
	width: 300px;
}
.right {
	width: 300px;
}
.center {
	background: red;
}
```

---

### 盒模型

谈谈你对盒模型的认识

#### 分类

标准模型（`bos-sizing: content-box;`）：`width = content.width` （不包含`border`和`padding`）

IE模型（`bos-sizing: border-box;`）：`width = content.width + border + padding`

#### CSS 如何设置这两种盒模型

`bos-sizing: content-box;`

`bos-sizing: border-box;`

#### JS 如何获取盒模型的宽高

`dom.style.width/height`

`dom.currentStyle.width/height`

`window.getComputedStyle(dom).width/height`

`dom.getBoundingClientRect().width/height`

---

### BFC

#### 概念

`BFC（Block Formatting Context）`：块级格式化上下文，里面的元素不会影响外面的，外面的也不会影响里面的

#### 原理

BFC 会参与子元素宽高计算

#### 如何创建 BFC

根元素

`position: absolute/fixed;`

`display: inline-block/table;`

`float != none`

`overflow != visible`

#### BFC 的使用场景

浮动撑开高度

阻止浮动覆盖

解决边距重叠

---

### DOM

#### DOM 事件级别

DOM0: `element.onclick = function(){}`

DOM2: `element.addEventListener('click', function(){})`

DOM3: `element.addEventListener('keyup', function(){}) // 相比 DOM2 只是多了更多事件类型`

#### DOM 事件流

捕获（`addEventListener`第三个参数为`true`） -> 目标 -> 冒泡

#### 描述 DOM 事件捕获的具体流程

`window` -> `document` -> `html(document.documentElment)` -> `body` -> ... -> `e.target`(目标元素，`e.currentTarget`是绑定事件的元素)

#### Event 对象的常见应用

`event.preventDefault()`

`event.stopPropagation() // 若目标元素绑定了俩事件，这个只能阻止冒泡的而不能阻止第二个`

`event.stopImmediatePropagation() // 若目标元素绑定了俩事件，则这个能全部阻止掉包括自身俩和冒泡`

`event.currentTarget // 事件绑定的元素`

`event.target // 事件触发的元素`

#### 自定义事件

```js
var eve = new Event('myEvent', {
	bubbles: true,
	cancelable: true,
	composed: true // 事件是否会触发shadow DOM（阴影DOM）根节点之外的事件监听器 默认 false
})
document.addEventListener('myEvent', function(){})
document.dispatchEvent(eve)
```

```js
var eve = new CustomEvent('myCustomEvent', {
	detail: {}, // 自定义事件的自定义数据
	bubbles: true,
	cancelable: true,
	composed: true // 事件是否会触发shadow DOM（阴影DOM）根节点之外的事件监听器 默认 false
})
document.addEventListener('myCustomEvent', function(){})
document.dispatchEvent(eve)
```

---

### HTTP 协议类

#### HTTP 协议的主要特点

简单快速（想要访问啥资源直接输入 URL 即可）、灵活（HTTP 头部有个数据类型，可传输不同数据）、无连接（连接一次就会断开，不会保持连接）、无状态（第一次请求断开后第二次请求服务器并不能记住状态）

#### HTTP 报文的组成部分

请求报文：

请求行：包括请求方法、请求的`url`、`HTTP`协议及版本  
请求头：一大堆的键值对  
空行：当服务器在解析请求头的时候，如果遇到了空行，则表明，后面的内容是请求体  
请求体：数据部分  

响应报文：

状态行：`HTTP`协议及版本、状态码及状态描述  
响应头  
空行  
响应体  

#### HTTP 方法

GET：获取资源  
POST：传输资源  
PUT：更新资源  
DELETE：删除资源  
HEAD：获得报文首部  

#### GET 和 POST 的区别

有一点要强调，get是相对不隐私的，而post是相对隐私的。

我们大概要记住以下几点：

浏览器在回退时，get 不会重新请求，但是post会重新请求。【重要】  
get请求会被浏览器主动缓存，而post不会。【重要】  
get请求的参数，会报保留在浏览器的历史记录里，而post不会。做业务时要注意。为了防止CSRF攻击，很多公司把get统一改成了post。  
get请求在url中传递的参数有大小限制，基本是2kb，不同的浏览器略有不同。而post没有注意。  
get的参数是直接暴露在url上的，相对不安全。而post是放在请求体中的。  

#### HTTP 状态码

1xx：指示信息——表示请求已收到，继续处理
2xx：成功——表示请求已成功接收
3xx：重定向——表示要完成请求必须做进一步处理
4xx：客户端错误——表示请求有语法错误或者请求无法实现
5xx：服务器错误——表示服务器未能实现合法请求

200：成功。
206：range指的是请求的范围，客户端只请求某个大文件里的一部分内容。比如说，如果播放视频地址或音频地址的前面一部分，可以用到206。
301：重定向（永久）。
302：重定向（临时）。
304：我这个服务器告诉客户端，你已经有缓存了，不需要从我这里取了。
400和401用的不多，未授权。
403指的是请求被拒绝。
404指的是资源不存在。

#### 什么是持久化连接

轮询：HTTP 1.0中，客户端每隔很短的时间，都会对服务器发出请求，查看是否有新的消息，只要轮询速度足够快，例如1秒，就能给人造成交互是实时进行的印象。这种做法是无奈之举，实际上对服务器、客户端双方都造成了大量的性能浪费。

长连接：HTTP 1.1中，通过使用`Connection: keep-alive`进行长连接，客户端只请求一次，但是服务器会将继续保持连接，当再次请求时，避免了重新建立连接。
注意，HTTP 1.1默认进行持久连接。在一次 TCP 连接中可以完成多个 HTTP 请求，但是对每个请求仍然要单独发 header，Keep-Alive不会永久保持连接，它有一个保持时间，可以在不同的服务器软件（如Apache）中设定这个时间。

#### 什么是管线化

长连接时，默认的请求这样的：

请求1 --> 响应1 --> 请求2 --> 响应2 --> 请求3 --> 响应3

管线化就是，我把现在的请求打包，一次性发过去，你也给我一次响应回来。


---

### 原型链

创建对象有几种方法

#### 字面量

```js
var o1 = { name: 'o1' }
var o2 = new Object({ name: 'o1' })
```

#### 构造函数

```js
var M = function() {
	this.name = 'o1'
}
var o1 = new M()
```

#### Object.create()

```js
var P = { name: 'o1' }
var o1 = Object.create(P)
```

#### 原型、构造函数、实例、原型链

`构造函数.prototype` -> 原型对象（`原型对象也有.__proto__` -> 原型对象）

`new 构造函数()` -> 实例（`实例.__proto__` -> 上面的原型对象，也就是`构造函数.prototype`）

`原型对象.construct` -> 构造函数（也就是`构造函数.prototype.construct === 构造函数`）

### instanceof 原理

通过判断是否在原型链上

### new 运算符

#### new 运算符具体做了什么

1. 创建一个空对象，继承了该函数的原型
2. 构造函数被执行，上下文（`this`）指定为新实例
3. 如果构造函数返回了对象，则`new`返回该对象；如果没有返回则返回之前的对象

---

### OOP

参考[继承的实现](https://github.com/shaoyuyun/algorithm-note/blob/master/JavaScript/es5Inherit.md#%E6%89%A9%E5%B1%95)

---

### 通信类

#### 什么是同源策略及限制

协议、域名、端口

不同则跨域，不能访问 Cookie、LocalStorage、IndexDB、DOM、AJAX

#### 前后端如何通信

AJAX、Websocket、CORS

#### 如何创建 AJAX

```js
// 1. 创建连接
var xhr = new XMLHttpRequest() // new ActiveXObject('Microsoft.XMLHTTP')
// 2. 连接服务器
xhr.open('get', url, true)
// 3. 发送请求
xhr.send()
// 4. 接受请求
xhr.onreadystatechange = function(){
	if(xhr.readyState == 4){
		if(xhr.status == 200 || xhr.status == 304) {
			success(xhr.responseText)
		} else { 
			// false
			fail && fail(xhr.status)
		}
	}
}
```

#### 跨域通信的几种方式

1. JSONP
2. Hash
3. postMessage
4. WebSocket
5. CORS

---

### 安全类

#### 常见攻击类型

CSRF、XSS

#### CSRF

`CSRF（Cross-site Request Forgery）`： 跨站请求伪造，用户在已登录 A 的情况下，B 利用登录 Cookie 做不当操作

防范措施： Token 验证、Referer 验证、隐藏令牌（在 HTTP 请求头中）

#### XSS

`XSS（Cross-site Scripting）`：跨站脚本攻击，主要是注入攻击 JS 代码做不当操作

防范措施：转义内容（主要是引号、尖括号、斜杠）、白名单过滤

---

#### 算法类

参考[算法笔记](https://github.com/shaoyuyun/algorithm-note/blob/master/README.md)

## 二面/三面

### 渲染机制类

#### 什么是 DOCTYPE 及作用

`DTD（Docement Type Definition）`：文档类型定义，规定浏览器以何种类型解析文档

DOCTYPE 使用来声明稳定类型和 DTD 规范的

HTML5： `<!DOCTYPE html>`，因为 HTML5 不基于 SGML，因此不需要对 DTD 进行引用，但需要 DOCTYPE 来规定浏览器的行为

HTML4: 有严格模式和传统模式，严格模式不包括展示型和弃用的元素（比如font），传统模式包括

#### 浏览器渲染过程

HTML -> DOM Tree + CSS -> CSSOM Tree = Render Tree（Layout）-> Painting -> Displaying

#### 重排（Reflow）

当渲染树中的元素的布局（如：尺寸、位置、隐藏/状态状态）发生改变时，产生重排回流

#### 重绘（Repaint）

当渲染树中的元素外观（如：颜色）发生改变，不影响布局时，产生重绘

#### 用 CSS 实现硬件加速

硬件加速是指通过创建独立的复合图层，让GPU来渲染这个图层，从而提高性能

一般触发硬件加速的 CSS 属性有`transform`、`opacity`、`filter`

为了避免 2D 动画在开始和结束的时候的`Repaint`操作，一般使用`tranform: translateZ(0)`

---

### 运行机制类

#### 单线程

JS 是单线程的

#### 微任务和宏任务

微任务：

`process.nextTick`
`Promise`
`Object.observe`
`MutationObserver`

宏任务：

`script`
`setTimeout`
`setInterval`
`setImmediate`
`I/O`
`UI rendering`

宏任务中包括了`script`，浏览器会先执行一个宏任务，接下来有异步代码的话就先执行微任务

#### Event Loop

一次 Event Loop 顺序是这样的：

1. 执行同步代码，这属于宏任务
2. 执行栈为空，查询是否有微任务需要执行
3. 执行所有微任务
4. 必要的话渲染 UI
5. 然后开始下一轮 Event loop，执行宏任务中的异步代码

通过上述的 Event Loop 顺序可知，如果宏任务中的异步代码有大量的计算并且需要操作 DOM 的话，为了更快的响应界面响应，我们可以把操作 DOM 放入微任务中

---

### 页面性能类

#### 提升页面性能的方法

1. 资源压缩合并，减少 HTTP 请求
2. 非核心代码异步加载
3. 利用浏览器缓存
4. 使用 CDN
5. 预解析 DNS

#### 异步加载

异步加载的方式：

动态脚本加载、defer、async

异步加载的区别：

defer 是 HTML 解析完之后才执行，如果是多个则按加载顺序执行

async 是加载完后立即执行，如果是多个则与加载顺序无关

#### 浏览器缓存

##### 缓存的分类：

强缓存、协商缓存

强缓存：

Expires（相对的客户端时间，HTTP 1.0）、Cache-Control(max-age，单位秒，HTTP 1.1)

强缓存不需要请求，HTTP status code 为200

协商缓存：

Last-Modified（文件上一次修改的服务器时间）、If-Modified-Since（把时间发给服务器）

E-tag（解决了时间变了文件内容没变的加载浪费，HTTP 1.1）、If-None-Match

协商缓存在强缓存过期后使用，需要向服务端请求，如果缓存有效则 HTTP status code 为304

##### 选择合适的缓存策略：

对于大部分的场景都可以使用强缓存配合协商缓存解决，但是在一些特殊的地方可能需要选择特殊的缓存策略

对于某些不需要缓存的资源，可以使用`Cache-control: no-store`，表示该资源不需要缓存
对于频繁变动的资源，可以使用`Cache-Control: no-cache`并配合`ETag`使用，表示该资源已被缓存，但是每次都会发送请求询问资源是否更新。
对于代码文件来说，通常使用`Cache-Control: max-age=31536000`并配合策略缓存使用，然后对文件进行指纹处理，一旦文件名变动就会立刻下载新的文件

##### 使用 HTTP / 2.0：

因为浏览器会有并发请求限制，在 HTTP / 1.1 时代，每个请求都需要建立和断开，消耗了好几个 RTT 时间，并且由于 TCP 慢启动的原因，加载体积大的文件会需要更多的时间
在 HTTP / 2.0 中引入了多路复用，能够让多个请求使用同一个 TCP 链接，极大的加快了网页的加载速度。并且还支持 Header 压缩，进一步的减少了请求的数据大小

#### 预解析 DNS

`<meta http-equiv="x-dns-prefetch-control" content="on">`

`<link rel="dns-prefetch" href="//host_name_to_prefetch.com">`

---

### 错误监控类

#### 前端错误的分类

即时运行错误（代码错误）、资源加载错误

#### 错误的捕获方式

即时运行错误的捕获方式：

`try catch`、`window.onerror`

资源加载错误的捕获方式：

`object.onerro（比如img.onerror）`、`performance.getEntries()（与总资源对比）`、`Error`事件捕获（没有冒泡但是有捕获，`addEventListener('error', function(){})`）

跨域的 JS 运行错误可以捕获吗？错误提示什么？怎么处理？

默认不可以捕获，提示`Script error.`

处理：

1. 在`script`标签上增加`crossorigin`属性
2. 设置 JS 资源响应头`Access-Control-Allow-Origin: *`

#### 上报错误的基本原理

1. 采用 AJAX 上报
2. 利用 Image 对象上报（`(new Image()).src='https://baidu.com/testjk?data=xxxx'`）
