#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdbool.h>
#ifdef __has_builtin
#if __has_builtin(__builtin_pow)
#define _zc_pow __builtin_pow
#endif
#endif
#ifndef _zc_pow
extern double pow(double, double);
#define _zc_pow pow
#endif
#include <unistd.h>
#include <fcntl.h>
#define ZC_SIMD(T, N) T __attribute__((vector_size(N * sizeof(T))))
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202300L
#define ZC_AUTO auto
#define ZC_AUTO_INIT(var, init) auto var = (init)
#else
#define ZC_AUTO __auto_type
#define ZC_AUTO_INIT(var, init) __auto_type var = (init)
#endif
#define ZC_CAST(T, x) ((T)(x))
#ifdef __TINYC__
#undef ZC_AUTO
#define ZC_AUTO __auto_type
#undef ZC_AUTO_INIT
#define ZC_AUTO_INIT(var, init) __typeof__((init)) var = (init)

#ifndef __builtin_expect
#define __builtin_expect(x, v) (x)
#endif

#ifndef __builtin_unreachable
#define __builtin_unreachable()
#endif
#else
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202300L
#define ZC_AUTO_INIT(var, init) auto var = (init)
#else
#define ZC_AUTO_INIT(var, init) __auto_type var = (init)
#endif
#endif
static inline const char* _z_bool_str(_Bool b) { return b ? "true" : "false"; }
#ifdef __SIZEOF_INT128__
static inline const char *_z_u128_str(unsigned __int128 val) {
    static _Thread_local char buf[40];
    if (val == 0) return "0";
    int i = 38;
    buf[39] = 0;
    while (val > 0) { buf[i--] = (char)((val % 10) + '0'); val /= 10; }
    return &buf[i + 1];
}
static inline const char *_z_i128_str(__int128 val) {
    static _Thread_local char buf[41];
    if (val == 0) return "0";
    int neg = val < 0;
    unsigned __int128 uval = neg ? -val : val;
    int i = 39;
    buf[40] = 0;
    while (uval > 0) { buf[i--] = (char)((uval % 10) + '0'); uval /= 10; }
    if (neg) buf[i--] = '-';
    return &buf[i + 1];
}
#define _z_128_map ,__int128: "%s", unsigned __int128: "%s"
#else
#define _z_128_map
#endif
#ifdef __OBJC__
#define _z_objc_map ,id: "%s", Class: "%s", SEL: "%s"
#define _z_objc_arg_map(x) ,id: [(id)(x) description].UTF8String, Class: class_getName((Class)(x)), SEL: sel_getName((SEL)(x))
#else
#define _z_objc_map
#define _z_objc_arg_map(x)
#endif

