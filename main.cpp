#include <iostream>
#include "future.h"
#include "promise.h"

template<typename T>
Future<T> Flatten(Future<T> f) {
    return f;
}

template<typename T, class U>
Future<T> Flatten(Future<U> f) {
    U u = f.Get();
    return Flatten(u);
};




int main() {
    Promise<void> p;
    Future<void> f = p.GetFuture();
    int x = 10;
    int const y = 100;
    p.Set();
    f.Get();
    if (f.IsReady()) std::cout << "True";
    return 0;
}