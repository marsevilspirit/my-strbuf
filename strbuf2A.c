#include "strbuf.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

void strbuf_init(struct strbuf *sb, size_t alloc)
{
    sb->buf = (char *)malloc(sizeof(size_t)*alloc);   
    sb->alloc = alloc;
    int len = 0;
}

void strbuf_attach(struct strbuf *sb, void *str, size_t len, size_t alloc)
{
    if(len < alloc)
    {
        strcpy(sb->buf,str);
        return;
    }

    sb->buf = realloc(str, len+1);
    memcpy(sb->buf, str, len);
    sb->len = len;
    sb->alloc = alloc;
}

void strbuf_release(struct strbuf *sb)
{
    free(sb);
    sb->buf = NULL;
}

void strbuf_swap(struct strbuf *a, struct strbuf *b)
{
    struct strbuf * temp = a;
    a = b;
    b = temp;
}

char *strbuf_detach(struct strbuf *sb, size_t *sz)
{
    char *str = sb->buf;
    *sz = sb->alloc;
    sb->len = 0;
    sb->buf = NULL;
    return str;
}

int strbuf_cmp(const struct strbuf *first, const struct strbuf *second)
{
    if(first->len != second->len)
    {
        return 0;
    }

    return (memcmp(first->buf,second->buf,first->len) == 0);
}

void strbuf_reset(struct strbuf *sb)
{
    if(sb->buf != NULL)
    {
        free(sb->buf);
    }
    sb->buf = NULL;
    sb->len = 0;
    sb->alloc = 0;
}