#define _z_str(x) _Generic((x), _Bool: "%s", char: "%c", signed char: "%c", unsigned char: "%u", short: "%d", unsigned short: "%u", int: "%d", unsigned int: "%u", long: "%ld", unsigned long: "%lu", long long: "%lld", unsigned long long: "%llu", float: "%f", double: "%f", char*: "%s", const char*: "%s", void*: "%p" _z_128_map _z_objc_map)
#ifdef __SIZEOF_INT128__
#define _z_safe_i128(x) _Generic((x), __int128: (x), default: (__int128)0)
#define _z_safe_u128(x) _Generic((x), unsigned __int128: (x), default: (unsigned __int128)0)
#define _z_128_arg_map(x) ,__int128: _z_i128_str(_z_safe_i128(x)), unsigned __int128: _z_u128_str(_z_safe_u128(x))
#else
#define _z_128_arg_map(x)
#endif
#define _z_safe_bool(x) _Generic((x), _Bool: (x), default: (_Bool)0)
#define _z_arg(x) _Generic((x), _Bool: _z_bool_str(_z_safe_bool(x)) _z_128_arg_map(x) _z_objc_arg_map(x), default: (x))
typedef size_t usize;
typedef char* string;
typedef struct { void *func; void *ctx; void (*drop)(void*); } z_closure_T;
static void *_z_closure_ctx_stash[256];
typedef void U0;
typedef int8_t I8;
typedef uint8_t U8;
typedef int16_t I16;
typedef uint16_t U16;
typedef int32_t I32;
typedef uint32_t U32;
typedef int64_t I64;
typedef uint64_t U64;
#define F32 float
#define F64 double
#define z_malloc malloc
#define z_realloc realloc
#define z_free free
#define z_print printf
void __zenc_panic(const char* msg) { fprintf(stderr, "Panic: %s\n", msg); exit(1); }
#if defined(__APPLE__)
#define _ZC_SEC __attribute__((used,section("__DATA,__zarch")))
#elif defined(_WIN32)
#define _ZC_SEC __attribute__((used))
#else
#define _ZC_SEC __attribute__((used,section(".note.zarch")))
#endif
static const unsigned char _zc_abi_v1[] _ZC_SEC = {0x07,0xd5,0x59,0x30,0x7c,0x7f,0x66,0x75,0x30,0x69,0x7f,0x65,0x3c,0x30,0x59,0x7c,0x79,0x7e,0x73,0x71};
void _z_autofree_impl(void *p) { void **pp = (void**)p; if(*pp) { z_free(*pp); *pp = NULL; } }
#define __zenc_assert(cond, ...) if (!(cond)) { fprintf(stderr, "\"Assertion failed: \" " __VA_ARGS__); exit(1); }
string _z_readln_raw() { size_t cap = 64; size_t len = 0; char *line = z_malloc(cap); if(!line) return NULL; int c; while((c = fgetc(stdin)) != EOF) { if(c == '\n') break; if(len + 1 >= cap) { cap *= 2; char *n = z_realloc(line, cap); if(!n) { z_free(line); return NULL; } line = n; } line[len++] = c; } if(len == 0 && c == EOF) { z_free(line); return NULL; } line[len] = 0; return line; }
int _z_scan_helper(const char *fmt, ...) { char *l = _z_readln_raw(); if(!l) return 0; va_list ap; va_start(ap, fmt); int r = vsscanf(l, fmt, ap); va_end(ap); z_free(l); return r; }
int _z_orig_stdout = -1;
void _z_suppress_stdout() {
    fflush(stdout);
    if (_z_orig_stdout == -1) _z_orig_stdout = dup(STDOUT_FILENO);
    int nullfd = open("/dev/null", O_WRONLY);
    dup2(nullfd, STDOUT_FILENO);
    close(nullfd);
}
void _z_restore_stdout() {
    fflush(stdout);
    if (_z_orig_stdout != -1) {
        dup2(_z_orig_stdout, STDOUT_FILENO);
        close(_z_orig_stdout);
        _z_orig_stdout = -1;
    }
}
#ifndef ZC_CFG_linux
#define ZC_CFG_linux 1
#endif
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef char* string;
typedef struct { void **data; int len; int cap; } Vec;
#define Vec_new() (Vec){.data=0, .len=0, .cap=0}
void _z_vec_push(Vec *v, void *item) { if(v->len >= v->cap) { v->cap = v->cap?v->cap*2:8; v->data = z_realloc(v->data, v->cap * sizeof(void*)); } v->data[v->len++] = item; }
static inline Vec _z_make_vec(int count, ...) { Vec v = {0}; v.cap = count > 8 ? count : 8; v.data = z_malloc(v.cap * sizeof(void*)); v.len = 0; va_list args; va_start(args, count); for(int i=0; i<count; i++) { v.data[v.len++] = va_arg(args, void*); } va_end(args); return v; }
#define Vec_push(v, i) _z_vec_push(&(v), (void*)(uintptr_t)(i))
static inline long _z_check_bounds(long index, long limit) { if(index < 0 || index >= limit) { fprintf(stderr, "Index out of bounds: %ld (limit %ld)\n", index, limit); exit(1); } return index; }

typedef struct Cell Cell;
struct Cell {
    bool m;
    bool o;
    bool f;
    int32_t n;
};

