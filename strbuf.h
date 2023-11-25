#include <stddef.h>
struct strbuf {
  int len;     //当前缓冲区（字符串）长度
  int alloc;   //当前缓冲区（字符串）容量
  char *buf;   //缓冲区（字符串）
};

//初始化 sb 结构体，容量为 alloc
void strbuf_init(struct strbuf *sb, size_t alloc);

//将字符串填充到 sb 中，长度为 len, 容量为 alloc
void strbuf_attach(struct strbuf *sb, void *str, size_t len, size_t alloc);

//释放 sb 结构体的内存
void strbuf_release(struct strbuf *sb);

//交换两个 strbuf
void strbuf_swap(struct strbuf *a, struct strbuf *b);

//将 sb 中的原始内存取出，并将 sz 设置为其 alloc 大小
char *strbuf_detach(struct strbuf *sb, size_t *sz);

//比较两个 strbuf 的内存是否相同
int strbuf_cmp(const struct strbuf *first, const struct strbuf *second);

//清空 sb 
void strbuf_reset(struct strbuf *sb);

