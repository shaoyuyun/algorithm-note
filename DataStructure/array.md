# 数组

## 数组的基本应用

### 两数之和

给定一个整数数组`nums`和一个目标值`target`，请你在该数组中找出和为目标值的那两个整数，并返回他们的数组下标。  
你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例：

```js
给定 nums = [2, 7, 11, 15], target = 9

因为 num[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
```

可以考虑使用一个`map`将遍历过的数字存起来，值作为`key`，下标作为值。

对于每次遍历：
1. 在`map`中查找是否有`key`为`target - nums[i]`的值
2. 如果取到了，返回
3. 如果没取到，将当前值作为`key`，下标作为值存入`map`

时间复杂度：`O(n)`，空间复杂度：`O(n)`

```js
var twoSum = function(nums, target) {
    let map = new Map()
    if (Array.isArray(nums)) {
       for (let i = 0; i < nums.length; i++) {
           if (map.has(target - nums[i])) {
               return [map.get(target - nums[i]), i]
           } else {
               map.set(nums[i], i)
           }
       } 
    }
    return []
}
```

### 三数之和

给定一个包含n个整数的数组`nums`，判断`nums`中是否存在三个元素`a, b, c`，使得`a + b + c = 0`？找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

示例：

```js
给定数组 nums = [-1, 0, 1, 2, -1, -4]

满足要求的三元组集合为：
[
    [-1, 0, 1],
    [-1, -1, 2]
]
```

题目中说明可能会出现多组结果，所以我们要考虑好去重
1. 为了方便去重，我们首先将数组排序
2. 对数组进行遍历，取当前遍历的数`nums[i]`为一个基准数，遍历数后面的数组为寻找数组
3. 在寻找数组中设定两个起点，最左侧的`left(i + 1)`和最右侧的`right(length - 1)`
4. 判断`nums[i] + nums[left] + nums[right]`是否等于`0`，如果等于`0`，加入结果，并分别将`left`和`right`移动一位
5. 如果结果大于`0`，将`right`向左移动一位，向结果逼近
6. 如果结果小于`0`，将`left`向右移动一位，向结果逼近

注意整个过程中要考虑去重

```js
var threeSum = function(nums) {
    const result = []
    nums.sort((a, b) => a - b)
    for (let i = 0; i < nums.length; i++) {
        // 跳过重复数字
        if (i && nums[i] === nums[i - 1]) {
            continue
        }
        let left = i + 1
        let right = nums.length - 1
        while (left < right) {
            const sum = nums[i] + nums[left] + nums[right]
            if (sum > 0) {
                right--
            } else if (sum < 0) {
                left++
            } else {
                result.push([nums[i], nums[left++], nums[right--]])
                // 跳过重复数字
                while (nums[left] === nums[left - 1]) {
                    left++
                }
                // 跳过重复数字
                while (nums[right] === nums[right + 1]) {
                    right--
                }
            }
        }
    }
    return result
}
```

### 连续子数组的最大和

输入一个整型数组，数组里有正数也有负数。数组中的一个或连续多个证书组成一个子数组。求所有子数组的和的最大值，要求时间复杂度为`O(n)`

例如：`[6, -3, -2, 7, -15, 1, 2, 2]`，连续子向量的最大和为8（从第0个开始到第3个为止）

记录一个当前连续子数组最大值`max`，默认值为数组第一项
记录一个当前连续子数组累加值`sum`，默认值为数组第一项
1. 从数组第二个数开始，若`sum < 0`则当前的`sum`不再对后面的累加有贡献，`sum = 当前数`
2. 若`sum > 0`则`sum = sum + 当前数`
3. 比较`sum`和`max`，`max = 两者最大值`

```js
function findGreatestSumOfSubArray(array) {
    if (Array.isArray(array) && array.length > 0) {
        let sum = array[0]
        let max = array[0]
        for (let i = 1; i < array.length; i++) {
            if (sum < 0) {
                sum = array[i]
            } else {
                sum = sum + array[i]
            }
            if (sum > max) {
                max = sum
            }
        }
        return max
    }
    return 0
}
```
