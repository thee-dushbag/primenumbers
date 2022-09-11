#ifndef utiL_H
#define utiL_H

char msg[50], head[10];

void show()
{
    extern char msg[50], head[10];
    upper(head);
    char *Head = (char *)malloc(10 * sizeof(char));
    strncpy(Head, head, 10);
    int l = (int)strlen(Head);
    while (l < 10)
    {
        Head[l] = ' ';
        l++;
    }
    printf("[ %s ] : %s\n", Head, msg);
    free(Head);
}

float timer(void func(int, int *store), int q, int *store, const char *funcname)
{
    extern char head[10], msg[50];
    strcpy(head, "running");
    sprintf(msg, "%s(%d)", funcname, q);
    show();
    time_t t[2];
    t[0] = time(NULL);
    func(q, store);
    t[1] = time(NULL);
    float T = (float)difftime(t[1], t[0]);
    strcpy(head, "tested");
    sprintf(msg, "%s(%d) took %f seconds", funcname, q, T);
    show();
    return T;
}

struct bundle
{
    void (*func)(int, int*);
    int q;
    int *store;
    const char *funcname;
    float exectime;
};

void speedtest(struct bundle *bud, int size)
{
    int i;
    float highest = 0.0, ratio;
    extern char head[10], msg[50];
    for (i = 0; i < size; i++)
        bud[i].exectime = timer(*bud[i].func, bud[i].q, bud[i].store, bud[i].funcname);
    for (i = 0; i < size; i++)
        if (bud[i].exectime > highest)
            highest = bud[i].exectime;
    strcpy(head, "nb");
    strcpy(msg, "compared to the slowest function");
    show();
    strcpy(head, "ratio");
    for (i = 0; i < size; i++)
    {
        ratio = (float)(highest / bud[i].exectime);
        sprintf(msg, "%.2fx | %s(%d)", ratio, bud[i].funcname, bud[i].q);
        show();
    }
}

#endif
