#include <stdio.h>

// define state
#define NORMAL              0
#define SINGLE_QUOTE        1
#define DOUBLE_QUOTE        2
#define ESCAPE_SINGLE_QUOTE 3
#define ESCAPE_DOUBLE_QUOTE 4
#define INLINE_COMMENT      5
#define MULTI_COMMENT       6
#define PRE_COMMENT         7
#define FIN_COMMENT         8

int stateFromNormal(char c) {
    if ('\'' == c) {
        return SINGLE_QUOTE;
    } else if ('"' == c) {
        return DOUBLE_QUOTE;
    } else if ('/' == c) {
        return PRE_COMMENT;
    } else {
        return NORMAL;
    }
}

int stateFromSingleQuote(char c) {
    if ('\'' == c) {
        return NORMAL;
    } else if ('\\' == c) {
        return ESCAPE_SINGLE_QUOTE;
    } else {
        return SINGLE_QUOTE;
    }
}

int stateFromDoubleQuote(char c) {
    if ('"' == c) {
        return NORMAL;
    } else if ('\\' == c) {
        return ESCAPE_DOUBLE_QUOTE;
    } else {
        return DOUBLE_QUOTE;
    }
}

int stateFromEscapeSingleQuote(char c) {
    return SINGLE_QUOTE;
}

int stateFromEscapeDoubleQuote(char c) {
    return DOUBLE_QUOTE;
}

int stateFromInlineComment(char c) {
    if ('\n' == c) {
        return NORMAL;
    } else {
        return INLINE_COMMENT;
    }
}

int stateFromMultiComment(char c) {
    if ('*' == c) {
        return FIN_COMMENT;
    } else {
        return MULTI_COMMENT;
    }
}

int stateFromPreComment(char c) {
    if ('*' == c) {
        return MULTI_COMMENT;
    } else if ('/' == c) {
        return INLINE_COMMENT;
    } else {
        return stateFromNormal(c);
    }
}

int stateFromFinComment(char c) {
    if ('/' == c) {
        return NORMAL;
    } else if ('*' == c) {
        return FIN_COMMENT;
    } else {
        return MULTI_COMMENT;
    }
}

int stateFrom(int preState, char c) {
    if (preState == NORMAL) {
        return stateFromNormal(c);
    } else if (preState == SINGLE_QUOTE) {
        return stateFromSingleQuote(c);
    } else if (preState == DOUBLE_QUOTE) {
        return stateFromDoubleQuote(c);
    } else if (preState == ESCAPE_SINGLE_QUOTE) {
        return stateFromEscapeSingleQuote(c);
    } else if (preState == ESCAPE_DOUBLE_QUOTE) {
        return stateFromEscapeDoubleQuote(c);
    } else if (preState == INLINE_COMMENT) {
        return stateFromInlineComment(c);
    } else if (preState == MULTI_COMMENT) {
        return stateFromMultiComment(c);
    } else if (preState == PRE_COMMENT) {
        return stateFromPreComment(c);
    } else if (preState == FIN_COMMENT) {
        return stateFromFinComment(c);
    } else {
        return -1;
    }
}



main() {
    char stack[1000];
    int i, c, state;

    i = 0;
    state = NORMAL;
    while ((c = getchar()) != EOF) {
        state = stateFrom(state, c);
        if (NORMAL == state) {
            if ('[' == c || '(' == c || '{' == c) {
                stack[i++] = c;
            } else if (']' == c || ')' == c || '}' == c) {
                if (i <= 0) {
                    printf("Unexpected %c\n", c);
                    return 1;
                }
                char match;
                if (']' == c) {
                    match = '[';
                } else if (')' == c) {
                    match = '(';
                } else if ('}' == c) {
                    match = '{';
                } else {
                    match = '\0';
                }
                if (match != stack[i - 1]) {
                    printf("Unexpected %c\n", c);
                    return 1;
                }
                i--;
            }
        }
    }

    if (i > 0) {
		printf("Unbalanced %c\n", stack[0]);
		return 1;
	} else {
		printf("Balanced\n");
	}

    return 0;
}
