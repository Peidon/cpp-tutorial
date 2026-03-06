#include <iostream>
#include <pthread.h>

using namespace std;

#define NUM_THREADS 5 // number of threads

void *say_hello(void *t_id)
{
    int tid = *static_cast<int *>(t_id);
    cout << "Hello World \t" << tid << endl;
    pthread_exit(nullptr);
}

// g++ t.cpp -lpthread -o test.o
int main()
{
    pthread_t tids[NUM_THREADS];

    // int indexes[NUM_THREADS];

    for (pthread_t & tid : tids)
    {

        const int ret = pthread_create(&tid, nullptr, say_hello, nullptr);
        if (ret != 0)
        {
            cout << "pthread_create error: error_code=" << ret << endl;
        }
    }

    pthread_exit(nullptr);
}
