# 事务的四个性质
## 原子性（Atomicity）：

即不可分割性，事务中的操作要么全不做，要么全做

拿之前转账的例子来说，用户A给用户B转账，至少要包含两个操作，用户A钱数减少，用户B钱数增加，增加和减少的操作要么全部成功，要么全部失败，是一个原子操作。如下图，如果事务在T1 完成之后但在T2完成之前失败，将导致数据库状态不正确。
## 一致性（Consistency）：

一个事务在执行前后，数据库都必须处于正确的状态，满足完整性约束

假设用户A和用户B两者的钱加起来一共是700，那么不管A和B之间如何转账，转几次账，这一约束都得成立，即事务结束后两个用户的钱相加起来还得是700，这就是事务的一致性。

## 隔离性（Isolation）：

多个事务并发执行时，一个事务的执行不应影响其他事务的执行

## 持久性（Durability）：

事务处理完成后，对数据的修改就是永久的，即便系统故障也不会丢失

# 隔离级别
（1）脏读：一个事务读取了另一个未提交的事务写入的数据。

（2）不可重复读：一个事务重新读取前面读取过的数据时，发现该数据已改变。

（3）幻读：一个事务开始后，需要根据数据库中现有的数据做一些更新，于是重新执行一个查询，返回符合查询条件的行，这时发现这些行因为其它最近提交的事务而发生了改变，导致现有事务如果再进行下去可能发发生逻辑上的错误。

## 读未提交（READ UNCOMMITTED）
表示可以读到其他会话未提交的数据（postgresql不支持）。
## 读已提交（READ COMMITTED）
表示可以读到其他会话已提交的数据。
## 重复读（REPEATABLE READ）
表示在一个事务中，执行同一条SQL，读到的是同样的数据（即使被读的数据可能已经被其他会话修改并提交）。
## 串行化（SERIALIZABLE）
表示并行事务模拟串行执行，违反串行执行规则的事务，将回滚。

# 两阶段提交
P357
预提交，全局提交

# 并发控制
## 可串行化调度
## 乐观
事后检测
- 读阶段维护读集合和写集合
- 有效性确认阶段 检查是否违背可串行化
- 写阶段 对私有空间的数据进行应用

## 悲观
事先检测冲突，检测完尝试阻塞。比如两阶段锁。

### 两阶段锁（S，X)
#### 增长阶段
事务可以申请锁
#### 收缩阶段
事务可以放锁

## 锁
### 自旋锁
TEST AND SET
### LWLOCK
共享内存的锁，等待队列。
### REgular lock

## MVCC
CLOG, 快照
### FSM, Visable MAP


# WAL LOG
用于存储事务日志

# 索引
## B-Tree
首先注意：B树就是B-树，"-"是个连字符号，不是减号。
B-树是一种平衡的多路查找(又称排序)树，在文件系统中有所应用。主要用作文件的索引。其中的B就表示平衡(Balance)

B+树有一个最大的好处，方便扫库，B树必须用中序遍历的方法按序扫库，而B+树直接从叶子结点挨个扫一遍就完了。

B+树支持range-query(区间查询)非常方便，而B树不支持。这是数据库选用B+树的最主要原因