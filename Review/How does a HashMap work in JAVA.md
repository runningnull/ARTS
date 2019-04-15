---
title: Review 《How does a HashMap work in JAVA》
date: 2019-04-14 11:25:24
tags: [阅读,技术]
---
原文链接：[How does a HashMap work in JAVA](http://coding-geek.com/how-does-a-hashmap-work-in-java/#Internal_storage)  

周六下午在图书馆里刷完了这篇文章。因为先前写过一篇关于 Hash 算法的文章，所以这篇文章看下来基本上都能懂。  
文章介绍了：  
* Java7 和 Java8 中 HashMap 的内部存储结构（Java7 中用Entry数组，Java8 中用 Node 数组 和 TreeNode）
* HashMap 中的自动扩容机制（如果 <font color=red>当前元素个数 > 当前最大容量*填充因子</font> 就进行扩容）
* 线程不安全（如果想要线程安全使用 HashTable 或者 ConcurrentHashMap）
* HashMap 的 key 值要具有不可变性（因为内部是通过计算 key 值的 hashcode 进行 crud 的。如果 key 值可变，那么那就像韩国选美一样，都整容成一样的女生，你能认出谁是谁吗？）
* Java8 中 HashMap 的优化（无非就是将出现 hash 碰撞次数大于 8 次的链表改为红黑树）
* Java7 和 Java8 中 HashMap 的内存开销（假设 Java7 中 HahsMap 有 N 个元素并且空间为 CAPACITY，则一般占用空间为 16 * N + 4 * CAPACITY 个字节，Java8 中一般为 44 * N + 4 * CAPACITY 个字节）
* 对比了不平衡 HashMap 和平衡 HashMap（就是说别乱设 key，散列函数要优秀）
* 扩充规则（默认容量大小为 16，依次翻倍增加。用户默认设置的大小如果不是2的幂次，那么它会找到比用户设置的大的那个2的幂次数，如用户设置 37，那么实际上初始化的时候会把容量大小设置为 64）

总得来说，这篇文章非常不错，干货满满，帮我梳通了 HashMap 的构造，为我读源码提供了必要的基础。