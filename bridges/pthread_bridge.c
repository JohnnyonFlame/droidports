#include <errno.h>
#include <stdint.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>

#include "platform.h"
#include "so_util.h"
#include "pthread_bridge.h"

ABI_ATTR int pthread_key_create_bridge(pthread_key_t *key, void (*destr_function) (void *))
{
    int ret = pthread_key_create(key, destr_function);
    return ret;
}

ABI_ATTR int pthread_key_delete_bridge(pthread_key_t key)
{
    return pthread_key_delete(key);
}

ABI_ATTR int pthread_setspecific_bridge(pthread_key_t key, const void *__pointer)
{
    // TODO:: Investigate if this is valid - currently this works around Splash setting the zero key and causing crashes elsewhere.
    if (key == 0)
        return -EINVAL;

    int ret = pthread_setspecific(key, __pointer);
    return ret;
}

ABI_ATTR void* pthread_getspecific_bridge(pthread_key_t key)
{
    return pthread_getspecific(key);
}

ABI_ATTR int pthread_mutex_init_bridge(BIONIC_pthread_mutex_t *_uid, pthread_mutexattr_t **mutexattr)
{
    pthread_mutex_t **uid = (pthread_mutex_t**)_uid;

    pthread_mutexattr_t *attr = mutexattr ? *mutexattr : NULL; 
    pthread_mutex_t *m = (pthread_mutex_t *)calloc(1, sizeof(pthread_mutex_t));
    if (!m)
        return -1;

    int ret = pthread_mutex_init(m, attr);
    if (ret < 0)
    {
        free(m);
        return -1;
    }

    *uid = m;

    return 0;
}

ABI_ATTR int pthread_mutex_destroy_bridge(BIONIC_pthread_mutex_t *_uid)
{
    pthread_mutex_t **uid = (pthread_mutex_t**)_uid;

    if (uid && *uid && (uintptr_t)*uid > 0x8000)
    {
        pthread_mutex_destroy(*uid);
        free(*uid);
        *uid = NULL;
    }
    return 0;
}

ABI_ATTR int pthread_mutex_lock_bridge(BIONIC_pthread_mutex_t *_uid)
{
    pthread_mutex_t **uid = (pthread_mutex_t**)_uid;

    if (uid < (BIONIC_pthread_mutex_t*)0x1000)
        return -1;

    if (!*uid)
        pthread_mutex_init_bridge(uid, NULL);
    
    return pthread_mutex_lock(*uid);
}

ABI_ATTR int pthread_mutex_unlock_bridge(BIONIC_pthread_mutex_t *_uid)
{
    pthread_mutex_t **uid = (pthread_mutex_t**)_uid;

    int ret = 0;
    if (uid < (pthread_mutex_t**)0x1000)
        return -1;

    if (!*uid)
        ret = pthread_mutex_init_bridge(uid, NULL);

    if (ret < 0)
        return ret;
    
    return pthread_mutex_unlock(*uid);
}

ABI_ATTR int pthread_cond_init_bridge(pthread_cond_t **cnd, const int *condattr)
{
    pthread_cond_t *c = (pthread_cond_t *)calloc(1, sizeof(pthread_cond_t));
    if (!c)
        return -1;

    *c = (pthread_cond_t)PTHREAD_COND_INITIALIZER;
    int ret = pthread_cond_init(c, NULL);
    if (ret < 0)
    {
        free(c);
        return -1;
    }

    *cnd = c;

    return 0;
}

ABI_ATTR int pthread_cond_broadcast_bridge(pthread_cond_t **cnd)
{
    if (!*cnd)
    {
        if (pthread_cond_init_bridge(cnd, NULL) < 0)
            return -1;
    }
    return pthread_cond_broadcast(*cnd);
}

ABI_ATTR int pthread_cond_signal_bridge(pthread_cond_t **cnd)
{
    if (!*cnd)
    {
        if (pthread_cond_init_bridge(cnd, NULL) < 0)
            return -1;
    };
    return pthread_cond_signal(*cnd);
}

ABI_ATTR int pthread_cond_destroy_bridge(pthread_cond_t **cnd)
{
    if (cnd && *cnd)
    {
        pthread_cond_destroy(*cnd);
        free(*cnd);
        *cnd = NULL;
    }
    return 0;
}

