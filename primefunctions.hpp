#ifndef myPrimes_H
#define myPrimes_H

int get_primes_all(int q, std::vector<int> &store)
{
    store.push_back(2);
    int cur = 2;
    while (store.size() < q)
    {
        for (int i = 2; i < cur; i++)
            if (cur % i == 0)
                break;
            else if (i == (cur - 1))
                store.push_back(cur);
        cur++;
    }
    return 1;
}

void get_primes_odd(int q, std::vector<int> &store)
{
    store.push_back(3);
    int cur = 5;
    while (store.size() < (q - 1))
    {
        for (int i = 3; i < cur; i += 2)
            if (cur % i == 0)
                break;
            else if (i == (cur - 2))
                store.push_back(cur);
        cur += 2;
    }
    store.push_back(2);
}

void get_primes_half_odd(int q, std::vector<int> &store)
{
    store.push_back(3);
    int cur = 5;
    while (store.size() < (q - 1))
    {
        for (int i = 3; i < cur; i += 2)
            if (cur % i == 0)
                break;
            else if (i > (cur / 2))
            {
                store.push_back(cur);
                break;
            }
        cur += 2;
    }
    store.push_back(2);
}

void get_primes_half_found(int q, std::vector<int> &store)
{
    store.push_back(3);
    int cur = 5;
    while (store.size() < (q - 1))
    {
        for (int i : store)
            if (cur % i == 0)
                break;
            else if (i > (cur / 2))
            {
                store.push_back(cur);
                break;
            }
        cur += 2;
    }
    store.push_back(2);
}

#endif