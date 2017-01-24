#include <stdio.h>

#define NORMAL 0
#define IN_QUOTE 1
#define IN_COMMENT 2
#define PRE_COMMENT 3
#define FIN_COMMENT 4

#define SINGLE_QUOTE 1
#define DOUBLE_QUOTE 2

main() {
    int c, state, mode;

    state = NORMAL;
    mode = 0;
    while ((c = getchar()) != EOF) {
        /*
        类似一个状态机的东西
        */
        if (state == NORMAL) {
            if ('\'' == c) {
                state = IN_QUOTE;
                mode = SINGLE_QUOTE;
                putchar(c);
            } else if ('"' == c) {
                state = IN_QUOTE;
                mode = DOUBLE_QUOTE;
                putchar(c);
            } else if ('/' == c) {
                state = PRE_COMMENT;
            } else {
                putchar(c);
            }
        } else if (state == IN_QUOTE) {
            putchar(c);
            if ('\'' == c || '"' == c) {
                if (mode == SINGLE_QUOTE && '\'' == c) {
                    state = NORMAL;
                } else if (mode == DOUBLE_QUOTE && '"' == c) {
                    state = NORMAL;
                }
            }
        } else if (state == IN_COMMENT) { /* 如果在comment中，只有出现*才可能会结束comment */
            if ('*' == c) {
                state = FIN_COMMENT;
            }
        } else if (state == PRE_COMMENT) {
            if ('*' == c) {
                state = IN_COMMENT;
            } else {
                putchar('/');
                if ('\'' == c) {
                    state = IN_QUOTE;
                    mode = SINGLE_QUOTE;
                    putchar(c);
                } else if ('"' == c) {
                    state = IN_QUOTE;
                    mode = DOUBLE_QUOTE;
                    putchar(c);
                } else if ('/' == c) {
                    state = PRE_COMMENT;
                } else {
                    putchar(c);
                }
            }
        } else if (state == FIN_COMMENT) {
            if ('/' == c) {
                state = NORMAL;
            } else if ('*' == c) {
                state = FIN_COMMENT;
            } else {
                state = IN_COMMENT;
            }
        }

    }
    printf("这个就是为了测试字符串中的评论 /*hello world */ \n");

    return 0;
}
