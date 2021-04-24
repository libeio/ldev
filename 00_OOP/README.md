
## 使用 C++ 编程
- 用最少行数的代码来编写程序往往并不会产生最好的解决方案。然而，优良的设计却总是比拙劣的设计有着更短的代码。
- 并不是每一个问题都需要虚函数才能解决。使用数据成员来表示对象在属性上的区别也是一种不错的方法。
- 在设计一个类时，程序员通常需要从两个方面进行考虑。接口必须能够代表一致的抽象，而实现又必须使对象在行为上与这个抽象保持一致。
- 类的设计中的一致性：既要在接口上保持外部一致性，也要在每个对象状态的实现上保持内部一致性。
- 在任何时候，一个对象都是处于某种状态，这种状态是由对象中所有数据成员的值来确定的。
- 降低耦合性，将类之间的交互最小化。
- 当我们要决定在一个类中到底是使用数据成员还是函数成员来表示一个特性时，首先应该考虑：
    + 这个特性是由属性值来描述的还是由行为来描述的
    + 派生类和基类是否有着同样的行为
- 无论在类中定义了多少个虚函数，在每个对象中都只有一个虚指针。而且，同一个类的所有对象都将共享同一个虚表。
- 一个类中方法和数据可能会有很多，理解一个类的最快方法是了解该类所实例化的对象。之后根据该对象的属性和行为
  找出该类的主要方法和成员数据。
  
## C++ 的面向对象方法论
- 数据封装
- 数据抽象
- 类型继承
- 多态
    
## C++ 强静态类型语言特性
- 所有变量都必须声明和定义。声明指变量的类型和存储方式必须声明，定义指变量的内存分配和初始化过程。
- 所有的 UDT (用户自定义类型, user defined types)在使用之前都必须完整地定义。
- C++ 语言的推荐范式和用法指南都不建议使用 C-casting, 并且提供 C++ 支持的转型运算符(static_cast, dynamic_cast, reinterpret_cast 等)。
  ```c++
    /* C 代码 */
    char c = 'c';
    char* pc = &c;
    int* pi = (int*)pc;
    *pi = 5;                // 运行时错误
    /* C++ 代码 */
    char c = 'c';
    char* pc = &c;
    int* pi = static_cast<int*>pc;      // 编译时错误，更早地发现错误
  ```
- 提供有限的运行态型辨识服务(RTID)。一般来说，静态的 UDT 意味着在运行环境下，UDT 的印记可以被完全抹去。C++ 不提供反射(reflection)服务，但是程序员可以选择使用简单、有效的 RTID 服务：
  ```c++
    A& a = dynamic_cast<B&>(b);
    assert(typeid(a) == typeid(b));     // 这个等式成立
  ```

## C++ 的类型清除
- 类型清除是指程序设计中的类型印记在编译时被清除，取而代之的是系统的低级操作。
- UDT 的所有操作和转换规则都是在程序编译时查证的，不存在运行时类型的转化规则。运行时只有简单的内存地址的重定向，不存在任何关于类型的踪影。
- C++ 类型清除的步骤
    + 变量绑定: 数据类型和实例的绑定。
    + 操作绑定
- C++ 的操作绑定指的是抽象操作与实际操作的绑定。静态类型的操作绑定都是在编译时完成的。动态类型的操作绑定可以在运行时完成。静态类型操作绑定又可分类完全绑定和部分绑定。
    + 完全绑定完全绑定意味着在编译时，变量的操作被转换成固定的函数调用或 inline 汇编代码，操作的语义完全固定下来。
    + 部分绑定意味着在编译时，变量操作的范畴和形式可以固定下来，但是具体的操作代码是在运行时确定的。部分
      绑定是支持抽象性和虚函数的必要手段。C++ 是强静态类型程序设计语言，它不支持完全的运行时绑定，但是支
      持基于某个抽象类的部分绑定。
- 类型推导(type inference)
    + 类型推论是指在编译时（或者 runtime）根据上下文自动推论出变量的类型。

