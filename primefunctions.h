#ifndef pFuncs_H
#define pFuncs_H

void get_primes_all(int q, int *store)
{
    // extern char msg[50], head[10];
    // strcpy(head, "added");
    int found, cur;
    store[0] = 2;
    found = 1;
    cur = 2;
    while (found < q)
    {
        for (int i = 2; i < cur; i++)
            if (cur % i == 0)
                break;
            else if (i == (cur - 1))
            {
                store[found] = cur;
                // sprintf(msg, "%d has bean added", cur);
                // show();
                found++;
            }
        cur++;
    }
}

void get_primes_odd(int q, int *store)
{
    // extern char msg[50], head[10];
    // strcpy(head, "added");
    int found, cur;
    store[0] = 2;
    store[1] = 3;
    found = 2;
    cur = 5;
    while (found < q)
    {
        for (int i = 3; i < cur; i += 2)
            if (cur % i == 0)
                break;
            else if (i == (cur - 2))
            {
                store[found] = cur;
                // sprintf(msg, "%d has bean added", cur);
                // show();
                found++;
            }
        cur += 2;
    }
}

void get_primes_half_odd(int q, int *store)
{
    // extern char msg[50], head[10];
    // strcpy(head, "added");
    int found, cur;
    store[0] = 2;
    store[1] = 3;
    found = 2;
    cur = 5;
    while (found < q)
    {
        for (int i = 3; i < cur; i += 2)
            if (cur % i == 0)
                break;
            else if (i > (cur / 2))
            {
                store[found] = cur;
                // sprintf(msg, "%d has bean added", cur);
                // show();
                found++;
                break;
            }
        cur += 2;
    }
}

void get_primes_half_primes(int q, int *store)
{
    // extern char msg[50], head[10];
    // strcpy(head, "added");
    int found, cur;
    store[0] = 2;
    store[1] = 3;
    found = 2;
    cur = 5;
    while (found < q)
    {
        for (int i = 1; i < found; i++)
            if (cur % store[i] == 0)
                break;
            else if (store[i] > (cur / 2))
            {
                store[found] = cur;
                // sprintf(msg, "%d has bean added", cur);
                // show();
                found++;
                break;
            }
        cur += 2;
    }
}

#endif