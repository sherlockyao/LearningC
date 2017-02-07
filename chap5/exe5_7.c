#define MAXLEN 1000

// assume lines has enough storage
int readlines(char *lineptr[], int maxlines, char *lines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    p = lines;
    while ((len = getline(line, MAXLEN)) > 0)
    {
        if (nlines >= maxlines) {
            return -1;
        } else {
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
            while (*p++ != '\0') {
            }
        }
    }
    return nlines;
}
