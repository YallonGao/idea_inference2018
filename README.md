# 毫秒级解决《2018年刑侦科推理试题》

[个人博客](https://yallongao.github.io/blog/idea_inference2018/)

前几年比较火的《2018年刑侦科推理试题》，但我最近才看到，这里写一下如何利用C++或Python在几毫秒内求得结果。

![img](https://yallongao.github.io/blog/assets/images/2023-6-5-idea_inference2018/%E9%A2%98%E7%9B%AE.jpeg)

## 分析

显然，可以用暴力解决，在410个答案内依次进行遍历看答案是否合规，网上能搜索到的教程一般也是这种暴力解法，一般有如下两种形式：

- 10个for循环嵌套
- 递归，递归深度为10，每一个新的递归都向下递归四次（即ABCD四个选项）

由于上述解法不美观且有很多示例，这里则不做补充。接下来讲具体思路。

递归的思想是没问题的，这里我用手稿演示一下。

![FCABA2A6EE23680C3AA303A2DDAF829B](https://yallongao.github.io/blog/assets/images/2023-6-5-idea_inference2018/%E5%9B%9B%E5%8F%89%E6%A0%91.jpg)

可以看出递归的思路是一颗高为10的完全四叉树，如果要完全验证这么多答案是否合理是很耗费时间的，那么有没有什么方法可以加快运算速度呢，当然是有的，就是剪枝，有如下两种思路：

- 不需要递归至第十层才判断是否合理，而在中途就选择性进行回溯。例如第一题和第五题答案不同（这里随便写的），那么递归至第五层时，就应该检验当前的答案和第一题的答案是否一致，如果一致，说明答案已经不合理了，不需要再递归下去。
- 另外一种优化方法，十道题并没有固定的递归顺序，所以先递归第一题和先递归第二题本质是一样的，我们可以先让更容易得出结果的题目先递归

知晓此思路后，利用C++和python 分别写出代码。

## 结果

电脑配置：NVIDAGTX1050Ti（官方算力表为6.1），i7-8750H十六核处理器，电脑已使用四年半

运行结果：都是几毫秒内解决，并且C++可以达到1毫秒

（我是双系统，所以都测一下，并且每次运行时间可能有差异，随机取一次，且精确至五位小数，您可以使用代码多跑几次求平均运行时间）

|             |  Python  |   C++    |
| :---------: | :------: | :------: |
|  windows10  | 0.00698s | 0.00200s |
| Ubuntu22.04 | 0.00463s | 0.00139s |

可以发现：

- 同样的代码逻辑实现，python比C++慢很多
- 同样的代码同样的设备，Ubuntu比windows更快