## C++ 实现多态的方法
- 指针和引用都支持多态实例(polymorphic instance)。实例只有被赋予指针或者引用后，才能体现其多态性。否则，只能是具体实例(concrete instance)，不能虚拟化。
- 引用具有"指针-object二象性": "多态"是指针的属性，而引用是通过指针实现的，自然也就继承了指针的"多态性"。
- C++ 编译支持合理的指针赋值机制，这里主要通过两个运算符 static_cast 和 dynamic_cast 来实现。

## C++ 的资源获取即初始化 RAII
- 在构造函数中获取资源，然后在析构函数中释放它们，这种技术称为资源获取即初始化(RAII)。这可以避免
  "裸new"或"裸delete"操作。
- 下例中，构造函数负责为元素分配空间并正确地初始化 Vector 成员，析构函数则负责释放空间。这就是所谓的数据句柄模型。
  ```c++
    class Vector {
    private:
        double* elem;   // elem 指向一个含 sz 个 double 型元素的数组
        int sz;
    public:
        Vector(int s) :elem{new double[s]}, sz{s} {     // 构造函数：获取资源
            for (int i = 0; i != s; ++i)                // 初始化元素
                elem[i] = 0;
        }
        ~Vector() { delete[] elem; }                    // 析构函数：释放资源
        
        double& operator[] (int i);
        int size() const;
    };
  ```

## 更好地使用 C++
- 在 C++ 里几乎不需要用宏。用 const 或 enum 定义明显的常量，用 inline 避免函数调用的额外开销，用 template 去刻画一族函数或者类型，用 namespace 去避免名字冲突。
- 试着去避免 `void*`、指针算术、联合和强制，除了在某些函数或类实现的深层之外。在大部分情况下，强制都是设计错误的指示器。
- 尽量少用数组和C风格的字符串。与传统的C风格相比，使用C++标准库string和vector常常可以简化程序设计。

## C++ 编程忠告
- 在编程序时，你是在为你针对某个问题的解决方案中的思想建立起一种具体表示。让程序的结构尽可能地直接反映
  这些思想：
    + 如果你能把“它”看成一个独立的概念，就把它做成一个类；
    + 如果你能把“它”看成一个独立的实体，就把它做成某个类的一个对象；
    + 如果两个类有共同的界面，将此界面做成一个抽象类；
    + 如果两个类的实现有某些显著的共同东西，将这些共性做成一个基类；
    + 如果一个类是一种对象的容器，将它做成一个模板；
    + 如果一个函数实现对某容器的一个算法，将它实现为对一族容器可用的模板函数；
    + 如果一组类、模板等相互之间有逻辑联系，将它们放进一个名字空间里。
- 在定义一个并不是实现某个像矩阵或复数这样的数学对象的类时，或者定义一个低层的类型如链接表的时候：
    + 不要使用全局数据（使用成员）
    + 不要使用全局函数
    + 不要使用公用数据成员
    + 不要使用友元，除非为了避免a或c
    + 不要在一个类里面放“类型域”；采用虚函数
  类型域：指那种为了说明一个类所存储数据的情况而放置的标志域。
  
## C++ 经验法则
- 头文件里可以包括：
    + 命名名字空间    namespace N { /***/ }
    + 类型定义        struct Point { int x, y };
    + 模板声明        template <class T> class Z;
    + 模板定义        template <class T> class V { /***/ };
    + 函数声明        extern int strlen(const char*);
    + 在线函数定义    inline char get(char* p) { return *p++; }
    + 数据声明        extern int a;
    + 常量定义        const float pi = 3.141593;
    + 枚举            enum Light { red, yellow, green };
    + 名字声明        class Matrix;
    + 包含指令        #include <algorithm>
    + 宏定义          #define VERSION 12
    + 条件编译指令    #ifdef __cplusplus
- 头文件里绝不应该有：
    + 常规的函数定义  char get(char* p) { return *p++; }
    + 数据定义        int a;
    + 聚集量定义      short tbl[] = { 1, 2, 3 };
    + 无名名字空间    namespace { /***/ }