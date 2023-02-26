#include <iostream>
using namespace std;
#if 0
#if 0
//函数模板
template<class T>
T Add(const T& left,const T& right)
{
    return left+right;
}
class Complex
{
public:
    Complex(double real,double image)
    :_real(real),
    _image(image)
    {}
    Complex operator+(const Complex& D2)const
    {
        return Complex(_real+D2._real,_image+D2._image);
    }
    void Print()
    {
        cout<<_real<<" "<<_image<<endl;
    }
private:
    double _real;
    double _image;

};

int main()
{
    Complex D1(1.2,2.3);
    Complex D2(3.4,4.5);
     
    Add(10,20);
    //Add(10.2,20);报错
    Add<int>(10.2,20);

    Complex D3=Add(D1,D2);//运算符重载
    D3.Print();

    system("pause");
    return 0;
}
#endif

#if 0
template<class T>
T Add(const T& left,const T& right)
{
    return left+right;
}

int Add(int a,int b)
{
    return a+b;
}

int main()
{
    //优先调用非模板函数
    Add(1,3);//进普通函数

    //Add<int>(1.3,2.3);//进模板函数 
    //告诉编译器根据模板来生成对应的函数
    Add<>(1.3,2.3);//隐式实例化

    system("pause");
    return 0;
}
#endif

// 类模板
// 待实现

// 下标运算符重载[]
// 下标运算符是成对重载的 --const & 普通类型
#endif

#if 0
// 实现一个通用的加法函数
// 方法要通用，在实现类型就不能具体化--即：类型给具体了之后，方法只能处理该种类型
// 需要告诉编译器，T是一个类型

// typedef double T;//这种不是我们需要的，实际类型还得看具体

// 函数模板
template <typename T>
T Add(T left, T right)
{
    return left + right;
}
template <typename T, typename S, class U>
void Print(T data1, S data2, U data3)
{
    cout << data1 << endl;
    cout << data2 << endl;
    cout << data3 << endl;
}
template <class T>
void Swap(T &left, T &right)
{
    T temp = left;
    left = right;
    right = temp;
}
#endif
#if 0
int main()
{
    // 普通引用
    int a = 10;
    // 可以通过ra来修改a
    int &ra = a;

    // b是一个常量，b的内容是不允许被修改的
    const int b = a;

    // 将 "int &" 类型的引用绑定到 "const int"
    // 类型的初始值设定项时，限定符被丢弃
    // int &rb = b;
    const int &rb = b;

    system("pause");
    return 0;
}
#endif
#if 0
// 定义一个Add函数模板
// 注意:函数模板不是函数，而是一个模具，是一个规则
// 是编译器根据实例化结果推演出来的类型生成处理具体类型代码的一个规则
// template <class T>
// T Add(const T &left, const T &right)
// {
//     cout << typeid(T).name() << endl;
//     return left + right;
// }

// 解决方式二
template <class T, class S>
T Add(const T &left, const S &right)
{
    cout << left + right << endl;
    return left + right;
}

// 函数模板的编译原理：
// 1.在实例化之前，只是对模板进行简单的语法检测
// 2.在实例化之后：根据用户对函数模板的实例化结果来生成处理对应类型的代码，并对这些代码再次进行生成

int main()
{
    // 调用：是对函数模板的实例化
    // 隐式实例化：没有明确指定T的实际类型，然后编译器需要跟进传递的实参类型推演T的实际类型
    //             编译器不会进行隐式类型转化
    Add(1, 2);     // 1->int 2->int 就认为T是int类型的，则会根据模板生成处理int类型的Add<int>函数
    Add(1.2, 2.3); // 1.2->double 3.4->double 就认为T是double类型的，则会根据模板生成处理double类型的Add<double>函数
    Add('1', '2'); //'1'->char '2'->char就认为T是char类型的，则会根据模板生成处理char类型的Add<char>函数

    Add(1, (int)2.3); // 1->int  2.3->double  T到底应该成int类型  还是double类型 编译器就无法确定

    // 对模板进行显式实例化，明确指明了模板参数类表中的T的实际类型
    Add<double>(1, 2.3);
    system("pause");
    return 0;
}
#endif
#if 0
template <class T>
T Add(const T &left, const T &right)
{
    return left + right;
}

class Complex
{
private:
    double _real;
    double _image;

public:
    Complex(double real, double image)
        : _real(real), _image(image)
    {
    }
    Complex(const Complex &c)
    {
        cout << "Complex(const Complex&)" << endl;
    }

    Complex operator+(const Complex &c) const
    {
        return Complex(_real + c._real, _image + c._image);
    }
};