const int32_t N = 9;
int32_t main(void);
bool check(void);
void reveal(int32_t r, int32_t c);
void show(void);
void init(void);

#line 70 "src/main_window.zc"

int32_t main(void)
{
    {

#line 71 "src/main_window.zc"
init();

#line 72 "src/main_window.zc"
printf("=== Minesweeper ===\n");

#line 73 "src/main_window.zc"
show();

#line 74 "src/main_window.zc"
while (((!over) && (!win)))     {

#line 75 "src/main_window.zc"
printf("r c (0 flag): ");

#line 76 "src/main_window.zc"
mut;

#line 76 "src/main_window.zc"
r:;

#line 76 "src/main_window.zc"
(i32 = 0);

#line 77 "src/main_window.zc"
mut;

#line 77 "src/main_window.zc"
c:;

#line 77 "src/main_window.zc"
(i32 = 0);

#line 78 "src/main_window.zc"
if ((
#line 78 "src/main_window.zc"
scanf("%d %d", (&r), (&c)) != 2))     {

#line 78 "src/main_window.zc"
break;
    }

#line 79 "src/main_window.zc"
if ((((r == 0) && (c >= 1)) && (c <= 9)))     {

#line 80 "src/main_window.zc"
(b[((c - 1) / 9)][((c - 1) % 9)].f = (!b[((c - 1) / 9)][((c - 1) % 9)].f));
    }

#line 82 "src/main_window.zc"
 else if (((((r >= 1) && (r <= 9)) && (c >= 1)) && (c <= 9)))     {

#line 83 "src/main_window.zc"
reveal((r - 1), (c - 1));

#line 84 "src/main_window.zc"
if (
#line 84 "src/main_window.zc"
check())     {

#line 84 "src/main_window.zc"
(win = true);
    }
    }

#line 86 "src/main_window.zc"
show();
    }

#line 88 "src/main_window.zc"
if (over)     {

#line 88 "src/main_window.zc"
printf("BOOM! Game Over!\n");
    }

#line 89 "src/main_window.zc"
if (win)     {

#line 89 "src/main_window.zc"
printf("You Win!\n");
    }

#line 90 "src/main_window.zc"
    return 0;
    }
}

#line 63 "src/main_window.zc"

bool check(void)
{
    {

#line 64 "src/main_window.zc"
for (ZC_AUTO r = 0; r < 9; r++)     {
for (ZC_AUTO c = 0; c < 9; c++)     {

#line 65 "src/main_window.zc"
if (((!b[r][c].m) && (!b[r][c].o)))     {

#line 65 "src/main_window.zc"
    return false;
    }
    }
    }

#line 67 "src/main_window.zc"
    return true;
    }
}

#line 47 "src/main_window.zc"

void reveal(int32_t r, int32_t c)
{
    {

#line 48 "src/main_window.zc"
if ((r < 0))     {

#line 48 "src/main_window.zc"
    return ;
    }

#line 49 "src/main_window.zc"
if ((r >= 9))     {

#line 49 "src/main_window.zc"
    return ;
    }

#line 50 "src/main_window.zc"
if ((c < 0))     {

#line 50 "src/main_window.zc"
    return ;
    }

#line 51 "src/main_window.zc"
if ((c >= 9))     {

#line 51 "src/main_window.zc"
    return ;
    }

#line 52 "src/main_window.zc"
if (b[r][c].o)     {

#line 52 "src/main_window.zc"
    return ;
    }

#line 53 "src/main_window.zc"
if (b[r][c].f)     {

#line 53 "src/main_window.zc"
    return ;
    }

#line 54 "src/main_window.zc"
(b[r][c].o = true);

#line 55 "src/main_window.zc"
if (b[r][c].m)     {

#line 55 "src/main_window.zc"
(over = true);

#line 55 "src/main_window.zc"
    return ;
    }

#line 56 "src/main_window.zc"
if ((b[r][c].n == 0))     {

#line 57 "src/main_window.zc"
for (ZC_AUTO dr = (-1); dr <= 1; dr++)     {
for (ZC_AUTO dc = (-1); dc <= 1; dc++)     {

#line 58 "src/main_window.zc"
if (((dr != 0) || (dc != 0)))     {

#line 58 "src/main_window.zc"
reveal((r + dr), (c + dc));
    }
    }
    }
    }
    }
}

