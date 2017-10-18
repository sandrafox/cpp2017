//
// Created by Александра on 01.10.2017.
//

#ifndef FUTUREANDPROMISE_FUTURE_H
#define FUTUREANDPROMISE_FUTURE_H

#include <stdexcept>
#include <cassert>
#include <memory>
#include "shared_state.h"

template <typename T>
class Promise;

template <typename T>
class shared_state;

template <typename T>
class Future {
private:
    std::shared_ptr<shared_state<T>> sh;
public:
    Future<T>(std::shared_ptr<shared_state<T>> s) {
        sh = s;
    }

    const T& Get() const {
        if (!sh->ready && !sh->existPromise) {
            throw "Don't exist value";
        }
        while (!sh->ready);
        if (sh->ex != nullptr) {
            throw sh->ex;
        }
        return sh->value;
    }

    void Wait() {
        assert(sh->ready||sh->existPromise);
        while (!sh->ready);
    }

    bool IsReady() {
        return sh->ready;
    }

    Future(Future &) = delete;
    Future(Future&&) = default;
    Future& operator=(Future &) = delete;
    Future& operator=(Future&&) = default;
};


/*template <typename T>
class Future<T &> {
private:
    std::shared_ptr<shared_state<T &>> sh;
public:
    Future<T &>(std::shared_ptr<shared_state<T &>> s) {
        sh = s;
    }

    const T& Get() const {
        if (!sh->ready && !sh->existPromise) {
            throw "Don't exist value";
        }
        while (!sh->ready);
        if (sh->ex != nullptr) {
            throw sh->ex;
        }
        return *sh->value;
    }

    void Wait() {
        assert(sh->ready||sh->existPromise);
        while (!sh->ready);
    }

    bool IsReady() {
        return sh->ready;
    }

    Future(Future &) = delete;
    Future(Future&&) = default;
    Future& operator=(Future &) = delete;
    Future& operator=(Future&&) = default;

    friend Promise<T>;
};
 */

class shared_state<void>;

template<>
class Future<void> {
private:
    std::shared_ptr<shared_state<void>> sh;
public:
    Future<void>(std::shared_ptr<shared_state<void>> s) {
        sh = s;
    }

    const void Get() const {
        if (!sh->ready && !sh->existPromise) {
            throw "Don't exist value";
        }
        while (!sh->ready);
        if (sh->ex != nullptr) {
            throw sh->ex;
        }
    }

    void Wait() {
        assert(sh->ready||sh->existPromise);
        while (!sh->ready);
    }

    bool IsReady() {
        return sh->ready;
    }

    Future(Future &) = delete;
    Future(Future&&) = default;
    Future& operator=(Future &) = delete;
    Future& operator=(Future&&) = default;
};

#endif //FUTUREANDPROMISE_FUTURE_H
