### RAII是什么
RAII全程是**Resource Acquisition Is Initialization**--**资源获取即初始化**，常用于面向对象开发语言中。

**RAII**要求：
> 资源的有效期和持有资源的对象的生命周期严格绑定；
> 就是由对象的构造函数完成资源的分配，同时由析构函数完成释放；
> 只要对象能够正确地析构，就不会出现内存泄漏问题

也就是说我们可以将需要使用的资源封装在类中，通过构造函数和析构函数分配和释放，这样可以避免认为释放内存，更多地用于线程资源访问，因为RAII可以**保证代码的异常安全性**；


### 如何使用RAII

参考C++标准库的**lock_guard**实现，使用RAII机制来控制互斥量
```
template <class Mutex> class lock_guard {
private:
    Mutex& mutex_;

public:
    lock_guard(Mutex& mutex) : mutex_(mutex) { mutex_.lock(); }
    ~lock_guard() { mutex_.unlock(); }

    lock_guard(lock_guard const&) = delete;
    lock_guard& operator=(lock_guard const&) = delete;
};
```

这样我们可以使用**lock_guard**而不需要担心异常安全
```
extern void unsafe_code();  // 可能抛出异常

using std::mutex;
using std::lock_guard;

mutex g_mutex;

void access_critical_section()
{
    lock_guard<mutex> lock(g_mutex);
    unsafe_code();
}
```