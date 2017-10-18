//
// Created by Александра on 01.10.2017.
//

#ifndef FUTUREANDPROMISE_PROMISE_H
#define FUTUREANDPROMISE_PROMISE_H

#include <memory>
#include "shared_state.h"

template <typename T>
class Future;

template <typename T>
class Promise {
private:
    std::shared_ptr<shared_state<T>> sh;
    bool getAvailable = true;
    void Setpr() {
        assert(!sh->ready);
        sh->ready = true;
    }
public:
    Promise() : sh(new shared_state<T>) {
        sh->existPromise = true;
    }

    void Set(const T& a) {
        Setpr();
        sh->value = a;
    }

    void Set(T && a) {
        Setpr();
        sh->value = a;
    }

    void SetException(const std::exception_ptr e) {
        Setpr();
        sh->ex = e;
    }

    Future<T> GetFuture() {
        assert(getAvailable);
        getAvailable = false;
        Future<T> future(sh);
        return future;
    }

    ~Promise() {
        sh->existPromise = false;
        
    }
};

/*template <typename T>
class Promise<T &> {
private:
    std::shared_ptr<shared_state<T &>> sh;
    bool getAvailable = true;
    void Setpr() {
        assert(!sh->ready);
        sh->ready = true;
    }
public:
    Promise() : sh(new shared_state<T &>) {
        sh->existPromise = true;
    }

    void Set(const T& a) {
        Setpr();
        sh->value = &a;
    }

    void Set(const T && a) {
        Setpr();
        sh->value = &a;
    }

    void SetException(const std::exception_ptr e) {
        Setpr();
        sh->ex = e;
    }

    Future<T &> GetFuture() {
        assert(getAvailable);
        getAvailable = false;
        Future<T &> future(sh);
        return future;
    }

    ~Promise() {
        sh->existPromise = false;

    }
};
 */

template<>
class Promise<void> {
private:
    std::shared_ptr<shared_state<void>> sh;
    bool getAvailable = true;
    void Setpr() {
        assert(!sh->ready);
        sh->ready = true;
    }
public:
    Promise() : sh(new shared_state<void>) {
        sh->existPromise = true;
    }

    void Set() {
        Setpr();
    }

    void SetException(const std::exception_ptr e) {
        Setpr();
        sh->ex = e;
    }

    Future<void> GetFuture() {
        assert(getAvailable);
        getAvailable = false;
        Future<void> future(sh);
        return future;
    }

    ~Promise() {
        sh->existPromise = false;

    }
};

#endif //FUTUREANDPROMISE_PROMISE_H
