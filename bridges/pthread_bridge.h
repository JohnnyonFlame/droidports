#ifndef __PTHREAD_BRIDGE_H__
#define __PTHREAD_BRIDGE_H__

#include <errno.h>
#include <stdint.h>
#include <pthread.h>

#include "platform.h"

typedef struct
{
    // real bionic has "value" here - bridged uses a pointer to an actual pthread struct
    union {
        int volatile value;
        pthread_mutex_t *real_mtx;
    };
} BIONIC_pthread_mutex_t;

typedef struct BIONIC_Mutex {
    void *vmt;
    BIONIC_pthread_mutex_t mutex;
} BIONIC_Mutex;

ABI_ATTR extern int   pthread_key_create_bridge(pthread_key_t *key, void (*destr_function) (void *));
ABI_ATTR extern int   pthread_key_delete_bridge(pthread_key_t key);
ABI_ATTR extern int   pthread_setspecific_bridge(pthread_key_t key, const void *__pointer);
ABI_ATTR extern void* pthread_getspecific_bridge(pthread_key_t key);
ABI_ATTR extern int   pthread_mutex_init_bridge(BIONIC_pthread_mutex_t *uid, pthread_mutexattr_t **mutexattr);
ABI_ATTR extern int   pthread_mutex_destroy_fake(BIONIC_pthread_mutex_t *uid);
ABI_ATTR extern int   pthread_mutex_lock_bridge(BIONIC_pthread_mutex_t *uid);
ABI_ATTR extern int   pthread_mutex_unlock_bridge(BIONIC_pthread_mutex_t *uid);
ABI_ATTR extern int   pthread_cond_init_bridge(pthread_cond_t **cnd, const int *condattr);
ABI_ATTR extern int   pthread_cond_broadcast_bridge(pthread_cond_t **cnd);
ABI_ATTR extern int   pthread_cond_signal_bridge(pthread_cond_t **cnd);
ABI_ATTR extern int   pthread_cond_destroy_bridge(pthread_cond_t **cnd);
ABI_ATTR extern int   pthread_cond_wait_bridge(pthread_cond_t **cnd, BIONIC_pthread_mutex_t *mtx);
ABI_ATTR extern int   pthread_cond_timedwait_bridge(pthread_cond_t **cnd, BIONIC_pthread_mutex_t *mtx, const struct timespec *t);
ABI_ATTR extern int   pthread_once_bridge(volatile int *once_control, void (*init_routine)(void));
ABI_ATTR extern int   pthread_create_bridge(pthread_t *thread, const void *unused, void *(*entry)(void *), void *arg);
ABI_ATTR extern int   pthread_mutexattr_init_bridge(pthread_mutexattr_t **attr_ptr);
ABI_ATTR extern int   pthread_mutexattr_settype_bridge(pthread_mutexattr_t **attr_ptr, int kind);
ABI_ATTR extern int   pthread_mutexattr_destroy_bridge(pthread_mutexattr_t **attr_ptr);
ABI_ATTR extern int   pthread_join_bridge(pthread_t th, void **thread_return);

#endif /* __PTHREAD_BRIDGE_H__ */