int main()
{
    Add(1, 2);
    Add(1.4, 2.3);

    Complex C1(1.2, 3.4);
    Complex C2(2, 3);

    C1+C2;
    Add(C1, C2);

    system("pause");
    return 0;
}
#endif
#if 0
template <class T>
class SeqList
{
private:
    T *_arr;
    size_t _capacity;
    size_t _size;

public:
    SeqList(size_t cap = 10)
        : _arr(nullptr), _capacity(cap == 0 ? 3 : cap), _size(0)
    {
        _arr = new T[10];
    }
    void PushBack(const T &data)
    {
        _arr[_size] = data;
        _size++;
    }
    void PopBack()
    {
        if (Empty())
        {
            return;
        }
        _size--;
    }
    bool Empty() const
    {
        return 0 == _size;
    }

    size_t Size() const
    {
        return _size;
    }

    // 类模板中的成员方法也可以放外面定义，但是不推荐
    T &Front();
    T &Back();
    ~SeqList()
    {
        if (_arr)
        {
            delete[] _arr;
            _arr = nullptr;
            _capacity = 0;
            _size = 0;
        }
    }
};
template <class T>
T &SeqList<T>::Front()
{
    return _arr[0];
}
template <class T>
T &SeqList<T>::Back()
{
    return _arr[_size - 1];
}

int main()
{
    // SeqList不是类，而是一个类模板的名字
    // SeqList<int>才是真正的类型
    SeqList<int> s1;
    s1.PushBack(2);
    s1.PushBack(3);
    s1.PushBack(4);
    s1.PushBack(5);

    cout << s1.Size() << endl;
    cout << s1.Front() << endl;
    cout << s1.Back() << endl;

    SeqList<double> s2;
    s2.PushBack(1.2);
    s2.PushBack(2.2);
    s2.PushBack(3.2);
    s2.PushBack(4.2);
    s2.PushBack(5.2);
    cout << s2.Size() << endl;
    cout << s2.Front() << endl;
    cout << s2.Back() << endl;

    system("pause");
    return 0;
}
#endif
#if 0
int Add(int left, int right)
{
    return left + right;
}

template <class T>
T Add(const T &left, const T &right)
{
    return left + right;
}

int main()
{
    // 如果有类型完全匹配的方法则直接调用，不需要让编译器根据模板生成了
    Add(1, 2); // 调用普通版本的Add方法

    // Add<int>(10,20);
    Add(2.3, 9.1);

    // 告诉编译器根据模板来生成对应类型的Add函数
    Add<>(20, 30); // 隐式实例化
    system("pause");
    return 0;
}
#endif
#if 0
template <class T, class U>
T Add(const T &left, const U &right)
{
    return left + right;
}
int Add(int left, int right)
{
    return left + right;
}

int main()
{
    Add(1, 2);
    // 1->int 2.0->double
    //  虽然double可以和int之间发生隐式类型转换，但是此处编译器发现
    //  函数模板可以生成更加匹配的方法，则最终选择让模板生成
    Add(1, 2.0);

    system("pause");
    return 0;
}
#endif

template <class T>
class SeqList
{
private:
    T *_arr;
    size_t _capacity;
    size_t _size;

public:
    SeqList(int cap = 0)
        : _capacity(cap == 0 ? 3 : cap), _arr(nullptr), _size(0)
    {
        _arr = new T[10];
    }
    void PushBack(const T &data)
    {
        _arr[_size++] = data;
    }
    void PopBack()
    {
        if (Empty())
        {
            return;
        }
        _size--;
    }

    bool Empty() const
    {
        return 0 == _size;
    }
    size_t Size() const
    {
        return _size;
    }
    // 对[]下标运算符进行重载 普通与const
    T &operator[](size_t index)
    {
        assert(index < _size);
        return _arr[index];
    }
    const T &operator[](size_t index) const
    {
        assert(index < _size);
        return _arr[index];
    }

    // 类模板中的成员方法也可定义在类外
    T &Front();
    T &Back();
    ~SeqList()
    {
        if (_arr)
        {
            delete[] arr;
            arr = nullptr;
            _capacity = 0;
            _size = 0;
        }
    }
};

template <class T>
T &SeqList<T>::Front()
{
    return _arr[0];
}

template <class T>
T &SeqList<T>::Back()
{
    return _arr[size - 1];
}

int main()
{
    SeqList<int> s;
    s.PushBack(1);
    s.PushBack(2);
    s.PushBack(3);

    int array[] = {1, 2, 3, 4, 5};
    cout << array[1] << endl;

    s[2] = 30;
    cout << s[2] << endl;
    const SeqList<int> cs;
    cs[0]; // const对象不能访问普通的成员函数

    // SeqList<double>: 就是对SeqList类模板进行实例化
    SeqList<double> sd;
    sd.PushBack(1.1);
    sd.PushBack(2.2);
    sd.PushBack(3.3);

    system("pause");
    return 0;
}

// 2022-11-29