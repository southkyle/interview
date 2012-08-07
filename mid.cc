
设计一个一个数据结构能够返回中位数。

1 数组 插入效率 O(n) 返回中位数 O(1)

2 弄一个最大堆 一个最小堆，然后插入一个数时
  if left.size == right.size
     if x > left.min insert to right
     else z = left.min left.pop left.insert(x)
          right.push(z)
  if left.size < right.size

3 算法导论，二叉树中记录了左右子树 以及 根的个数
  size[x] = size[left[x]] + size[right[x]] + 1


