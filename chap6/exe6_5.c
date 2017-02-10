void undef(char *s)
{
    struct nlist *np;
    struct nlist *pre;

    for (pre = np = hashtab[hash(s)]; np != NULL; pre = np, np = np->next) {
        if (strcmp(s, np->name) == 0) {
            if (pre == np) {
                hashtab[hash(s)] = np->next;
            } else {
                pre->next = np->next;
            }
            free(np->name);
            free(np->defn);
            free(np);
        }
    }
}
