#include <iostream>
#include <pthread.h>

using namespace std;

#define NUM_THREADS 5 // number of threads

void *say_hello(void *t_id)
{
    int tid = *((int *)t_id);
    cout << "Hello World \t" << tid << endl;
    pthread_exit(NULL);
}

// g++ t.cpp -lpthread -o test.o
int main()
{
    pthread_t tids[NUM_THREADS];

    int indexes[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; ++i)
    {

        int ret = pthread_create(&tids[i], NULL, say_hello, NULL);
        if (ret != 0)
        {
            cout << "pthread_create error: error_code=" << ret << endl;
        }
    }

    pthread_exit(NULL);
}