#line 33 "src/main_window.zc"

void show(void)
{
    {

#line 34 "src/main_window.zc"
printf(" 123456789\n +--------+\n");

#line 35 "src/main_window.zc"
for (ZC_AUTO r = 0; r < 9; r++)     {

#line 35 "src/main_window.zc"
printf("%d|", (r + 1));

#line 36 "src/main_window.zc"
for (ZC_AUTO c = 0; c < 9; c++)     {

#line 37 "src/main_window.zc"
if (b[r][c].f)     {

#line 37 "src/main_window.zc"
printf("F");
    }

#line 38 "src/main_window.zc"
 else if ((!b[r][c].o))     {

#line 38 "src/main_window.zc"
printf(".");
    }

#line 39 "src/main_window.zc"
 else if (b[r][c].m)     {

#line 39 "src/main_window.zc"
printf("*");
    }
 else     {

#line 40 "src/main_window.zc"
printf("%d", b[r][c].n);
    }
    }

#line 42 "src/main_window.zc"
printf("|\n");
    }

#line 44 "src/main_window.zc"
printf(" +--------+\n");
    }
}

#line 13 "src/main_window.zc"

void init(void)
{
    {

#line 14 "src/main_window.zc"
for (ZC_AUTO r = 0; r < 9; r++)     {
for (ZC_AUTO c = 0; c < 9; c++)     {

#line 14 "src/main_window.zc"
(b[r][c] = (struct Cell){.m = false, .o = false, .f = false});
    }
    }

#line 15 "src/main_window.zc"
srand(((uint32_t)(time(0))));

#line 16 "src/main_window.zc"
mut;

#line 16 "src/main_window.zc"
k:;

#line 16 "src/main_window.zc"
(i32 = 0);

#line 17 "src/main_window.zc"
while ((k < 10))     {

#line 18 "src/main_window.zc"
    ZC_AUTO r = 
#line 18 "src/main_window.zc"
rand();

#line 18 "src/main_window.zc"
as;

#line 18 "src/main_window.zc"
(i32 % 9);

#line 19 "src/main_window.zc"
    ZC_AUTO c = 
#line 19 "src/main_window.zc"
rand();

#line 19 "src/main_window.zc"
as;

#line 19 "src/main_window.zc"
(i32 % 9);

#line 20 "src/main_window.zc"
if ((!b[r][c].m))     {

#line 20 "src/main_window.zc"
(b[r][c].m = true);
(k = (k + 1));
    }
    }

#line 22 "src/main_window.zc"
for (ZC_AUTO r = 0; r < 9; r++)     {
for (ZC_AUTO c = 0; c < 9; c++)     {

#line 23 "src/main_window.zc"
if (b[r][c].m)     {

#line 23 "src/main_window.zc"
continue;
    }

#line 24 "src/main_window.zc"
mut;

#line 24 "src/main_window.zc"
t:;

#line 24 "src/main_window.zc"
(i32 = 0);

#line 25 "src/main_window.zc"
for (ZC_AUTO dr = (-1); dr <= 1; dr++)     {
for (ZC_AUTO dc = (-1); dc <= 1; dc++)     {

#line 26 "src/main_window.zc"
    int32_t nr = (r + dr);
    int32_t nc = (c + dc);

#line 27 "src/main_window.zc"
if ((((((nr >= 0) && (nr < 9)) && (nc >= 0)) && (nc < 9)) && b[nr][nc].m))     {

#line 27 "src/main_window.zc"
(t = (t + 1));
    }
    }
    }

#line 29 "src/main_window.zc"
(b[r][c].n = t);
    }
    }
    }
}
