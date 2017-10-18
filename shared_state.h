//
// Created by Александра on 05.10.2017.
//

#ifndef FUTUREANDPROMISE_SHARED_STATE_H
#define FUTUREANDPROMISE_SHARED_STATE_H

#include <cassert>
#include <exception>

template <typename T>
        class Future;

template <typename T>
        class Promise;

template <typename T>
class shared_state {
private:
    T value;
    bool ready = false;
    bool existPromise;
    std::exception_ptr ex;
public:
    friend Future<T>;
    friend Promise<T>;
};

/*template <typename T>
class shared_state<T &> {
private:
    T&* value;
    bool ready = false;
    bool existPromise;
    std::exception_ptr ex;
public:
    friend Future<T &>;
    friend Promise<T &>;
};
 */

template<>
class shared_state<void> {
private:
    bool ready = false;
    bool existPromise;
    std::exception_ptr ex;
public:
    friend Future<void>;
    friend Promise<void>;
};

#endif //FUTUREANDPROMISE_SHARED_STATE_H
