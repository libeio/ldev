
### 方程求解

[二分插值](二分插值.md)

[试位插值](试位插值.md)

[反二次插值](反二次插值.md)


### 一元函数极值搜寻计算

对于一元函数，它可以是单极值分布，也可以是多峰值分布。

如果函数在一个区间内，只有一个最大或最小值，那么它就是单峰值分布函数，否则就是多峰值分布函数。

对于单峰值函数，可以通过重新设置初始点来解决全局问题。

一元函数可以是连续的，也可以是离散的。两种函数的极值搜寻方法有一定的不同，如连续函数极值可以通过求导数计算，而离散函数则不能直接求导。

则于多元函数的极值计算可以转化为一元函数的极值计算，如 Powell 法、尝试梯度法等，因此一元函数的极值计算是函数极值计算的基础。

这里介绍几种连续的一元函数极值计算方法。

[黄金分割](黄金分割.md)

[斐波拉契](斐波拉契.md)


### 多元函数极值搜寻计算

多元函数的极值问题比单元函数的极值问题复杂，有些多元极值问题可以分解成几个或多个单元函数的极值问题。

这里介绍几种典型的、算法也很简单的函数极值搜寻方法。

[Nelder-Mead算法](Nelder-Mead算法.md)