ABI_ATTR int pthread_cond_wait_bridge(pthread_cond_t **cnd, BIONIC_pthread_mutex_t *_mtx)
{
    pthread_mutex_t **mtx = _mtx;
    
    if (!*cnd)
    {
        if (pthread_cond_init_bridge(cnd, NULL) < 0)
            return -1;
    }
    return pthread_cond_wait(*cnd, *mtx);
}

ABI_ATTR int pthread_cond_timedwait_bridge(pthread_cond_t **cnd, BIONIC_pthread_mutex_t *_mtx, const struct timespec *t)
{
    pthread_mutex_t **mtx = _mtx;

    if (!*cnd)
    {
        if (pthread_cond_init_bridge(cnd, NULL) < 0)
            return -1;
    }
    return pthread_cond_timedwait(*cnd, *mtx, t);
}

ABI_ATTR int pthread_once_bridge(volatile int *once_control, void (*init_routine)(void))
{
    if (!once_control || !init_routine)
        return -1;
    if (__sync_lock_test_and_set(once_control, 1) == 0)
        (*init_routine)();
    return 0;
}

// pthread_t is an unsigned int, so it should be fine
// TODO: probably shouldn't assume default attributes
ABI_ATTR int pthread_create_bridge(pthread_t *thread, const void *unused, void *(*entry)(void *), void *arg)
{
    return pthread_create(thread, NULL, entry, arg);
}

ABI_ATTR int pthread_mutexattr_init_bridge(pthread_mutexattr_t **attr_ptr)
{
    pthread_mutexattr_t *attr = calloc(1, sizeof(pthread_mutexattr_t));
    int r = pthread_mutexattr_init(attr);
    *attr_ptr = attr;

    return r;
}

ABI_ATTR int pthread_mutexattr_settype_bridge(pthread_mutexattr_t **attr_ptr, int kind)
{
    int ret = pthread_mutexattr_settype(*attr_ptr, kind);
    return ret;
}

ABI_ATTR int pthread_mutexattr_destroy_bridge(pthread_mutexattr_t **attr_ptr)
{
    int ret = pthread_mutexattr_destroy(*attr_ptr);
    //free(attr_ptr);
}

ABI_ATTR int pthread_join_bridge(pthread_t th, void **thread_return)
{
    pthread_join(th, thread_return);
}

DynLibFunction symtable_pthread[] = {
    {"pthread_key_create", (uintptr_t)&pthread_key_create_bridge},
    {"pthread_key_delete", (uintptr_t)&pthread_key_delete_bridge},
    {"pthread_setspecific", (uintptr_t)&pthread_setspecific_bridge},
    {"pthread_getspecific", (uintptr_t)&pthread_getspecific_bridge},
    {"pthread_mutex_init", (uintptr_t)&pthread_mutex_init_bridge},
    {"pthread_mutex_destroy", (uintptr_t)&pthread_mutex_destroy_bridge},
    {"pthread_mutex_lock", (uintptr_t)&pthread_mutex_lock_bridge},
    {"pthread_mutex_unlock", (uintptr_t)&pthread_mutex_unlock_bridge},
    {"pthread_cond_init", (uintptr_t)&pthread_cond_init_bridge},
    {"pthread_cond_broadcast", (uintptr_t)&pthread_cond_broadcast_bridge},
    {"pthread_cond_signal", (uintptr_t)&pthread_cond_signal_bridge},
    {"pthread_cond_destroy", (uintptr_t)&pthread_cond_destroy_bridge},
    {"pthread_cond_wait", (uintptr_t)&pthread_cond_wait_bridge},
    {"pthread_cond_timedwait", (uintptr_t)&pthread_cond_timedwait_bridge},
    {"pthread_once", (uintptr_t)&pthread_once_bridge},
    {"pthread_create", (uintptr_t)&pthread_create_bridge},
    {"pthread_mutexattr_init", (uintptr_t)&pthread_mutexattr_init_bridge},
    {"pthread_mutexattr_settype", (uintptr_t)&pthread_mutexattr_settype_bridge},
    {"pthread_mutexattr_destroy", (uintptr_t)&pthread_mutexattr_destroy_bridge},
    {"pthread_join", (uintptr_t)&pthread_join_bridge},
    {"sem_destroy", (uintptr_t)&sem_destroy},
    // { "sem_getvalue", (uintptr_t)&sem_getvalue },
    {"sem_init", (uintptr_t)&sem_init},
    {"sem_post", (uintptr_t)&sem_post},
    // { "sem_trywait", (uintptr_t)&sem_trywait },
    {"sem_wait", (uintptr_t)&sem_wait},

    {NULL, (uintptr_t)NULL}
};