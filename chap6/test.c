#include <stdio.h>

typedef struct {
    int num;
} test_t;

typedef test_t num_t;

struct name_t_ {
    char *t;
};

typedef struct name_t_ * name_t;

void hello(name_t *name)
{
    printf("hello to: %s\n", (*name)->t);
}

int main(int argc, char *argv[])
{
    name_t *name;

    (*name)->t = "Jobs";
    hello(name);
}
