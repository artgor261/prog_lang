int com(int num_1, int num_2);
int coml(int num, int prev);
int add(int num_1, int num_2);
int addl(int num, int prev);
int sb(int num_1, int num_2);
int sbl(int num, int prev);

const int COUNT = 6;

const struct {
    char *name;
    int (*func)(int, int);
} func_map[] = {
    {"add", &add},
    {"addl", &addl},
    {"sb", &sb},
    {"sbl", &sbl},
    {"com", &com},
    {"coml", &coml}
};
