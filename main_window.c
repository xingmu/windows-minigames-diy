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
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdarg.h>
#include "math.h"
typedef char* string;
typedef struct { void **data; int len; int cap; } Vec;
#define Vec_new() (Vec){.data=0, .len=0, .cap=0}
void _z_vec_push(Vec *v, void *item) { if(v->len >= v->cap) { v->cap = v->cap?v->cap*2:8; v->data = z_realloc(v->data, v->cap * sizeof(void*)); } v->data[v->len++] = item; }
static inline Vec _z_make_vec(int count, ...) { Vec v = {0}; v.cap = count > 8 ? count : 8; v.data = z_malloc(v.cap * sizeof(void*)); v.len = 0; va_list args; va_start(args, count); for(int i=0; i<count; i++) { v.data[v.len++] = va_arg(args, void*); } va_end(args); return v; }
#define Vec_push(v, i) _z_vec_push(&(v), (void*)(uintptr_t)(i))
static inline long _z_check_bounds(long index, long limit) { if(index < 0 || index >= limit) { fprintf(stderr, "Index out of bounds: %ld (limit %ld)\n", index, limit); exit(1); } return index; }
typedef struct Tuple__int32_t__int32_t Tuple__int32_t__int32_t;
struct Tuple__int32_t__int32_t { int32_t v0; int32_t v1; };

typedef struct VecIterResult__String VecIterResult__String;
typedef struct VecIterRef__String VecIterRef__String;
typedef struct VecIter__String VecIter__String;
typedef struct Vec__String Vec__String;
typedef struct VecIterResult__int32_t VecIterResult__int32_t;
typedef struct VecIterRef__int32_t VecIterRef__int32_t;
typedef struct VecIter__int32_t VecIter__int32_t;
typedef struct Vec__int32_t Vec__int32_t;
typedef struct VecIterResult__size_t VecIterResult__size_t;
typedef struct VecIterRef__size_t VecIterRef__size_t;
typedef struct VecIter__size_t VecIter__size_t;
typedef struct Vec__size_t Vec__size_t;
typedef struct Option__size_t Option__size_t;
typedef struct Option__int32_t Option__int32_t;
typedef struct VecIterResult__char VecIterResult__char;
typedef struct VecIterRef__char VecIterRef__char;
typedef struct Option__char Option__char;
typedef struct VecIter__char VecIter__char;
typedef struct Vec__char Vec__char;
typedef struct Ball Ball;
typedef struct Paddle Paddle;
typedef struct Math Math;
typedef struct FBData FBData;
typedef struct Color Color;
typedef struct WNDCLASSA WNDCLASSA;
typedef struct StringCharsIter StringCharsIter;
typedef struct Sort Sort;
typedef struct GameStatus GameStatus;
typedef struct KeyCode KeyCode;
typedef struct EventType EventType;
typedef struct Brick Brick;
typedef struct Event Event;
typedef struct String String;
typedef struct Option__String Option__String;
typedef struct BrickGrid BrickGrid;
typedef struct BreakoutState BreakoutState;
GameStatus GameStatus__Ready();
GameStatus GameStatus__Playing();
GameStatus GameStatus__Lost();
GameStatus GameStatus__Won();
KeyCode KeyCode__KeyUnknown();
KeyCode KeyCode__KeyUp();
KeyCode KeyCode__KeyDown();
KeyCode KeyCode__KeyLeft();
KeyCode KeyCode__KeyRight();
KeyCode KeyCode__KeySpace();
KeyCode KeyCode__KeyEscape();
KeyCode KeyCode__KeyR();
KeyCode KeyCode__KeyW();
KeyCode KeyCode__KeyA();
KeyCode KeyCode__KeyS();
KeyCode KeyCode__KeyD();
KeyCode KeyCode__KeyP();
EventType EventType__EventNone();
EventType EventType__EventKeyDown();
EventType EventType__EventKeyUp();
EventType EventType__EventMouseMove();
EventType EventType__EventMouseDown();
EventType EventType__EventMouseUp();
EventType EventType__EventWindowClose();
EventType EventType__EventWindowResize();
EventType EventType__EventTimer();
typedef z_closure_T MouseHandler;
typedef z_closure_T PaintHandler;
typedef z_closure_T TimerHandler;
typedef z_closure_T KeyHandler;
typedef z_closure_T TimerCallback;
typedef void* GraphicsContext;
typedef void* WindowHandle;
typedef void* WindowHandle;
typedef void* GraphicsContext;
typedef z_closure_T TimerCallback;
typedef z_closure_T KeyHandler;
typedef z_closure_T TimerHandler;
typedef z_closure_T PaintHandler;
typedef z_closure_T MouseHandler;
typedef struct Clone_VTable {
    void* (*clone)(void* self);
} Clone_VTable;
typedef struct Clone { void *self; Clone_VTable *vtable; } Clone;

typedef struct Copy_VTable {
} Copy_VTable;
typedef struct Copy { void *self; Copy_VTable *vtable; } Copy;

typedef struct Drop_VTable {
    void (*drop)(void* self);
} Drop_VTable;
typedef struct Drop { void *self; Drop_VTable *vtable; } Drop;


    #define ZC_IMPL_SORT(T) \
    static int _z_partition_##T(T* arr, int low, int high) { \
        T pivot = arr[high]; \
        int i = low - 1; \
        for (int j = low; j < high; j++) { \
            if (arr[j] < pivot) { \
                i++; \
                T temp = arr[i]; \
                arr[i] = arr[j]; \
                arr[j] = temp; \
            } \
        } \
        T temp2 = arr[i + 1]; \
        arr[i + 1] = arr[high]; \
        arr[high] = temp2; \
        return i + 1; \
    } \
    static void _z_quick_sort_##T(T* arr, int low, int high) { \
        if (low < high) { \
            int pivot_idx = _z_partition_##T(arr, low, high); \
            _z_quick_sort_##T(arr, low, pivot_idx - 1); \
            _z_quick_sort_##T(arr, pivot_idx + 1, high); \
        } \
    } \
    void sort_##T(T* arr, size_t len) { \
        if (len > 1) { \
            _z_quick_sort_##T(arr, 0, (int)len - 1); \
        } \
    }

    // Pre-declare standard library types
    ZC_IMPL_SORT(int)
    ZC_IMPL_SORT(long)
    ZC_IMPL_SORT(float)
    ZC_IMPL_SORT(double)

#if defined(_WIN32) || defined(WIN32) || defined(__WIN32__) || defined(__NT__)

#define IS_WINDOWS 1

#define IS_LINUX 0

#define IS_MACOS 0

#elif defined(__linux__)

#define IS_WINDOWS 0

#define IS_LINUX 1

#elif defined(__APPLE__) && defined(__MACH__)

#define IS_MACOS 1

#else

#error "Unsupported platform"

#endif

#if IS_WINDOWS

struct VecIterResult__String {
    String* ptr;
};

struct VecIterRef__String {
    String* data;
    size_t count;
    size_t idx;
};

struct VecIter__String {
    String* data;
    size_t count;
    size_t idx;
};

struct Vec__String {
    String* data;
    size_t len;
    size_t cap;
};

struct VecIterResult__int32_t {
    int32_t* ptr;
};

struct VecIterRef__int32_t {
    int32_t* data;
    size_t count;
    size_t idx;
};

struct VecIter__int32_t {
    int32_t* data;
    size_t count;
    size_t idx;
};

struct Vec__int32_t {
    int32_t* data;
    size_t len;
    size_t cap;
};

struct VecIterResult__size_t {
    size_t* ptr;
};

struct VecIterRef__size_t {
    size_t* data;
    size_t count;
    size_t idx;
};

struct VecIter__size_t {
    size_t* data;
    size_t count;
    size_t idx;
};

struct Vec__size_t {
    size_t* data;
    size_t len;
    size_t cap;
};

struct Option__size_t {
    bool is_some;
    size_t val;
};

struct Option__int32_t {
    bool is_some;
    int32_t val;
};

struct VecIterResult__char {
    char* ptr;
};

struct VecIterRef__char {
    char* data;
    size_t count;
    size_t idx;
};

struct Option__char {
    bool is_some;
    char val;
};

struct VecIter__char {
    char* data;
    size_t count;
    size_t idx;
};

struct Vec__char {
    char* data;
    size_t len;
    size_t cap;
};

struct Ball {
    int32_t x;
    int32_t y;
    int32_t vx;
    int32_t vy;
    int32_t radius;
};

struct Paddle {
    int32_t x;
    int32_t y;
    int32_t width;
    int32_t height;
    int32_t speed;
};

struct Math {
    char _placeholder;
};

struct FBData {
    void* window;
    int32_t width;
    int32_t height;
    void* hdc;
    void* memDC;
    void* bitmap;
    void* buffer;
    bool valid;
};

struct Color {
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

struct WNDCLASSA {
    uint32_t style;
    void* lpfnWndProc;
    void* hInstance;
    void* hIcon;
    void* hCursor;
    void* hbrBackground;
    int8_t* lpszMenuName;
    int8_t* lpszClassName;
};

struct StringCharsIter {
    char* data;
    size_t len;
    size_t pos;
};

struct Sort {
    char _placeholder;
};

typedef enum { GameStatus__Ready_Tag, GameStatus__Playing_Tag, GameStatus__Lost_Tag, GameStatus__Won_Tag, } GameStatus_Tag;
struct GameStatus { GameStatus_Tag tag; union { } data; };

GameStatus GameStatus__Ready() { return (GameStatus){.tag=GameStatus__Ready_Tag}; }
GameStatus GameStatus__Playing() { return (GameStatus){.tag=GameStatus__Playing_Tag}; }
GameStatus GameStatus__Lost() { return (GameStatus){.tag=GameStatus__Lost_Tag}; }
GameStatus GameStatus__Won() { return (GameStatus){.tag=GameStatus__Won_Tag}; }
typedef enum { KeyCode__KeyUnknown_Tag, KeyCode__KeyUp_Tag, KeyCode__KeyDown_Tag, KeyCode__KeyLeft_Tag, KeyCode__KeyRight_Tag, KeyCode__KeySpace_Tag, KeyCode__KeyEscape_Tag, KeyCode__KeyR_Tag, KeyCode__KeyW_Tag, KeyCode__KeyA_Tag, KeyCode__KeyS_Tag, KeyCode__KeyD_Tag, KeyCode__KeyP_Tag, } KeyCode_Tag;
struct KeyCode { KeyCode_Tag tag; union { } data; };

KeyCode KeyCode__KeyUnknown() { return (KeyCode){.tag=KeyCode__KeyUnknown_Tag}; }
KeyCode KeyCode__KeyUp() { return (KeyCode){.tag=KeyCode__KeyUp_Tag}; }
KeyCode KeyCode__KeyDown() { return (KeyCode){.tag=KeyCode__KeyDown_Tag}; }
KeyCode KeyCode__KeyLeft() { return (KeyCode){.tag=KeyCode__KeyLeft_Tag}; }
KeyCode KeyCode__KeyRight() { return (KeyCode){.tag=KeyCode__KeyRight_Tag}; }
KeyCode KeyCode__KeySpace() { return (KeyCode){.tag=KeyCode__KeySpace_Tag}; }
KeyCode KeyCode__KeyEscape() { return (KeyCode){.tag=KeyCode__KeyEscape_Tag}; }
KeyCode KeyCode__KeyR() { return (KeyCode){.tag=KeyCode__KeyR_Tag}; }
KeyCode KeyCode__KeyW() { return (KeyCode){.tag=KeyCode__KeyW_Tag}; }
KeyCode KeyCode__KeyA() { return (KeyCode){.tag=KeyCode__KeyA_Tag}; }
KeyCode KeyCode__KeyS() { return (KeyCode){.tag=KeyCode__KeyS_Tag}; }
KeyCode KeyCode__KeyD() { return (KeyCode){.tag=KeyCode__KeyD_Tag}; }
KeyCode KeyCode__KeyP() { return (KeyCode){.tag=KeyCode__KeyP_Tag}; }
typedef enum { EventType__EventNone_Tag, EventType__EventKeyDown_Tag, EventType__EventKeyUp_Tag, EventType__EventMouseMove_Tag, EventType__EventMouseDown_Tag, EventType__EventMouseUp_Tag, EventType__EventWindowClose_Tag, EventType__EventWindowResize_Tag, EventType__EventTimer_Tag, } EventType_Tag;
struct EventType { EventType_Tag tag; union { } data; };

EventType EventType__EventNone() { return (EventType){.tag=EventType__EventNone_Tag}; }
EventType EventType__EventKeyDown() { return (EventType){.tag=EventType__EventKeyDown_Tag}; }
EventType EventType__EventKeyUp() { return (EventType){.tag=EventType__EventKeyUp_Tag}; }
EventType EventType__EventMouseMove() { return (EventType){.tag=EventType__EventMouseMove_Tag}; }
EventType EventType__EventMouseDown() { return (EventType){.tag=EventType__EventMouseDown_Tag}; }
EventType EventType__EventMouseUp() { return (EventType){.tag=EventType__EventMouseUp_Tag}; }
EventType EventType__EventWindowClose() { return (EventType){.tag=EventType__EventWindowClose_Tag}; }
EventType EventType__EventWindowResize() { return (EventType){.tag=EventType__EventWindowResize_Tag}; }
EventType EventType__EventTimer() { return (EventType){.tag=EventType__EventTimer_Tag}; }
struct Brick {
    int32_t x;
    int32_t y;
    int32_t width;
    int32_t height;
    bool alive;
    Color color;
};

struct Event {
    EventType type;
    KeyCode key;
    int32_t x;
    int32_t y;
    int32_t width;
    int32_t height;
};

struct String {
    Vec__char vec;
};

struct Option__String {
    bool is_some;
    String val;
};

struct BrickGrid {
    Brick bricks[50];
    int32_t rows;
    int32_t cols;
};

struct BreakoutState {
    Paddle paddle;
    Ball ball;
    BrickGrid bricks;
    int32_t score;
    int32_t lives;
    GameStatus status;
    int32_t width;
    int32_t height;
};

const uint32_t WS_OVERLAPPEDWINDOW = 13565952;
const int32_t CW_USEDEFAULT = 2147483648;
const uint32_t WM_CREATE = 1;
const uint32_t WM_PAINT = 15;
const uint32_t WM_KEYDOWN = 256;
const uint32_t WM_KEYUP = 257;
const uint32_t WM_LBUTTONDOWN = 513;
const uint32_t WM_LBUTTONUP = 514;
const uint32_t WM_DESTROY = 2;
const uint32_t WM_TIMER = 275;
const uint32_t WM_SIZE = 5;
const int32_t COLOR_WINDOW = 5;
const int8_t* IDC_ARROW = ((int8_t*)(32512));
const uint32_t SRCCOPY = 13369376;
const int32_t GWLP_WNDPROC = (-4);
const uint32_t CS_HREDRAW = 2;
const uint32_t CS_VREDRAW = 1;
const uint32_t WS_SYSMENU = 524288;
const uint32_t WS_MINIMIZEBOX = 131072;
const uint32_t WS_MAXIMIZEBOX = 65536;
const uint32_t WS_CAPTION = 12582912;
const uint32_t WM_USER = 1024;
const int32_t TRANSPARENT = 1;
const int8_t OUT_DEFAULT_PRECIS = 0;
const int8_t CLIP_DEFAULT_PRECIS = 0;
const int8_t DEFAULT_QUALITY = 0;
const uint8_t DEFAULT_PITCH = 0;
fn*() -> void destroy_handler = null;
const int32_t GAME_WIDTH = 800;
const int32_t GAME_HEIGHT = 600;
const int32_t PADDLE_WIDTH = 100;
const int32_t PADDLE_HEIGHT = 15;
const int32_t PADDLE_Y = (600 - 40);
const int32_t BALL_RADIUS = 8;
const int32_t BALL_SPEED = 5;
const int32_t BRICK_ROWS = 5;
const int32_t BRICK_COLS = 10;
const int32_t BRICK_WIDTH = 70;
const int32_t BRICK_HEIGHT = 25;
const int32_t BRICK_PADDING = 5;
const int32_t BRICK_TOP_OFFSET = 60;
const int32_t BRICK_LEFT_OFFSET = 30;
const int32_t POINTS_PER_BRICK = 10;
const int32_t INITIAL_LIVES = 3;
const Color BRICK_COLORS[5] = {(struct Color){.r = 255, .g = 107, .b = 107}, (struct Color){.r = 255, .g = 224, .b = 102}, (struct Color){.r = 107, .g = 203, .b = 119}, (struct Color){.r = 77, .g = 150, .b = 255}, (struct Color){.r = 199, .g = 125, .b = 255}};
Clone Clone__clone(Clone* self) {
    void* res = self->vtable->clone(self->self);
    return (Clone){.self = res, .vtable = self->vtable};
}



void Drop__drop(Drop* self) {
    return self->vtable->drop(self->self);
}


Vec__String Vec__String__new(void);
Vec__String Vec__String__with_capacity(size_t cap);
void Vec__String__grow(Vec__String* self);
void Vec__String__grow_to_fit(Vec__String* self, size_t new_len);
VecIter__String Vec__String__iterator(Vec__String* self);
VecIterRef__String Vec__String__iter_ref(Vec__String* self);
void Vec__String__push(Vec__String* self, String item);
void Vec__String__insert(Vec__String* self, size_t idx, String item);
String Vec__String__pop(Vec__String* self);
Option__String Vec__String__pop_opt(Vec__String* self);
String Vec__String__remove(Vec__String* self, size_t idx);
void Vec__String__append(Vec__String* self, Vec__String other);
String Vec__String__get(Vec__String* self, size_t idx);
String Vec__String__index(Vec__String* self, size_t idx);
String* Vec__String__get_ref(Vec__String* self, size_t idx);
String Vec__String__last(Vec__String* self);
size_t Vec__String__length(Vec__String* self);
bool Vec__String__contains(Vec__String* self, String item);
bool Vec__String__is_empty(Vec__String* self);
void Vec__String__clear(Vec__String* self);
void Vec__String__free(Vec__String* self);
String Vec__String__first(Vec__String* self);
void Vec__String__set(Vec__String* self, size_t idx, String item);
void Vec__String__reverse(Vec__String* self);
bool Vec__String__eq(Vec__String* self, Vec__String* other);
void Vec__String__forget(Vec__String* self);
Vec__String Vec__String__add(Vec__String* self, Vec__String* other);
void Vec__String__add_assign(Vec__String* self, Vec__String* other);
bool Vec__String__neq(Vec__String* self, Vec__String* other);
void Vec__String__shl(Vec__String* self, String item);
void Vec__String__shr(Vec__String* self, String* out_item);
Vec__String Vec__String__mul(Vec__String* self, size_t count);
void Vec__String__mul_assign(Vec__String* self, size_t count);
Vec__String Vec__String__clone(Vec__String* self);
VecIterResult__String VecIterRef__String__next(VecIterRef__String* self);
VecIterRef__String VecIterRef__String__iterator(VecIterRef__String* self);
bool VecIterResult__String__is_none(VecIterResult__String* self);
String* VecIterResult__String__unwrap(VecIterResult__String* self);
Option__String VecIter__String__next(VecIter__String* self);
VecIter__String VecIter__String__iterator(VecIter__String* self);
Option__String Option__String__Some(String v);
Option__String Option__String__None(void);
bool Option__String__is_some(Option__String* self);
bool Option__String__is_none(Option__String* self);
void Option__String__forget(Option__String* self);
String Option__String__unwrap(Option__String* self);
String* Option__String__unwrap_ref(Option__String* self);
String Option__String__unwrap_or(Option__String* self, String def_val);
String Option__String__expect(Option__String* self, char* msg);
Option__String Option__String__or_else(Option__String* self, Option__String other);
void Vec__String__Drop__drop(Vec__String* self);
Vec__int32_t Vec__int32_t__new(void);
Vec__int32_t Vec__int32_t__with_capacity(size_t cap);
void Vec__int32_t__grow(Vec__int32_t* self);
void Vec__int32_t__grow_to_fit(Vec__int32_t* self, size_t new_len);
VecIter__int32_t Vec__int32_t__iterator(Vec__int32_t* self);
VecIterRef__int32_t Vec__int32_t__iter_ref(Vec__int32_t* self);
void Vec__int32_t__push(Vec__int32_t* self, int32_t item);
void Vec__int32_t__insert(Vec__int32_t* self, size_t idx, int32_t item);
int32_t Vec__int32_t__pop(Vec__int32_t* self);
Option__int32_t Vec__int32_t__pop_opt(Vec__int32_t* self);
int32_t Vec__int32_t__remove(Vec__int32_t* self, size_t idx);
void Vec__int32_t__append(Vec__int32_t* self, Vec__int32_t other);
int32_t Vec__int32_t__get(Vec__int32_t* self, size_t idx);
int32_t Vec__int32_t__index(Vec__int32_t* self, size_t idx);
int32_t* Vec__int32_t__get_ref(Vec__int32_t* self, size_t idx);
int32_t Vec__int32_t__last(Vec__int32_t* self);
size_t Vec__int32_t__length(Vec__int32_t* self);
bool Vec__int32_t__contains(Vec__int32_t* self, int32_t item);
bool Vec__int32_t__is_empty(Vec__int32_t* self);
void Vec__int32_t__clear(Vec__int32_t* self);
void Vec__int32_t__free(Vec__int32_t* self);
int32_t Vec__int32_t__first(Vec__int32_t* self);
void Vec__int32_t__set(Vec__int32_t* self, size_t idx, int32_t item);
void Vec__int32_t__reverse(Vec__int32_t* self);
bool Vec__int32_t__eq(Vec__int32_t* self, Vec__int32_t* other);
void Vec__int32_t__forget(Vec__int32_t* self);
Vec__int32_t Vec__int32_t__add(Vec__int32_t* self, Vec__int32_t* other);
void Vec__int32_t__add_assign(Vec__int32_t* self, Vec__int32_t* other);
bool Vec__int32_t__neq(Vec__int32_t* self, Vec__int32_t* other);
void Vec__int32_t__shl(Vec__int32_t* self, int32_t item);
void Vec__int32_t__shr(Vec__int32_t* self, int32_t* out_item);
Vec__int32_t Vec__int32_t__mul(Vec__int32_t* self, size_t count);
void Vec__int32_t__mul_assign(Vec__int32_t* self, size_t count);
Vec__int32_t Vec__int32_t__clone(Vec__int32_t* self);
VecIterResult__int32_t VecIterRef__int32_t__next(VecIterRef__int32_t* self);
VecIterRef__int32_t VecIterRef__int32_t__iterator(VecIterRef__int32_t* self);
bool VecIterResult__int32_t__is_none(VecIterResult__int32_t* self);
int32_t* VecIterResult__int32_t__unwrap(VecIterResult__int32_t* self);
Option__int32_t VecIter__int32_t__next(VecIter__int32_t* self);
VecIter__int32_t VecIter__int32_t__iterator(VecIter__int32_t* self);
void Vec__int32_t__Drop__drop(Vec__int32_t* self);
Vec__size_t Vec__size_t__new(void);
Vec__size_t Vec__size_t__with_capacity(size_t cap);
void Vec__size_t__grow(Vec__size_t* self);
void Vec__size_t__grow_to_fit(Vec__size_t* self, size_t new_len);
VecIter__size_t Vec__size_t__iterator(Vec__size_t* self);
VecIterRef__size_t Vec__size_t__iter_ref(Vec__size_t* self);
void Vec__size_t__push(Vec__size_t* self, size_t item);
void Vec__size_t__insert(Vec__size_t* self, size_t idx, size_t item);
size_t Vec__size_t__pop(Vec__size_t* self);
Option__size_t Vec__size_t__pop_opt(Vec__size_t* self);
size_t Vec__size_t__remove(Vec__size_t* self, size_t idx);
void Vec__size_t__append(Vec__size_t* self, Vec__size_t other);
size_t Vec__size_t__get(Vec__size_t* self, size_t idx);
size_t Vec__size_t__index(Vec__size_t* self, size_t idx);
size_t* Vec__size_t__get_ref(Vec__size_t* self, size_t idx);
size_t Vec__size_t__last(Vec__size_t* self);
size_t Vec__size_t__length(Vec__size_t* self);
bool Vec__size_t__contains(Vec__size_t* self, size_t item);
bool Vec__size_t__is_empty(Vec__size_t* self);
void Vec__size_t__clear(Vec__size_t* self);
void Vec__size_t__free(Vec__size_t* self);
size_t Vec__size_t__first(Vec__size_t* self);
void Vec__size_t__set(Vec__size_t* self, size_t idx, size_t item);
void Vec__size_t__reverse(Vec__size_t* self);
bool Vec__size_t__eq(Vec__size_t* self, Vec__size_t* other);
void Vec__size_t__forget(Vec__size_t* self);
Vec__size_t Vec__size_t__add(Vec__size_t* self, Vec__size_t* other);
void Vec__size_t__add_assign(Vec__size_t* self, Vec__size_t* other);
bool Vec__size_t__neq(Vec__size_t* self, Vec__size_t* other);
void Vec__size_t__shl(Vec__size_t* self, size_t item);
void Vec__size_t__shr(Vec__size_t* self, size_t* out_item);
Vec__size_t Vec__size_t__mul(Vec__size_t* self, size_t count);
void Vec__size_t__mul_assign(Vec__size_t* self, size_t count);
Vec__size_t Vec__size_t__clone(Vec__size_t* self);
VecIterResult__size_t VecIterRef__size_t__next(VecIterRef__size_t* self);
VecIterRef__size_t VecIterRef__size_t__iterator(VecIterRef__size_t* self);
bool VecIterResult__size_t__is_none(VecIterResult__size_t* self);
size_t* VecIterResult__size_t__unwrap(VecIterResult__size_t* self);
Option__size_t VecIter__size_t__next(VecIter__size_t* self);
VecIter__size_t VecIter__size_t__iterator(VecIter__size_t* self);
void Vec__size_t__Drop__drop(Vec__size_t* self);
Option__size_t Option__size_t__Some(size_t v);
Option__size_t Option__size_t__None(void);
bool Option__size_t__is_some(Option__size_t* self);
bool Option__size_t__is_none(Option__size_t* self);
void Option__size_t__forget(Option__size_t* self);
size_t Option__size_t__unwrap(Option__size_t* self);
size_t* Option__size_t__unwrap_ref(Option__size_t* self);
size_t Option__size_t__unwrap_or(Option__size_t* self, size_t def_val);
size_t Option__size_t__expect(Option__size_t* self, char* msg);
Option__size_t Option__size_t__or_else(Option__size_t* self, Option__size_t other);
Option__int32_t Option__int32_t__Some(int32_t v);
Option__int32_t Option__int32_t__None(void);
bool Option__int32_t__is_some(Option__int32_t* self);
bool Option__int32_t__is_none(Option__int32_t* self);
void Option__int32_t__forget(Option__int32_t* self);
int32_t Option__int32_t__unwrap(Option__int32_t* self);
int32_t* Option__int32_t__unwrap_ref(Option__int32_t* self);
int32_t Option__int32_t__unwrap_or(Option__int32_t* self, int32_t def_val);
int32_t Option__int32_t__expect(Option__int32_t* self, char* msg);
Option__int32_t Option__int32_t__or_else(Option__int32_t* self, Option__int32_t other);
Vec__char Vec__char__new(void);
Vec__char Vec__char__with_capacity(size_t cap);
void Vec__char__grow(Vec__char* self);
void Vec__char__grow_to_fit(Vec__char* self, size_t new_len);
VecIter__char Vec__char__iterator(Vec__char* self);
VecIterRef__char Vec__char__iter_ref(Vec__char* self);
void Vec__char__push(Vec__char* self, char item);
void Vec__char__insert(Vec__char* self, size_t idx, char item);
char Vec__char__pop(Vec__char* self);
Option__char Vec__char__pop_opt(Vec__char* self);
char Vec__char__remove(Vec__char* self, size_t idx);
void Vec__char__append(Vec__char* self, Vec__char other);
char Vec__char__get(Vec__char* self, size_t idx);
char Vec__char__index(Vec__char* self, size_t idx);
char* Vec__char__get_ref(Vec__char* self, size_t idx);
char Vec__char__last(Vec__char* self);
size_t Vec__char__length(Vec__char* self);
bool Vec__char__contains(Vec__char* self, char item);
bool Vec__char__is_empty(Vec__char* self);
void Vec__char__clear(Vec__char* self);
void Vec__char__free(Vec__char* self);
char Vec__char__first(Vec__char* self);
void Vec__char__set(Vec__char* self, size_t idx, char item);
void Vec__char__reverse(Vec__char* self);
bool Vec__char__eq(Vec__char* self, Vec__char* other);
void Vec__char__forget(Vec__char* self);
Vec__char Vec__char__add(Vec__char* self, Vec__char* other);
void Vec__char__add_assign(Vec__char* self, Vec__char* other);
bool Vec__char__neq(Vec__char* self, Vec__char* other);
void Vec__char__shl(Vec__char* self, char item);
void Vec__char__shr(Vec__char* self, char* out_item);
Vec__char Vec__char__mul(Vec__char* self, size_t count);
void Vec__char__mul_assign(Vec__char* self, size_t count);
Vec__char Vec__char__clone(Vec__char* self);
VecIterResult__char VecIterRef__char__next(VecIterRef__char* self);
VecIterRef__char VecIterRef__char__iterator(VecIterRef__char* self);
bool VecIterResult__char__is_none(VecIterResult__char* self);
char* VecIterResult__char__unwrap(VecIterResult__char* self);
Option__char VecIter__char__next(VecIter__char* self);
VecIter__char VecIter__char__iterator(VecIter__char* self);
Option__char Option__char__Some(char v);
Option__char Option__char__None(void);
bool Option__char__is_some(Option__char* self);
bool Option__char__is_none(Option__char* self);
void Option__char__forget(Option__char* self);
char Option__char__unwrap(Option__char* self);
char* Option__char__unwrap_ref(Option__char* self);
char Option__char__unwrap_or(Option__char* self, char def_val);
char Option__char__expect(Option__char* self, char* msg);
Option__char Option__char__or_else(Option__char* self, Option__char other);
void Vec__char__Drop__drop(Vec__char* self);
int32_t main(void);
void on_destroy(void);
void on_mouse(int32_t x, int32_t y);
void on_paint(int32_t w, int32_t h);
bool on_timer(void);
bool on_key(KeyCode key);
int32_t abs(int32_t n);
string get_controls_text(void);
string get_status_text(BreakoutState* game);
int32_t get_score(BreakoutState* game);
bool update_game(BreakoutState* game);
bool handle_input(BreakoutState* game, KeyCode key);
void init_bricks(BreakoutState* game);
void reset_ball(BreakoutState* game);
void init_game(BreakoutState* game);
uint32_t window_proc(void* hwnd, uint32_t msg, uint32_t wParam, uint32_t lParam);
KeyCode map_vkey(int32_t vk);
uint32_t window_proc(void* hwnd, uint32_t msg, uint32_t wParam, uint32_t lParam);
Tuple__int32_t__int32_t get_client_size(void);
void set_client_size(int32_t w, int32_t h);
void set_destroy_handler(z_closure_T h);
void set_mouse_handler(z_closure_T h);
void set_paint_handler(z_closure_T h);
void set_timer_handler(z_closure_T h);
void set_key_handler(z_closure_T h);
void fb_draw_text_size(int32_t x, int32_t y, string text, Color color, int32_t size);
void fb_draw_text(int32_t x, int32_t y, string text, Color color);
bool DeleteObject_3(void* hObject);
void* SelectObject_3(void* hDC, void* hObject);
void* CreateFontA(int32_t height, int32_t width, int32_t escapement, int32_t orientation, int32_t weight, uint8_t italic, uint8_t underline, uint8_t strikeout, uint8_t charset, uint8_t outPrecision, uint8_t clipPrecision, uint8_t quality, uint8_t pitchAndFamily, int8_t* lpszFace);
uint32_t SetTextColor(void* hDC, uint32_t color);
int32_t SetBkMode(void* hDC, int32_t mode);
bool TextOutA(void* hDC, int32_t x, int32_t y, int8_t* lpString, int32_t cBytes);
void fb_shutdown(void);
void fb_present(void);
void fb_draw_circle(int32_t x, int32_t y, int32_t radius, Color color);
void fb_draw_rect(int32_t x, int32_t y, int32_t width, int32_t height, Color color);
void fb_clear(Color color);
void fb_init(void* window, int32_t width, int32_t height);
void draw_circle(void* ctx, int32_t x, int32_t y, int32_t radius, Color color);
void draw_rect(void* ctx, int32_t x, int32_t y, int32_t width, int32_t height, Color color);
uint32_t color_to_u32(Color c);
Color rgb(uint8_t r, uint8_t g, uint8_t b);
bool get_window_client_size(void* window, int32_t* width, int32_t* height);
void redraw_window(void* window);
void kill_game_timer(void* window);
void set_game_timer(void* window, uint32_t interval_ms);
void quit_application(void);
void run_event_loop(void* window);
void show_window(void* window);
void* create_window(string title, int32_t width, int32_t height);
void* CreateWindowExA_2(uint32_t dwExStyle, int8_t* lpClassName, int8_t* lpWindowName, uint32_t dwStyle, int32_t x, int32_t y, int32_t nWidth, int32_t nHeight, void* hWndParent, void* hMenu, void* hInstance, void* lpParam);
uint64_t GetWindowLongPtrA(void* hWnd, int32_t nIndex);
uint64_t SetWindowLongPtrA(void* hWnd, int32_t nIndex, uint64_t dwNewLong);
uint32_t DefWindowProcA(void* hWnd, uint32_t msg, uint32_t wParam, uint32_t lParam);
uint16_t RegisterClassA(WNDCLASSA* lpWndClass);
bool DeleteObject_2(void* hObject);
bool DeleteDC(void* hDC);
bool BitBlt(void* hDC, int32_t x, int32_t y, int32_t w, int32_t h, void* hSrcDC, int32_t xSrc, int32_t ySrc, uint32_t rop);
void* SelectObject_2(void* hDC, void* hObject);
void* CreateCompatibleBitmap(void* hDC, int32_t width, int32_t height);
void* CreateCompatibleDC(void* hDC);
int32_t ReleaseDC(void* hWnd, void* hDC);
void* GetDC(void* hWnd);
void SetCursor(void* hCursor);
void* LoadCursorA(void* hInstance, int8_t* lpCursorName);
void* GetModuleHandleA(int8_t* lpModuleName);
void PostQuitMessage(int32_t nExitCode);
bool KillTimer(void* hWnd, uint32_t uIDEvent);
uint32_t SetTimer(void* hWnd, uint32_t nIDEvent, uint32_t uElapse, void* lpTimerFunc);
bool DeleteObject(void* hObject);
void* SelectObject(void* hDC, void* hObject);
void* CreateSolidBrush(uint32_t color);
bool Ellipse(void* hDC, int32_t left, int32_t top, int32_t right, int32_t bottom);
bool Rectangle(void* hDC, int32_t left, int32_t top, int32_t right, int32_t bottom);
int32_t FillRect(void* hDC, void* lprc, void* hbr);
bool GetClientRect(void* hWnd, void* lpRect);
void EndPaint(void* hWnd, void* lpPaint);
void* BeginPaint(void* hWnd, void* lpPaint);
bool InvalidateRect(void* hWnd, void* lpRect, bool bErase);
int32_t DispatchMessageA(void* lpMsg);
bool TranslateMessage(void* lpMsg);
bool GetMessageA(void* lpMsg, void* hWnd, uint32_t wMsgFilterMin, uint32_t wMsgFilterMax);
bool UpdateWindow(void* hWnd);
bool ShowWindow(void* hWnd, int32_t nCmdShow);
void* CreateWindowExA(uint32_t dwExStyle, int8_t* lpClassName, int8_t* lpWindowName, uint32_t dwStyle, int32_t x, int32_t y, int32_t nWidth, int32_t nHeight, void* hWndParent, void* hMenu, void* hInstance, void* lpParam);
char* _z_str_rune(int32_t r);
char* utos(uint32_t n);
char* itos_new(int32_t n);
char* itos(int32_t n);
int32_t read_rune(void);
size_t _utf8_seq_len(uint8_t first_byte);
char* readln(void);
int println(char* fmt, ...);
int print(char* fmt, ...);
char* format_new(char* fmt, ...);
int format_into(char* buffer, size_t size, char* fmt, ...);
char* format(char* fmt, ...);
int32_t strcasecmp(const char* s1, const char* s2);
void sort_double(double* arr, size_t len);
void sort_float(float* arr, size_t len);
void sort_long(long* arr, size_t len);
void sort_int(int32_t* arr, size_t len);
void __zenc_todo_impl(const char* file, int32_t line, const char* func, const char* msg);
void __zenc_panic_impl(const char* file, int32_t line, const char* func, const char* msg);
double Math__PI(void);
double Math__E(void);
double Math__abs(double x);
double Math__sin(double x);
double Math__cos(double x);
double Math__tan(double x);
double Math__asin(double x);
double Math__acos(double x);
double Math__atan(double x);
double Math__atan2(double y, double x);
double Math__sqrt(double x);
double Math__pow(double base, double exp);
double Math__exp(double x);
double Math__log(double x);
double Math__log10(double x);
double Math__ceil(double x);
double Math__floor(double x);
double Math__round(double x);
double Math__mod(double x, double y);
double Math__max(double a, double b);
double Math__min(double a, double b);
String String__new(char* s);
String String__from(char* s);
String String__from_rune(int32_t r);
String String__from_runes(int32_t* runes, size_t count);
char* String__c_str(String* self);
char* String__to_string(String* self);
void String__destroy(String* self);
void String__forget(String* self);
void String__append(String* self, String* other);
void String__append_c(String* self, char* s);
void String__push_rune(String* self, int32_t r);
void String__append_c_ptr(String* ptr, char* s);
String String__add(String* self, String* other);
void String__add_assign(String* self, String* other);
bool String__eq(String* self, String* other);
bool String__neq(String* self, String* other);
int32_t String__compare(String* self, String* other);
bool String__lt(String* self, String* other);
bool String__gt(String* self, String* other);
bool String__le(String* self, String* other);
bool String__ge(String* self, String* other);
int32_t String__compare_ignore_case(String* self, String* other);
bool String__eq_ignore_case(String* self, String* other);
bool String__eq_str(String* self, char* s);
size_t String__length(String* self);
String String__substring(String* self, size_t start, size_t len);
bool String__contains_str(String* self, char* target);
Option__size_t String__find_str(String* self, char* target);
Vec__size_t String__find_all_str(String* self, char* target);
String String__to_lowercase(String* self);
String String__pad_right(String* self, size_t target_len, char pad_char);
String String__pad_left(String* self, size_t target_len, char pad_char);
String String__to_uppercase(String* self);
Option__size_t String__find(String* self, char target);
void String__print(String* self);
void String__println(String* self);
bool String__is_empty(String* self);
bool String__contains(String* self, char target);
bool String__starts_with(String* self, char* prefix);
bool String__ends_with(String* self, char* suffix);
void String__reserve(String* self, size_t cap);
void String__free(String* self);
size_t String__utf8_seq_len(char first_byte);
size_t String__utf8_len(String* self);
String String__utf8_at(String* self, size_t idx);
int32_t String__utf8_get(String* self, size_t idx);
Vec__int32_t String__runes(String* self);
StringCharsIter String__iterator(String* self);
StringCharsIter String__chars(String* self);
String String__from_runes_vec(Vec__int32_t runes);
void String__insert_rune(String* self, size_t idx, int32_t r);
int32_t String__remove_rune_at(String* self, size_t idx);
String String__utf8_substr(String* self, size_t start_idx, size_t num_chars);
Vec__String String__split(String* self, char delim);
String String__trim(String* self);
String String__replace(String* self, char* target, char* replacement);
Option__int32_t StringCharsIter__next(StringCharsIter* self);
StringCharsIter StringCharsIter__iterator(StringCharsIter* self);
// Auto-Generated RAII Glue for Vec__String
void Vec__String__Drop__glue(Vec__String *self) {
}


// Auto-Generated RAII Glue for Vec__int32_t
void Vec__int32_t__Drop__glue(Vec__int32_t *self) {
}


// Auto-Generated RAII Glue for Vec__size_t
void Vec__size_t__Drop__glue(Vec__size_t *self) {
}


// Auto-Generated RAII Glue for Vec__char
void Vec__char__Drop__glue(Vec__char *self) {
}


// Auto-Generated RAII Glue for String
void String__Drop__glue(String *self) {
    Vec__char__Drop__glue(&self->vec);
}


// Auto-Generated RAII Glue for Option__String
void Option__String__Drop__glue(Option__String *self) {
    String__Drop__glue(&self->val);
}



#line 73 "/usr/local/share/zenc/std/vec.zc"

Vec__String Vec__String__new(void)
{
    {

#line 74 "/usr/local/share/zenc/std/vec.zc"
    return (Vec__String){.data = NULL};
    }
}

#line 77 "/usr/local/share/zenc/std/vec.zc"

Vec__String Vec__String__with_capacity(size_t cap)
{
    {

#line 78 "/usr/local/share/zenc/std/vec.zc"
if ((cap == 0))     {

#line 79 "/usr/local/share/zenc/std/vec.zc"
    return (Vec__String){.data = NULL};
    }

#line 81 "/usr/local/share/zenc/std/vec.zc"
    return (Vec__String){.data = ((String*)(
#line 82 "/usr/local/share/zenc/std/vec.zc"
malloc((cap * sizeof(String))))), .cap = cap};
    }
}

#line 88 "/usr/local/share/zenc/std/vec.zc"

void Vec__String__grow(Vec__String* self)
{
    {

#line 89 "/usr/local/share/zenc/std/vec.zc"
if ((self->cap == 0))     {

#line 89 "/usr/local/share/zenc/std/vec.zc"
(self->cap = 8);
    }
 else     {

#line 90 "/usr/local/share/zenc/std/vec.zc"
(self->cap = (self->cap * 2));
    }

#line 91 "/usr/local/share/zenc/std/vec.zc"
(self->data = ((String*)(
#line 91 "/usr/local/share/zenc/std/vec.zc"
realloc(self->data, (self->cap * sizeof(String))))));
    }
}

#line 94 "/usr/local/share/zenc/std/vec.zc"

void Vec__String__grow_to_fit(Vec__String* self, size_t new_len)
{
    {

#line 95 "/usr/local/share/zenc/std/vec.zc"
if ((self->cap >= new_len))     {

#line 96 "/usr/local/share/zenc/std/vec.zc"
    return ;
    }

#line 99 "/usr/local/share/zenc/std/vec.zc"
if ((self->cap == 0))     {

#line 99 "/usr/local/share/zenc/std/vec.zc"
(self->cap = 8);
    }

#line 100 "/usr/local/share/zenc/std/vec.zc"
while ((self->cap < new_len))     {

#line 101 "/usr/local/share/zenc/std/vec.zc"
(self->cap = (self->cap * 2));
    }

#line 104 "/usr/local/share/zenc/std/vec.zc"
(self->data = ((String*)(
#line 104 "/usr/local/share/zenc/std/vec.zc"
realloc(self->data, (self->cap * sizeof(String))))));
    }
}

#line 107 "/usr/local/share/zenc/std/vec.zc"

VecIter__String Vec__String__iterator(Vec__String* self)
{
    {

#line 108 "/usr/local/share/zenc/std/vec.zc"
    return (VecIter__String){.data = self->data, .count = self->len};
    }
}

#line 115 "/usr/local/share/zenc/std/vec.zc"

VecIterRef__String Vec__String__iter_ref(Vec__String* self)
{
    {

#line 116 "/usr/local/share/zenc/std/vec.zc"
    return (VecIterRef__String){.data = self->data, .count = self->len};
    }
}

#line 123 "/usr/local/share/zenc/std/vec.zc"

void Vec__String__push(Vec__String* self, String item)
{

#line 123 "/usr/local/share/zenc/std/vec.zc"
    int __z_drop_flag_item = 1;
    {

#line 124 "/usr/local/share/zenc/std/vec.zc"
if ((self->len >= self->cap))     {

#line 125 "/usr/local/share/zenc/std/vec.zc"
Vec__String__grow(self);
    }

#line 127 "/usr/local/share/zenc/std/vec.zc"
(self->data[self->len] = ({ __z_drop_flag_item = 0; item; }));

#line 128 "/usr/local/share/zenc/std/vec.zc"
(self->len = (self->len + 1));
    }

#line 123 "/usr/local/share/zenc/std/vec.zc"
    if (__z_drop_flag_item) String__Drop__glue(&item);
}

#line 131 "/usr/local/share/zenc/std/vec.zc"

void Vec__String__insert(Vec__String* self, size_t idx, String item)
{

#line 131 "/usr/local/share/zenc/std/vec.zc"
    int __z_drop_flag_item = 1;
    {

#line 132 "/usr/local/share/zenc/std/vec.zc"
if ((idx > self->len))     {

#line 133 "/usr/local/share/zenc/std/vec.zc"
    ({ fprintf(stderr, "%s", "Panic: Insert index out of bounds"); fprintf(stderr, "\n"); 0; });

#line 134 "/usr/local/share/zenc/std/vec.zc"
exit(1);
    }

#line 136 "/usr/local/share/zenc/std/vec.zc"
if ((self->len >= self->cap))     {

#line 137 "/usr/local/share/zenc/std/vec.zc"
Vec__String__grow(self);
    }

#line 140 "/usr/local/share/zenc/std/vec.zc"
if ((idx < self->len))     {

#line 141 "/usr/local/share/zenc/std/vec.zc"
memmove(((self->data + idx) + 1), (self->data + idx), ((self->len - idx) * sizeof(String)));
    }

#line 143 "/usr/local/share/zenc/std/vec.zc"
(self->data[idx] = ({ __z_drop_flag_item = 0; item; }));

#line 144 "/usr/local/share/zenc/std/vec.zc"
(self->len = (self->len + 1));
    }

#line 131 "/usr/local/share/zenc/std/vec.zc"
    if (__z_drop_flag_item) String__Drop__glue(&item);
}

#line 147 "/usr/local/share/zenc/std/vec.zc"

String Vec__String__pop(Vec__String* self)
{
    {

#line 148 "/usr/local/share/zenc/std/vec.zc"
if ((self->len == 0))     {

#line 149 "/usr/local/share/zenc/std/vec.zc"
    ({ fprintf(stderr, "%s", "Panic: pop called on empty Vec"); fprintf(stderr, "\n"); 0; });

#line 150 "/usr/local/share/zenc/std/vec.zc"
exit(1);
    }

#line 152 "/usr/local/share/zenc/std/vec.zc"
(self->len = (self->len - 1));

#line 153 "/usr/local/share/zenc/std/vec.zc"
    return self->data[self->len];
    }
}

#line 156 "/usr/local/share/zenc/std/vec.zc"

Option__String Vec__String__pop_opt(Vec__String* self)
{
    {

#line 157 "/usr/local/share/zenc/std/vec.zc"
if ((self->len == 0))     {

#line 158 "/usr/local/share/zenc/std/vec.zc"
    return 
#line 158 "/usr/local/share/zenc/std/vec.zc"
Option__String__None();
    }

#line 160 "/usr/local/share/zenc/std/vec.zc"
(self->len = (self->len - 1));

#line 161 "/usr/local/share/zenc/std/vec.zc"
    return 
#line 161 "/usr/local/share/zenc/std/vec.zc"
Option__String__Some(self->data[self->len]);
    }
}

#line 164 "/usr/local/share/zenc/std/vec.zc"

String Vec__String__remove(Vec__String* self, size_t idx)
{
    {

#line 165 "/usr/local/share/zenc/std/vec.zc"
if ((idx >= self->len))     {

#line 166 "/usr/local/share/zenc/std/vec.zc"
    ({ fprintf(stderr, "%s", "Panic: Remove index out of bounds"); fprintf(stderr, "\n"); 0; });

#line 167 "/usr/local/share/zenc/std/vec.zc"
exit(1);
    }

#line 169 "/usr/local/share/zenc/std/vec.zc"
    int __z_drop_flag_item = 1; String item = self->data[idx];

#line 171 "/usr/local/share/zenc/std/vec.zc"
if ((idx < (self->len - 1)))     {

#line 172 "/usr/local/share/zenc/std/vec.zc"
memmove((self->data + idx), ((self->data + idx) + 1), (((self->len - idx) - 1) * sizeof(String)));
    }

#line 174 "/usr/local/share/zenc/std/vec.zc"
(self->len = (self->len - 1));

#line 175 "/usr/local/share/zenc/std/vec.zc"
    return ({ ZC_AUTO _z_ret_mv = item; memset(&item, 0, sizeof(_z_ret_mv)); __z_drop_flag_item = 0; 
#line 169 "/usr/local/share/zenc/std/vec.zc"
    if (__z_drop_flag_item) String__Drop__glue(&item);
_z_ret_mv; });

#line 169 "/usr/local/share/zenc/std/vec.zc"
    if (__z_drop_flag_item) String__Drop__glue(&item);
    }
}

#line 180 "/usr/local/share/zenc/std/vec.zc"

void Vec__String__append(Vec__String* self, Vec__String other)
{

#line 180 "/usr/local/share/zenc/std/vec.zc"
    int __z_drop_flag_other = 1;
    {

#line 181 "/usr/local/share/zenc/std/vec.zc"
    size_t new_len = (self->len + other.len);

#line 182 "/usr/local/share/zenc/std/vec.zc"
Vec__String__grow_to_fit(self, new_len);

#line 184 "/usr/local/share/zenc/std/vec.zc"
memcpy((self->data + self->len), other.data, (other.len * sizeof(String)));

#line 185 "/usr/local/share/zenc/std/vec.zc"
(self->len = new_len);

#line 186 "/usr/local/share/zenc/std/vec.zc"
Vec__String__forget(&other);
    }

#line 180 "/usr/local/share/zenc/std/vec.zc"
    if (__z_drop_flag_other) Vec__String__Drop__glue(&other);
}

#line 189 "/usr/local/share/zenc/std/vec.zc"

String Vec__String__get(Vec__String* self, size_t idx)
{
    {

#line 190 "/usr/local/share/zenc/std/vec.zc"
if ((idx >= self->len))     {

#line 191 "/usr/local/share/zenc/std/vec.zc"
    ({ fprintf(stderr, "%s", "Panic: Index out of bounds"); fprintf(stderr, "\n"); 0; });

#line 192 "/usr/local/share/zenc/std/vec.zc"
exit(1);
    }

#line 194 "/usr/local/share/zenc/std/vec.zc"
    return self->data[idx];
    }
}

#line 197 "/usr/local/share/zenc/std/vec.zc"

String Vec__String__index(Vec__String* self, size_t idx)
{
    {

#line 198 "/usr/local/share/zenc/std/vec.zc"
    return 
#line 198 "/usr/local/share/zenc/std/vec.zc"
Vec__String__get(self, idx);
    }
}

#line 201 "/usr/local/share/zenc/std/vec.zc"

String* Vec__String__get_ref(Vec__String* self, size_t idx)
{
    {

#line 202 "/usr/local/share/zenc/std/vec.zc"
if ((idx >= self->len))     {

#line 203 "/usr/local/share/zenc/std/vec.zc"
    ({ fprintf(stderr, "%s", "Panic: Index out of bounds"); fprintf(stderr, "\n"); 0; });

#line 204 "/usr/local/share/zenc/std/vec.zc"
exit(1);
    }

#line 206 "/usr/local/share/zenc/std/vec.zc"
    return (&self->data[idx]);
    }
}

#line 209 "/usr/local/share/zenc/std/vec.zc"

String Vec__String__last(Vec__String* self)
{
    {

#line 210 "/usr/local/share/zenc/std/vec.zc"
if ((self->len == 0))     {

#line 211 "/usr/local/share/zenc/std/vec.zc"
    ({ fprintf(stderr, "%s", "Panic: last called on empty Vec"); fprintf(stderr, "\n"); 0; });

#line 212 "/usr/local/share/zenc/std/vec.zc"
exit(1);
    }

#line 214 "/usr/local/share/zenc/std/vec.zc"
    return self->data[(self->len - 1)];
    }
}

#line 217 "/usr/local/share/zenc/std/vec.zc"

size_t Vec__String__length(Vec__String* self)
{
    {

#line 218 "/usr/local/share/zenc/std/vec.zc"
    return self->len;
    }
}

#line 221 "/usr/local/share/zenc/std/vec.zc"

bool Vec__String__contains(Vec__String* self, String item)
{

#line 221 "/usr/local/share/zenc/std/vec.zc"
    int __z_drop_flag_item = 1;
    {

#line 222 "/usr/local/share/zenc/std/vec.zc"
    size_t i = 0;

#line 223 "/usr/local/share/zenc/std/vec.zc"
while ((i < self->len))     {

#line 224 "/usr/local/share/zenc/std/vec.zc"
if ((
#line 224 "/usr/local/share/zenc/std/vec.zc"
memcmp((&self->data[i]), (&item), sizeof(String)) == 0))     {

#line 224 "/usr/local/share/zenc/std/vec.zc"
    { bool _z_ret = true; 
#line 221 "/usr/local/share/zenc/std/vec.zc"
    if (__z_drop_flag_item) String__Drop__glue(&item);
return _z_ret; }
    }
(i++);
    }

#line 227 "/usr/local/share/zenc/std/vec.zc"
    { bool _z_ret = false; 
#line 221 "/usr/local/share/zenc/std/vec.zc"
    if (__z_drop_flag_item) String__Drop__glue(&item);
return _z_ret; }
    }

#line 221 "/usr/local/share/zenc/std/vec.zc"
    if (__z_drop_flag_item) String__Drop__glue(&item);
}

#line 230 "/usr/local/share/zenc/std/vec.zc"

bool Vec__String__is_empty(Vec__String* self)
{
    {

#line 231 "/usr/local/share/zenc/std/vec.zc"
    return (self->len == 0);
    }
}

#line 234 "/usr/local/share/zenc/std/vec.zc"

void Vec__String__clear(Vec__String* self)
{
    {

#line 235 "/usr/local/share/zenc/std/vec.zc"
(self->len = 0);
    }
}

#line 238 "/usr/local/share/zenc/std/vec.zc"

void Vec__String__free(Vec__String* self)
{
    {

#line 239 "/usr/local/share/zenc/std/vec.zc"
if (self->data)     {

#line 239 "/usr/local/share/zenc/std/vec.zc"
free(self->data);
    }

#line 240 "/usr/local/share/zenc/std/vec.zc"
(self->data = NULL);

#line 241 "/usr/local/share/zenc/std/vec.zc"
(self->len = 0);

#line 242 "/usr/local/share/zenc/std/vec.zc"
(self->cap = 0);
    }
}

#line 245 "/usr/local/share/zenc/std/vec.zc"

String Vec__String__first(Vec__String* self)
{
    {

#line 246 "/usr/local/share/zenc/std/vec.zc"
if ((self->len == 0))     {

#line 247 "/usr/local/share/zenc/std/vec.zc"
    ({ fprintf(stderr, "%s", "Panic: first called on empty Vec"); fprintf(stderr, "\n"); 0; });

#line 248 "/usr/local/share/zenc/std/vec.zc"
exit(1);
    }

#line 250 "/usr/local/share/zenc/std/vec.zc"
    return self->data[0];
    }
}

#line 253 "/usr/local/share/zenc/std/vec.zc"

void Vec__String__set(Vec__String* self, size_t idx, String item)
{

#line 253 "/usr/local/share/zenc/std/vec.zc"
    int __z_drop_flag_item = 1;
    {

#line 254 "/usr/local/share/zenc/std/vec.zc"
if ((idx >= self->len))     {

#line 255 "/usr/local/share/zenc/std/vec.zc"
    ({ fprintf(stderr, "%s", "Panic: set index out of bounds"); fprintf(stderr, "\n"); 0; });

#line 256 "/usr/local/share/zenc/std/vec.zc"
exit(1);
    }

#line 258 "/usr/local/share/zenc/std/vec.zc"
(self->data[idx] = ({ __z_drop_flag_item = 0; item; }));
    }

#line 253 "/usr/local/share/zenc/std/vec.zc"
    if (__z_drop_flag_item) String__Drop__glue(&item);
}

#line 261 "/usr/local/share/zenc/std/vec.zc"

void Vec__String__reverse(Vec__String* self)
{
    {

#line 262 "/usr/local/share/zenc/std/vec.zc"
    size_t i = 0;

#line 263 "/usr/local/share/zenc/std/vec.zc"
    size_t j = (self->len - 1);

#line 264 "/usr/local/share/zenc/std/vec.zc"
while ((i < j))     {

#line 265 "/usr/local/share/zenc/std/vec.zc"
    int __z_drop_flag_tmp = 1; String tmp = self->data[i];

#line 266 "/usr/local/share/zenc/std/vec.zc"
(self->data[i] = self->data[j]);

#line 267 "/usr/local/share/zenc/std/vec.zc"
(self->data[j] = ({ __z_drop_flag_tmp = 0; tmp; }));
(i++);
(j--);

#line 265 "/usr/local/share/zenc/std/vec.zc"
    if (__z_drop_flag_tmp) String__Drop__glue(&tmp);
    }
    }
}

#line 275 "/usr/local/share/zenc/std/vec.zc"

bool Vec__String__eq(Vec__String* self, Vec__String* other)
{
    {

#line 276 "/usr/local/share/zenc/std/vec.zc"
if ((self->len != (*other).len))     {

#line 276 "/usr/local/share/zenc/std/vec.zc"
    return false;
    }

#line 277 "/usr/local/share/zenc/std/vec.zc"
    size_t i = 0;

#line 278 "/usr/local/share/zenc/std/vec.zc"
while ((i < self->len))     {

#line 279 "/usr/local/share/zenc/std/vec.zc"
if ((
#line 279 "/usr/local/share/zenc/std/vec.zc"
memcmp((&self->data[i]), (&(*other).data[i]), sizeof(String)) != 0))     {

#line 279 "/usr/local/share/zenc/std/vec.zc"
    return false;
    }

#line 280 "/usr/local/share/zenc/std/vec.zc"
(i = (i + 1));
    }

#line 282 "/usr/local/share/zenc/std/vec.zc"
    return true;
    }
}

#line 286 "/usr/local/share/zenc/std/vec.zc"

void Vec__String__forget(Vec__String* self)
{
    {

#line 287 "/usr/local/share/zenc/std/vec.zc"
(self->data = NULL);

#line 288 "/usr/local/share/zenc/std/vec.zc"
(self->len = 0);

#line 289 "/usr/local/share/zenc/std/vec.zc"
(self->cap = 0);
    }
}

#line 295 "/usr/local/share/zenc/std/vec.zc"

Vec__String Vec__String__add(Vec__String* self, Vec__String* other)
{
    {

#line 296 "/usr/local/share/zenc/std/vec.zc"
    int __z_drop_flag_result = 1; Vec__String result = 
#line 296 "/usr/local/share/zenc/std/vec.zc"
Vec__String__clone(self);

#line 297 "/usr/local/share/zenc/std/vec.zc"
Vec__String__append(&result, Vec__String__clone(other));

#line 298 "/usr/local/share/zenc/std/vec.zc"
    return ({ ZC_AUTO _z_ret_mv = result; memset(&result, 0, sizeof(_z_ret_mv)); __z_drop_flag_result = 0; 
#line 296 "/usr/local/share/zenc/std/vec.zc"
    if (__z_drop_flag_result) Vec__String__Drop__glue(&result);
_z_ret_mv; });

#line 296 "/usr/local/share/zenc/std/vec.zc"
    if (__z_drop_flag_result) Vec__String__Drop__glue(&result);
    }
}

#line 302 "/usr/local/share/zenc/std/vec.zc"

void Vec__String__add_assign(Vec__String* self, Vec__String* other)
{
    {

#line 303 "/usr/local/share/zenc/std/vec.zc"
Vec__String__append(self, Vec__String__clone(other));
    }
}

#line 306 "/usr/local/share/zenc/std/vec.zc"

bool Vec__String__neq(Vec__String* self, Vec__String* other)
{
    {

#line 307 "/usr/local/share/zenc/std/vec.zc"
    return (!
#line 307 "/usr/local/share/zenc/std/vec.zc"
Vec__String__eq(self, other));
    }
}

#line 311 "/usr/local/share/zenc/std/vec.zc"

void Vec__String__shl(Vec__String* self, String item)
{

#line 311 "/usr/local/share/zenc/std/vec.zc"
    int __z_drop_flag_item = 1;
    {

#line 312 "/usr/local/share/zenc/std/vec.zc"
Vec__String__push(self, ({ __z_drop_flag_item = 0; item; }));
    }

#line 311 "/usr/local/share/zenc/std/vec.zc"
    if (__z_drop_flag_item) String__Drop__glue(&item);
}

#line 316 "/usr/local/share/zenc/std/vec.zc"

void Vec__String__shr(Vec__String* self, String* out_item)
{
    {

#line 317 "/usr/local/share/zenc/std/vec.zc"
if ((out_item != NULL))     {

#line 318 "/usr/local/share/zenc/std/vec.zc"
((*out_item) = 
#line 318 "/usr/local/share/zenc/std/vec.zc"
Vec__String__pop(self));
    }
 else     {

#line 320 "/usr/local/share/zenc/std/vec.zc"
Vec__String__pop(self);
    }
    }
}

#line 327 "/usr/local/share/zenc/std/vec.zc"

Vec__String Vec__String__mul(Vec__String* self, size_t count)
{
    {

#line 328 "/usr/local/share/zenc/std/vec.zc"
    int __z_drop_flag_result = 1; Vec__String result = 
#line 328 "/usr/local/share/zenc/std/vec.zc"
Vec__String__with_capacity((self->len * count));

#line 329 "/usr/local/share/zenc/std/vec.zc"
    size_t c = 0;

#line 330 "/usr/local/share/zenc/std/vec.zc"
while ((c < count))     {

#line 331 "/usr/local/share/zenc/std/vec.zc"
Vec__String__append(&result, Vec__String__clone(self));

#line 332 "/usr/local/share/zenc/std/vec.zc"
(c = (c + 1));
    }

#line 334 "/usr/local/share/zenc/std/vec.zc"
    return ({ ZC_AUTO _z_ret_mv = result; memset(&result, 0, sizeof(_z_ret_mv)); __z_drop_flag_result = 0; 
#line 328 "/usr/local/share/zenc/std/vec.zc"
    if (__z_drop_flag_result) Vec__String__Drop__glue(&result);
_z_ret_mv; });

#line 328 "/usr/local/share/zenc/std/vec.zc"
    if (__z_drop_flag_result) Vec__String__Drop__glue(&result);
    }
}

#line 340 "/usr/local/share/zenc/std/vec.zc"

void Vec__String__mul_assign(Vec__String* self, size_t count)
{
    {

#line 341 "/usr/local/share/zenc/std/vec.zc"
if ((count == 0))     {

#line 342 "/usr/local/share/zenc/std/vec.zc"
Vec__String__clear(self);

#line 343 "/usr/local/share/zenc/std/vec.zc"
    return ;
    }

#line 345 "/usr/local/share/zenc/std/vec.zc"
if ((count == 1))     {

#line 346 "/usr/local/share/zenc/std/vec.zc"
    return ;
    }

#line 348 "/usr/local/share/zenc/std/vec.zc"
    size_t original_len = self->len;

#line 349 "/usr/local/share/zenc/std/vec.zc"
Vec__String__grow_to_fit(self, (self->len * count));

#line 350 "/usr/local/share/zenc/std/vec.zc"
    size_t c = 1;

#line 351 "/usr/local/share/zenc/std/vec.zc"
while ((c < count))     {

#line 352 "/usr/local/share/zenc/std/vec.zc"
memcpy((self->data + (original_len * c)), self->data, (original_len * sizeof(String)));

#line 353 "/usr/local/share/zenc/std/vec.zc"
(self->len = (self->len + original_len));

#line 354 "/usr/local/share/zenc/std/vec.zc"
(c = (c + 1));
    }
    }
}

#line 359 "/usr/local/share/zenc/std/vec.zc"

Vec__String Vec__String__clone(Vec__String* self)
{
    {

#line 360 "/usr/local/share/zenc/std/vec.zc"
if ((self->len == 0))     {

#line 361 "/usr/local/share/zenc/std/vec.zc"
    return (Vec__String){.data = NULL};
    }

#line 363 "/usr/local/share/zenc/std/vec.zc"
    String* new_data = ((String*)(
#line 363 "/usr/local/share/zenc/std/vec.zc"
malloc((self->len * sizeof(String)))));

#line 364 "/usr/local/share/zenc/std/vec.zc"
    size_t i = 0;

#line 365 "/usr/local/share/zenc/std/vec.zc"
while ((i < self->len))     {

#line 366 "/usr/local/share/zenc/std/vec.zc"
(new_data[i] = self->data[i]);

#line 367 "/usr/local/share/zenc/std/vec.zc"
(i = (i + 1));
    }

#line 369 "/usr/local/share/zenc/std/vec.zc"
    return (Vec__String){.data = new_data, .len = self->len, .cap = self->len};
    }
}

#line 58 "/usr/local/share/zenc/std/vec.zc"

VecIterResult__String VecIterRef__String__next(VecIterRef__String* self)
{
    {

#line 59 "/usr/local/share/zenc/std/vec.zc"
if ((self->idx < self->count))     {

#line 60 "/usr/local/share/zenc/std/vec.zc"
    String* item = (&self->data[self->idx]);

#line 61 "/usr/local/share/zenc/std/vec.zc"
(self->idx = (self->idx + 1));

#line 62 "/usr/local/share/zenc/std/vec.zc"
    return (VecIterResult__String){.ptr = item};
    }

#line 64 "/usr/local/share/zenc/std/vec.zc"
    return (VecIterResult__String){.ptr = NULL};
    }
}

#line 67 "/usr/local/share/zenc/std/vec.zc"

VecIterRef__String VecIterRef__String__iterator(VecIterRef__String* self)
{
    {

#line 68 "/usr/local/share/zenc/std/vec.zc"
    return *self;
    }
}

#line 23 "/usr/local/share/zenc/std/vec.zc"

bool VecIterResult__String__is_none(VecIterResult__String* self)
{
    {

#line 24 "/usr/local/share/zenc/std/vec.zc"
    return (self->ptr == NULL);
    }
}

#line 27 "/usr/local/share/zenc/std/vec.zc"

String* VecIterResult__String__unwrap(VecIterResult__String* self)
{
    {

#line 28 "/usr/local/share/zenc/std/vec.zc"
if ((self->ptr == NULL))     {

#line 29 "/usr/local/share/zenc/std/vec.zc"
    ({ fprintf(stderr, "%s", "Panic: unwrap called on null VecIterResult"); fprintf(stderr, "\n"); 0; });

#line 30 "/usr/local/share/zenc/std/vec.zc"
exit(1);
    }

#line 32 "/usr/local/share/zenc/std/vec.zc"
    return self->ptr;
    }
}

#line 43 "/usr/local/share/zenc/std/vec.zc"

Option__String VecIter__String__next(VecIter__String* self)
{
    {

#line 44 "/usr/local/share/zenc/std/vec.zc"
if ((self->idx < self->count))     {

#line 45 "/usr/local/share/zenc/std/vec.zc"
    int __z_drop_flag_item = 1; String item = self->data[self->idx];

#line 46 "/usr/local/share/zenc/std/vec.zc"
(self->idx = (self->idx + 1));

#line 47 "/usr/local/share/zenc/std/vec.zc"
    { Option__String _z_ret = 
#line 47 "/usr/local/share/zenc/std/vec.zc"
Option__String__Some(({ __z_drop_flag_item = 0; item; })); 
#line 45 "/usr/local/share/zenc/std/vec.zc"
    if (__z_drop_flag_item) String__Drop__glue(&item);
return _z_ret; }

#line 45 "/usr/local/share/zenc/std/vec.zc"
    if (__z_drop_flag_item) String__Drop__glue(&item);
    }

#line 49 "/usr/local/share/zenc/std/vec.zc"
    return 
#line 49 "/usr/local/share/zenc/std/vec.zc"
Option__String__None();
    }
}

#line 52 "/usr/local/share/zenc/std/vec.zc"

VecIter__String VecIter__String__iterator(VecIter__String* self)
{
    {

#line 53 "/usr/local/share/zenc/std/vec.zc"
    return *self;
    }
}

#line 10 "/usr/local/share/zenc/std/option.zc"

Option__String Option__String__Some(String v)
{

#line 10 "/usr/local/share/zenc/std/option.zc"
    int __z_drop_flag_v = 1;
    {

#line 11 "/usr/local/share/zenc/std/option.zc"
    { Option__String _z_ret = (Option__String){.is_some = true, .val = ({ __z_drop_flag_v = 0; v; })}; 
#line 10 "/usr/local/share/zenc/std/option.zc"
    if (__z_drop_flag_v) String__Drop__glue(&v);
return _z_ret; }
    }

#line 10 "/usr/local/share/zenc/std/option.zc"
    if (__z_drop_flag_v) String__Drop__glue(&v);
}

#line 14 "/usr/local/share/zenc/std/option.zc"

Option__String Option__String__None(void)
{
    {

#line 15 "/usr/local/share/zenc/std/option.zc"
    int __z_drop_flag_opt = 1; Option__String opt = {0};

#line 16 "/usr/local/share/zenc/std/option.zc"
(opt.is_some = false);

#line 17 "/usr/local/share/zenc/std/option.zc"
memset((&opt.val), 0, sizeof(String));

#line 18 "/usr/local/share/zenc/std/option.zc"
    return ({ ZC_AUTO _z_ret_mv = opt; memset(&opt, 0, sizeof(_z_ret_mv)); __z_drop_flag_opt = 0; 
#line 15 "/usr/local/share/zenc/std/option.zc"
    if (__z_drop_flag_opt) Option__String__Drop__glue(&opt);
_z_ret_mv; });

#line 15 "/usr/local/share/zenc/std/option.zc"
    if (__z_drop_flag_opt) Option__String__Drop__glue(&opt);
    }
}

#line 21 "/usr/local/share/zenc/std/option.zc"

bool Option__String__is_some(Option__String* self)
{
    {

#line 22 "/usr/local/share/zenc/std/option.zc"
    return self->is_some;
    }
}

#line 25 "/usr/local/share/zenc/std/option.zc"

bool Option__String__is_none(Option__String* self)
{
    {

#line 26 "/usr/local/share/zenc/std/option.zc"
    return (!self->is_some);
    }
}

#line 29 "/usr/local/share/zenc/std/option.zc"

void Option__String__forget(Option__String* self)
{
    {

#line 30 "/usr/local/share/zenc/std/option.zc"
memset((&self->val), 0, sizeof(String));
    }
}

#line 33 "/usr/local/share/zenc/std/option.zc"

String Option__String__unwrap(Option__String* self)
{
    {

#line 34 "/usr/local/share/zenc/std/option.zc"
if ((!self->is_some))     {

#line 35 "/usr/local/share/zenc/std/option.zc"
    ({ fprintf(stderr, "%s", "Panic: unwrap called on None"); fprintf(stderr, "\n"); 0; });

#line 36 "/usr/local/share/zenc/std/option.zc"
exit(1);
    }

#line 38 "/usr/local/share/zenc/std/option.zc"
    int __z_drop_flag_v = 1; String v = self->val;
memset(&self->val, 0, sizeof(self->val));

#line 39 "/usr/local/share/zenc/std/option.zc"
memset((&self->val), 0, sizeof(String));

#line 40 "/usr/local/share/zenc/std/option.zc"
    return ({ ZC_AUTO _z_ret_mv = v; memset(&v, 0, sizeof(_z_ret_mv)); __z_drop_flag_v = 0; 
#line 38 "/usr/local/share/zenc/std/option.zc"
    if (__z_drop_flag_v) String__Drop__glue(&v);
_z_ret_mv; });

#line 38 "/usr/local/share/zenc/std/option.zc"
    if (__z_drop_flag_v) String__Drop__glue(&v);
    }
}

#line 43 "/usr/local/share/zenc/std/option.zc"

String* Option__String__unwrap_ref(Option__String* self)
{
    {

#line 44 "/usr/local/share/zenc/std/option.zc"
if ((!self->is_some))     {

#line 45 "/usr/local/share/zenc/std/option.zc"
    ({ fprintf(stderr, "%s", "Panic: unwrap_ref called on None"); fprintf(stderr, "\n"); 0; });

#line 46 "/usr/local/share/zenc/std/option.zc"
exit(1);
    }

#line 48 "/usr/local/share/zenc/std/option.zc"
    return (&self->val);
    }
}

#line 51 "/usr/local/share/zenc/std/option.zc"

String Option__String__unwrap_or(Option__String* self, String def_val)
{

#line 51 "/usr/local/share/zenc/std/option.zc"
    int __z_drop_flag_def_val = 1;
    {

#line 52 "/usr/local/share/zenc/std/option.zc"
if (self->is_some)     {

#line 53 "/usr/local/share/zenc/std/option.zc"
    { String _z_ret = self->val; 
#line 51 "/usr/local/share/zenc/std/option.zc"
    if (__z_drop_flag_def_val) String__Drop__glue(&def_val);
return _z_ret; }
    }

#line 55 "/usr/local/share/zenc/std/option.zc"
    return ({ ZC_AUTO _z_ret_mv = def_val; memset(&def_val, 0, sizeof(_z_ret_mv)); __z_drop_flag_def_val = 0; 
#line 51 "/usr/local/share/zenc/std/option.zc"
    if (__z_drop_flag_def_val) String__Drop__glue(&def_val);
_z_ret_mv; });
    }

#line 51 "/usr/local/share/zenc/std/option.zc"
    if (__z_drop_flag_def_val) String__Drop__glue(&def_val);
}

#line 58 "/usr/local/share/zenc/std/option.zc"

String Option__String__expect(Option__String* self, char* msg)
{
    {

#line 59 "/usr/local/share/zenc/std/option.zc"
if ((!self->is_some))     {

#line 60 "/usr/local/share/zenc/std/option.zc"
    ({ fprintf(stderr, "%s", "Panic: "); fprintf(stderr, "%s", msg); fprintf(stderr, "\n"); 0; });

#line 61 "/usr/local/share/zenc/std/option.zc"
exit(1);
    }

#line 63 "/usr/local/share/zenc/std/option.zc"
    return self->val;
    }
}

#line 66 "/usr/local/share/zenc/std/option.zc"

Option__String Option__String__or_else(Option__String* self, Option__String other)
{

#line 66 "/usr/local/share/zenc/std/option.zc"
    int __z_drop_flag_other = 1;
    {

#line 67 "/usr/local/share/zenc/std/option.zc"
if (self->is_some)     {

#line 67 "/usr/local/share/zenc/std/option.zc"
    { Option__String _z_ret = *self; 
#line 66 "/usr/local/share/zenc/std/option.zc"
    if (__z_drop_flag_other) Option__String__Drop__glue(&other);
return _z_ret; }
    }

#line 68 "/usr/local/share/zenc/std/option.zc"
    return ({ ZC_AUTO _z_ret_mv = other; memset(&other, 0, sizeof(_z_ret_mv)); __z_drop_flag_other = 0; 
#line 66 "/usr/local/share/zenc/std/option.zc"
    if (__z_drop_flag_other) Option__String__Drop__glue(&other);
_z_ret_mv; });
    }

#line 66 "/usr/local/share/zenc/std/option.zc"
    if (__z_drop_flag_other) Option__String__Drop__glue(&other);
}

#line 378 "/usr/local/share/zenc/std/vec.zc"

void Vec__String__Drop__drop(Vec__String* self)
{
    {

#line 379 "/usr/local/share/zenc/std/vec.zc"
Vec__String__free(self);
    }
}

#line 73 "/usr/local/share/zenc/std/vec.zc"

Vec__int32_t Vec__int32_t__new(void)
{
    {

#line 74 "/usr/local/share/zenc/std/vec.zc"
    return (Vec__int32_t){.data = NULL};
    }
}

#line 77 "/usr/local/share/zenc/std/vec.zc"

Vec__int32_t Vec__int32_t__with_capacity(size_t cap)
{
    {

#line 78 "/usr/local/share/zenc/std/vec.zc"
if ((cap == 0))     {

#line 79 "/usr/local/share/zenc/std/vec.zc"
    return (Vec__int32_t){.data = NULL};
    }

#line 81 "/usr/local/share/zenc/std/vec.zc"
    return (Vec__int32_t){.data = ((int32_t*)(
#line 82 "/usr/local/share/zenc/std/vec.zc"
malloc((cap * sizeof(int32_t))))), .cap = cap};
    }
}

#line 88 "/usr/local/share/zenc/std/vec.zc"

void Vec__int32_t__grow(Vec__int32_t* self)
{
    {

#line 89 "/usr/local/share/zenc/std/vec.zc"
if ((self->cap == 0))     {

#line 89 "/usr/local/share/zenc/std/vec.zc"
(self->cap = 8);
    }
 else     {

#line 90 "/usr/local/share/zenc/std/vec.zc"
(self->cap = (self->cap * 2));
    }

#line 91 "/usr/local/share/zenc/std/vec.zc"
(self->data = ((int32_t*)(
#line 91 "/usr/local/share/zenc/std/vec.zc"
realloc(self->data, (self->cap * sizeof(int32_t))))));
    }
}

#line 94 "/usr/local/share/zenc/std/vec.zc"

void Vec__int32_t__grow_to_fit(Vec__int32_t* self, size_t new_len)
{
    {

#line 95 "/usr/local/share/zenc/std/vec.zc"
if ((self->cap >= new_len))     {

#line 96 "/usr/local/share/zenc/std/vec.zc"
    return ;
    }

#line 99 "/usr/local/share/zenc/std/vec.zc"
if ((self->cap == 0))     {

#line 99 "/usr/local/share/zenc/std/vec.zc"
(self->cap = 8);
    }

#line 100 "/usr/local/share/zenc/std/vec.zc"
while ((self->cap < new_len))     {

#line 101 "/usr/local/share/zenc/std/vec.zc"
(self->cap = (self->cap * 2));
    }

#line 104 "/usr/local/share/zenc/std/vec.zc"
(self->data = ((int32_t*)(
#line 104 "/usr/local/share/zenc/std/vec.zc"
realloc(self->data, (self->cap * sizeof(int32_t))))));
    }
}

#line 107 "/usr/local/share/zenc/std/vec.zc"

VecIter__int32_t Vec__int32_t__iterator(Vec__int32_t* self)
{
    {

#line 108 "/usr/local/share/zenc/std/vec.zc"
    return (VecIter__int32_t){.data = self->data, .count = self->len};
    }
}

#line 115 "/usr/local/share/zenc/std/vec.zc"

VecIterRef__int32_t Vec__int32_t__iter_ref(Vec__int32_t* self)
{
    {

#line 116 "/usr/local/share/zenc/std/vec.zc"
    return (VecIterRef__int32_t){.data = self->data, .count = self->len};
    }
}

#line 123 "/usr/local/share/zenc/std/vec.zc"

void Vec__int32_t__push(Vec__int32_t* self, int32_t item)
{
    {

#line 124 "/usr/local/share/zenc/std/vec.zc"
if ((self->len >= self->cap))     {

#line 125 "/usr/local/share/zenc/std/vec.zc"
Vec__int32_t__grow(self);
    }

#line 127 "/usr/local/share/zenc/std/vec.zc"
(self->data[self->len] = item);

#line 128 "/usr/local/share/zenc/std/vec.zc"
(self->len = (self->len + 1));
    }
}

#line 131 "/usr/local/share/zenc/std/vec.zc"

void Vec__int32_t__insert(Vec__int32_t* self, size_t idx, int32_t item)
{
    {

#line 132 "/usr/local/share/zenc/std/vec.zc"
if ((idx > self->len))     {

#line 133 "/usr/local/share/zenc/std/vec.zc"
    ({ fprintf(stderr, "%s", "Panic: Insert index out of bounds"); fprintf(stderr, "\n"); 0; });

#line 134 "/usr/local/share/zenc/std/vec.zc"
exit(1);
    }

#line 136 "/usr/local/share/zenc/std/vec.zc"
if ((self->len >= self->cap))     {

#line 137 "/usr/local/share/zenc/std/vec.zc"
Vec__int32_t__grow(self);
    }

#line 140 "/usr/local/share/zenc/std/vec.zc"
if ((idx < self->len))     {

#line 141 "/usr/local/share/zenc/std/vec.zc"
memmove(((self->data + idx) + 1), (self->data + idx), ((self->len - idx) * sizeof(int32_t)));
    }

#line 143 "/usr/local/share/zenc/std/vec.zc"
(self->data[idx] = item);

#line 144 "/usr/local/share/zenc/std/vec.zc"
(self->len = (self->len + 1));
    }
}

#line 147 "/usr/local/share/zenc/std/vec.zc"

int32_t Vec__int32_t__pop(Vec__int32_t* self)
{
    {

#line 148 "/usr/local/share/zenc/std/vec.zc"
if ((self->len == 0))     {

#line 149 "/usr/local/share/zenc/std/vec.zc"
    ({ fprintf(stderr, "%s", "Panic: pop called on empty Vec"); fprintf(stderr, "\n"); 0; });

#line 150 "/usr/local/share/zenc/std/vec.zc"
exit(1);
    }

#line 152 "/usr/local/share/zenc/std/vec.zc"
(self->len = (self->len - 1));

#line 153 "/usr/local/share/zenc/std/vec.zc"
    return self->data[self->len];
    }
}

#line 156 "/usr/local/share/zenc/std/vec.zc"

Option__int32_t Vec__int32_t__pop_opt(Vec__int32_t* self)
{
    {

#line 157 "/usr/local/share/zenc/std/vec.zc"
if ((self->len == 0))     {

#line 158 "/usr/local/share/zenc/std/vec.zc"
    return 
#line 158 "/usr/local/share/zenc/std/vec.zc"
Option__int32_t__None();
    }

#line 160 "/usr/local/share/zenc/std/vec.zc"
(self->len = (self->len - 1));

#line 161 "/usr/local/share/zenc/std/vec.zc"
    return 
#line 161 "/usr/local/share/zenc/std/vec.zc"
Option__int32_t__Some(self->data[self->len]);
    }
}

#line 164 "/usr/local/share/zenc/std/vec.zc"

int32_t Vec__int32_t__remove(Vec__int32_t* self, size_t idx)
{
    {

#line 165 "/usr/local/share/zenc/std/vec.zc"
if ((idx >= self->len))     {

#line 166 "/usr/local/share/zenc/std/vec.zc"
    ({ fprintf(stderr, "%s", "Panic: Remove index out of bounds"); fprintf(stderr, "\n"); 0; });

#line 167 "/usr/local/share/zenc/std/vec.zc"
exit(1);
    }

#line 169 "/usr/local/share/zenc/std/vec.zc"
    int32_t item = self->data[idx];

#line 171 "/usr/local/share/zenc/std/vec.zc"
if ((idx < (self->len - 1)))     {

#line 172 "/usr/local/share/zenc/std/vec.zc"
memmove((self->data + idx), ((self->data + idx) + 1), (((self->len - idx) - 1) * sizeof(int32_t)));
    }

#line 174 "/usr/local/share/zenc/std/vec.zc"
(self->len = (self->len - 1));

#line 175 "/usr/local/share/zenc/std/vec.zc"
    return item;
    }
}

#line 180 "/usr/local/share/zenc/std/vec.zc"

void Vec__int32_t__append(Vec__int32_t* self, Vec__int32_t other)
{

#line 180 "/usr/local/share/zenc/std/vec.zc"
    int __z_drop_flag_other = 1;
    {

#line 181 "/usr/local/share/zenc/std/vec.zc"
    size_t new_len = (self->len + other.len);

#line 182 "/usr/local/share/zenc/std/vec.zc"
Vec__int32_t__grow_to_fit(self, new_len);

#line 184 "/usr/local/share/zenc/std/vec.zc"
memcpy((self->data + self->len), other.data, (other.len * sizeof(int32_t)));

#line 185 "/usr/local/share/zenc/std/vec.zc"
(self->len = new_len);

#line 186 "/usr/local/share/zenc/std/vec.zc"
Vec__int32_t__forget(&other);
    }

#line 180 "/usr/local/share/zenc/std/vec.zc"
    if (__z_drop_flag_other) Vec__int32_t__Drop__glue(&other);
}

#line 189 "/usr/local/share/zenc/std/vec.zc"

int32_t Vec__int32_t__get(Vec__int32_t* self, size_t idx)
{
    {

#line 190 "/usr/local/share/zenc/std/vec.zc"
if ((idx >= self->len))     {

#line 191 "/usr/local/share/zenc/std/vec.zc"
    ({ fprintf(stderr, "%s", "Panic: Index out of bounds"); fprintf(stderr, "\n"); 0; });

#line 192 "/usr/local/share/zenc/std/vec.zc"
exit(1);
    }

#line 194 "/usr/local/share/zenc/std/vec.zc"
    return self->data[idx];
    }
}

#line 197 "/usr/local/share/zenc/std/vec.zc"

int32_t Vec__int32_t__index(Vec__int32_t* self, size_t idx)
{
    {

#line 198 "/usr/local/share/zenc/std/vec.zc"
    return 
#line 198 "/usr/local/share/zenc/std/vec.zc"
Vec__int32_t__get(self, idx);
    }
}

#line 201 "/usr/local/share/zenc/std/vec.zc"

int32_t* Vec__int32_t__get_ref(Vec__int32_t* self, size_t idx)
{
    {

#line 202 "/usr/local/share/zenc/std/vec.zc"
if ((idx >= self->len))     {

#line 203 "/usr/local/share/zenc/std/vec.zc"
    ({ fprintf(stderr, "%s", "Panic: Index out of bounds"); fprintf(stderr, "\n"); 0; });

#line 204 "/usr/local/share/zenc/std/vec.zc"
exit(1);
    }

#line 206 "/usr/local/share/zenc/std/vec.zc"
    return (&self->data[idx]);
    }
}

#line 209 "/usr/local/share/zenc/std/vec.zc"

int32_t Vec__int32_t__last(Vec__int32_t* self)
{
    {

#line 210 "/usr/local/share/zenc/std/vec.zc"
if ((self->len == 0))     {

#line 211 "/usr/local/share/zenc/std/vec.zc"
    ({ fprintf(stderr, "%s", "Panic: last called on empty Vec"); fprintf(stderr, "\n"); 0; });

#line 212 "/usr/local/share/zenc/std/vec.zc"
exit(1);
    }

#line 214 "/usr/local/share/zenc/std/vec.zc"
    return self->data[(self->len - 1)];
    }
}

#line 217 "/usr/local/share/zenc/std/vec.zc"

size_t Vec__int32_t__length(Vec__int32_t* self)
{
    {

#line 218 "/usr/local/share/zenc/std/vec.zc"
    return self->len;
    }
}

#line 221 "/usr/local/share/zenc/std/vec.zc"

bool Vec__int32_t__contains(Vec__int32_t* self, int32_t item)
{
    {

#line 222 "/usr/local/share/zenc/std/vec.zc"
    size_t i = 0;

#line 223 "/usr/local/share/zenc/std/vec.zc"
while ((i < self->len))     {

#line 224 "/usr/local/share/zenc/std/vec.zc"
if ((
#line 224 "/usr/local/share/zenc/std/vec.zc"
memcmp((&self->data[i]), (&item), sizeof(int32_t)) == 0))     {

#line 224 "/usr/local/share/zenc/std/vec.zc"
    return true;
    }
(i++);
    }

#line 227 "/usr/local/share/zenc/std/vec.zc"
    return false;
    }
}

#line 230 "/usr/local/share/zenc/std/vec.zc"

bool Vec__int32_t__is_empty(Vec__int32_t* self)
{
    {

#line 231 "/usr/local/share/zenc/std/vec.zc"
    return (self->len == 0);
    }
}

#line 234 "/usr/local/share/zenc/std/vec.zc"

void Vec__int32_t__clear(Vec__int32_t* self)
{
    {

#line 235 "/usr/local/share/zenc/std/vec.zc"
(self->len = 0);
    }
}

#line 238 "/usr/local/share/zenc/std/vec.zc"

void Vec__int32_t__free(Vec__int32_t* self)
{
    {

#line 239 "/usr/local/share/zenc/std/vec.zc"
if (self->data)     {

#line 239 "/usr/local/share/zenc/std/vec.zc"
free(self->data);
    }

#line 240 "/usr/local/share/zenc/std/vec.zc"
(self->data = NULL);

#line 241 "/usr/local/share/zenc/std/vec.zc"
(self->len = 0);

#line 242 "/usr/local/share/zenc/std/vec.zc"
(self->cap = 0);
    }
}

#line 245 "/usr/local/share/zenc/std/vec.zc"

int32_t Vec__int32_t__first(Vec__int32_t* self)
{
    {

#line 246 "/usr/local/share/zenc/std/vec.zc"
if ((self->len == 0))     {

#line 247 "/usr/local/share/zenc/std/vec.zc"
    ({ fprintf(stderr, "%s", "Panic: first called on empty Vec"); fprintf(stderr, "\n"); 0; });

#line 248 "/usr/local/share/zenc/std/vec.zc"
exit(1);
    }

#line 250 "/usr/local/share/zenc/std/vec.zc"
    return self->data[0];
    }
}

#line 253 "/usr/local/share/zenc/std/vec.zc"

void Vec__int32_t__set(Vec__int32_t* self, size_t idx, int32_t item)
{
    {

#line 254 "/usr/local/share/zenc/std/vec.zc"
if ((idx >= self->len))     {

#line 255 "/usr/local/share/zenc/std/vec.zc"
    ({ fprintf(stderr, "%s", "Panic: set index out of bounds"); fprintf(stderr, "\n"); 0; });

#line 256 "/usr/local/share/zenc/std/vec.zc"
exit(1);
    }

#line 258 "/usr/local/share/zenc/std/vec.zc"
(self->data[idx] = item);
    }
}

#line 261 "/usr/local/share/zenc/std/vec.zc"

void Vec__int32_t__reverse(Vec__int32_t* self)
{
    {

#line 262 "/usr/local/share/zenc/std/vec.zc"
    size_t i = 0;

#line 263 "/usr/local/share/zenc/std/vec.zc"
    size_t j = (self->len - 1);

#line 264 "/usr/local/share/zenc/std/vec.zc"
while ((i < j))     {

#line 265 "/usr/local/share/zenc/std/vec.zc"
    int32_t tmp = self->data[i];

#line 266 "/usr/local/share/zenc/std/vec.zc"
(self->data[i] = self->data[j]);

#line 267 "/usr/local/share/zenc/std/vec.zc"
(self->data[j] = tmp);
(i++);
(j--);
    }
    }
}

#line 275 "/usr/local/share/zenc/std/vec.zc"

bool Vec__int32_t__eq(Vec__int32_t* self, Vec__int32_t* other)
{
    {

#line 276 "/usr/local/share/zenc/std/vec.zc"
if ((self->len != (*other).len))     {

#line 276 "/usr/local/share/zenc/std/vec.zc"
    return false;
    }

#line 277 "/usr/local/share/zenc/std/vec.zc"
    size_t i = 0;

#line 278 "/usr/local/share/zenc/std/vec.zc"
while ((i < self->len))     {

#line 279 "/usr/local/share/zenc/std/vec.zc"
if ((
#line 279 "/usr/local/share/zenc/std/vec.zc"
memcmp((&self->data[i]), (&(*other).data[i]), sizeof(int32_t)) != 0))     {

#line 279 "/usr/local/share/zenc/std/vec.zc"
    return false;
    }

#line 280 "/usr/local/share/zenc/std/vec.zc"
(i = (i + 1));
    }

#line 282 "/usr/local/share/zenc/std/vec.zc"
    return true;
    }
}

#line 286 "/usr/local/share/zenc/std/vec.zc"

void Vec__int32_t__forget(Vec__int32_t* self)
{
    {

#line 287 "/usr/local/share/zenc/std/vec.zc"
(self->data = NULL);

#line 288 "/usr/local/share/zenc/std/vec.zc"
(self->len = 0);

#line 289 "/usr/local/share/zenc/std/vec.zc"
(self->cap = 0);
    }
}

#line 295 "/usr/local/share/zenc/std/vec.zc"

Vec__int32_t Vec__int32_t__add(Vec__int32_t* self, Vec__int32_t* other)
{
    {

#line 296 "/usr/local/share/zenc/std/vec.zc"
    int __z_drop_flag_result = 1; Vec__int32_t result = 
#line 296 "/usr/local/share/zenc/std/vec.zc"
Vec__int32_t__clone(self);

#line 297 "/usr/local/share/zenc/std/vec.zc"
Vec__int32_t__append(&result, Vec__int32_t__clone(other));

#line 298 "/usr/local/share/zenc/std/vec.zc"
    return ({ ZC_AUTO _z_ret_mv = result; memset(&result, 0, sizeof(_z_ret_mv)); __z_drop_flag_result = 0; 
#line 296 "/usr/local/share/zenc/std/vec.zc"
    if (__z_drop_flag_result) Vec__int32_t__Drop__glue(&result);
_z_ret_mv; });

#line 296 "/usr/local/share/zenc/std/vec.zc"
    if (__z_drop_flag_result) Vec__int32_t__Drop__glue(&result);
    }
}

#line 302 "/usr/local/share/zenc/std/vec.zc"

void Vec__int32_t__add_assign(Vec__int32_t* self, Vec__int32_t* other)
{
    {

#line 303 "/usr/local/share/zenc/std/vec.zc"
Vec__int32_t__append(self, Vec__int32_t__clone(other));
    }
}

#line 306 "/usr/local/share/zenc/std/vec.zc"

bool Vec__int32_t__neq(Vec__int32_t* self, Vec__int32_t* other)
{
    {

#line 307 "/usr/local/share/zenc/std/vec.zc"
    return (!
#line 307 "/usr/local/share/zenc/std/vec.zc"
Vec__int32_t__eq(self, other));
    }
}

#line 311 "/usr/local/share/zenc/std/vec.zc"

void Vec__int32_t__shl(Vec__int32_t* self, int32_t item)
{
    {

#line 312 "/usr/local/share/zenc/std/vec.zc"
Vec__int32_t__push(self, item);
    }
}

#line 316 "/usr/local/share/zenc/std/vec.zc"

void Vec__int32_t__shr(Vec__int32_t* self, int32_t* out_item)
{
    {

#line 317 "/usr/local/share/zenc/std/vec.zc"
if ((out_item != NULL))     {

#line 318 "/usr/local/share/zenc/std/vec.zc"
((*out_item) = 
#line 318 "/usr/local/share/zenc/std/vec.zc"
Vec__int32_t__pop(self));
    }
 else     {

#line 320 "/usr/local/share/zenc/std/vec.zc"
Vec__int32_t__pop(self);
    }
    }
}

#line 327 "/usr/local/share/zenc/std/vec.zc"

Vec__int32_t Vec__int32_t__mul(Vec__int32_t* self, size_t count)
{
    {

#line 328 "/usr/local/share/zenc/std/vec.zc"
    int __z_drop_flag_result = 1; Vec__int32_t result = 
#line 328 "/usr/local/share/zenc/std/vec.zc"
Vec__int32_t__with_capacity((self->len * count));

#line 329 "/usr/local/share/zenc/std/vec.zc"
    size_t c = 0;

#line 330 "/usr/local/share/zenc/std/vec.zc"
while ((c < count))     {

#line 331 "/usr/local/share/zenc/std/vec.zc"
Vec__int32_t__append(&result, Vec__int32_t__clone(self));

#line 332 "/usr/local/share/zenc/std/vec.zc"
(c = (c + 1));
    }

#line 334 "/usr/local/share/zenc/std/vec.zc"
    return ({ ZC_AUTO _z_ret_mv = result; memset(&result, 0, sizeof(_z_ret_mv)); __z_drop_flag_result = 0; 
#line 328 "/usr/local/share/zenc/std/vec.zc"
    if (__z_drop_flag_result) Vec__int32_t__Drop__glue(&result);
_z_ret_mv; });

#line 328 "/usr/local/share/zenc/std/vec.zc"
    if (__z_drop_flag_result) Vec__int32_t__Drop__glue(&result);
    }
}

#line 340 "/usr/local/share/zenc/std/vec.zc"

void Vec__int32_t__mul_assign(Vec__int32_t* self, size_t count)
{
    {

#line 341 "/usr/local/share/zenc/std/vec.zc"
if ((count == 0))     {

#line 342 "/usr/local/share/zenc/std/vec.zc"
Vec__int32_t__clear(self);

#line 343 "/usr/local/share/zenc/std/vec.zc"
    return ;
    }

#line 345 "/usr/local/share/zenc/std/vec.zc"
if ((count == 1))     {

#line 346 "/usr/local/share/zenc/std/vec.zc"
    return ;
    }

#line 348 "/usr/local/share/zenc/std/vec.zc"
    size_t original_len = self->len;

#line 349 "/usr/local/share/zenc/std/vec.zc"
Vec__int32_t__grow_to_fit(self, (self->len * count));

#line 350 "/usr/local/share/zenc/std/vec.zc"
    size_t c = 1;

#line 351 "/usr/local/share/zenc/std/vec.zc"
while ((c < count))     {

#line 352 "/usr/local/share/zenc/std/vec.zc"
memcpy((self->data + (original_len * c)), self->data, (original_len * sizeof(int32_t)));

#line 353 "/usr/local/share/zenc/std/vec.zc"
(self->len = (self->len + original_len));

#line 354 "/usr/local/share/zenc/std/vec.zc"
(c = (c + 1));
    }
    }
}

#line 359 "/usr/local/share/zenc/std/vec.zc"

Vec__int32_t Vec__int32_t__clone(Vec__int32_t* self)
{
    {

#line 360 "/usr/local/share/zenc/std/vec.zc"
if ((self->len == 0))     {

#line 361 "/usr/local/share/zenc/std/vec.zc"
    return (Vec__int32_t){.data = NULL};
    }

#line 363 "/usr/local/share/zenc/std/vec.zc"
    int32_t* new_data = ((int32_t*)(
#line 363 "/usr/local/share/zenc/std/vec.zc"
malloc((self->len * sizeof(int32_t)))));

#line 364 "/usr/local/share/zenc/std/vec.zc"
    size_t i = 0;

#line 365 "/usr/local/share/zenc/std/vec.zc"
while ((i < self->len))     {

#line 366 "/usr/local/share/zenc/std/vec.zc"
(new_data[i] = self->data[i]);

#line 367 "/usr/local/share/zenc/std/vec.zc"
(i = (i + 1));
    }

#line 369 "/usr/local/share/zenc/std/vec.zc"
    return (Vec__int32_t){.data = new_data, .len = self->len, .cap = self->len};
    }
}

#line 58 "/usr/local/share/zenc/std/vec.zc"

VecIterResult__int32_t VecIterRef__int32_t__next(VecIterRef__int32_t* self)
{
    {

#line 59 "/usr/local/share/zenc/std/vec.zc"
if ((self->idx < self->count))     {

#line 60 "/usr/local/share/zenc/std/vec.zc"
    int32_t* item = (&self->data[self->idx]);

#line 61 "/usr/local/share/zenc/std/vec.zc"
(self->idx = (self->idx + 1));

#line 62 "/usr/local/share/zenc/std/vec.zc"
    return (VecIterResult__int32_t){.ptr = item};
    }

#line 64 "/usr/local/share/zenc/std/vec.zc"
    return (VecIterResult__int32_t){.ptr = NULL};
    }
}

#line 67 "/usr/local/share/zenc/std/vec.zc"

VecIterRef__int32_t VecIterRef__int32_t__iterator(VecIterRef__int32_t* self)
{
    {

#line 68 "/usr/local/share/zenc/std/vec.zc"
    return *self;
    }
}

#line 23 "/usr/local/share/zenc/std/vec.zc"

bool VecIterResult__int32_t__is_none(VecIterResult__int32_t* self)
{
    {

#line 24 "/usr/local/share/zenc/std/vec.zc"
    return (self->ptr == NULL);
    }
}

#line 27 "/usr/local/share/zenc/std/vec.zc"

int32_t* VecIterResult__int32_t__unwrap(VecIterResult__int32_t* self)
{
    {

#line 28 "/usr/local/share/zenc/std/vec.zc"
if ((self->ptr == NULL))     {

#line 29 "/usr/local/share/zenc/std/vec.zc"
    ({ fprintf(stderr, "%s", "Panic: unwrap called on null VecIterResult"); fprintf(stderr, "\n"); 0; });

#line 30 "/usr/local/share/zenc/std/vec.zc"
exit(1);
    }

#line 32 "/usr/local/share/zenc/std/vec.zc"
    return self->ptr;
    }
}

#line 43 "/usr/local/share/zenc/std/vec.zc"

Option__int32_t VecIter__int32_t__next(VecIter__int32_t* self)
{
    {

#line 44 "/usr/local/share/zenc/std/vec.zc"
if ((self->idx < self->count))     {

#line 45 "/usr/local/share/zenc/std/vec.zc"
    int32_t item = self->data[self->idx];

#line 46 "/usr/local/share/zenc/std/vec.zc"
(self->idx = (self->idx + 1));

#line 47 "/usr/local/share/zenc/std/vec.zc"
    return 
#line 47 "/usr/local/share/zenc/std/vec.zc"
Option__int32_t__Some(item);
    }

#line 49 "/usr/local/share/zenc/std/vec.zc"
    return 
#line 49 "/usr/local/share/zenc/std/vec.zc"
Option__int32_t__None();
    }
}

#line 52 "/usr/local/share/zenc/std/vec.zc"

VecIter__int32_t VecIter__int32_t__iterator(VecIter__int32_t* self)
{
    {

#line 53 "/usr/local/share/zenc/std/vec.zc"
    return *self;
    }
}

#line 378 "/usr/local/share/zenc/std/vec.zc"

void Vec__int32_t__Drop__drop(Vec__int32_t* self)
{
    {

#line 379 "/usr/local/share/zenc/std/vec.zc"
Vec__int32_t__free(self);
    }
}

#line 73 "/usr/local/share/zenc/std/vec.zc"

Vec__size_t Vec__size_t__new(void)
{
    {

#line 74 "/usr/local/share/zenc/std/vec.zc"
    return (Vec__size_t){.data = NULL};
    }
}

#line 77 "/usr/local/share/zenc/std/vec.zc"

Vec__size_t Vec__size_t__with_capacity(size_t cap)
{
    {

#line 78 "/usr/local/share/zenc/std/vec.zc"
if ((cap == 0))     {

#line 79 "/usr/local/share/zenc/std/vec.zc"
    return (Vec__size_t){.data = NULL};
    }

#line 81 "/usr/local/share/zenc/std/vec.zc"
    return (Vec__size_t){.data = ((size_t*)(
#line 82 "/usr/local/share/zenc/std/vec.zc"
malloc((cap * sizeof(size_t))))), .cap = cap};
    }
}

#line 88 "/usr/local/share/zenc/std/vec.zc"

void Vec__size_t__grow(Vec__size_t* self)
{
    {

#line 89 "/usr/local/share/zenc/std/vec.zc"
if ((self->cap == 0))     {

#line 89 "/usr/local/share/zenc/std/vec.zc"
(self->cap = 8);
    }
 else     {

#line 90 "/usr/local/share/zenc/std/vec.zc"
(self->cap = (self->cap * 2));
    }

#line 91 "/usr/local/share/zenc/std/vec.zc"
(self->data = ((size_t*)(
#line 91 "/usr/local/share/zenc/std/vec.zc"
realloc(self->data, (self->cap * sizeof(size_t))))));
    }
}

#line 94 "/usr/local/share/zenc/std/vec.zc"

void Vec__size_t__grow_to_fit(Vec__size_t* self, size_t new_len)
{
    {

#line 95 "/usr/local/share/zenc/std/vec.zc"
if ((self->cap >= new_len))     {

#line 96 "/usr/local/share/zenc/std/vec.zc"
    return ;
    }

#line 99 "/usr/local/share/zenc/std/vec.zc"
if ((self->cap == 0))     {

#line 99 "/usr/local/share/zenc/std/vec.zc"
(self->cap = 8);
    }

#line 100 "/usr/local/share/zenc/std/vec.zc"
while ((self->cap < new_len))     {

#line 101 "/usr/local/share/zenc/std/vec.zc"
(self->cap = (self->cap * 2));
    }

#line 104 "/usr/local/share/zenc/std/vec.zc"
(self->data = ((size_t*)(
#line 104 "/usr/local/share/zenc/std/vec.zc"
realloc(self->data, (self->cap * sizeof(size_t))))));
    }
}

#line 107 "/usr/local/share/zenc/std/vec.zc"

VecIter__size_t Vec__size_t__iterator(Vec__size_t* self)
{
    {

#line 108 "/usr/local/share/zenc/std/vec.zc"
    return (VecIter__size_t){.data = self->data, .count = self->len};
    }
}

#line 115 "/usr/local/share/zenc/std/vec.zc"

VecIterRef__size_t Vec__size_t__iter_ref(Vec__size_t* self)
{
    {

#line 116 "/usr/local/share/zenc/std/vec.zc"
    return (VecIterRef__size_t){.data = self->data, .count = self->len};
    }
}

#line 123 "/usr/local/share/zenc/std/vec.zc"

void Vec__size_t__push(Vec__size_t* self, size_t item)
{
    {

#line 124 "/usr/local/share/zenc/std/vec.zc"
if ((self->len >= self->cap))     {

#line 125 "/usr/local/share/zenc/std/vec.zc"
Vec__size_t__grow(self);
    }

#line 127 "/usr/local/share/zenc/std/vec.zc"
(self->data[self->len] = item);

#line 128 "/usr/local/share/zenc/std/vec.zc"
(self->len = (self->len + 1));
    }
}

#line 131 "/usr/local/share/zenc/std/vec.zc"

void Vec__size_t__insert(Vec__size_t* self, size_t idx, size_t item)
{
    {

#line 132 "/usr/local/share/zenc/std/vec.zc"
if ((idx > self->len))     {

#line 133 "/usr/local/share/zenc/std/vec.zc"
    ({ fprintf(stderr, "%s", "Panic: Insert index out of bounds"); fprintf(stderr, "\n"); 0; });

#line 134 "/usr/local/share/zenc/std/vec.zc"
exit(1);
    }

#line 136 "/usr/local/share/zenc/std/vec.zc"
if ((self->len >= self->cap))     {

#line 137 "/usr/local/share/zenc/std/vec.zc"
Vec__size_t__grow(self);
    }

#line 140 "/usr/local/share/zenc/std/vec.zc"
if ((idx < self->len))     {

#line 141 "/usr/local/share/zenc/std/vec.zc"
memmove(((self->data + idx) + 1), (self->data + idx), ((self->len - idx) * sizeof(size_t)));
    }

#line 143 "/usr/local/share/zenc/std/vec.zc"
(self->data[idx] = item);

#line 144 "/usr/local/share/zenc/std/vec.zc"
(self->len = (self->len + 1));
    }
}

#line 147 "/usr/local/share/zenc/std/vec.zc"

size_t Vec__size_t__pop(Vec__size_t* self)
{
    {

#line 148 "/usr/local/share/zenc/std/vec.zc"
if ((self->len == 0))     {

#line 149 "/usr/local/share/zenc/std/vec.zc"
    ({ fprintf(stderr, "%s", "Panic: pop called on empty Vec"); fprintf(stderr, "\n"); 0; });

#line 150 "/usr/local/share/zenc/std/vec.zc"
exit(1);
    }

#line 152 "/usr/local/share/zenc/std/vec.zc"
(self->len = (self->len - 1));

#line 153 "/usr/local/share/zenc/std/vec.zc"
    return self->data[self->len];
    }
}

#line 156 "/usr/local/share/zenc/std/vec.zc"

Option__size_t Vec__size_t__pop_opt(Vec__size_t* self)
{
    {

#line 157 "/usr/local/share/zenc/std/vec.zc"
if ((self->len == 0))     {

#line 158 "/usr/local/share/zenc/std/vec.zc"
    return 
#line 158 "/usr/local/share/zenc/std/vec.zc"
Option__size_t__None();
    }

#line 160 "/usr/local/share/zenc/std/vec.zc"
(self->len = (self->len - 1));

#line 161 "/usr/local/share/zenc/std/vec.zc"
    return 
#line 161 "/usr/local/share/zenc/std/vec.zc"
Option__size_t__Some(self->data[self->len]);
    }
}

#line 164 "/usr/local/share/zenc/std/vec.zc"

size_t Vec__size_t__remove(Vec__size_t* self, size_t idx)
{
    {

#line 165 "/usr/local/share/zenc/std/vec.zc"
if ((idx >= self->len))     {

#line 166 "/usr/local/share/zenc/std/vec.zc"
    ({ fprintf(stderr, "%s", "Panic: Remove index out of bounds"); fprintf(stderr, "\n"); 0; });

#line 167 "/usr/local/share/zenc/std/vec.zc"
exit(1);
    }

#line 169 "/usr/local/share/zenc/std/vec.zc"
    size_t item = self->data[idx];

#line 171 "/usr/local/share/zenc/std/vec.zc"
if ((idx < (self->len - 1)))     {

#line 172 "/usr/local/share/zenc/std/vec.zc"
memmove((self->data + idx), ((self->data + idx) + 1), (((self->len - idx) - 1) * sizeof(size_t)));
    }

#line 174 "/usr/local/share/zenc/std/vec.zc"
(self->len = (self->len - 1));

#line 175 "/usr/local/share/zenc/std/vec.zc"
    return item;
    }
}

#line 180 "/usr/local/share/zenc/std/vec.zc"

void Vec__size_t__append(Vec__size_t* self, Vec__size_t other)
{

#line 180 "/usr/local/share/zenc/std/vec.zc"
    int __z_drop_flag_other = 1;
    {

#line 181 "/usr/local/share/zenc/std/vec.zc"
    size_t new_len = (self->len + other.len);

#line 182 "/usr/local/share/zenc/std/vec.zc"
Vec__size_t__grow_to_fit(self, new_len);

#line 184 "/usr/local/share/zenc/std/vec.zc"
memcpy((self->data + self->len), other.data, (other.len * sizeof(size_t)));

#line 185 "/usr/local/share/zenc/std/vec.zc"
(self->len = new_len);

#line 186 "/usr/local/share/zenc/std/vec.zc"
Vec__size_t__forget(&other);
    }

#line 180 "/usr/local/share/zenc/std/vec.zc"
    if (__z_drop_flag_other) Vec__size_t__Drop__glue(&other);
}

#line 189 "/usr/local/share/zenc/std/vec.zc"

size_t Vec__size_t__get(Vec__size_t* self, size_t idx)
{
    {

#line 190 "/usr/local/share/zenc/std/vec.zc"
if ((idx >= self->len))     {

#line 191 "/usr/local/share/zenc/std/vec.zc"
    ({ fprintf(stderr, "%s", "Panic: Index out of bounds"); fprintf(stderr, "\n"); 0; });

#line 192 "/usr/local/share/zenc/std/vec.zc"
exit(1);
    }

#line 194 "/usr/local/share/zenc/std/vec.zc"
    return self->data[idx];
    }
}

#line 197 "/usr/local/share/zenc/std/vec.zc"

size_t Vec__size_t__index(Vec__size_t* self, size_t idx)
{
    {

#line 198 "/usr/local/share/zenc/std/vec.zc"
    return 
#line 198 "/usr/local/share/zenc/std/vec.zc"
Vec__size_t__get(self, idx);
    }
}

#line 201 "/usr/local/share/zenc/std/vec.zc"

size_t* Vec__size_t__get_ref(Vec__size_t* self, size_t idx)
{
    {

#line 202 "/usr/local/share/zenc/std/vec.zc"
if ((idx >= self->len))     {

#line 203 "/usr/local/share/zenc/std/vec.zc"
    ({ fprintf(stderr, "%s", "Panic: Index out of bounds"); fprintf(stderr, "\n"); 0; });

#line 204 "/usr/local/share/zenc/std/vec.zc"
exit(1);
    }

#line 206 "/usr/local/share/zenc/std/vec.zc"
    return (&self->data[idx]);
    }
}

#line 209 "/usr/local/share/zenc/std/vec.zc"

size_t Vec__size_t__last(Vec__size_t* self)
{
    {

#line 210 "/usr/local/share/zenc/std/vec.zc"
if ((self->len == 0))     {

#line 211 "/usr/local/share/zenc/std/vec.zc"
    ({ fprintf(stderr, "%s", "Panic: last called on empty Vec"); fprintf(stderr, "\n"); 0; });

#line 212 "/usr/local/share/zenc/std/vec.zc"
exit(1);
    }

#line 214 "/usr/local/share/zenc/std/vec.zc"
    return self->data[(self->len - 1)];
    }
}

#line 217 "/usr/local/share/zenc/std/vec.zc"

size_t Vec__size_t__length(Vec__size_t* self)
{
    {

#line 218 "/usr/local/share/zenc/std/vec.zc"
    return self->len;
    }
}

#line 221 "/usr/local/share/zenc/std/vec.zc"

bool Vec__size_t__contains(Vec__size_t* self, size_t item)
{
    {

#line 222 "/usr/local/share/zenc/std/vec.zc"
    size_t i = 0;

#line 223 "/usr/local/share/zenc/std/vec.zc"
while ((i < self->len))     {

#line 224 "/usr/local/share/zenc/std/vec.zc"
if ((
#line 224 "/usr/local/share/zenc/std/vec.zc"
memcmp((&self->data[i]), (&item), sizeof(size_t)) == 0))     {

#line 224 "/usr/local/share/zenc/std/vec.zc"
    return true;
    }
(i++);
    }

#line 227 "/usr/local/share/zenc/std/vec.zc"
    return false;
    }
}

#line 230 "/usr/local/share/zenc/std/vec.zc"

bool Vec__size_t__is_empty(Vec__size_t* self)
{
    {

#line 231 "/usr/local/share/zenc/std/vec.zc"
    return (self->len == 0);
    }
}

#line 234 "/usr/local/share/zenc/std/vec.zc"

void Vec__size_t__clear(Vec__size_t* self)
{
    {

#line 235 "/usr/local/share/zenc/std/vec.zc"
(self->len = 0);
    }
}

#line 238 "/usr/local/share/zenc/std/vec.zc"

void Vec__size_t__free(Vec__size_t* self)
{
    {

#line 239 "/usr/local/share/zenc/std/vec.zc"
if (self->data)     {

#line 239 "/usr/local/share/zenc/std/vec.zc"
free(self->data);
    }

#line 240 "/usr/local/share/zenc/std/vec.zc"
(self->data = NULL);

#line 241 "/usr/local/share/zenc/std/vec.zc"
(self->len = 0);

#line 242 "/usr/local/share/zenc/std/vec.zc"
(self->cap = 0);
    }
}

#line 245 "/usr/local/share/zenc/std/vec.zc"

size_t Vec__size_t__first(Vec__size_t* self)
{
    {

#line 246 "/usr/local/share/zenc/std/vec.zc"
if ((self->len == 0))     {

#line 247 "/usr/local/share/zenc/std/vec.zc"
    ({ fprintf(stderr, "%s", "Panic: first called on empty Vec"); fprintf(stderr, "\n"); 0; });

#line 248 "/usr/local/share/zenc/std/vec.zc"
exit(1);
    }

#line 250 "/usr/local/share/zenc/std/vec.zc"
    return self->data[0];
    }
}

#line 253 "/usr/local/share/zenc/std/vec.zc"

void Vec__size_t__set(Vec__size_t* self, size_t idx, size_t item)
{
    {

#line 254 "/usr/local/share/zenc/std/vec.zc"
if ((idx >= self->len))     {

#line 255 "/usr/local/share/zenc/std/vec.zc"
    ({ fprintf(stderr, "%s", "Panic: set index out of bounds"); fprintf(stderr, "\n"); 0; });

#line 256 "/usr/local/share/zenc/std/vec.zc"
exit(1);
    }

#line 258 "/usr/local/share/zenc/std/vec.zc"
(self->data[idx] = item);
    }
}

#line 261 "/usr/local/share/zenc/std/vec.zc"

void Vec__size_t__reverse(Vec__size_t* self)
{
    {

#line 262 "/usr/local/share/zenc/std/vec.zc"
    size_t i = 0;

#line 263 "/usr/local/share/zenc/std/vec.zc"
    size_t j = (self->len - 1);

#line 264 "/usr/local/share/zenc/std/vec.zc"
while ((i < j))     {

#line 265 "/usr/local/share/zenc/std/vec.zc"
    size_t tmp = self->data[i];

#line 266 "/usr/local/share/zenc/std/vec.zc"
(self->data[i] = self->data[j]);

#line 267 "/usr/local/share/zenc/std/vec.zc"
(self->data[j] = tmp);
(i++);
(j--);
    }
    }
}

#line 275 "/usr/local/share/zenc/std/vec.zc"

bool Vec__size_t__eq(Vec__size_t* self, Vec__size_t* other)
{
    {

#line 276 "/usr/local/share/zenc/std/vec.zc"
if ((self->len != (*other).len))     {

#line 276 "/usr/local/share/zenc/std/vec.zc"
    return false;
    }

#line 277 "/usr/local/share/zenc/std/vec.zc"
    size_t i = 0;

#line 278 "/usr/local/share/zenc/std/vec.zc"
while ((i < self->len))     {

#line 279 "/usr/local/share/zenc/std/vec.zc"
if ((
#line 279 "/usr/local/share/zenc/std/vec.zc"
memcmp((&self->data[i]), (&(*other).data[i]), sizeof(size_t)) != 0))     {

#line 279 "/usr/local/share/zenc/std/vec.zc"
    return false;
    }

#line 280 "/usr/local/share/zenc/std/vec.zc"
(i = (i + 1));
    }

#line 282 "/usr/local/share/zenc/std/vec.zc"
    return true;
    }
}

#line 286 "/usr/local/share/zenc/std/vec.zc"

void Vec__size_t__forget(Vec__size_t* self)
{
    {

#line 287 "/usr/local/share/zenc/std/vec.zc"
(self->data = NULL);

#line 288 "/usr/local/share/zenc/std/vec.zc"
(self->len = 0);

#line 289 "/usr/local/share/zenc/std/vec.zc"
(self->cap = 0);
    }
}

#line 295 "/usr/local/share/zenc/std/vec.zc"

Vec__size_t Vec__size_t__add(Vec__size_t* self, Vec__size_t* other)
{
    {

#line 296 "/usr/local/share/zenc/std/vec.zc"
    int __z_drop_flag_result = 1; Vec__size_t result = 
#line 296 "/usr/local/share/zenc/std/vec.zc"
Vec__size_t__clone(self);

#line 297 "/usr/local/share/zenc/std/vec.zc"
Vec__size_t__append(&result, Vec__size_t__clone(other));

#line 298 "/usr/local/share/zenc/std/vec.zc"
    return ({ ZC_AUTO _z_ret_mv = result; memset(&result, 0, sizeof(_z_ret_mv)); __z_drop_flag_result = 0; 
#line 296 "/usr/local/share/zenc/std/vec.zc"
    if (__z_drop_flag_result) Vec__size_t__Drop__glue(&result);
_z_ret_mv; });

#line 296 "/usr/local/share/zenc/std/vec.zc"
    if (__z_drop_flag_result) Vec__size_t__Drop__glue(&result);
    }
}

#line 302 "/usr/local/share/zenc/std/vec.zc"

void Vec__size_t__add_assign(Vec__size_t* self, Vec__size_t* other)
{
    {

#line 303 "/usr/local/share/zenc/std/vec.zc"
Vec__size_t__append(self, Vec__size_t__clone(other));
    }
}

#line 306 "/usr/local/share/zenc/std/vec.zc"

bool Vec__size_t__neq(Vec__size_t* self, Vec__size_t* other)
{
    {

#line 307 "/usr/local/share/zenc/std/vec.zc"
    return (!
#line 307 "/usr/local/share/zenc/std/vec.zc"
Vec__size_t__eq(self, other));
    }
}

#line 311 "/usr/local/share/zenc/std/vec.zc"

void Vec__size_t__shl(Vec__size_t* self, size_t item)
{
    {

#line 312 "/usr/local/share/zenc/std/vec.zc"
Vec__size_t__push(self, item);
    }
}

#line 316 "/usr/local/share/zenc/std/vec.zc"

void Vec__size_t__shr(Vec__size_t* self, size_t* out_item)
{
    {

#line 317 "/usr/local/share/zenc/std/vec.zc"
if ((out_item != NULL))     {

#line 318 "/usr/local/share/zenc/std/vec.zc"
((*out_item) = 
#line 318 "/usr/local/share/zenc/std/vec.zc"
Vec__size_t__pop(self));
    }
 else     {

#line 320 "/usr/local/share/zenc/std/vec.zc"
Vec__size_t__pop(self);
    }
    }
}

#line 327 "/usr/local/share/zenc/std/vec.zc"

Vec__size_t Vec__size_t__mul(Vec__size_t* self, size_t count)
{
    {

#line 328 "/usr/local/share/zenc/std/vec.zc"
    int __z_drop_flag_result = 1; Vec__size_t result = 
#line 328 "/usr/local/share/zenc/std/vec.zc"
Vec__size_t__with_capacity((self->len * count));

#line 329 "/usr/local/share/zenc/std/vec.zc"
    size_t c = 0;

#line 330 "/usr/local/share/zenc/std/vec.zc"
while ((c < count))     {

#line 331 "/usr/local/share/zenc/std/vec.zc"
Vec__size_t__append(&result, Vec__size_t__clone(self));

#line 332 "/usr/local/share/zenc/std/vec.zc"
(c = (c + 1));
    }

#line 334 "/usr/local/share/zenc/std/vec.zc"
    return ({ ZC_AUTO _z_ret_mv = result; memset(&result, 0, sizeof(_z_ret_mv)); __z_drop_flag_result = 0; 
#line 328 "/usr/local/share/zenc/std/vec.zc"
    if (__z_drop_flag_result) Vec__size_t__Drop__glue(&result);
_z_ret_mv; });

#line 328 "/usr/local/share/zenc/std/vec.zc"
    if (__z_drop_flag_result) Vec__size_t__Drop__glue(&result);
    }
}

#line 340 "/usr/local/share/zenc/std/vec.zc"

void Vec__size_t__mul_assign(Vec__size_t* self, size_t count)
{
    {

#line 341 "/usr/local/share/zenc/std/vec.zc"
if ((count == 0))     {

#line 342 "/usr/local/share/zenc/std/vec.zc"
Vec__size_t__clear(self);

#line 343 "/usr/local/share/zenc/std/vec.zc"
    return ;
    }

#line 345 "/usr/local/share/zenc/std/vec.zc"
if ((count == 1))     {

#line 346 "/usr/local/share/zenc/std/vec.zc"
    return ;
    }

#line 348 "/usr/local/share/zenc/std/vec.zc"
    size_t original_len = self->len;

#line 349 "/usr/local/share/zenc/std/vec.zc"
Vec__size_t__grow_to_fit(self, (self->len * count));

#line 350 "/usr/local/share/zenc/std/vec.zc"
    size_t c = 1;

#line 351 "/usr/local/share/zenc/std/vec.zc"
while ((c < count))     {

#line 352 "/usr/local/share/zenc/std/vec.zc"
memcpy((self->data + (original_len * c)), self->data, (original_len * sizeof(size_t)));

#line 353 "/usr/local/share/zenc/std/vec.zc"
(self->len = (self->len + original_len));

#line 354 "/usr/local/share/zenc/std/vec.zc"
(c = (c + 1));
    }
    }
}

#line 359 "/usr/local/share/zenc/std/vec.zc"

Vec__size_t Vec__size_t__clone(Vec__size_t* self)
{
    {

#line 360 "/usr/local/share/zenc/std/vec.zc"
if ((self->len == 0))     {

#line 361 "/usr/local/share/zenc/std/vec.zc"
    return (Vec__size_t){.data = NULL};
    }

#line 363 "/usr/local/share/zenc/std/vec.zc"
    size_t* new_data = ((size_t*)(
#line 363 "/usr/local/share/zenc/std/vec.zc"
malloc((self->len * sizeof(size_t)))));

#line 364 "/usr/local/share/zenc/std/vec.zc"
    size_t i = 0;

#line 365 "/usr/local/share/zenc/std/vec.zc"
while ((i < self->len))     {

#line 366 "/usr/local/share/zenc/std/vec.zc"
(new_data[i] = self->data[i]);

#line 367 "/usr/local/share/zenc/std/vec.zc"
(i = (i + 1));
    }

#line 369 "/usr/local/share/zenc/std/vec.zc"
    return (Vec__size_t){.data = new_data, .len = self->len, .cap = self->len};
    }
}

#line 58 "/usr/local/share/zenc/std/vec.zc"

VecIterResult__size_t VecIterRef__size_t__next(VecIterRef__size_t* self)
{
    {

#line 59 "/usr/local/share/zenc/std/vec.zc"
if ((self->idx < self->count))     {

#line 60 "/usr/local/share/zenc/std/vec.zc"
    size_t* item = (&self->data[self->idx]);

#line 61 "/usr/local/share/zenc/std/vec.zc"
(self->idx = (self->idx + 1));

#line 62 "/usr/local/share/zenc/std/vec.zc"
    return (VecIterResult__size_t){.ptr = item};
    }

#line 64 "/usr/local/share/zenc/std/vec.zc"
    return (VecIterResult__size_t){.ptr = NULL};
    }
}

#line 67 "/usr/local/share/zenc/std/vec.zc"

VecIterRef__size_t VecIterRef__size_t__iterator(VecIterRef__size_t* self)
{
    {

#line 68 "/usr/local/share/zenc/std/vec.zc"
    return *self;
    }
}

#line 23 "/usr/local/share/zenc/std/vec.zc"

bool VecIterResult__size_t__is_none(VecIterResult__size_t* self)
{
    {

#line 24 "/usr/local/share/zenc/std/vec.zc"
    return (self->ptr == NULL);
    }
}

#line 27 "/usr/local/share/zenc/std/vec.zc"

size_t* VecIterResult__size_t__unwrap(VecIterResult__size_t* self)
{
    {

#line 28 "/usr/local/share/zenc/std/vec.zc"
if ((self->ptr == NULL))     {

#line 29 "/usr/local/share/zenc/std/vec.zc"
    ({ fprintf(stderr, "%s", "Panic: unwrap called on null VecIterResult"); fprintf(stderr, "\n"); 0; });

#line 30 "/usr/local/share/zenc/std/vec.zc"
exit(1);
    }

#line 32 "/usr/local/share/zenc/std/vec.zc"
    return self->ptr;
    }
}

#line 43 "/usr/local/share/zenc/std/vec.zc"

Option__size_t VecIter__size_t__next(VecIter__size_t* self)
{
    {

#line 44 "/usr/local/share/zenc/std/vec.zc"
if ((self->idx < self->count))     {

#line 45 "/usr/local/share/zenc/std/vec.zc"
    size_t item = self->data[self->idx];

#line 46 "/usr/local/share/zenc/std/vec.zc"
(self->idx = (self->idx + 1));

#line 47 "/usr/local/share/zenc/std/vec.zc"
    return 
#line 47 "/usr/local/share/zenc/std/vec.zc"
Option__size_t__Some(item);
    }

#line 49 "/usr/local/share/zenc/std/vec.zc"
    return 
#line 49 "/usr/local/share/zenc/std/vec.zc"
Option__size_t__None();
    }
}

#line 52 "/usr/local/share/zenc/std/vec.zc"

VecIter__size_t VecIter__size_t__iterator(VecIter__size_t* self)
{
    {

#line 53 "/usr/local/share/zenc/std/vec.zc"
    return *self;
    }
}

#line 378 "/usr/local/share/zenc/std/vec.zc"

void Vec__size_t__Drop__drop(Vec__size_t* self)
{
    {

#line 379 "/usr/local/share/zenc/std/vec.zc"
Vec__size_t__free(self);
    }
}

#line 10 "/usr/local/share/zenc/std/option.zc"

Option__size_t Option__size_t__Some(size_t v)
{
    {

#line 11 "/usr/local/share/zenc/std/option.zc"
    return (Option__size_t){.is_some = true, .val = v};
    }
}

#line 14 "/usr/local/share/zenc/std/option.zc"

Option__size_t Option__size_t__None(void)
{
    {

#line 15 "/usr/local/share/zenc/std/option.zc"
    Option__size_t opt = {0};

#line 16 "/usr/local/share/zenc/std/option.zc"
(opt.is_some = false);

#line 17 "/usr/local/share/zenc/std/option.zc"
memset((&opt.val), 0, sizeof(size_t));

#line 18 "/usr/local/share/zenc/std/option.zc"
    return opt;
    }
}

#line 21 "/usr/local/share/zenc/std/option.zc"

bool Option__size_t__is_some(Option__size_t* self)
{
    {

#line 22 "/usr/local/share/zenc/std/option.zc"
    return self->is_some;
    }
}

#line 25 "/usr/local/share/zenc/std/option.zc"

bool Option__size_t__is_none(Option__size_t* self)
{
    {

#line 26 "/usr/local/share/zenc/std/option.zc"
    return (!self->is_some);
    }
}

#line 29 "/usr/local/share/zenc/std/option.zc"

void Option__size_t__forget(Option__size_t* self)
{
    {

#line 30 "/usr/local/share/zenc/std/option.zc"
memset((&self->val), 0, sizeof(size_t));
    }
}

#line 33 "/usr/local/share/zenc/std/option.zc"

size_t Option__size_t__unwrap(Option__size_t* self)
{
    {

#line 34 "/usr/local/share/zenc/std/option.zc"
if ((!self->is_some))     {

#line 35 "/usr/local/share/zenc/std/option.zc"
    ({ fprintf(stderr, "%s", "Panic: unwrap called on None"); fprintf(stderr, "\n"); 0; });

#line 36 "/usr/local/share/zenc/std/option.zc"
exit(1);
    }

#line 38 "/usr/local/share/zenc/std/option.zc"
    size_t v = self->val;

#line 39 "/usr/local/share/zenc/std/option.zc"
memset((&self->val), 0, sizeof(size_t));

#line 40 "/usr/local/share/zenc/std/option.zc"
    return v;
    }
}

#line 43 "/usr/local/share/zenc/std/option.zc"

size_t* Option__size_t__unwrap_ref(Option__size_t* self)
{
    {

#line 44 "/usr/local/share/zenc/std/option.zc"
if ((!self->is_some))     {

#line 45 "/usr/local/share/zenc/std/option.zc"
    ({ fprintf(stderr, "%s", "Panic: unwrap_ref called on None"); fprintf(stderr, "\n"); 0; });

#line 46 "/usr/local/share/zenc/std/option.zc"
exit(1);
    }

#line 48 "/usr/local/share/zenc/std/option.zc"
    return (&self->val);
    }
}

#line 51 "/usr/local/share/zenc/std/option.zc"

size_t Option__size_t__unwrap_or(Option__size_t* self, size_t def_val)
{
    {

#line 52 "/usr/local/share/zenc/std/option.zc"
if (self->is_some)     {

#line 53 "/usr/local/share/zenc/std/option.zc"
    return self->val;
    }

#line 55 "/usr/local/share/zenc/std/option.zc"
    return def_val;
    }
}

#line 58 "/usr/local/share/zenc/std/option.zc"

size_t Option__size_t__expect(Option__size_t* self, char* msg)
{
    {

#line 59 "/usr/local/share/zenc/std/option.zc"
if ((!self->is_some))     {

#line 60 "/usr/local/share/zenc/std/option.zc"
    ({ fprintf(stderr, "%s", "Panic: "); fprintf(stderr, "%s", msg); fprintf(stderr, "\n"); 0; });

#line 61 "/usr/local/share/zenc/std/option.zc"
exit(1);
    }

#line 63 "/usr/local/share/zenc/std/option.zc"
    return self->val;
    }
}

#line 66 "/usr/local/share/zenc/std/option.zc"

Option__size_t Option__size_t__or_else(Option__size_t* self, Option__size_t other)
{
    {

#line 67 "/usr/local/share/zenc/std/option.zc"
if (self->is_some)     {

#line 67 "/usr/local/share/zenc/std/option.zc"
    return *self;
    }

#line 68 "/usr/local/share/zenc/std/option.zc"
    return other;
    }
}

#line 10 "/usr/local/share/zenc/std/option.zc"

Option__int32_t Option__int32_t__Some(int32_t v)
{
    {

#line 11 "/usr/local/share/zenc/std/option.zc"
    return (Option__int32_t){.is_some = true, .val = v};
    }
}

#line 14 "/usr/local/share/zenc/std/option.zc"

Option__int32_t Option__int32_t__None(void)
{
    {

#line 15 "/usr/local/share/zenc/std/option.zc"
    Option__int32_t opt = {0};

#line 16 "/usr/local/share/zenc/std/option.zc"
(opt.is_some = false);

#line 17 "/usr/local/share/zenc/std/option.zc"
memset((&opt.val), 0, sizeof(int32_t));

#line 18 "/usr/local/share/zenc/std/option.zc"
    return opt;
    }
}

#line 21 "/usr/local/share/zenc/std/option.zc"

bool Option__int32_t__is_some(Option__int32_t* self)
{
    {

#line 22 "/usr/local/share/zenc/std/option.zc"
    return self->is_some;
    }
}

#line 25 "/usr/local/share/zenc/std/option.zc"

bool Option__int32_t__is_none(Option__int32_t* self)
{
    {

#line 26 "/usr/local/share/zenc/std/option.zc"
    return (!self->is_some);
    }
}

#line 29 "/usr/local/share/zenc/std/option.zc"

void Option__int32_t__forget(Option__int32_t* self)
{
    {

#line 30 "/usr/local/share/zenc/std/option.zc"
memset((&self->val), 0, sizeof(int32_t));
    }
}

#line 33 "/usr/local/share/zenc/std/option.zc"

int32_t Option__int32_t__unwrap(Option__int32_t* self)
{
    {

#line 34 "/usr/local/share/zenc/std/option.zc"
if ((!self->is_some))     {

#line 35 "/usr/local/share/zenc/std/option.zc"
    ({ fprintf(stderr, "%s", "Panic: unwrap called on None"); fprintf(stderr, "\n"); 0; });

#line 36 "/usr/local/share/zenc/std/option.zc"
exit(1);
    }

#line 38 "/usr/local/share/zenc/std/option.zc"
    int32_t v = self->val;

#line 39 "/usr/local/share/zenc/std/option.zc"
memset((&self->val), 0, sizeof(int32_t));

#line 40 "/usr/local/share/zenc/std/option.zc"
    return v;
    }
}

#line 43 "/usr/local/share/zenc/std/option.zc"

int32_t* Option__int32_t__unwrap_ref(Option__int32_t* self)
{
    {

#line 44 "/usr/local/share/zenc/std/option.zc"
if ((!self->is_some))     {

#line 45 "/usr/local/share/zenc/std/option.zc"
    ({ fprintf(stderr, "%s", "Panic: unwrap_ref called on None"); fprintf(stderr, "\n"); 0; });

#line 46 "/usr/local/share/zenc/std/option.zc"
exit(1);
    }

#line 48 "/usr/local/share/zenc/std/option.zc"
    return (&self->val);
    }
}

#line 51 "/usr/local/share/zenc/std/option.zc"

int32_t Option__int32_t__unwrap_or(Option__int32_t* self, int32_t def_val)
{
    {

#line 52 "/usr/local/share/zenc/std/option.zc"
if (self->is_some)     {

#line 53 "/usr/local/share/zenc/std/option.zc"
    return self->val;
    }

#line 55 "/usr/local/share/zenc/std/option.zc"
    return def_val;
    }
}

#line 58 "/usr/local/share/zenc/std/option.zc"

int32_t Option__int32_t__expect(Option__int32_t* self, char* msg)
{
    {

#line 59 "/usr/local/share/zenc/std/option.zc"
if ((!self->is_some))     {

#line 60 "/usr/local/share/zenc/std/option.zc"
    ({ fprintf(stderr, "%s", "Panic: "); fprintf(stderr, "%s", msg); fprintf(stderr, "\n"); 0; });

#line 61 "/usr/local/share/zenc/std/option.zc"
exit(1);
    }

#line 63 "/usr/local/share/zenc/std/option.zc"
    return self->val;
    }
}

#line 66 "/usr/local/share/zenc/std/option.zc"

Option__int32_t Option__int32_t__or_else(Option__int32_t* self, Option__int32_t other)
{
    {

#line 67 "/usr/local/share/zenc/std/option.zc"
if (self->is_some)     {

#line 67 "/usr/local/share/zenc/std/option.zc"
    return *self;
    }

#line 68 "/usr/local/share/zenc/std/option.zc"
    return other;
    }
}

#line 73 "/usr/local/share/zenc/std/vec.zc"

Vec__char Vec__char__new(void)
{
    {

#line 74 "/usr/local/share/zenc/std/vec.zc"
    return (Vec__char){.data = NULL};
    }
}

#line 77 "/usr/local/share/zenc/std/vec.zc"

Vec__char Vec__char__with_capacity(size_t cap)
{
    {

#line 78 "/usr/local/share/zenc/std/vec.zc"
if ((cap == 0))     {

#line 79 "/usr/local/share/zenc/std/vec.zc"
    return (Vec__char){.data = NULL};
    }

#line 81 "/usr/local/share/zenc/std/vec.zc"
    return (Vec__char){.data = ((char*)(
#line 82 "/usr/local/share/zenc/std/vec.zc"
malloc((cap * sizeof(char))))), .cap = cap};
    }
}

#line 88 "/usr/local/share/zenc/std/vec.zc"

void Vec__char__grow(Vec__char* self)
{
    {

#line 89 "/usr/local/share/zenc/std/vec.zc"
if ((self->cap == 0))     {

#line 89 "/usr/local/share/zenc/std/vec.zc"
(self->cap = 8);
    }
 else     {

#line 90 "/usr/local/share/zenc/std/vec.zc"
(self->cap = (self->cap * 2));
    }

#line 91 "/usr/local/share/zenc/std/vec.zc"
(self->data = ((char*)(
#line 91 "/usr/local/share/zenc/std/vec.zc"
realloc(self->data, (self->cap * sizeof(char))))));
    }
}

#line 94 "/usr/local/share/zenc/std/vec.zc"

void Vec__char__grow_to_fit(Vec__char* self, size_t new_len)
{
    {

#line 95 "/usr/local/share/zenc/std/vec.zc"
if ((self->cap >= new_len))     {

#line 96 "/usr/local/share/zenc/std/vec.zc"
    return ;
    }

#line 99 "/usr/local/share/zenc/std/vec.zc"
if ((self->cap == 0))     {

#line 99 "/usr/local/share/zenc/std/vec.zc"
(self->cap = 8);
    }

#line 100 "/usr/local/share/zenc/std/vec.zc"
while ((self->cap < new_len))     {

#line 101 "/usr/local/share/zenc/std/vec.zc"
(self->cap = (self->cap * 2));
    }

#line 104 "/usr/local/share/zenc/std/vec.zc"
(self->data = ((char*)(
#line 104 "/usr/local/share/zenc/std/vec.zc"
realloc(self->data, (self->cap * sizeof(char))))));
    }
}

#line 107 "/usr/local/share/zenc/std/vec.zc"

VecIter__char Vec__char__iterator(Vec__char* self)
{
    {

#line 108 "/usr/local/share/zenc/std/vec.zc"
    return (VecIter__char){.data = self->data, .count = self->len};
    }
}

#line 115 "/usr/local/share/zenc/std/vec.zc"

VecIterRef__char Vec__char__iter_ref(Vec__char* self)
{
    {

#line 116 "/usr/local/share/zenc/std/vec.zc"
    return (VecIterRef__char){.data = self->data, .count = self->len};
    }
}

#line 123 "/usr/local/share/zenc/std/vec.zc"

void Vec__char__push(Vec__char* self, char item)
{
    {

#line 124 "/usr/local/share/zenc/std/vec.zc"
if ((self->len >= self->cap))     {

#line 125 "/usr/local/share/zenc/std/vec.zc"
Vec__char__grow(self);
    }

#line 127 "/usr/local/share/zenc/std/vec.zc"
(self->data[self->len] = item);

#line 128 "/usr/local/share/zenc/std/vec.zc"
(self->len = (self->len + 1));
    }
}

#line 131 "/usr/local/share/zenc/std/vec.zc"

void Vec__char__insert(Vec__char* self, size_t idx, char item)
{
    {

#line 132 "/usr/local/share/zenc/std/vec.zc"
if ((idx > self->len))     {

#line 133 "/usr/local/share/zenc/std/vec.zc"
    ({ fprintf(stderr, "%s", "Panic: Insert index out of bounds"); fprintf(stderr, "\n"); 0; });

#line 134 "/usr/local/share/zenc/std/vec.zc"
exit(1);
    }

#line 136 "/usr/local/share/zenc/std/vec.zc"
if ((self->len >= self->cap))     {

#line 137 "/usr/local/share/zenc/std/vec.zc"
Vec__char__grow(self);
    }

#line 140 "/usr/local/share/zenc/std/vec.zc"
if ((idx < self->len))     {

#line 141 "/usr/local/share/zenc/std/vec.zc"
memmove(((self->data + idx) + 1), (self->data + idx), ((self->len - idx) * sizeof(char)));
    }

#line 143 "/usr/local/share/zenc/std/vec.zc"
(self->data[idx] = item);

#line 144 "/usr/local/share/zenc/std/vec.zc"
(self->len = (self->len + 1));
    }
}

#line 147 "/usr/local/share/zenc/std/vec.zc"

char Vec__char__pop(Vec__char* self)
{
    {

#line 148 "/usr/local/share/zenc/std/vec.zc"
if ((self->len == 0))     {

#line 149 "/usr/local/share/zenc/std/vec.zc"
    ({ fprintf(stderr, "%s", "Panic: pop called on empty Vec"); fprintf(stderr, "\n"); 0; });

#line 150 "/usr/local/share/zenc/std/vec.zc"
exit(1);
    }

#line 152 "/usr/local/share/zenc/std/vec.zc"
(self->len = (self->len - 1));

#line 153 "/usr/local/share/zenc/std/vec.zc"
    return self->data[self->len];
    }
}

#line 156 "/usr/local/share/zenc/std/vec.zc"

Option__char Vec__char__pop_opt(Vec__char* self)
{
    {

#line 157 "/usr/local/share/zenc/std/vec.zc"
if ((self->len == 0))     {

#line 158 "/usr/local/share/zenc/std/vec.zc"
    return 
#line 158 "/usr/local/share/zenc/std/vec.zc"
Option__char__None();
    }

#line 160 "/usr/local/share/zenc/std/vec.zc"
(self->len = (self->len - 1));

#line 161 "/usr/local/share/zenc/std/vec.zc"
    return 
#line 161 "/usr/local/share/zenc/std/vec.zc"
Option__char__Some(self->data[self->len]);
    }
}

#line 164 "/usr/local/share/zenc/std/vec.zc"

char Vec__char__remove(Vec__char* self, size_t idx)
{
    {

#line 165 "/usr/local/share/zenc/std/vec.zc"
if ((idx >= self->len))     {

#line 166 "/usr/local/share/zenc/std/vec.zc"
    ({ fprintf(stderr, "%s", "Panic: Remove index out of bounds"); fprintf(stderr, "\n"); 0; });

#line 167 "/usr/local/share/zenc/std/vec.zc"
exit(1);
    }

#line 169 "/usr/local/share/zenc/std/vec.zc"
    char item = self->data[idx];

#line 171 "/usr/local/share/zenc/std/vec.zc"
if ((idx < (self->len - 1)))     {

#line 172 "/usr/local/share/zenc/std/vec.zc"
memmove((self->data + idx), ((self->data + idx) + 1), (((self->len - idx) - 1) * sizeof(char)));
    }

#line 174 "/usr/local/share/zenc/std/vec.zc"
(self->len = (self->len - 1));

#line 175 "/usr/local/share/zenc/std/vec.zc"
    return item;
    }
}

#line 180 "/usr/local/share/zenc/std/vec.zc"

void Vec__char__append(Vec__char* self, Vec__char other)
{

#line 180 "/usr/local/share/zenc/std/vec.zc"
    int __z_drop_flag_other = 1;
    {

#line 181 "/usr/local/share/zenc/std/vec.zc"
    size_t new_len = (self->len + other.len);

#line 182 "/usr/local/share/zenc/std/vec.zc"
Vec__char__grow_to_fit(self, new_len);

#line 184 "/usr/local/share/zenc/std/vec.zc"
memcpy((self->data + self->len), other.data, (other.len * sizeof(char)));

#line 185 "/usr/local/share/zenc/std/vec.zc"
(self->len = new_len);

#line 186 "/usr/local/share/zenc/std/vec.zc"
Vec__char__forget(&other);
    }

#line 180 "/usr/local/share/zenc/std/vec.zc"
    if (__z_drop_flag_other) Vec__char__Drop__glue(&other);
}

#line 189 "/usr/local/share/zenc/std/vec.zc"

char Vec__char__get(Vec__char* self, size_t idx)
{
    {

#line 190 "/usr/local/share/zenc/std/vec.zc"
if ((idx >= self->len))     {

#line 191 "/usr/local/share/zenc/std/vec.zc"
    ({ fprintf(stderr, "%s", "Panic: Index out of bounds"); fprintf(stderr, "\n"); 0; });

#line 192 "/usr/local/share/zenc/std/vec.zc"
exit(1);
    }

#line 194 "/usr/local/share/zenc/std/vec.zc"
    return self->data[idx];
    }
}

#line 197 "/usr/local/share/zenc/std/vec.zc"

char Vec__char__index(Vec__char* self, size_t idx)
{
    {

#line 198 "/usr/local/share/zenc/std/vec.zc"
    return 
#line 198 "/usr/local/share/zenc/std/vec.zc"
Vec__char__get(self, idx);
    }
}

#line 201 "/usr/local/share/zenc/std/vec.zc"

char* Vec__char__get_ref(Vec__char* self, size_t idx)
{
    {

#line 202 "/usr/local/share/zenc/std/vec.zc"
if ((idx >= self->len))     {

#line 203 "/usr/local/share/zenc/std/vec.zc"
    ({ fprintf(stderr, "%s", "Panic: Index out of bounds"); fprintf(stderr, "\n"); 0; });

#line 204 "/usr/local/share/zenc/std/vec.zc"
exit(1);
    }

#line 206 "/usr/local/share/zenc/std/vec.zc"
    return (&self->data[idx]);
    }
}

#line 209 "/usr/local/share/zenc/std/vec.zc"

char Vec__char__last(Vec__char* self)
{
    {

#line 210 "/usr/local/share/zenc/std/vec.zc"
if ((self->len == 0))     {

#line 211 "/usr/local/share/zenc/std/vec.zc"
    ({ fprintf(stderr, "%s", "Panic: last called on empty Vec"); fprintf(stderr, "\n"); 0; });

#line 212 "/usr/local/share/zenc/std/vec.zc"
exit(1);
    }

#line 214 "/usr/local/share/zenc/std/vec.zc"
    return self->data[(self->len - 1)];
    }
}

#line 217 "/usr/local/share/zenc/std/vec.zc"

size_t Vec__char__length(Vec__char* self)
{
    {

#line 218 "/usr/local/share/zenc/std/vec.zc"
    return self->len;
    }
}

#line 221 "/usr/local/share/zenc/std/vec.zc"

bool Vec__char__contains(Vec__char* self, char item)
{
    {

#line 222 "/usr/local/share/zenc/std/vec.zc"
    size_t i = 0;

#line 223 "/usr/local/share/zenc/std/vec.zc"
while ((i < self->len))     {

#line 224 "/usr/local/share/zenc/std/vec.zc"
if ((
#line 224 "/usr/local/share/zenc/std/vec.zc"
memcmp((&self->data[i]), (&item), sizeof(char)) == 0))     {

#line 224 "/usr/local/share/zenc/std/vec.zc"
    return true;
    }
(i++);
    }

#line 227 "/usr/local/share/zenc/std/vec.zc"
    return false;
    }
}

#line 230 "/usr/local/share/zenc/std/vec.zc"

bool Vec__char__is_empty(Vec__char* self)
{
    {

#line 231 "/usr/local/share/zenc/std/vec.zc"
    return (self->len == 0);
    }
}

#line 234 "/usr/local/share/zenc/std/vec.zc"

void Vec__char__clear(Vec__char* self)
{
    {

#line 235 "/usr/local/share/zenc/std/vec.zc"
(self->len = 0);
    }
}

#line 238 "/usr/local/share/zenc/std/vec.zc"

void Vec__char__free(Vec__char* self)
{
    {

#line 239 "/usr/local/share/zenc/std/vec.zc"
if (self->data)     {

#line 239 "/usr/local/share/zenc/std/vec.zc"
free(self->data);
    }

#line 240 "/usr/local/share/zenc/std/vec.zc"
(self->data = NULL);

#line 241 "/usr/local/share/zenc/std/vec.zc"
(self->len = 0);

#line 242 "/usr/local/share/zenc/std/vec.zc"
(self->cap = 0);
    }
}

#line 245 "/usr/local/share/zenc/std/vec.zc"

char Vec__char__first(Vec__char* self)
{
    {

#line 246 "/usr/local/share/zenc/std/vec.zc"
if ((self->len == 0))     {

#line 247 "/usr/local/share/zenc/std/vec.zc"
    ({ fprintf(stderr, "%s", "Panic: first called on empty Vec"); fprintf(stderr, "\n"); 0; });

#line 248 "/usr/local/share/zenc/std/vec.zc"
exit(1);
    }

#line 250 "/usr/local/share/zenc/std/vec.zc"
    return self->data[0];
    }
}

#line 253 "/usr/local/share/zenc/std/vec.zc"

void Vec__char__set(Vec__char* self, size_t idx, char item)
{
    {

#line 254 "/usr/local/share/zenc/std/vec.zc"
if ((idx >= self->len))     {

#line 255 "/usr/local/share/zenc/std/vec.zc"
    ({ fprintf(stderr, "%s", "Panic: set index out of bounds"); fprintf(stderr, "\n"); 0; });

#line 256 "/usr/local/share/zenc/std/vec.zc"
exit(1);
    }

#line 258 "/usr/local/share/zenc/std/vec.zc"
(self->data[idx] = item);
    }
}

#line 261 "/usr/local/share/zenc/std/vec.zc"

void Vec__char__reverse(Vec__char* self)
{
    {

#line 262 "/usr/local/share/zenc/std/vec.zc"
    size_t i = 0;

#line 263 "/usr/local/share/zenc/std/vec.zc"
    size_t j = (self->len - 1);

#line 264 "/usr/local/share/zenc/std/vec.zc"
while ((i < j))     {

#line 265 "/usr/local/share/zenc/std/vec.zc"
    char tmp = self->data[i];

#line 266 "/usr/local/share/zenc/std/vec.zc"
(self->data[i] = self->data[j]);

#line 267 "/usr/local/share/zenc/std/vec.zc"
(self->data[j] = tmp);
(i++);
(j--);
    }
    }
}

#line 275 "/usr/local/share/zenc/std/vec.zc"

bool Vec__char__eq(Vec__char* self, Vec__char* other)
{
    {

#line 276 "/usr/local/share/zenc/std/vec.zc"
if ((self->len != (*other).len))     {

#line 276 "/usr/local/share/zenc/std/vec.zc"
    return false;
    }

#line 277 "/usr/local/share/zenc/std/vec.zc"
    size_t i = 0;

#line 278 "/usr/local/share/zenc/std/vec.zc"
while ((i < self->len))     {

#line 279 "/usr/local/share/zenc/std/vec.zc"
if ((
#line 279 "/usr/local/share/zenc/std/vec.zc"
memcmp((&self->data[i]), (&(*other).data[i]), sizeof(char)) != 0))     {

#line 279 "/usr/local/share/zenc/std/vec.zc"
    return false;
    }

#line 280 "/usr/local/share/zenc/std/vec.zc"
(i = (i + 1));
    }

#line 282 "/usr/local/share/zenc/std/vec.zc"
    return true;
    }
}

#line 286 "/usr/local/share/zenc/std/vec.zc"

void Vec__char__forget(Vec__char* self)
{
    {

#line 287 "/usr/local/share/zenc/std/vec.zc"
(self->data = NULL);

#line 288 "/usr/local/share/zenc/std/vec.zc"
(self->len = 0);

#line 289 "/usr/local/share/zenc/std/vec.zc"
(self->cap = 0);
    }
}

#line 295 "/usr/local/share/zenc/std/vec.zc"

Vec__char Vec__char__add(Vec__char* self, Vec__char* other)
{
    {

#line 296 "/usr/local/share/zenc/std/vec.zc"
    int __z_drop_flag_result = 1; Vec__char result = 
#line 296 "/usr/local/share/zenc/std/vec.zc"
Vec__char__clone(self);

#line 297 "/usr/local/share/zenc/std/vec.zc"
Vec__char__append(&result, Vec__char__clone(other));

#line 298 "/usr/local/share/zenc/std/vec.zc"
    return ({ ZC_AUTO _z_ret_mv = result; memset(&result, 0, sizeof(_z_ret_mv)); __z_drop_flag_result = 0; 
#line 296 "/usr/local/share/zenc/std/vec.zc"
    if (__z_drop_flag_result) Vec__char__Drop__glue(&result);
_z_ret_mv; });

#line 296 "/usr/local/share/zenc/std/vec.zc"
    if (__z_drop_flag_result) Vec__char__Drop__glue(&result);
    }
}

#line 302 "/usr/local/share/zenc/std/vec.zc"

void Vec__char__add_assign(Vec__char* self, Vec__char* other)
{
    {

#line 303 "/usr/local/share/zenc/std/vec.zc"
Vec__char__append(self, Vec__char__clone(other));
    }
}

#line 306 "/usr/local/share/zenc/std/vec.zc"

bool Vec__char__neq(Vec__char* self, Vec__char* other)
{
    {

#line 307 "/usr/local/share/zenc/std/vec.zc"
    return (!
#line 307 "/usr/local/share/zenc/std/vec.zc"
Vec__char__eq(self, other));
    }
}

#line 311 "/usr/local/share/zenc/std/vec.zc"

void Vec__char__shl(Vec__char* self, char item)
{
    {

#line 312 "/usr/local/share/zenc/std/vec.zc"
Vec__char__push(self, item);
    }
}

#line 316 "/usr/local/share/zenc/std/vec.zc"

void Vec__char__shr(Vec__char* self, char* out_item)
{
    {

#line 317 "/usr/local/share/zenc/std/vec.zc"
if ((out_item != NULL))     {

#line 318 "/usr/local/share/zenc/std/vec.zc"
((*out_item) = 
#line 318 "/usr/local/share/zenc/std/vec.zc"
Vec__char__pop(self));
    }
 else     {

#line 320 "/usr/local/share/zenc/std/vec.zc"
Vec__char__pop(self);
    }
    }
}

#line 327 "/usr/local/share/zenc/std/vec.zc"

Vec__char Vec__char__mul(Vec__char* self, size_t count)
{
    {

#line 328 "/usr/local/share/zenc/std/vec.zc"
    int __z_drop_flag_result = 1; Vec__char result = 
#line 328 "/usr/local/share/zenc/std/vec.zc"
Vec__char__with_capacity((self->len * count));

#line 329 "/usr/local/share/zenc/std/vec.zc"
    size_t c = 0;

#line 330 "/usr/local/share/zenc/std/vec.zc"
while ((c < count))     {

#line 331 "/usr/local/share/zenc/std/vec.zc"
Vec__char__append(&result, Vec__char__clone(self));

#line 332 "/usr/local/share/zenc/std/vec.zc"
(c = (c + 1));
    }

#line 334 "/usr/local/share/zenc/std/vec.zc"
    return ({ ZC_AUTO _z_ret_mv = result; memset(&result, 0, sizeof(_z_ret_mv)); __z_drop_flag_result = 0; 
#line 328 "/usr/local/share/zenc/std/vec.zc"
    if (__z_drop_flag_result) Vec__char__Drop__glue(&result);
_z_ret_mv; });

#line 328 "/usr/local/share/zenc/std/vec.zc"
    if (__z_drop_flag_result) Vec__char__Drop__glue(&result);
    }
}

#line 340 "/usr/local/share/zenc/std/vec.zc"

void Vec__char__mul_assign(Vec__char* self, size_t count)
{
    {

#line 341 "/usr/local/share/zenc/std/vec.zc"
if ((count == 0))     {

#line 342 "/usr/local/share/zenc/std/vec.zc"
Vec__char__clear(self);

#line 343 "/usr/local/share/zenc/std/vec.zc"
    return ;
    }

#line 345 "/usr/local/share/zenc/std/vec.zc"
if ((count == 1))     {

#line 346 "/usr/local/share/zenc/std/vec.zc"
    return ;
    }

#line 348 "/usr/local/share/zenc/std/vec.zc"
    size_t original_len = self->len;

#line 349 "/usr/local/share/zenc/std/vec.zc"
Vec__char__grow_to_fit(self, (self->len * count));

#line 350 "/usr/local/share/zenc/std/vec.zc"
    size_t c = 1;

#line 351 "/usr/local/share/zenc/std/vec.zc"
while ((c < count))     {

#line 352 "/usr/local/share/zenc/std/vec.zc"
memcpy((self->data + (original_len * c)), self->data, (original_len * sizeof(char)));

#line 353 "/usr/local/share/zenc/std/vec.zc"
(self->len = (self->len + original_len));

#line 354 "/usr/local/share/zenc/std/vec.zc"
(c = (c + 1));
    }
    }
}

#line 359 "/usr/local/share/zenc/std/vec.zc"

Vec__char Vec__char__clone(Vec__char* self)
{
    {

#line 360 "/usr/local/share/zenc/std/vec.zc"
if ((self->len == 0))     {

#line 361 "/usr/local/share/zenc/std/vec.zc"
    return (Vec__char){.data = NULL};
    }

#line 363 "/usr/local/share/zenc/std/vec.zc"
    char* new_data = ((char*)(
#line 363 "/usr/local/share/zenc/std/vec.zc"
malloc((self->len * sizeof(char)))));

#line 364 "/usr/local/share/zenc/std/vec.zc"
    size_t i = 0;

#line 365 "/usr/local/share/zenc/std/vec.zc"
while ((i < self->len))     {

#line 366 "/usr/local/share/zenc/std/vec.zc"
(new_data[i] = self->data[i]);

#line 367 "/usr/local/share/zenc/std/vec.zc"
(i = (i + 1));
    }

#line 369 "/usr/local/share/zenc/std/vec.zc"
    return (Vec__char){.data = new_data, .len = self->len, .cap = self->len};
    }
}

#line 58 "/usr/local/share/zenc/std/vec.zc"

VecIterResult__char VecIterRef__char__next(VecIterRef__char* self)
{
    {

#line 59 "/usr/local/share/zenc/std/vec.zc"
if ((self->idx < self->count))     {

#line 60 "/usr/local/share/zenc/std/vec.zc"
    char* item = (&self->data[self->idx]);

#line 61 "/usr/local/share/zenc/std/vec.zc"
(self->idx = (self->idx + 1));

#line 62 "/usr/local/share/zenc/std/vec.zc"
    return (VecIterResult__char){.ptr = item};
    }

#line 64 "/usr/local/share/zenc/std/vec.zc"
    return (VecIterResult__char){.ptr = NULL};
    }
}

#line 67 "/usr/local/share/zenc/std/vec.zc"

VecIterRef__char VecIterRef__char__iterator(VecIterRef__char* self)
{
    {

#line 68 "/usr/local/share/zenc/std/vec.zc"
    return *self;
    }
}

#line 23 "/usr/local/share/zenc/std/vec.zc"

bool VecIterResult__char__is_none(VecIterResult__char* self)
{
    {

#line 24 "/usr/local/share/zenc/std/vec.zc"
    return (self->ptr == NULL);
    }
}

#line 27 "/usr/local/share/zenc/std/vec.zc"

char* VecIterResult__char__unwrap(VecIterResult__char* self)
{
    {

#line 28 "/usr/local/share/zenc/std/vec.zc"
if ((self->ptr == NULL))     {

#line 29 "/usr/local/share/zenc/std/vec.zc"
    ({ fprintf(stderr, "%s", "Panic: unwrap called on null VecIterResult"); fprintf(stderr, "\n"); 0; });

#line 30 "/usr/local/share/zenc/std/vec.zc"
exit(1);
    }

#line 32 "/usr/local/share/zenc/std/vec.zc"
    return self->ptr;
    }
}

#line 43 "/usr/local/share/zenc/std/vec.zc"

Option__char VecIter__char__next(VecIter__char* self)
{
    {

#line 44 "/usr/local/share/zenc/std/vec.zc"
if ((self->idx < self->count))     {

#line 45 "/usr/local/share/zenc/std/vec.zc"
    char item = self->data[self->idx];

#line 46 "/usr/local/share/zenc/std/vec.zc"
(self->idx = (self->idx + 1));

#line 47 "/usr/local/share/zenc/std/vec.zc"
    return 
#line 47 "/usr/local/share/zenc/std/vec.zc"
Option__char__Some(item);
    }

#line 49 "/usr/local/share/zenc/std/vec.zc"
    return 
#line 49 "/usr/local/share/zenc/std/vec.zc"
Option__char__None();
    }
}

#line 52 "/usr/local/share/zenc/std/vec.zc"

VecIter__char VecIter__char__iterator(VecIter__char* self)
{
    {

#line 53 "/usr/local/share/zenc/std/vec.zc"
    return *self;
    }
}

#line 10 "/usr/local/share/zenc/std/option.zc"

Option__char Option__char__Some(char v)
{
    {

#line 11 "/usr/local/share/zenc/std/option.zc"
    return (Option__char){.is_some = true, .val = v};
    }
}

#line 14 "/usr/local/share/zenc/std/option.zc"

Option__char Option__char__None(void)
{
    {

#line 15 "/usr/local/share/zenc/std/option.zc"
    Option__char opt = {0};

#line 16 "/usr/local/share/zenc/std/option.zc"
(opt.is_some = false);

#line 17 "/usr/local/share/zenc/std/option.zc"
memset((&opt.val), 0, sizeof(char));

#line 18 "/usr/local/share/zenc/std/option.zc"
    return opt;
    }
}

#line 21 "/usr/local/share/zenc/std/option.zc"

bool Option__char__is_some(Option__char* self)
{
    {

#line 22 "/usr/local/share/zenc/std/option.zc"
    return self->is_some;
    }
}

#line 25 "/usr/local/share/zenc/std/option.zc"

bool Option__char__is_none(Option__char* self)
{
    {

#line 26 "/usr/local/share/zenc/std/option.zc"
    return (!self->is_some);
    }
}

#line 29 "/usr/local/share/zenc/std/option.zc"

void Option__char__forget(Option__char* self)
{
    {

#line 30 "/usr/local/share/zenc/std/option.zc"
memset((&self->val), 0, sizeof(char));
    }
}

#line 33 "/usr/local/share/zenc/std/option.zc"

char Option__char__unwrap(Option__char* self)
{
    {

#line 34 "/usr/local/share/zenc/std/option.zc"
if ((!self->is_some))     {

#line 35 "/usr/local/share/zenc/std/option.zc"
    ({ fprintf(stderr, "%s", "Panic: unwrap called on None"); fprintf(stderr, "\n"); 0; });

#line 36 "/usr/local/share/zenc/std/option.zc"
exit(1);
    }

#line 38 "/usr/local/share/zenc/std/option.zc"
    char v = self->val;

#line 39 "/usr/local/share/zenc/std/option.zc"
memset((&self->val), 0, sizeof(char));

#line 40 "/usr/local/share/zenc/std/option.zc"
    return v;
    }
}

#line 43 "/usr/local/share/zenc/std/option.zc"

char* Option__char__unwrap_ref(Option__char* self)
{
    {

#line 44 "/usr/local/share/zenc/std/option.zc"
if ((!self->is_some))     {

#line 45 "/usr/local/share/zenc/std/option.zc"
    ({ fprintf(stderr, "%s", "Panic: unwrap_ref called on None"); fprintf(stderr, "\n"); 0; });

#line 46 "/usr/local/share/zenc/std/option.zc"
exit(1);
    }

#line 48 "/usr/local/share/zenc/std/option.zc"
    return (&self->val);
    }
}

#line 51 "/usr/local/share/zenc/std/option.zc"

char Option__char__unwrap_or(Option__char* self, char def_val)
{
    {

#line 52 "/usr/local/share/zenc/std/option.zc"
if (self->is_some)     {

#line 53 "/usr/local/share/zenc/std/option.zc"
    return self->val;
    }

#line 55 "/usr/local/share/zenc/std/option.zc"
    return def_val;
    }
}

#line 58 "/usr/local/share/zenc/std/option.zc"

char Option__char__expect(Option__char* self, char* msg)
{
    {

#line 59 "/usr/local/share/zenc/std/option.zc"
if ((!self->is_some))     {

#line 60 "/usr/local/share/zenc/std/option.zc"
    ({ fprintf(stderr, "%s", "Panic: "); fprintf(stderr, "%s", msg); fprintf(stderr, "\n"); 0; });

#line 61 "/usr/local/share/zenc/std/option.zc"
exit(1);
    }

#line 63 "/usr/local/share/zenc/std/option.zc"
    return self->val;
    }
}

#line 66 "/usr/local/share/zenc/std/option.zc"

Option__char Option__char__or_else(Option__char* self, Option__char other)
{
    {

#line 67 "/usr/local/share/zenc/std/option.zc"
if (self->is_some)     {

#line 67 "/usr/local/share/zenc/std/option.zc"
    return *self;
    }

#line 68 "/usr/local/share/zenc/std/option.zc"
    return other;
    }
}

#line 378 "/usr/local/share/zenc/std/vec.zc"

void Vec__char__Drop__drop(Vec__char* self)
{
    {

#line 379 "/usr/local/share/zenc/std/vec.zc"
Vec__char__free(self);
    }
}

#line 95 "src/004-breakout/src/main_window.zc"

int32_t main(void)
{
    {

#line 96 "src/004-breakout/src/main_window.zc"
io.println
#line 96 "src/004-breakout/src/main_window.zc"
    ({ fprintf(stdout, "%s", "========================================"); fprintf(stdout, "\n"); 0; });

#line 97 "src/004-breakout/src/main_window.zc"
io.println
#line 97 "src/004-breakout/src/main_window.zc"
    ({ fprintf(stdout, "%s", "Zen-C Breakout 打砖块游戏"); fprintf(stdout, "\n"); 0; });

#line 98 "src/004-breakout/src/main_window.zc"
io.println
#line 98 "src/004-breakout/src/main_window.zc"
    ({ fprintf(stdout, "%s", "========================================"); fprintf(stdout, "\n"); 0; });

#line 101 "src/004-breakout/src/main_window.zc"
init_game((&game));

#line 104 "src/004-breakout/src/main_window.zc"
    string title = "Breakout - 打砖块游戏";

#line 105 "src/004-breakout/src/main_window.zc"
(window = 
#line 105 "src/004-breakout/src/main_window.zc"
create_window(title, 800, 600));

#line 107 "src/004-breakout/src/main_window.zc"
if ((window == null))     {

#line 108 "src/004-breakout/src/main_window.zc"
io.println
#line 108 "src/004-breakout/src/main_window.zc"
    ({ fprintf(stdout, "%s", "错误: 无法创建窗口"); fprintf(stdout, "\n"); 0; });

#line 109 "src/004-breakout/src/main_window.zc"
    return 1;
    }

#line 113 "src/004-breakout/src/main_window.zc"
    int32_t cw = 0;

#line 114 "src/004-breakout/src/main_window.zc"
    int32_t ch = 0;

#line 115 "src/004-breakout/src/main_window.zc"
get_window_client_size(window, (&cw), (&ch));

#line 116 "src/004-breakout/src/main_window.zc"
if (((cw > 0) && (ch > 0)))     {

#line 117 "src/004-breakout/src/main_window.zc"
(game.width = cw);

#line 118 "src/004-breakout/src/main_window.zc"
(game.height = ch);

#line 119 "src/004-breakout/src/main_window.zc"
set_client_size(cw, ch);
    }

#line 123 "src/004-breakout/src/main_window.zc"
set_key_handler(on_key);

#line 124 "src/004-breakout/src/main_window.zc"
set_timer_handler(on_timer);

#line 125 "src/004-breakout/src/main_window.zc"
set_paint_handler(on_paint);

#line 126 "src/004-breakout/src/main_window.zc"
set_mouse_handler(on_mouse);

#line 127 "src/004-breakout/src/main_window.zc"
set_destroy_handler(on_destroy);

#line 130 "src/004-breakout/src/main_window.zc"
show_window(window);

#line 133 "src/004-breakout/src/main_window.zc"
set_game_timer(window, game_speed);

#line 135 "src/004-breakout/src/main_window.zc"
io.println
#line 135 "src/004-breakout/src/main_window.zc"
    ({ fprintf(stdout, "%s", "窗口创建成功!"); fprintf(stdout, "\n"); 0; });

#line 136 "src/004-breakout/src/main_window.zc"
io.println
#line 136 "src/004-breakout/src/main_window.zc"
    ({ fprintf(stdout, "%s", "按空格键开始游戏"); fprintf(stdout, "\n"); 0; });

#line 137 "src/004-breakout/src/main_window.zc"
io.println
#line 137 "src/004-breakout/src/main_window.zc"
    ({ fprintf(stdout, "%s", "使用 ← → 方向键控制挡板"); fprintf(stdout, "\n"); 0; });

#line 138 "src/004-breakout/src/main_window.zc"
io.println
#line 138 "src/004-breakout/src/main_window.zc"
    ({ fprintf(stdout, "%s", "========================================"); fprintf(stdout, "\n"); 0; });

#line 141 "src/004-breakout/src/main_window.zc"
redraw_window(window);

#line 144 "src/004-breakout/src/main_window.zc"
run_event_loop(window);

#line 146 "src/004-breakout/src/main_window.zc"
io.println
#line 146 "src/004-breakout/src/main_window.zc"
    ({ fprintf(stdout, "%s", "游戏结束!"); fprintf(stdout, "\n"); 0; });

#line 147 "src/004-breakout/src/main_window.zc"
io.println(({ 
#line 147 "src/004-breakout/src/main_window.zc"
    static char _b[4096]; _b[0]=0;
    char _t[128];
    strcat(_b, "最终得分: ");

#line 147 "src/004-breakout/src/main_window.zc"
sprintf(_t, _z_str(game), game);

#line 147 "src/004-breakout/src/main_window.zc"
    strcat(_b, _t);
    _b;
 }).score.toString());

#line 148 "src/004-breakout/src/main_window.zc"
io.println
#line 148 "src/004-breakout/src/main_window.zc"
    ({ fprintf(stdout, "%s", "========================================"); fprintf(stdout, "\n"); 0; });

#line 150 "src/004-breakout/src/main_window.zc"
0;
    }
}

#line 89 "src/004-breakout/src/main_window.zc"

void on_destroy(void)
{
    {

#line 90 "src/004-breakout/src/main_window.zc"
fb_shutdown();
    }
}

#line 78 "src/004-breakout/src/main_window.zc"

void on_mouse(int32_t x, int32_t y)
{
    {

#line 80 "src/004-breakout/src/main_window.zc"
if ((game.status == GameStatus__Ready))     {

#line 81 "src/004-breakout/src/main_window.zc"
(game.status = GameStatus__Playing);

#line 82 "src/004-breakout/src/main_window.zc"
    int32_t angle = ((
#line 82 "src/004-breakout/src/main_window.zc"
math.rand() % 50) - 25);

#line 82 "src/004-breakout/src/main_window.zc"
as;
i32;

#line 83 "src/004-breakout/src/main_window.zc"
    float rad = (((float)(((angle)((*3.1415899999999999))))) / 180.0);

#line 84 "src/004-breakout/src/main_window.zc"
(game.ball.vx = ((float)(((BALL_SPEED)((*
#line 84 "src/004-breakout/src/main_window.zc"
math.sin(rad)))))));

#line 84 "src/004-breakout/src/main_window.zc"
as;
i32;

#line 85 "src/004-breakout/src/main_window.zc"
(game.ball.vy = (-5));
    }
    }
}

#line 29 "src/004-breakout/src/main_window.zc"

void on_paint(int32_t w, int32_t h)
{
    {

#line 31 "src/004-breakout/src/main_window.zc"
if ((!fb_data.valid))     {

#line 32 "src/004-breakout/src/main_window.zc"
fb_init(window, w, h);
    }

#line 36 "src/004-breakout/src/main_window.zc"
fb_clear(rgb(0, 0, 0));

#line 39 "src/004-breakout/src/main_window.zc"
for (ZC_AUTO i = 0; i < (5 * 10); i++)     {

#line 40 "src/004-breakout/src/main_window.zc"
    int32_t brick = game.bricks.bricks[i];

#line 41 "src/004-breakout/src/main_window.zc"
if (brick.alive)     {

#line 42 "src/004-breakout/src/main_window.zc"
fb_draw_rect(brick.x, brick.y, brick.width, brick.height, brick.color);
    }
    }

#line 47 "src/004-breakout/src/main_window.zc"
fb_draw_rect(game.paddle.x, game.paddle.y, game.paddle.width, game.paddle.height, 
#line 52 "src/004-breakout/src/main_window.zc"
rgb(255, 255, 255));

#line 56 "src/004-breakout/src/main_window.zc"
fb_draw_circle(game.ball.x, game.ball.y, game.ball.radius, 
#line 60 "src/004-breakout/src/main_window.zc"
rgb(255, 255, 255));

#line 64 "src/004-breakout/src/main_window.zc"
    string info = ({ 
#line 64 "src/004-breakout/src/main_window.zc"
    static char _b[4096]; _b[0]=0;
    char _t[128];
    strcat(_b, "分数: ");

#line 64 "src/004-breakout/src/main_window.zc"
sprintf(_t, _z_str(game.score), game.score);

#line 64 "src/004-breakout/src/main_window.zc"
    strcat(_b, _t);
    strcat(_b, " 生命: ");

#line 64 "src/004-breakout/src/main_window.zc"
sprintf(_t, _z_str(game.lives), game.lives);

#line 64 "src/004-breakout/src/main_window.zc"
    strcat(_b, _t);
    _b;
 });

#line 65 "src/004-breakout/src/main_window.zc"
fb_draw_text_size(10, 10, info, rgb(255, 255, 255), 18);

#line 68 "src/004-breakout/src/main_window.zc"
    string status = 
#line 68 "src/004-breakout/src/main_window.zc"
get_status_text((&game));

#line 69 "src/004-breakout/src/main_window.zc"
fb_draw_text_size(250, 280, status, rgb(255, 255, 0), 24);

#line 72 "src/004-breakout/src/main_window.zc"
fb_draw_text_size(10, (600 - 30), get_controls_text(), rgb(180, 180, 180), 14);

#line 75 "src/004-breakout/src/main_window.zc"
fb_present();
    }
}

#line 22 "src/004-breakout/src/main_window.zc"

bool on_timer(void)
{
    {

#line 23 "src/004-breakout/src/main_window.zc"
if ((game.status == GameStatus__Playing))     {

#line 24 "src/004-breakout/src/main_window.zc"
    return 
#line 24 "src/004-breakout/src/main_window.zc"
update_game((&game));
    }

#line 26 "src/004-breakout/src/main_window.zc"
    return false;
    }
}

#line 18 "src/004-breakout/src/main_window.zc"

bool on_key(KeyCode key)
{
    {

#line 19 "src/004-breakout/src/main_window.zc"
    return 
#line 19 "src/004-breakout/src/main_window.zc"
handle_input((&game), key);
    }
}

#line 326 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"

int32_t abs(int32_t n)
{
    {

#line 327 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
if ((n < 0))     {
(-n);
    }
 else     {

#line 327 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
n;
    }
    }
}

#line 321 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"

string get_controls_text(void)
{
    {

#line 322 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
    ({ fprintf(stdout, "%s", "控制: ← → 移动挡板 | 空格 开始 | ESC 退出"); fprintf(stdout, "\n"); 0; });
    }
}

#line 311 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"

string get_status_text(BreakoutState* game)
{
    {

#line 312 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
{ GameStatus _m_0 = game->status; 
#line 313 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
if (_m_0.tag == 0) {     return "按空格键开始游戏";
 } else 
#line 314 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
if (_m_0.tag == 1) {     return "游戏中...";
 } else 
#line 315 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
if (_m_0.tag == 2) {     return "游戏结束! 按 R 重新开始";
 } else 
#line 316 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
if (_m_0.tag == 3) {     return "恭喜通关! 按 R 重新开始";
 } };
    }
}

#line 306 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"

int32_t get_score(BreakoutState* game)
{
    {

#line 307 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
game->score    }
}

#line 188 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"

bool update_game(BreakoutState* game)
{
    {

#line 189 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
if ((!GameStatus__Eq__eq(&game->status, &GameStatus__Playing)))     {

#line 190 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
    return false;
    }

#line 194 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
(game->ball.x = (game->ball.x + game->ball.vx));

#line 195 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
(game->ball.y = (game->ball.y + game->ball.vy));

#line 198 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
if (((game->ball.x - game->ball.radius) <= 0))     {

#line 199 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
(game->ball.x = game->ball.radius);

#line 200 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
(game->ball.vx = (-game->ball.vx));
    }

#line 202 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
if (((game->ball.x + game->ball.radius) >= 800))     {

#line 203 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
(game->ball.x = (800 - game->ball.radius));

#line 204 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
(game->ball.vx = (-game->ball.vx));
    }

#line 207 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
if (((game->ball.y - game->ball.radius) <= 0))     {

#line 208 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
(game->ball.y = game->ball.radius);

#line 209 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
(game->ball.vy = (-game->ball.vy));
    }

#line 213 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
if (((game->ball.y + game->ball.radius) >= 600))     {

#line 214 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
(game->lives = (game->lives - 1));

#line 215 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
if ((game->lives <= 0))     {

#line 216 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
(game->status = GameStatus__Lost);
    }
 else     {

#line 218 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
reset_ball(game);

#line 219 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
(game->status = GameStatus__Ready);
    }

#line 221 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
    return true;
    }

#line 225 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
if ((game->ball.vy > 0))     {

#line 226 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
    int32_t ball_left = (game->ball.x - game->ball.radius);

#line 227 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
    int32_t ball_right = (game->ball.x + game->ball.radius);

#line 228 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
    int32_t ball_bottom = (game->ball.y + game->ball.radius);

#line 230 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
    int32_t paddle_left = game->paddle.x;

#line 231 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
    int32_t paddle_right = (game->paddle.x + game->paddle.width);

#line 232 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
    int32_t paddle_top = game->paddle.y;

#line 234 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
if (((((ball_right >= paddle_left) && (ball_left <= paddle_right)) && (ball_bottom >= paddle_top)) && (ball_bottom <= ((paddle_top + game->paddle.height) + 
#line 235 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
abs(game->ball.vy)))))     {

#line 236 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
(game->ball.y = (paddle_top - game->ball.radius));

#line 239 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
    int32_t hit_pos = (game->ball.x - game->paddle.x);

#line 239 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
as;

#line 239 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
(f32 / ((float)(game->paddle.width)));

#line 240 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
    int32_t angle = (((hit_pos - 0.5) * 2.0) * 60.0);

#line 241 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
    int32_t rad = ((angle * 3.1415899999999999) / 180.0);

#line 242 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
    ZC_AUTO speed = 
#line 242 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
math.sqrt(((game->ball.vx * game->ball.vx) + (game->ball.vy * game->ball.vy)));

#line 243 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
if ((speed < 5))     {

#line 244 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
(speed = 5);
    }

#line 247 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
(game->ball.vx = ((float)(((speed)((*
#line 247 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
Math__sin(rad)))))));

#line 248 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
(game->ball.vy = (-((float)(((speed)((*
#line 248 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
Math__cos(rad))))))));

#line 250 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
if ((game->ball.vy > (-3)))     {

#line 251 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
(game->ball.vy = (-3));
    }
    }
    }

#line 257 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
    int32_t bricks_remaining = 0;

#line 258 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
for (ZC_AUTO i = 0; i < (5 * 10); i++)     {

#line 259 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
if (game->bricks.bricks[_z_check_bounds(i, 50)].alive)     {

#line 260 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
(bricks_remaining = (bricks_remaining + 1));

#line 262 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
    Brick brick = game->bricks.bricks[_z_check_bounds(i, 50)];

#line 263 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
    int32_t ball_left = (game->ball.x - game->ball.radius);

#line 264 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
    int32_t ball_right = (game->ball.x + game->ball.radius);

#line 265 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
    int32_t ball_top = (game->ball.y - game->ball.radius);

#line 266 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
    int32_t ball_bottom = (game->ball.y + game->ball.radius);

#line 268 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
    int32_t brick_right = (brick.x + brick.width);

#line 269 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
    int32_t brick_bottom = (brick.y + brick.height);

#line 271 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
if (((((ball_right >= brick.x) && (ball_left <= brick_right)) && (ball_bottom >= brick.y)) && (ball_top <= brick_bottom)))     {

#line 273 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
(game->bricks.bricks[_z_check_bounds(i, 50)].alive = false);

#line 274 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
(game->score = (game->score + 10));

#line 275 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
(bricks_remaining = (bricks_remaining - 1));

#line 277 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
    int32_t overlap_left = (ball_right - brick.x);

#line 278 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
    int32_t overlap_right = (brick_right - ball_left);

#line 279 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
    int32_t overlap_top = (ball_bottom - brick.y);

#line 280 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
    int32_t overlap_bottom = (brick_bottom - ball_top);

#line 282 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
    ZC_AUTO min_overlap_x = ({ __typeof__(overlap_left) _ifval; if ((overlap_left < overlap_right)) { _ifval = overlap_left; } else { _ifval = overlap_right; } _ifval; });

#line 283 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
    ZC_AUTO min_overlap_y = ({ __typeof__(overlap_top) _ifval; if ((overlap_top < overlap_bottom)) { _ifval = overlap_top; } else { _ifval = overlap_bottom; } _ifval; });

#line 285 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
if ((min_overlap_x < min_overlap_y))     {

#line 286 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
(game->ball.vx = (-game->ball.vx));
    }
 else     {

#line 288 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
(game->ball.vy = (-game->ball.vy));
    }

#line 291 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
break;
    }
    }
    }

#line 297 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
if ((bricks_remaining == 0))     {

#line 298 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
(game->status = GameStatus__Won);

#line 299 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
    return true;
    }

#line 302 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
    return true;
    }
}

#line 147 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"

bool handle_input(BreakoutState* game, KeyCode key)
{
    {

#line 148 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
{ KeyCode _m_1 = key; 
#line 149 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
if (_m_1.tag == 3) {     {

#line 150 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
(game->paddle.x = (game->paddle.x - game->paddle.speed));

#line 151 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
if ((game->paddle.x < 0))     {

#line 152 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
(game->paddle.x = 0);
    }
    }
 } else 
#line 155 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
if (_m_1.tag == 4) {     {

#line 156 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
(game->paddle.x = (game->paddle.x + game->paddle.speed));

#line 157 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
if ((game->paddle.x > (800 - game->paddle.width)))     {

#line 158 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
(game->paddle.x = (800 - game->paddle.width));
    }
    }
 } else 
#line 161 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
if (_m_1.tag == 5) {     {

#line 162 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
if (((GameStatus__Eq__eq(&game->status, &GameStatus__Ready) || GameStatus__Eq__eq(&game->status, &GameStatus__Lost)) || GameStatus__Eq__eq(&game->status, &GameStatus__Won)))     {

#line 165 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
(game->status = GameStatus__Playing);

#line 166 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
reset_ball(game);

#line 168 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
    int32_t angle = ((
#line 168 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
Random__new().next_int_range(0, 100) % 50) - 25);

#line 169 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
    float rad = (((float)(((angle)((*3.1415899999999999))))) / 180.0);

#line 170 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
(game->ball.vx = ((float)(((BALL_SPEED)((*
#line 170 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
Math__sin(rad)))))));

#line 171 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
(game->ball.vy = (-5));
    }
    }
 } else 
#line 174 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
if (_m_1.tag == 7) {     {

#line 175 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
if ((GameStatus__Eq__eq(&game->status, &GameStatus__Lost) || GameStatus__Eq__eq(&game->status, &GameStatus__Won)))     {

#line 176 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
init_game(game);
    }
    }
 } else 
#line 179 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
if (_m_1.tag == 6) {     {

#line 180 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
    return false;
    }
 } else 
#line 182 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
if (1) {     {
    }
 } };

#line 184 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
    return true;
    }
}

#line 124 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"

void init_bricks(BreakoutState* game)
{
    {

#line 125 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
(game->bricks.rows = 5);

#line 126 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
(game->bricks.cols = 10);

#line 128 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
for (ZC_AUTO row = 0; row < 5; row++)     {

#line 129 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
for (ZC_AUTO col = 0; col < 10; col++)     {

#line 130 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
    int32_t index = ((row * 10) + col);

#line 131 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
    int32_t brick_x = (30 + (col * (70 + 5)));

#line 132 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
    int32_t brick_y = (60 + (row * (25 + 5)));

#line 134 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
(game->bricks.bricks[_z_check_bounds(index, 50)] = (struct Brick){.x = brick_x, .y = brick_y, .width = 70, .height = 25, .alive = true, .color = BRICK_COLORS[_z_check_bounds(row, 5)]});
    }
    }
    }
}

#line 115 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"

void reset_ball(BreakoutState* game)
{
    {

#line 116 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
(game->ball.x = (800 / 2));

#line 117 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
(game->ball.y = ((600 / 2) + 100));

#line 118 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
(game->ball.vx = 5);

#line 119 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
(game->ball.vy = (-5));

#line 120 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
(game->ball.radius = 8);
    }
}

#line 91 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"

void init_game(BreakoutState* game)
{
    {

#line 92 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
(game->width = 800);

#line 93 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
(game->height = 600);

#line 94 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
(game->score = 0);

#line 95 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
(game->lives = 3);

#line 96 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
(game->status = GameStatus__Ready);

#line 99 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
(game->paddle = (struct Paddle){.x = ((800 - 100) / 2), .y = 560, .width = 100, .height = 15, .speed = 8});

#line 108 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
reset_ball(game);

#line 111 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/game_logic.zc"
init_bricks(game);
    }
}

#line 536 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"

KeyCode map_vkey(int32_t vk)
{
    {

#line 537 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
{ int32_t _m_2 = vk; 
#line 538 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
if (_m_2 == 0x25) { KeyCode.KeyLeft } else 
#line 539 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
if (_m_2 == 0x26) { KeyCode.KeyUp } else 
#line 540 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
if (_m_2 == 0x27) { KeyCode.KeyRight } else 
#line 541 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
if (_m_2 == 0x28) { KeyCode.KeyDown } else 
#line 542 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
if (_m_2 == 0x20) { KeyCode.KeySpace } else 
#line 543 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
if (_m_2 == 0x1B) { KeyCode.KeyEscape } else 
#line 544 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
if (_m_2 == 0x52) { KeyCode.KeyR } else 
#line 545 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
if (_m_2 == 0x57) { KeyCode.KeyW } else 
#line 546 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
if (_m_2 == 0x41) { KeyCode.KeyA } else 
#line 547 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
if (_m_2 == 0x53) { KeyCode.KeyS } else 
#line 548 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
if (_m_2 == 0x44) { KeyCode.KeyD } else 
#line 549 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
if (_m_2 == 0x50) { KeyCode.KeyP } else 
#line 550 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
if (1) { KeyCode.KeyUnknown } };
    }
}

#line 480 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"

uint32_t window_proc(void* hwnd, uint32_t msg, uint32_t wParam, uint32_t lParam)
{
    {

#line 481 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
{ uint32_t _m_3 = msg; 
#line 482 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
if (_m_3 == WM_PAINT) {     {

#line 483 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
if ((paint_handler != null))     {

#line 484 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
paint_handler(client_width, client_height);
    }

#line 486 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    return 0;
    }
 } else 
#line 488 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
if (_m_3 == WM_KEYDOWN) {     {

#line 489 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    KeyCode key = 
#line 489 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
map_vkey(((int32_t)(wParam)));

#line 490 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
if ((key_handler != null))     {

#line 491 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
key_handler(key);
    }

#line 493 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
redraw_window(hwnd);

#line 494 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    return 0;
    }
 } else 
#line 496 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
if (_m_3 == WM_KEYUP) {     {

#line 497 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    return 0;
    }
 } else 
#line 499 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
if (_m_3 == WM_LBUTTONDOWN) {     {

#line 500 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
if ((mouse_handler != null))     {

#line 501 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    uint32_t x = (lParam & 65535);

#line 501 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
as;
i32;

#line 502 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    uint32_t y = ((lParam >> 16) & 65535);

#line 502 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
as;
i32;

#line 503 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
mouse_handler(x, y);
    }

#line 505 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
redraw_window(hwnd);

#line 506 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    return 0;
    }
 } else 
#line 508 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
if (_m_3 == WM_TIMER) {     {

#line 509 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
if ((timer_handler != null))     {

#line 510 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    ZC_AUTO needs_redraw = 
#line 510 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
timer_handler();

#line 511 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
if (needs_redraw)     {

#line 512 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
redraw_window(hwnd);
    }
    }

#line 515 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    return 0;
    }
 } else 
#line 517 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
if (_m_3 == WM_SIZE) {     {

#line 518 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
(client_width = (lParam & 65535));

#line 518 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
as;
i32;

#line 519 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
(client_height = ((lParam >> 16) & 65535));

#line 519 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
as;
i32;

#line 520 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
redraw_window(hwnd);

#line 521 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    return 0;
    }
 } else 
#line 523 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
if (_m_3 == WM_DESTROY) {     {

#line 524 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
if ((destroy_handler != null))     {

#line 525 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
destroy_handler();
    }

#line 527 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
PostQuitMessage(0);

#line 528 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    return 0;
    }
 } else 
#line 530 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
if (1) {     {

#line 531 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    return 
#line 531 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
DefWindowProcA(hwnd, msg, wParam, lParam);
    }
 } };
    }
}

#line 478 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"

Tuple__int32_t__int32_t get_client_size(void)
{
    {

#line 478 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    return (Tuple__int32_t__int32_t){client_width, client_height};
    }
}

#line 477 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"

void set_client_size(int32_t w, int32_t h)
{
    {

#line 477 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
(client_width = w);
(client_height = h);
    }
}

#line 476 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"

void set_destroy_handler(z_closure_T h)
{

#line 476 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    int __z_drop_flag_h = 1;
    {

#line 476 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
(destroy_handler = ({ __z_drop_flag_h = 0; h; }));
    }

#line 476 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    if (__z_drop_flag_h && h.drop) h.drop(h.ctx);
}

#line 475 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"

void set_mouse_handler(z_closure_T h)
{

#line 475 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    int __z_drop_flag_h = 1;
    {

#line 475 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
(mouse_handler = ({ __z_drop_flag_h = 0; h; }));
    }

#line 475 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    if (__z_drop_flag_h && h.drop) h.drop(h.ctx);
}

#line 474 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"

void set_paint_handler(z_closure_T h)
{

#line 474 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    int __z_drop_flag_h = 1;
    {

#line 474 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
(paint_handler = ({ __z_drop_flag_h = 0; h; }));
    }

#line 474 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    if (__z_drop_flag_h && h.drop) h.drop(h.ctx);
}

#line 473 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"

void set_timer_handler(z_closure_T h)
{

#line 473 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    int __z_drop_flag_h = 1;
    {

#line 473 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
(timer_handler = ({ __z_drop_flag_h = 0; h; }));
    }

#line 473 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    if (__z_drop_flag_h && h.drop) h.drop(h.ctx);
}

#line 472 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"

void set_key_handler(z_closure_T h)
{

#line 472 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    int __z_drop_flag_h = 1;
    {

#line 472 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
(key_handler = ({ __z_drop_flag_h = 0; h; }));
    }

#line 472 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    if (__z_drop_flag_h && h.drop) h.drop(h.ctx);
}

#line 434 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"

void fb_draw_text_size(int32_t x, int32_t y, string text, Color color, int32_t size)
{
    {

#line 435 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    #if IS_WINDOWS


#line 436 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
if ((!fb_data.valid))     {

#line 436 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    return ;
    }

#line 437 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    uint32_t prev_color = 
#line 437 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
SetTextColor(fb_data.memDC, color_to_u32(color));

#line 438 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    int32_t prev_mode = 
#line 438 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
SetBkMode(fb_data.memDC, 1);

#line 440 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    void* font = 
#line 440 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
CreateFontA(size, 0, 0, 0, 400, 0, 0, 0, 0, 0, 0, 0, 0, 
#line 442 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
char*__c_str((char*[]){"Arial\0"}));

#line 443 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    void* old_font = 
#line 443 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
SelectObject_3(fb_data.memDC, font);

#line 445 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
TextOutA(fb_data.memDC, x, y, char*__c_str(&text), ((int32_t)(text.len)));

#line 447 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
SelectObject_3(fb_data.memDC, old_font);

#line 448 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
DeleteObject_3(font);

#line 449 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
SetBkMode(fb_data.memDC, prev_mode);

#line 450 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
SetTextColor(fb_data.memDC, prev_color);

#line 451 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    #endif

    }
}

#line 414 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"

void fb_draw_text(int32_t x, int32_t y, string text, Color color)
{
    {

#line 415 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    #if IS_WINDOWS


#line 416 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
if ((!fb_data.valid))     {

#line 416 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    return ;
    }

#line 417 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    uint32_t prev_color = 
#line 417 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
SetTextColor(fb_data.memDC, color_to_u32(color));

#line 418 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    int32_t prev_mode = 
#line 418 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
SetBkMode(fb_data.memDC, 1);

#line 420 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    void* font = 
#line 420 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
CreateFontA(16, 0, 0, 0, 400, 0, 0, 0, 0, 0, 0, 0, 0, 
#line 422 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
char*__c_str((char*[]){"Arial\0"}));

#line 423 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    void* old_font = 
#line 423 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
SelectObject_3(fb_data.memDC, font);

#line 425 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
TextOutA(fb_data.memDC, x, y, char*__c_str(&text), ((int32_t)(text.len)));

#line 427 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
SelectObject_3(fb_data.memDC, old_font);

#line 428 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
DeleteObject_3(font);

#line 429 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
SetBkMode(fb_data.memDC, prev_mode);

#line 430 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
SetTextColor(fb_data.memDC, prev_color);

#line 431 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    #endif

    }
}

#line 380 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"

void fb_shutdown(void)
{
    {

#line 381 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    #if IS_WINDOWS


#line 382 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
if ((fb_data.memDC != null))     {

#line 383 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
DeleteDC(fb_data.memDC);
    }

#line 385 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
if ((fb_data.bitmap != null))     {

#line 386 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
DeleteObject_2(fb_data.bitmap);
    }

#line 388 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
if ((fb_data.hdc != null))     {

#line 389 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
ReleaseDC(fb_data.window, fb_data.hdc);
    }

#line 391 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
(fb_data.valid = false);

#line 392 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    #endif

    }
}

#line 373 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"

void fb_present(void)
{
    {

#line 374 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    #if IS_WINDOWS


#line 375 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
if ((!fb_data.valid))     {

#line 375 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    return ;
    }

#line 376 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
BitBlt(fb_data.hdc, 0, 0, fb_data.width, fb_data.height, fb_data.memDC, 0, 0, 13369376);

#line 377 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    #endif

    }
}

#line 362 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"

void fb_draw_circle(int32_t x, int32_t y, int32_t radius, Color color)
{
    {

#line 363 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    #if IS_WINDOWS


#line 364 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
if ((!fb_data.valid))     {

#line 364 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    return ;
    }

#line 365 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    void* brush = 
#line 365 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
CreateSolidBrush(color_to_u32(color));

#line 366 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    void* old_brush = 
#line 366 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
SelectObject(fb_data.memDC, brush);

#line 367 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
Ellipse(fb_data.memDC, (x - radius), (y - radius), (x + radius), (y + radius));

#line 368 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
SelectObject(fb_data.memDC, old_brush);

#line 369 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
DeleteObject(brush);

#line 370 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    #endif

    }
}

#line 350 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"

void fb_draw_rect(int32_t x, int32_t y, int32_t width, int32_t height, Color color)
{
    {

#line 351 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    #if IS_WINDOWS


#line 352 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
if ((!fb_data.valid))     {

#line 352 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    return ;
    }

#line 353 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    void* brush = 
#line 353 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
CreateSolidBrush(color_to_u32(color));

#line 354 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    void* old_brush = 
#line 354 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
SelectObject(fb_data.memDC, brush);

#line 355 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    int32_t rect[4] = {x, y, (x + width), (y + height)};

#line 356 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
FillRect(fb_data.memDC, (&rect), brush);

#line 357 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
SelectObject(fb_data.memDC, old_brush);

#line 358 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
DeleteObject(brush);

#line 359 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    #endif

    }
}

#line 339 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"

void fb_clear(Color color)
{
    {

#line 340 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    #if IS_WINDOWS


#line 341 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
if ((!fb_data.valid))     {

#line 341 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    return ;
    }

#line 342 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    void* brush = 
#line 342 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
CreateSolidBrush(color_to_u32(color));

#line 343 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    void* old_brush = 
#line 343 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
SelectObject(fb_data.memDC, brush);

#line 344 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
Rectangle(fb_data.memDC, 0, 0, fb_data.width, fb_data.height);

#line 345 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
SelectObject(fb_data.memDC, old_brush);

#line 346 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
DeleteObject(brush);

#line 347 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    #endif

    }
}

#line 319 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"

void fb_init(void* window, int32_t width, int32_t height)
{
    {

#line 320 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    #if IS_WINDOWS


#line 321 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
(fb_data.window = window);

#line 322 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
(fb_data.width = width);

#line 323 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
(fb_data.height = height);

#line 324 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
(fb_data.hdc = 
#line 324 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
GetDC(window));

#line 325 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
(fb_data.memDC = 
#line 325 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
CreateCompatibleDC(fb_data.hdc));

#line 326 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
(fb_data.bitmap = 
#line 326 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
CreateCompatibleBitmap(fb_data.hdc, width, height));

#line 327 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
SelectObject_2(fb_data.memDC, fb_data.bitmap);

#line 328 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
(fb_data.valid = true);

#line 331 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    void* brush = 
#line 331 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
CreateSolidBrush(16777215);

#line 332 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    void* old_brush = 
#line 332 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
SelectObject(fb_data.memDC, brush);

#line 333 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
Rectangle(fb_data.memDC, 0, 0, width, height);

#line 334 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
SelectObject(fb_data.memDC, old_brush);

#line 335 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
DeleteObject(brush);

#line 336 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    #endif

    }
}

#line 291 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"

void draw_circle(void* ctx, int32_t x, int32_t y, int32_t radius, Color color)
{
    {

#line 292 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    #if IS_WINDOWS


#line 293 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    void* brush = 
#line 293 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
CreateSolidBrush(color_to_u32(color));

#line 294 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    void* old_brush = 
#line 294 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
SelectObject(ctx, brush);

#line 296 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
Ellipse(ctx, (x - radius), (y - radius), (x + radius), (y + radius));

#line 298 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
SelectObject(ctx, old_brush);

#line 299 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
DeleteObject(brush);

#line 300 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    #endif

    }
}

#line 278 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"

void draw_rect(void* ctx, int32_t x, int32_t y, int32_t width, int32_t height, Color color)
{
    {

#line 279 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    #if IS_WINDOWS


#line 280 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    void* brush = 
#line 280 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
CreateSolidBrush(color_to_u32(color));

#line 281 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    void* old_brush = 
#line 281 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
SelectObject(ctx, brush);

#line 283 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    int32_t rect[4] = {x, y, (x + width), (y + height)};

#line 284 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
FillRect(ctx, (&rect), brush);

#line 286 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
SelectObject(ctx, old_brush);

#line 287 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
DeleteObject(brush);

#line 288 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    #endif

    }
}

#line 274 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"

uint32_t color_to_u32(Color c)
{
    {

#line 275 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
((((uint32_t)(c.r)) | (((uint32_t)(c.g)) << 8)) | (((uint32_t)(c.b)) << 16));
    }
}

#line 270 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"

Color rgb(uint8_t r, uint8_t g, uint8_t b)
{
    {

#line 271 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
(struct Color){.r = r, .g = g, .b = b};
    }
}

#line 248 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"

bool get_window_client_size(void* window, int32_t* width, int32_t* height)
{
    {

#line 249 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    #if IS_WINDOWS


#line 250 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    int32_t rect[4] = {0, 0, 0, 0};

#line 251 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
if (
#line 251 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
GetClientRect(window, (&rect)))     {

#line 252 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
((*width) = (rect[_z_check_bounds(2, 4)] - rect[_z_check_bounds(0, 4)]));

#line 253 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
((*height) = (rect[_z_check_bounds(3, 4)] - rect[_z_check_bounds(1, 4)]));

#line 254 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    return true;
    }

#line 256 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    return false;

#line 257 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    #else


#line 258 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    return false;

#line 259 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    #endif

    }
}

#line 242 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"

void redraw_window(void* window)
{
    {

#line 243 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    #if IS_WINDOWS


#line 244 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
InvalidateRect(window, null, true);

#line 245 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    #endif

    }
}

#line 236 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"

void kill_game_timer(void* window)
{
    {

#line 237 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    #if IS_WINDOWS


#line 238 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
KillTimer(window, 1);

#line 239 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    #endif

    }
}

#line 230 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"

void set_game_timer(void* window, uint32_t interval_ms)
{
    {

#line 231 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    #if IS_WINDOWS


#line 232 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
SetTimer(window, 1, interval_ms, null);

#line 233 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    #endif

    }
}

#line 224 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"

void quit_application(void)
{
    {

#line 225 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    #if IS_WINDOWS


#line 226 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
PostQuitMessage(0);

#line 227 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    #endif

    }
}

#line 214 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"

void run_event_loop(void* window)
{
    {

#line 215 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    #if IS_WINDOWS


#line 216 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    uint8_t msg[28] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

#line 217 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
while (
#line 217 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
GetMessageA((&msg), window, 0, 0))     {

#line 218 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
TranslateMessage((&msg));

#line 219 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
DispatchMessageA((&msg));
    }

#line 221 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    #endif

    }
}

#line 207 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"

void show_window(void* window)
{
    {

#line 208 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    #if IS_WINDOWS


#line 209 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
ShowWindow(window, 1);

#line 210 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
UpdateWindow(window);

#line 211 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    #endif

    }
}

#line 170 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"

void* create_window(string title, int32_t width, int32_t height)
{
    {

#line 171 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    #if IS_WINDOWS


#line 172 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    void* hInstance = 
#line 172 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
GetModuleHandleA(null);

#line 174 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    WNDCLASSA wndclass = (struct WNDCLASSA){.style = (2 | 1), .lpfnWndProc = window_proc, .hInstance = hInstance, .hIcon = null, .hCursor = 
#line 179 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
LoadCursorA(null, IDC_ARROW), .hbrBackground = ((void*)(1)), .lpszMenuName = null, .lpszClassName = 
#line 182 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
char*__c_str((char*[]){"BreakoutGame\0"})};

#line 185 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
RegisterClassA((&wndclass));

#line 187 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    void* hwnd = 
#line 187 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
CreateWindowExA(0, 
#line 189 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
char*__c_str((char*[]){"BreakoutGame\0"}), 
#line 190 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
char*__c_str(&title), (((12582912 | 524288) | 131072) | 65536), 18446744071562067968ULL, 18446744071562067968ULL, (width + 16), (height + 56), null, null, hInstance, null);

#line 199 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    return hwnd;

#line 200 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    #elif IS_LINUX


#line 201 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    return null;

#line 202 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    #elif IS_MACOS


#line 203 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    return null;

#line 204 "/home/yq/github/xingmu/windows-minigames-diy/src/004-breakout/src/platform_api.zc"
    #endif

    }
}

#line 162 "/usr/local/share/zenc/std/io.zc"

char* _z_str_rune(int32_t r)
{
    {

#line 163 "/usr/local/share/zenc/std/io.zc"
    static char buffer[5] = {0};

#line 164 "/usr/local/share/zenc/std/io.zc"
    uint32_t val = ((uint32_t)(r));

#line 165 "/usr/local/share/zenc/std/io.zc"
if ((val < 128))     {

#line 166 "/usr/local/share/zenc/std/io.zc"
(buffer[_z_check_bounds(0, 5)] = ((char)(val)));

#line 167 "/usr/local/share/zenc/std/io.zc"
(buffer[_z_check_bounds(1, 5)] = 0);
    }

#line 168 "/usr/local/share/zenc/std/io.zc"
 else if ((val < 2048))     {

#line 169 "/usr/local/share/zenc/std/io.zc"
(buffer[_z_check_bounds(0, 5)] = ((char)((192 | (val >> 6)))));

#line 170 "/usr/local/share/zenc/std/io.zc"
(buffer[_z_check_bounds(1, 5)] = ((char)((128 | (val & 63)))));

#line 171 "/usr/local/share/zenc/std/io.zc"
(buffer[_z_check_bounds(2, 5)] = 0);
    }

#line 172 "/usr/local/share/zenc/std/io.zc"
 else if ((val < 65536))     {

#line 173 "/usr/local/share/zenc/std/io.zc"
(buffer[_z_check_bounds(0, 5)] = ((char)((224 | (val >> 12)))));

#line 174 "/usr/local/share/zenc/std/io.zc"
(buffer[_z_check_bounds(1, 5)] = ((char)((128 | ((val >> 6) & 63)))));

#line 175 "/usr/local/share/zenc/std/io.zc"
(buffer[_z_check_bounds(2, 5)] = ((char)((128 | (val & 63)))));

#line 176 "/usr/local/share/zenc/std/io.zc"
(buffer[_z_check_bounds(3, 5)] = 0);
    }
 else     {

#line 178 "/usr/local/share/zenc/std/io.zc"
(buffer[_z_check_bounds(0, 5)] = ((char)((240 | (val >> 18)))));

#line 179 "/usr/local/share/zenc/std/io.zc"
(buffer[_z_check_bounds(1, 5)] = ((char)((128 | ((val >> 12) & 63)))));

#line 180 "/usr/local/share/zenc/std/io.zc"
(buffer[_z_check_bounds(2, 5)] = ((char)((128 | ((val >> 6) & 63)))));

#line 181 "/usr/local/share/zenc/std/io.zc"
(buffer[_z_check_bounds(3, 5)] = ((char)((128 | (val & 63)))));

#line 182 "/usr/local/share/zenc/std/io.zc"
(buffer[_z_check_bounds(4, 5)] = 0);
    }

#line 184 "/usr/local/share/zenc/std/io.zc"
    return ((char*)(buffer));
    }
}

#line 155 "/usr/local/share/zenc/std/io.zc"

char* utos(uint32_t n)
{
    {

#line 156 "/usr/local/share/zenc/std/io.zc"
    static char buffer[32] = {0};

#line 157 "/usr/local/share/zenc/std/io.zc"
sprintf(((char*)(buffer)), "%u", n);

#line 158 "/usr/local/share/zenc/std/io.zc"
    return ((char*)(buffer));
    }
}

#line 147 "/usr/local/share/zenc/std/io.zc"

char* itos_new(int32_t n)
{
    {

#line 148 "/usr/local/share/zenc/std/io.zc"
    char* buffer = 
#line 148 "/usr/local/share/zenc/std/io.zc"
malloc(32);

#line 149 "/usr/local/share/zenc/std/io.zc"
if ((buffer == NULL))     {

#line 149 "/usr/local/share/zenc/std/io.zc"
    return NULL;
    }

#line 150 "/usr/local/share/zenc/std/io.zc"
sprintf(buffer, "%d", n);

#line 151 "/usr/local/share/zenc/std/io.zc"
    return buffer;
    }
}

#line 140 "/usr/local/share/zenc/std/io.zc"

char* itos(int32_t n)
{
    {

#line 141 "/usr/local/share/zenc/std/io.zc"
    static char buffer[32] = {0};

#line 142 "/usr/local/share/zenc/std/io.zc"
sprintf(((char*)(buffer)), "%d", n);

#line 143 "/usr/local/share/zenc/std/io.zc"
    return ((char*)(buffer));
    }
}

#line 112 "/usr/local/share/zenc/std/io.zc"

int32_t read_rune(void)
{
    {

#line 113 "/usr/local/share/zenc/std/io.zc"
    void* std_in = stdin;

#line 114 "/usr/local/share/zenc/std/io.zc"
    ZC_AUTO c1 = 
#line 114 "/usr/local/share/zenc/std/io.zc"
fgetc(std_in);

#line 115 "/usr/local/share/zenc/std/io.zc"
if ((c1 == (-1)))     {

#line 115 "/usr/local/share/zenc/std/io.zc"
    return ((int32_t)(0));
    }

#line 117 "/usr/local/share/zenc/std/io.zc"
    uint8_t first = ((uint8_t)(c1));

#line 118 "/usr/local/share/zenc/std/io.zc"
    size_t len = 
#line 118 "/usr/local/share/zenc/std/io.zc"
_utf8_seq_len(first);

#line 119 "/usr/local/share/zenc/std/io.zc"
if ((len == 1))     {

#line 119 "/usr/local/share/zenc/std/io.zc"
    return ((int32_t)(first));
    }

#line 121 "/usr/local/share/zenc/std/io.zc"
    uint32_t val = 0;

#line 122 "/usr/local/share/zenc/std/io.zc"
if ((len == 2))     {

#line 123 "/usr/local/share/zenc/std/io.zc"
(val = (((uint32_t)((first & 31))) << 6));

#line 124 "/usr/local/share/zenc/std/io.zc"
(val = (val | ((uint32_t)((((uint8_t)(
#line 124 "/usr/local/share/zenc/std/io.zc"
fgetc(std_in))) & 63)))));
    }

#line 125 "/usr/local/share/zenc/std/io.zc"
 else if ((len == 3))     {

#line 126 "/usr/local/share/zenc/std/io.zc"
(val = (((uint32_t)((first & 15))) << 12));

#line 127 "/usr/local/share/zenc/std/io.zc"
(val = (val | (((uint32_t)((((uint8_t)(
#line 127 "/usr/local/share/zenc/std/io.zc"
fgetc(std_in))) & 63))) << 6)));

#line 128 "/usr/local/share/zenc/std/io.zc"
(val = (val | ((uint32_t)((((uint8_t)(
#line 128 "/usr/local/share/zenc/std/io.zc"
fgetc(std_in))) & 63)))));
    }

#line 129 "/usr/local/share/zenc/std/io.zc"
 else if ((len == 4))     {

#line 130 "/usr/local/share/zenc/std/io.zc"
(val = (((uint32_t)((first & 7))) << 18));

#line 131 "/usr/local/share/zenc/std/io.zc"
(val = (val | (((uint32_t)((((uint8_t)(
#line 131 "/usr/local/share/zenc/std/io.zc"
fgetc(std_in))) & 63))) << 12)));

#line 132 "/usr/local/share/zenc/std/io.zc"
(val = (val | (((uint32_t)((((uint8_t)(
#line 132 "/usr/local/share/zenc/std/io.zc"
fgetc(std_in))) & 63))) << 6)));

#line 133 "/usr/local/share/zenc/std/io.zc"
(val = (val | ((uint32_t)((((uint8_t)(
#line 133 "/usr/local/share/zenc/std/io.zc"
fgetc(std_in))) & 63)))));
    }

#line 135 "/usr/local/share/zenc/std/io.zc"
    return ((int32_t)(val));
    }
}

#line 103 "/usr/local/share/zenc/std/io.zc"

size_t _utf8_seq_len(uint8_t first_byte)
{
    {

#line 104 "/usr/local/share/zenc/std/io.zc"
    int32_t b = ((int32_t)(first_byte));

#line 105 "/usr/local/share/zenc/std/io.zc"
if (((b & 128) == 0))     {

#line 105 "/usr/local/share/zenc/std/io.zc"
    return 1;
    }

#line 106 "/usr/local/share/zenc/std/io.zc"
if (((b & 224) == 192))     {

#line 106 "/usr/local/share/zenc/std/io.zc"
    return 2;
    }

#line 107 "/usr/local/share/zenc/std/io.zc"
if (((b & 240) == 224))     {

#line 107 "/usr/local/share/zenc/std/io.zc"
    return 3;
    }

#line 108 "/usr/local/share/zenc/std/io.zc"
if (((b & 248) == 240))     {

#line 108 "/usr/local/share/zenc/std/io.zc"
    return 4;
    }

#line 109 "/usr/local/share/zenc/std/io.zc"
    return 1;
    }
}

#line 62 "/usr/local/share/zenc/std/io.zc"

char* readln(void)
{
    {

#line 63 "/usr/local/share/zenc/std/io.zc"
    size_t cap = 64;

#line 64 "/usr/local/share/zenc/std/io.zc"
    size_t len = 0;

#line 65 "/usr/local/share/zenc/std/io.zc"
    char* line = 
#line 65 "/usr/local/share/zenc/std/io.zc"
malloc(cap);

#line 66 "/usr/local/share/zenc/std/io.zc"
if ((line == NULL))     {

#line 66 "/usr/local/share/zenc/std/io.zc"
    return NULL;
    }

#line 68 "/usr/local/share/zenc/std/io.zc"
    int c = 0;

#line 69 "/usr/local/share/zenc/std/io.zc"
    void* std_in = stdin;

#line 71 "/usr/local/share/zenc/std/io.zc"
while (true)     {

#line 72 "/usr/local/share/zenc/std/io.zc"
(c = 
#line 72 "/usr/local/share/zenc/std/io.zc"
fgetc(std_in));

#line 74 "/usr/local/share/zenc/std/io.zc"
    int eof_c = (-1);

#line 75 "/usr/local/share/zenc/std/io.zc"
if ((c == eof_c))     {

#line 75 "/usr/local/share/zenc/std/io.zc"
break;
    }

#line 76 "/usr/local/share/zenc/std/io.zc"
    int nl_c = 10;

#line 77 "/usr/local/share/zenc/std/io.zc"
if ((c == nl_c))     {

#line 77 "/usr/local/share/zenc/std/io.zc"
break;
    }

#line 79 "/usr/local/share/zenc/std/io.zc"
if (((len + 1) >= cap))     {

#line 80 "/usr/local/share/zenc/std/io.zc"
(cap = (cap * 2));

#line 81 "/usr/local/share/zenc/std/io.zc"
    void* n = 
#line 81 "/usr/local/share/zenc/std/io.zc"
realloc(line, cap);

#line 82 "/usr/local/share/zenc/std/io.zc"
if ((n == NULL))     {

#line 83 "/usr/local/share/zenc/std/io.zc"
free(line);

#line 84 "/usr/local/share/zenc/std/io.zc"
    return NULL;
    }

#line 86 "/usr/local/share/zenc/std/io.zc"
(line = n);
    }

#line 89 "/usr/local/share/zenc/std/io.zc"
(line[len] = c);

#line 90 "/usr/local/share/zenc/std/io.zc"
(len = (len + 1));
    }

#line 93 "/usr/local/share/zenc/std/io.zc"
    int32_t eof_final = (-1);

#line 94 "/usr/local/share/zenc/std/io.zc"
if (((len == 0) && (c == eof_final)))     {

#line 95 "/usr/local/share/zenc/std/io.zc"
free(line);

#line 96 "/usr/local/share/zenc/std/io.zc"
    return NULL;
    }

#line 99 "/usr/local/share/zenc/std/io.zc"
(line[len] = 0);

#line 100 "/usr/local/share/zenc/std/io.zc"
    return line;
    }
}

#line 53 "/usr/local/share/zenc/std/io.zc"

int println(char* fmt, ...)
{
    {

#line 54 "/usr/local/share/zenc/std/io.zc"
    va_list ap = {0};
va_start(ap, fmt);

#line 56 "/usr/local/share/zenc/std/io.zc"
    ZC_AUTO ret = 
#line 56 "/usr/local/share/zenc/std/io.zc"
vprintf(fmt, ap);
va_end(ap);

#line 58 "/usr/local/share/zenc/std/io.zc"
puts("");

#line 59 "/usr/local/share/zenc/std/io.zc"
    return (ret + 1);
    }
}

#line 45 "/usr/local/share/zenc/std/io.zc"

int print(char* fmt, ...)
{
    {

#line 46 "/usr/local/share/zenc/std/io.zc"
    va_list ap = {0};
va_start(ap, fmt);

#line 48 "/usr/local/share/zenc/std/io.zc"
    ZC_AUTO ret = 
#line 48 "/usr/local/share/zenc/std/io.zc"
vprintf(fmt, ap);
va_end(ap);

#line 50 "/usr/local/share/zenc/std/io.zc"
    return ret;
    }
}

#line 32 "/usr/local/share/zenc/std/io.zc"

char* format_new(char* fmt, ...)
{
    {

#line 33 "/usr/local/share/zenc/std/io.zc"
    char* buffer = 
#line 33 "/usr/local/share/zenc/std/io.zc"
malloc(1024);

#line 34 "/usr/local/share/zenc/std/io.zc"
if ((buffer == NULL))     {

#line 34 "/usr/local/share/zenc/std/io.zc"
    return NULL;
    }

#line 36 "/usr/local/share/zenc/std/io.zc"
    va_list ap = {0};
va_start(ap, fmt);

#line 39 "/usr/local/share/zenc/std/io.zc"
vsnprintf(buffer, 1024, fmt, ap);
va_end(ap);

#line 42 "/usr/local/share/zenc/std/io.zc"
    return buffer;
    }
}

#line 22 "/usr/local/share/zenc/std/io.zc"

int format_into(char* buffer, size_t size, char* fmt, ...)
{
    {

#line 23 "/usr/local/share/zenc/std/io.zc"
    va_list ap = {0};
va_start(ap, fmt);

#line 26 "/usr/local/share/zenc/std/io.zc"
    ZC_AUTO ret = 
#line 26 "/usr/local/share/zenc/std/io.zc"
vsnprintf(buffer, size, fmt, ap);
va_end(ap);

#line 29 "/usr/local/share/zenc/std/io.zc"
    return ret;
    }
}

#line 11 "/usr/local/share/zenc/std/io.zc"

char* format(char* fmt, ...)
{
    {

#line 12 "/usr/local/share/zenc/std/io.zc"
    static char buffer[1024] = {0};

#line 13 "/usr/local/share/zenc/std/io.zc"
    va_list ap = {0};
va_start(ap, fmt);

#line 16 "/usr/local/share/zenc/std/io.zc"
vsnprintf(buffer, 1024, fmt, ap);
va_end(ap);

#line 19 "/usr/local/share/zenc/std/io.zc"
    return ((char*)(buffer));
    }
}

#line 13 "/usr/local/share/zenc/std/core.zc"

void __zenc_todo_impl(const char* file, int32_t line, const char* func, const char* msg)
{
    {

#line 14 "/usr/local/share/zenc/std/core.zc"
fprintf(stderr, "todo: %s\n  at %s:%d in %s()\n", msg, file, line, func);

#line 15 "/usr/local/share/zenc/std/core.zc"
exit(1);
    }
}

#line 8 "/usr/local/share/zenc/std/core.zc"

void __zenc_panic_impl(const char* file, int32_t line, const char* func, const char* msg)
{
    {

#line 9 "/usr/local/share/zenc/std/core.zc"
fprintf(stderr, "panic: %s\n  at %s:%d in %s()\n", msg, file, line, func);

#line 10 "/usr/local/share/zenc/std/core.zc"
exit(1);
    }
}

#line 9 "/usr/local/share/zenc/std/math.zc"

double Math__PI(void)
{
    {

#line 9 "/usr/local/share/zenc/std/math.zc"
    return 3.1415926535897931;
    }
}

#line 10 "/usr/local/share/zenc/std/math.zc"

double Math__E(void)
{
    {

#line 10 "/usr/local/share/zenc/std/math.zc"
    return 2.7182818284590451;
    }
}

#line 13 "/usr/local/share/zenc/std/math.zc"

double Math__abs(double x)
{
    {

#line 14 "/usr/local/share/zenc/std/math.zc"
    return 
#line 14 "/usr/local/share/zenc/std/math.zc"
fabs(x);
    }
}

#line 18 "/usr/local/share/zenc/std/math.zc"

double Math__sin(double x)
{
    {

#line 19 "/usr/local/share/zenc/std/math.zc"
    return 
#line 19 "/usr/local/share/zenc/std/math.zc"
sin(x);
    }
}

#line 22 "/usr/local/share/zenc/std/math.zc"

double Math__cos(double x)
{
    {

#line 23 "/usr/local/share/zenc/std/math.zc"
    return 
#line 23 "/usr/local/share/zenc/std/math.zc"
cos(x);
    }
}

#line 26 "/usr/local/share/zenc/std/math.zc"

double Math__tan(double x)
{
    {

#line 27 "/usr/local/share/zenc/std/math.zc"
    return 
#line 27 "/usr/local/share/zenc/std/math.zc"
tan(x);
    }
}

#line 30 "/usr/local/share/zenc/std/math.zc"

double Math__asin(double x)
{
    {

#line 31 "/usr/local/share/zenc/std/math.zc"
    return 
#line 31 "/usr/local/share/zenc/std/math.zc"
asin(x);
    }
}

#line 34 "/usr/local/share/zenc/std/math.zc"

double Math__acos(double x)
{
    {

#line 35 "/usr/local/share/zenc/std/math.zc"
    return 
#line 35 "/usr/local/share/zenc/std/math.zc"
acos(x);
    }
}

#line 38 "/usr/local/share/zenc/std/math.zc"

double Math__atan(double x)
{
    {

#line 39 "/usr/local/share/zenc/std/math.zc"
    return 
#line 39 "/usr/local/share/zenc/std/math.zc"
atan(x);
    }
}

#line 42 "/usr/local/share/zenc/std/math.zc"

double Math__atan2(double y, double x)
{
    {

#line 43 "/usr/local/share/zenc/std/math.zc"
    return 
#line 43 "/usr/local/share/zenc/std/math.zc"
atan2(y, x);
    }
}

#line 47 "/usr/local/share/zenc/std/math.zc"

double Math__sqrt(double x)
{
    {

#line 48 "/usr/local/share/zenc/std/math.zc"
    return 
#line 48 "/usr/local/share/zenc/std/math.zc"
sqrt(x);
    }
}

#line 51 "/usr/local/share/zenc/std/math.zc"

double Math__pow(double base, double exp)
{
    {

#line 52 "/usr/local/share/zenc/std/math.zc"
    return 
#line 52 "/usr/local/share/zenc/std/math.zc"
pow(base, exp);
    }
}

#line 55 "/usr/local/share/zenc/std/math.zc"

double Math__exp(double x)
{
    {

#line 56 "/usr/local/share/zenc/std/math.zc"
    return 
#line 56 "/usr/local/share/zenc/std/math.zc"
exp(x);
    }
}

#line 59 "/usr/local/share/zenc/std/math.zc"

double Math__log(double x)
{
    {

#line 60 "/usr/local/share/zenc/std/math.zc"
    return 
#line 60 "/usr/local/share/zenc/std/math.zc"
log(x);
    }
}

#line 63 "/usr/local/share/zenc/std/math.zc"

double Math__log10(double x)
{
    {

#line 64 "/usr/local/share/zenc/std/math.zc"
    return 
#line 64 "/usr/local/share/zenc/std/math.zc"
log10(x);
    }
}

#line 68 "/usr/local/share/zenc/std/math.zc"

double Math__ceil(double x)
{
    {

#line 69 "/usr/local/share/zenc/std/math.zc"
    return 
#line 69 "/usr/local/share/zenc/std/math.zc"
ceil(x);
    }
}

#line 72 "/usr/local/share/zenc/std/math.zc"

double Math__floor(double x)
{
    {

#line 73 "/usr/local/share/zenc/std/math.zc"
    return 
#line 73 "/usr/local/share/zenc/std/math.zc"
floor(x);
    }
}

#line 76 "/usr/local/share/zenc/std/math.zc"

double Math__round(double x)
{
    {

#line 77 "/usr/local/share/zenc/std/math.zc"
    return 
#line 77 "/usr/local/share/zenc/std/math.zc"
round(x);
    }
}

#line 80 "/usr/local/share/zenc/std/math.zc"

double Math__mod(double x, double y)
{
    {

#line 81 "/usr/local/share/zenc/std/math.zc"
    return 
#line 81 "/usr/local/share/zenc/std/math.zc"
fmod(x, y);
    }
}

#line 85 "/usr/local/share/zenc/std/math.zc"

double Math__max(double a, double b)
{
    {

#line 86 "/usr/local/share/zenc/std/math.zc"
    return 
#line 86 "/usr/local/share/zenc/std/math.zc"
fmax(a, b);
    }
}

#line 89 "/usr/local/share/zenc/std/math.zc"

double Math__min(double a, double b)
{
    {

#line 90 "/usr/local/share/zenc/std/math.zc"
    return 
#line 90 "/usr/local/share/zenc/std/math.zc"
fmin(a, b);
    }
}

#line 50 "/usr/local/share/zenc/std/string.zc"

String String__new(char* s)
{
    {

#line 51 "/usr/local/share/zenc/std/string.zc"
    ZC_AUTO len = 
#line 51 "/usr/local/share/zenc/std/string.zc"
strlen(s);

#line 52 "/usr/local/share/zenc/std/string.zc"
    int __z_drop_flag_v = 1; Vec__char v = 
#line 52 "/usr/local/share/zenc/std/string.zc"
Vec__char__new();

#line 54 "/usr/local/share/zenc/std/string.zc"
for (int i = (int)(0); i < len; i = (i + 1))     {

#line 55 "/usr/local/share/zenc/std/string.zc"
Vec__char__push((&v), s[i]);
    }

#line 57 "/usr/local/share/zenc/std/string.zc"
Vec__char__push((&v), 0);

#line 60 "/usr/local/share/zenc/std/string.zc"
    char* d = v.data;

#line 61 "/usr/local/share/zenc/std/string.zc"
    size_t l = v.len;

#line 62 "/usr/local/share/zenc/std/string.zc"
    size_t c = v.cap;

#line 65 "/usr/local/share/zenc/std/string.zc"
Vec__char__forget((&v));

#line 67 "/usr/local/share/zenc/std/string.zc"
    { String _z_ret = (struct String){.vec = (Vec__char){.data = d, .len = l, .cap = c}}; 
#line 52 "/usr/local/share/zenc/std/string.zc"
    if (__z_drop_flag_v) Vec__char__Drop__glue(&v);
return _z_ret; }

#line 52 "/usr/local/share/zenc/std/string.zc"
    if (__z_drop_flag_v) Vec__char__Drop__glue(&v);
    }
}

#line 70 "/usr/local/share/zenc/std/string.zc"

String String__from(char* s)
{
    {

#line 71 "/usr/local/share/zenc/std/string.zc"
    return 
#line 71 "/usr/local/share/zenc/std/string.zc"
String__new(s);
    }
}

#line 74 "/usr/local/share/zenc/std/string.zc"

String String__from_rune(int32_t r)
{
    {

#line 75 "/usr/local/share/zenc/std/string.zc"
    int __z_drop_flag_s = 1; String s = 
#line 75 "/usr/local/share/zenc/std/string.zc"
String__new("");

#line 76 "/usr/local/share/zenc/std/string.zc"
String__push_rune(&s, r);

#line 77 "/usr/local/share/zenc/std/string.zc"
    return ({ ZC_AUTO _z_ret_mv = s; memset(&s, 0, sizeof(_z_ret_mv)); __z_drop_flag_s = 0; 
#line 75 "/usr/local/share/zenc/std/string.zc"
    if (__z_drop_flag_s) String__Drop__glue(&s);
_z_ret_mv; });

#line 75 "/usr/local/share/zenc/std/string.zc"
    if (__z_drop_flag_s) String__Drop__glue(&s);
    }
}

#line 80 "/usr/local/share/zenc/std/string.zc"

String String__from_runes(int32_t* runes, size_t count)
{
    {

#line 81 "/usr/local/share/zenc/std/string.zc"
    int __z_drop_flag_s = 1; String s = 
#line 81 "/usr/local/share/zenc/std/string.zc"
String__new("");

#line 82 "/usr/local/share/zenc/std/string.zc"
for (size_t i = (size_t)(0); i < count; i = (i + 1))     {

#line 83 "/usr/local/share/zenc/std/string.zc"
String__push_rune(&s, runes[i]);
    }

#line 85 "/usr/local/share/zenc/std/string.zc"
    return ({ ZC_AUTO _z_ret_mv = s; memset(&s, 0, sizeof(_z_ret_mv)); __z_drop_flag_s = 0; 
#line 81 "/usr/local/share/zenc/std/string.zc"
    if (__z_drop_flag_s) String__Drop__glue(&s);
_z_ret_mv; });

#line 81 "/usr/local/share/zenc/std/string.zc"
    if (__z_drop_flag_s) String__Drop__glue(&s);
    }
}

#line 88 "/usr/local/share/zenc/std/string.zc"

char* String__c_str(String* self)
{
    {

#line 89 "/usr/local/share/zenc/std/string.zc"
    return self->vec.data;
    }
}

#line 92 "/usr/local/share/zenc/std/string.zc"

char* String__to_string(String* self)
{
    {

#line 93 "/usr/local/share/zenc/std/string.zc"
    return 
#line 93 "/usr/local/share/zenc/std/string.zc"
String__c_str(self);
    }
}

#line 96 "/usr/local/share/zenc/std/string.zc"

void String__destroy(String* self)
{
    {

#line 97 "/usr/local/share/zenc/std/string.zc"
Vec__char__free((&self->vec));
    }
}

#line 100 "/usr/local/share/zenc/std/string.zc"

void String__forget(String* self)
{
    {

#line 101 "/usr/local/share/zenc/std/string.zc"
Vec__char__forget((&self->vec));
    }
}

#line 104 "/usr/local/share/zenc/std/string.zc"

void String__append(String* self, String* other)
{
    {

#line 106 "/usr/local/share/zenc/std/string.zc"
if ((self->vec.len > 0))     {

#line 107 "/usr/local/share/zenc/std/string.zc"
(self->vec.len = (self->vec.len - 1));
    }

#line 110 "/usr/local/share/zenc/std/string.zc"
    size_t other_len = (*other).vec.len;

#line 111 "/usr/local/share/zenc/std/string.zc"
for (int i = (int)(0); i < other_len; i = (i + 1))     {

#line 112 "/usr/local/share/zenc/std/string.zc"
Vec__char__push((&self->vec), Vec__char__get((&(*other).vec), i));
    }
    }
}

#line 116 "/usr/local/share/zenc/std/string.zc"

void String__append_c(String* self, char* s)
{
    {

#line 117 "/usr/local/share/zenc/std/string.zc"
if ((self->vec.len > 0))     {

#line 118 "/usr/local/share/zenc/std/string.zc"
(self->vec.len = (self->vec.len - 1));
    }

#line 120 "/usr/local/share/zenc/std/string.zc"
    ZC_AUTO len = 
#line 120 "/usr/local/share/zenc/std/string.zc"
strlen(s);

#line 121 "/usr/local/share/zenc/std/string.zc"
for (int i = (int)(0); i < len; i = (i + 1))     {

#line 122 "/usr/local/share/zenc/std/string.zc"
Vec__char__push((&self->vec), s[i]);
    }

#line 124 "/usr/local/share/zenc/std/string.zc"
Vec__char__push((&self->vec), 0);
    }
}

#line 127 "/usr/local/share/zenc/std/string.zc"

void String__push_rune(String* self, int32_t r)
{
    {

#line 128 "/usr/local/share/zenc/std/string.zc"
if ((self->vec.len > 0))     {

#line 129 "/usr/local/share/zenc/std/string.zc"
(self->vec.len = (self->vec.len - 1));
    }

#line 132 "/usr/local/share/zenc/std/string.zc"
    uint32_t val = ((uint32_t)(r));

#line 133 "/usr/local/share/zenc/std/string.zc"
if ((val < 128))     {

#line 134 "/usr/local/share/zenc/std/string.zc"
Vec__char__push((&self->vec), ((char)(val)));
    }

#line 135 "/usr/local/share/zenc/std/string.zc"
 else if ((val < 2048))     {

#line 136 "/usr/local/share/zenc/std/string.zc"
Vec__char__push((&self->vec), ((char)((192 | (val >> 6)))));

#line 137 "/usr/local/share/zenc/std/string.zc"
Vec__char__push((&self->vec), ((char)((128 | (val & 63)))));
    }

#line 138 "/usr/local/share/zenc/std/string.zc"
 else if ((val < 65536))     {

#line 139 "/usr/local/share/zenc/std/string.zc"
Vec__char__push((&self->vec), ((char)((224 | (val >> 12)))));

#line 140 "/usr/local/share/zenc/std/string.zc"
Vec__char__push((&self->vec), ((char)((128 | ((val >> 6) & 63)))));

#line 141 "/usr/local/share/zenc/std/string.zc"
Vec__char__push((&self->vec), ((char)((128 | (val & 63)))));
    }
 else     {

#line 143 "/usr/local/share/zenc/std/string.zc"
Vec__char__push((&self->vec), ((char)((240 | (val >> 18)))));

#line 144 "/usr/local/share/zenc/std/string.zc"
Vec__char__push((&self->vec), ((char)((128 | ((val >> 12) & 63)))));

#line 145 "/usr/local/share/zenc/std/string.zc"
Vec__char__push((&self->vec), ((char)((128 | ((val >> 6) & 63)))));

#line 146 "/usr/local/share/zenc/std/string.zc"
Vec__char__push((&self->vec), ((char)((128 | (val & 63)))));
    }

#line 148 "/usr/local/share/zenc/std/string.zc"
Vec__char__push((&self->vec), 0);
    }
}

#line 151 "/usr/local/share/zenc/std/string.zc"

void String__append_c_ptr(String* ptr, char* s)
{
    {

#line 152 "/usr/local/share/zenc/std/string.zc"
if ((ptr->vec.len > 0))     {

#line 153 "/usr/local/share/zenc/std/string.zc"
(ptr->vec.len = (ptr->vec.len - 1));
    }

#line 155 "/usr/local/share/zenc/std/string.zc"
    ZC_AUTO len = 
#line 155 "/usr/local/share/zenc/std/string.zc"
strlen(s);

#line 156 "/usr/local/share/zenc/std/string.zc"
for (int i = (int)(0); i < len; i = (i + 1))     {

#line 157 "/usr/local/share/zenc/std/string.zc"
Vec__char__push((&ptr->vec), s[i]);
    }

#line 159 "/usr/local/share/zenc/std/string.zc"
Vec__char__push((&ptr->vec), 0);
    }
}

#line 162 "/usr/local/share/zenc/std/string.zc"

String String__add(String* self, String* other)
{
    {

#line 163 "/usr/local/share/zenc/std/string.zc"
    int __z_drop_flag_new_s = 1; String new_s = 
#line 163 "/usr/local/share/zenc/std/string.zc"
String__from(String__c_str(self));

#line 164 "/usr/local/share/zenc/std/string.zc"
String__append((&new_s), other);

#line 166 "/usr/local/share/zenc/std/string.zc"
    char* d = new_s.vec.data;

#line 167 "/usr/local/share/zenc/std/string.zc"
    size_t l = new_s.vec.len;

#line 168 "/usr/local/share/zenc/std/string.zc"
    size_t c = new_s.vec.cap;

#line 169 "/usr/local/share/zenc/std/string.zc"
String__forget((&new_s));

#line 171 "/usr/local/share/zenc/std/string.zc"
    { String _z_ret = (struct String){.vec = (Vec__char){.data = d, .len = l, .cap = c}}; 
#line 163 "/usr/local/share/zenc/std/string.zc"
    if (__z_drop_flag_new_s) String__Drop__glue(&new_s);
return _z_ret; }

#line 163 "/usr/local/share/zenc/std/string.zc"
    if (__z_drop_flag_new_s) String__Drop__glue(&new_s);
    }
}

#line 174 "/usr/local/share/zenc/std/string.zc"

void String__add_assign(String* self, String* other)
{
    {

#line 175 "/usr/local/share/zenc/std/string.zc"
String__append(self, other);
    }
}

#line 178 "/usr/local/share/zenc/std/string.zc"

bool String__eq(String* self, String* other)
{
    {

#line 179 "/usr/local/share/zenc/std/string.zc"
    int zero = 0;

#line 180 "/usr/local/share/zenc/std/string.zc"
    return (
#line 180 "/usr/local/share/zenc/std/string.zc"
strcmp(String__c_str(self), String__c_str((&(*other)))) == zero);
    }
}

#line 183 "/usr/local/share/zenc/std/string.zc"

bool String__neq(String* self, String* other)
{
    {

#line 184 "/usr/local/share/zenc/std/string.zc"
    return (!
#line 184 "/usr/local/share/zenc/std/string.zc"
String__eq(self, other));
    }
}

#line 187 "/usr/local/share/zenc/std/string.zc"

int32_t String__compare(String* self, String* other)
{
    {

#line 188 "/usr/local/share/zenc/std/string.zc"
    return 
#line 188 "/usr/local/share/zenc/std/string.zc"
strcmp(String__c_str(self), String__c_str((&(*other))));
    }
}

#line 191 "/usr/local/share/zenc/std/string.zc"

bool String__lt(String* self, String* other)
{
    {

#line 192 "/usr/local/share/zenc/std/string.zc"
    return (
#line 192 "/usr/local/share/zenc/std/string.zc"
String__compare(self, other) < 0);
    }
}

#line 195 "/usr/local/share/zenc/std/string.zc"

bool String__gt(String* self, String* other)
{
    {

#line 196 "/usr/local/share/zenc/std/string.zc"
    return (
#line 196 "/usr/local/share/zenc/std/string.zc"
String__compare(self, other) > 0);
    }
}

#line 199 "/usr/local/share/zenc/std/string.zc"

bool String__le(String* self, String* other)
{
    {

#line 200 "/usr/local/share/zenc/std/string.zc"
    return (
#line 200 "/usr/local/share/zenc/std/string.zc"
String__compare(self, other) <= 0);
    }
}

#line 203 "/usr/local/share/zenc/std/string.zc"

bool String__ge(String* self, String* other)
{
    {

#line 204 "/usr/local/share/zenc/std/string.zc"
    return (
#line 204 "/usr/local/share/zenc/std/string.zc"
String__compare(self, other) >= 0);
    }
}

#line 207 "/usr/local/share/zenc/std/string.zc"

int32_t String__compare_ignore_case(String* self, String* other)
{
    {

#line 208 "/usr/local/share/zenc/std/string.zc"
    return 
#line 208 "/usr/local/share/zenc/std/string.zc"
strcasecmp(String__c_str(self), String__c_str((&(*other))));
    }
}

#line 211 "/usr/local/share/zenc/std/string.zc"

bool String__eq_ignore_case(String* self, String* other)
{
    {

#line 212 "/usr/local/share/zenc/std/string.zc"
    int32_t zero = 0;

#line 213 "/usr/local/share/zenc/std/string.zc"
    return (
#line 213 "/usr/local/share/zenc/std/string.zc"
String__compare_ignore_case(self, other) == zero);
    }
}

#line 216 "/usr/local/share/zenc/std/string.zc"

bool String__eq_str(String* self, char* s)
{
    {

#line 217 "/usr/local/share/zenc/std/string.zc"
    int zero = 0;

#line 218 "/usr/local/share/zenc/std/string.zc"
    return (
#line 218 "/usr/local/share/zenc/std/string.zc"
strcmp(String__c_str(self), s) == zero);
    }
}

#line 221 "/usr/local/share/zenc/std/string.zc"

size_t String__length(String* self)
{
    {

#line 222 "/usr/local/share/zenc/std/string.zc"
if ((self->vec.len == 0))     {

#line 222 "/usr/local/share/zenc/std/string.zc"
    return 0;
    }

#line 223 "/usr/local/share/zenc/std/string.zc"
    return (self->vec.len - 1);
    }
}

#line 226 "/usr/local/share/zenc/std/string.zc"

String String__substring(String* self, size_t start, size_t len)
{
    {

#line 227 "/usr/local/share/zenc/std/string.zc"
if (((start + len) > 
#line 227 "/usr/local/share/zenc/std/string.zc"
String__length(self)))     {

#line 228 "/usr/local/share/zenc/std/string.zc"
__zenc_panic("substring out of bounds");
    }

#line 230 "/usr/local/share/zenc/std/string.zc"
    int __z_drop_flag_v = 1; Vec__char v = 
#line 230 "/usr/local/share/zenc/std/string.zc"
Vec__char__new();

#line 231 "/usr/local/share/zenc/std/string.zc"
for (size_t i = (size_t)(0); i < len; i = (i + 1))     {

#line 232 "/usr/local/share/zenc/std/string.zc"
Vec__char__push((&v), Vec__char__get((&self->vec), (start + i)));
    }

#line 234 "/usr/local/share/zenc/std/string.zc"
Vec__char__push((&v), 0);

#line 236 "/usr/local/share/zenc/std/string.zc"
    char* d = v.data;

#line 237 "/usr/local/share/zenc/std/string.zc"
    size_t l = v.len;

#line 238 "/usr/local/share/zenc/std/string.zc"
    size_t c = v.cap;

#line 239 "/usr/local/share/zenc/std/string.zc"
Vec__char__forget((&v));

#line 241 "/usr/local/share/zenc/std/string.zc"
    { String _z_ret = (struct String){.vec = (Vec__char){.data = d, .len = l, .cap = c}}; 
#line 230 "/usr/local/share/zenc/std/string.zc"
    if (__z_drop_flag_v) Vec__char__Drop__glue(&v);
return _z_ret; }

#line 230 "/usr/local/share/zenc/std/string.zc"
    if (__z_drop_flag_v) Vec__char__Drop__glue(&v);
    }
}

#line 243 "/usr/local/share/zenc/std/string.zc"

bool String__contains_str(String* self, char* target)
{
    {

#line 244 "/usr/local/share/zenc/std/string.zc"
    return 
#line 244 "/usr/local/share/zenc/std/string.zc"
Option__size_t__is_some((Option__size_t[]){String__find_str(self, target)});
    }
}

#line 247 "/usr/local/share/zenc/std/string.zc"

Option__size_t String__find_str(String* self, char* target)
{
    {

#line 248 "/usr/local/share/zenc/std/string.zc"
    ZC_AUTO t_len = 
#line 248 "/usr/local/share/zenc/std/string.zc"
strlen(target);

#line 249 "/usr/local/share/zenc/std/string.zc"
if ((t_len == 0))     {

#line 249 "/usr/local/share/zenc/std/string.zc"
    return 
#line 249 "/usr/local/share/zenc/std/string.zc"
Option__size_t__Some(0);
    }

#line 250 "/usr/local/share/zenc/std/string.zc"
    size_t s_len = 
#line 250 "/usr/local/share/zenc/std/string.zc"
String__length(self);

#line 251 "/usr/local/share/zenc/std/string.zc"
if ((t_len > s_len))     {

#line 251 "/usr/local/share/zenc/std/string.zc"
    return 
#line 251 "/usr/local/share/zenc/std/string.zc"
Option__size_t__None();
    }

#line 253 "/usr/local/share/zenc/std/string.zc"
for (size_t i = (size_t)(0); i <= (s_len - t_len); i = (i + 1))     {

#line 254 "/usr/local/share/zenc/std/string.zc"
    bool is_match = true;

#line 255 "/usr/local/share/zenc/std/string.zc"
for (size_t k = (size_t)(0); k < t_len; k = (k + 1))     {

#line 256 "/usr/local/share/zenc/std/string.zc"
if ((
#line 256 "/usr/local/share/zenc/std/string.zc"
Vec__char__get((&self->vec), (i + k)) != target[k]))     {

#line 257 "/usr/local/share/zenc/std/string.zc"
(is_match = false);

#line 258 "/usr/local/share/zenc/std/string.zc"
break;
    }
    }

#line 261 "/usr/local/share/zenc/std/string.zc"
if (is_match)     {

#line 261 "/usr/local/share/zenc/std/string.zc"
    return 
#line 261 "/usr/local/share/zenc/std/string.zc"
Option__size_t__Some(i);
    }
    }

#line 263 "/usr/local/share/zenc/std/string.zc"
    return 
#line 263 "/usr/local/share/zenc/std/string.zc"
Option__size_t__None();
    }
}

#line 266 "/usr/local/share/zenc/std/string.zc"

Vec__size_t String__find_all_str(String* self, char* target)
{
    {

#line 267 "/usr/local/share/zenc/std/string.zc"
    int __z_drop_flag_indices = 1; Vec__size_t indices = 
#line 267 "/usr/local/share/zenc/std/string.zc"
Vec__size_t__new();

#line 268 "/usr/local/share/zenc/std/string.zc"
    ZC_AUTO t_len = 
#line 268 "/usr/local/share/zenc/std/string.zc"
strlen(target);

#line 269 "/usr/local/share/zenc/std/string.zc"
if ((t_len == 0))     {

#line 269 "/usr/local/share/zenc/std/string.zc"
    return ({ ZC_AUTO _z_ret_mv = indices; memset(&indices, 0, sizeof(_z_ret_mv)); __z_drop_flag_indices = 0; 
#line 267 "/usr/local/share/zenc/std/string.zc"
    if (__z_drop_flag_indices) Vec__size_t__Drop__glue(&indices);
_z_ret_mv; });
    }

#line 270 "/usr/local/share/zenc/std/string.zc"
    size_t s_len = 
#line 270 "/usr/local/share/zenc/std/string.zc"
String__length(self);

#line 271 "/usr/local/share/zenc/std/string.zc"
if ((t_len > s_len))     {

#line 271 "/usr/local/share/zenc/std/string.zc"
    return ({ ZC_AUTO _z_ret_mv = indices; memset(&indices, 0, sizeof(_z_ret_mv)); __z_drop_flag_indices = 0; 
#line 267 "/usr/local/share/zenc/std/string.zc"
    if (__z_drop_flag_indices) Vec__size_t__Drop__glue(&indices);
_z_ret_mv; });
    }

#line 273 "/usr/local/share/zenc/std/string.zc"
for (size_t i = (size_t)(0); i <= (s_len - t_len); i = (i + 1))     {

#line 274 "/usr/local/share/zenc/std/string.zc"
    bool is_match = true;

#line 275 "/usr/local/share/zenc/std/string.zc"
for (size_t k = (size_t)(0); k < t_len; k = (k + 1))     {

#line 276 "/usr/local/share/zenc/std/string.zc"
if ((
#line 276 "/usr/local/share/zenc/std/string.zc"
Vec__char__get((&self->vec), (i + k)) != target[k]))     {

#line 277 "/usr/local/share/zenc/std/string.zc"
(is_match = false);

#line 278 "/usr/local/share/zenc/std/string.zc"
break;
    }
    }

#line 281 "/usr/local/share/zenc/std/string.zc"
if (is_match)     {

#line 282 "/usr/local/share/zenc/std/string.zc"
Vec__size_t__push((&indices), i);
    }
    }

#line 286 "/usr/local/share/zenc/std/string.zc"
    return ({ ZC_AUTO _z_ret_mv = indices; memset(&indices, 0, sizeof(_z_ret_mv)); __z_drop_flag_indices = 0; 
#line 267 "/usr/local/share/zenc/std/string.zc"
    if (__z_drop_flag_indices) Vec__size_t__Drop__glue(&indices);
_z_ret_mv; });

#line 267 "/usr/local/share/zenc/std/string.zc"
    if (__z_drop_flag_indices) Vec__size_t__Drop__glue(&indices);
    }
}

#line 289 "/usr/local/share/zenc/std/string.zc"

String String__to_lowercase(String* self)
{
    {

#line 290 "/usr/local/share/zenc/std/string.zc"
    size_t len = 
#line 290 "/usr/local/share/zenc/std/string.zc"
String__length(self);

#line 291 "/usr/local/share/zenc/std/string.zc"
    int __z_drop_flag_v = 1; Vec__char v = 
#line 291 "/usr/local/share/zenc/std/string.zc"
Vec__char__new();

#line 292 "/usr/local/share/zenc/std/string.zc"
for (size_t i = (size_t)(0); i < len; i = (i + 1))     {

#line 293 "/usr/local/share/zenc/std/string.zc"
    char c = 
#line 293 "/usr/local/share/zenc/std/string.zc"
Vec__char__get((&self->vec), i);

#line 294 "/usr/local/share/zenc/std/string.zc"
if (((c >= 'A') && (c <= 'Z')))     {

#line 295 "/usr/local/share/zenc/std/string.zc"
Vec__char__push((&v), ((char)((((int32_t)(c)) + 32))));
    }
 else     {

#line 297 "/usr/local/share/zenc/std/string.zc"
Vec__char__push((&v), c);
    }
    }

#line 300 "/usr/local/share/zenc/std/string.zc"
Vec__char__push((&v), 0);

#line 301 "/usr/local/share/zenc/std/string.zc"
    char* d = v.data;

#line 302 "/usr/local/share/zenc/std/string.zc"
    size_t l = v.len;

#line 303 "/usr/local/share/zenc/std/string.zc"
    size_t c_cap = v.cap;

#line 304 "/usr/local/share/zenc/std/string.zc"
Vec__char__forget((&v));

#line 305 "/usr/local/share/zenc/std/string.zc"
    { String _z_ret = (struct String){.vec = (Vec__char){.data = d, .len = l, .cap = c_cap}}; 
#line 291 "/usr/local/share/zenc/std/string.zc"
    if (__z_drop_flag_v) Vec__char__Drop__glue(&v);
return _z_ret; }

#line 291 "/usr/local/share/zenc/std/string.zc"
    if (__z_drop_flag_v) Vec__char__Drop__glue(&v);
    }
}

#line 308 "/usr/local/share/zenc/std/string.zc"

String String__pad_right(String* self, size_t target_len, char pad_char)
{
    {

#line 309 "/usr/local/share/zenc/std/string.zc"
    size_t current_len = 
#line 309 "/usr/local/share/zenc/std/string.zc"
String__length(self);

#line 310 "/usr/local/share/zenc/std/string.zc"
if ((current_len >= target_len))     {

#line 311 "/usr/local/share/zenc/std/string.zc"
    return 
#line 311 "/usr/local/share/zenc/std/string.zc"
String__from(String__c_str(self));
    }

#line 314 "/usr/local/share/zenc/std/string.zc"
    int __z_drop_flag_v = 1; Vec__char v = 
#line 314 "/usr/local/share/zenc/std/string.zc"
Vec__char__new();

#line 315 "/usr/local/share/zenc/std/string.zc"
for (size_t i = (size_t)(0); i < current_len; i = (i + 1))     {

#line 316 "/usr/local/share/zenc/std/string.zc"
Vec__char__push((&v), Vec__char__get((&self->vec), i));
    }

#line 318 "/usr/local/share/zenc/std/string.zc"
for (size_t i = (size_t)(current_len); i < target_len; i = (i + 1))     {

#line 319 "/usr/local/share/zenc/std/string.zc"
Vec__char__push((&v), pad_char);
    }

#line 321 "/usr/local/share/zenc/std/string.zc"
Vec__char__push((&v), 0);

#line 323 "/usr/local/share/zenc/std/string.zc"
    char* d = v.data;

#line 324 "/usr/local/share/zenc/std/string.zc"
    size_t l = v.len;

#line 325 "/usr/local/share/zenc/std/string.zc"
    size_t c_cap = v.cap;

#line 326 "/usr/local/share/zenc/std/string.zc"
Vec__char__forget((&v));

#line 327 "/usr/local/share/zenc/std/string.zc"
    { String _z_ret = (struct String){.vec = (Vec__char){.data = d, .len = l, .cap = c_cap}}; 
#line 314 "/usr/local/share/zenc/std/string.zc"
    if (__z_drop_flag_v) Vec__char__Drop__glue(&v);
return _z_ret; }

#line 314 "/usr/local/share/zenc/std/string.zc"
    if (__z_drop_flag_v) Vec__char__Drop__glue(&v);
    }
}

#line 330 "/usr/local/share/zenc/std/string.zc"

String String__pad_left(String* self, size_t target_len, char pad_char)
{
    {

#line 331 "/usr/local/share/zenc/std/string.zc"
    size_t current_len = 
#line 331 "/usr/local/share/zenc/std/string.zc"
String__length(self);

#line 332 "/usr/local/share/zenc/std/string.zc"
if ((current_len >= target_len))     {

#line 333 "/usr/local/share/zenc/std/string.zc"
    return 
#line 333 "/usr/local/share/zenc/std/string.zc"
String__from(String__c_str(self));
    }

#line 336 "/usr/local/share/zenc/std/string.zc"
    int __z_drop_flag_v = 1; Vec__char v = 
#line 336 "/usr/local/share/zenc/std/string.zc"
Vec__char__new();

#line 337 "/usr/local/share/zenc/std/string.zc"
    size_t diff = (target_len - current_len);

#line 338 "/usr/local/share/zenc/std/string.zc"
for (size_t i = (size_t)(0); i < diff; i = (i + 1))     {

#line 339 "/usr/local/share/zenc/std/string.zc"
Vec__char__push((&v), pad_char);
    }

#line 341 "/usr/local/share/zenc/std/string.zc"
for (size_t i = (size_t)(0); i < current_len; i = (i + 1))     {

#line 342 "/usr/local/share/zenc/std/string.zc"
Vec__char__push((&v), Vec__char__get((&self->vec), i));
    }

#line 344 "/usr/local/share/zenc/std/string.zc"
Vec__char__push((&v), 0);

#line 346 "/usr/local/share/zenc/std/string.zc"
    char* d = v.data;

#line 347 "/usr/local/share/zenc/std/string.zc"
    size_t l = v.len;

#line 348 "/usr/local/share/zenc/std/string.zc"
    size_t c_cap = v.cap;

#line 349 "/usr/local/share/zenc/std/string.zc"
Vec__char__forget((&v));

#line 350 "/usr/local/share/zenc/std/string.zc"
    { String _z_ret = (struct String){.vec = (Vec__char){.data = d, .len = l, .cap = c_cap}}; 
#line 336 "/usr/local/share/zenc/std/string.zc"
    if (__z_drop_flag_v) Vec__char__Drop__glue(&v);
return _z_ret; }

#line 336 "/usr/local/share/zenc/std/string.zc"
    if (__z_drop_flag_v) Vec__char__Drop__glue(&v);
    }
}

#line 353 "/usr/local/share/zenc/std/string.zc"

String String__to_uppercase(String* self)
{
    {

#line 354 "/usr/local/share/zenc/std/string.zc"
    size_t len = 
#line 354 "/usr/local/share/zenc/std/string.zc"
String__length(self);

#line 355 "/usr/local/share/zenc/std/string.zc"
    int __z_drop_flag_v = 1; Vec__char v = 
#line 355 "/usr/local/share/zenc/std/string.zc"
Vec__char__new();

#line 356 "/usr/local/share/zenc/std/string.zc"
for (size_t i = (size_t)(0); i < len; i = (i + 1))     {

#line 357 "/usr/local/share/zenc/std/string.zc"
    char c = 
#line 357 "/usr/local/share/zenc/std/string.zc"
Vec__char__get((&self->vec), i);

#line 358 "/usr/local/share/zenc/std/string.zc"
if (((c >= 'a') && (c <= 'z')))     {

#line 359 "/usr/local/share/zenc/std/string.zc"
Vec__char__push((&v), ((char)((((int32_t)(c)) - 32))));
    }
 else     {

#line 361 "/usr/local/share/zenc/std/string.zc"
Vec__char__push((&v), c);
    }
    }

#line 364 "/usr/local/share/zenc/std/string.zc"
Vec__char__push((&v), 0);

#line 365 "/usr/local/share/zenc/std/string.zc"
    char* d = v.data;

#line 366 "/usr/local/share/zenc/std/string.zc"
    size_t l = v.len;

#line 367 "/usr/local/share/zenc/std/string.zc"
    size_t c_cap = v.cap;

#line 368 "/usr/local/share/zenc/std/string.zc"
Vec__char__forget((&v));

#line 369 "/usr/local/share/zenc/std/string.zc"
    { String _z_ret = (struct String){.vec = (Vec__char){.data = d, .len = l, .cap = c_cap}}; 
#line 355 "/usr/local/share/zenc/std/string.zc"
    if (__z_drop_flag_v) Vec__char__Drop__glue(&v);
return _z_ret; }

#line 355 "/usr/local/share/zenc/std/string.zc"
    if (__z_drop_flag_v) Vec__char__Drop__glue(&v);
    }
}

#line 372 "/usr/local/share/zenc/std/string.zc"

Option__size_t String__find(String* self, char target)
{
    {

#line 373 "/usr/local/share/zenc/std/string.zc"
    size_t len = 
#line 373 "/usr/local/share/zenc/std/string.zc"
String__length(self);

#line 374 "/usr/local/share/zenc/std/string.zc"
for (size_t i = (size_t)(0); i < len; i = (i + 1))     {

#line 375 "/usr/local/share/zenc/std/string.zc"
if ((
#line 375 "/usr/local/share/zenc/std/string.zc"
Vec__char__get((&self->vec), i) == target))     {

#line 376 "/usr/local/share/zenc/std/string.zc"
    return 
#line 376 "/usr/local/share/zenc/std/string.zc"
Option__size_t__Some(i);
    }
    }

#line 379 "/usr/local/share/zenc/std/string.zc"
    return 
#line 379 "/usr/local/share/zenc/std/string.zc"
Option__size_t__None();
    }
}

#line 382 "/usr/local/share/zenc/std/string.zc"

void String__print(String* self)
{
    {

#line 383 "/usr/local/share/zenc/std/string.zc"
printf("%s", String__c_str(self));

#line 384 "/usr/local/share/zenc/std/string.zc"
fflush(stdout);
    }
}

#line 387 "/usr/local/share/zenc/std/string.zc"

void String__println(String* self)
{
    {

#line 388 "/usr/local/share/zenc/std/string.zc"
printf("%s\n", String__c_str(self));
    }
}

#line 391 "/usr/local/share/zenc/std/string.zc"

bool String__is_empty(String* self)
{
    {

#line 392 "/usr/local/share/zenc/std/string.zc"
    return (
#line 392 "/usr/local/share/zenc/std/string.zc"
String__length(self) == 0);
    }
}

#line 395 "/usr/local/share/zenc/std/string.zc"

bool String__contains(String* self, char target)
{
    {

#line 396 "/usr/local/share/zenc/std/string.zc"
    return 
#line 396 "/usr/local/share/zenc/std/string.zc"
Option__size_t__is_some((__typeof__((String__find(self, target)))[]){String__find(self, target)});
    }
}

#line 399 "/usr/local/share/zenc/std/string.zc"

bool String__starts_with(String* self, char* prefix)
{
    {

#line 400 "/usr/local/share/zenc/std/string.zc"
    ZC_AUTO plen = 
#line 400 "/usr/local/share/zenc/std/string.zc"
strlen(prefix);

#line 401 "/usr/local/share/zenc/std/string.zc"
if ((plen > 
#line 401 "/usr/local/share/zenc/std/string.zc"
String__length(self)))     {

#line 401 "/usr/local/share/zenc/std/string.zc"
    return false;
    }

#line 402 "/usr/local/share/zenc/std/string.zc"
    int zero = 0;

#line 403 "/usr/local/share/zenc/std/string.zc"
    return (
#line 403 "/usr/local/share/zenc/std/string.zc"
strncmp(String__c_str(self), prefix, plen) == zero);
    }
}

#line 406 "/usr/local/share/zenc/std/string.zc"

bool String__ends_with(String* self, char* suffix)
{
    {

#line 407 "/usr/local/share/zenc/std/string.zc"
    ZC_AUTO slen = 
#line 407 "/usr/local/share/zenc/std/string.zc"
strlen(suffix);

#line 408 "/usr/local/share/zenc/std/string.zc"
    size_t len = 
#line 408 "/usr/local/share/zenc/std/string.zc"
String__length(self);

#line 409 "/usr/local/share/zenc/std/string.zc"
if ((slen > len))     {

#line 409 "/usr/local/share/zenc/std/string.zc"
    return false;
    }

#line 410 "/usr/local/share/zenc/std/string.zc"
    int32_t offset = ((int32_t)((len - slen)));

#line 411 "/usr/local/share/zenc/std/string.zc"
    int zero = 0;

#line 412 "/usr/local/share/zenc/std/string.zc"
    return (
#line 412 "/usr/local/share/zenc/std/string.zc"
strcmp((String__c_str(self) + offset), suffix) == zero);
    }
}

#line 415 "/usr/local/share/zenc/std/string.zc"

void String__reserve(String* self, size_t cap)
{
    {

#line 416 "/usr/local/share/zenc/std/string.zc"
Vec__char__grow_to_fit((&self->vec), (cap + 1));
    }
}

#line 419 "/usr/local/share/zenc/std/string.zc"

void String__free(String* self)
{
    {

#line 420 "/usr/local/share/zenc/std/string.zc"
Vec__char__free((&self->vec));
    }
}

#line 423 "/usr/local/share/zenc/std/string.zc"

size_t String__utf8_seq_len(char first_byte)
{
    {

#line 424 "/usr/local/share/zenc/std/string.zc"
    int32_t b = ((int32_t)(first_byte));

#line 425 "/usr/local/share/zenc/std/string.zc"
if (((b & 128) == 0))     {

#line 425 "/usr/local/share/zenc/std/string.zc"
    return 1;
    }

#line 426 "/usr/local/share/zenc/std/string.zc"
if (((b & 224) == 192))     {

#line 426 "/usr/local/share/zenc/std/string.zc"
    return 2;
    }

#line 427 "/usr/local/share/zenc/std/string.zc"
if (((b & 240) == 224))     {

#line 427 "/usr/local/share/zenc/std/string.zc"
    return 3;
    }

#line 428 "/usr/local/share/zenc/std/string.zc"
if (((b & 248) == 240))     {

#line 428 "/usr/local/share/zenc/std/string.zc"
    return 4;
    }

#line 429 "/usr/local/share/zenc/std/string.zc"
    return 1;
    }
}

#line 432 "/usr/local/share/zenc/std/string.zc"

size_t String__utf8_len(String* self)
{
    {

#line 433 "/usr/local/share/zenc/std/string.zc"
    size_t count = 0;

#line 434 "/usr/local/share/zenc/std/string.zc"
    size_t i = 0;

#line 435 "/usr/local/share/zenc/std/string.zc"
    size_t len = 
#line 435 "/usr/local/share/zenc/std/string.zc"
String__length(self);

#line 436 "/usr/local/share/zenc/std/string.zc"
while ((i < len))     {

#line 437 "/usr/local/share/zenc/std/string.zc"
    char c = 
#line 437 "/usr/local/share/zenc/std/string.zc"
Vec__char__get((&self->vec), i);

#line 438 "/usr/local/share/zenc/std/string.zc"
(i = (i + 
#line 438 "/usr/local/share/zenc/std/string.zc"
String__utf8_seq_len(c)));

#line 439 "/usr/local/share/zenc/std/string.zc"
(count = (count + 1));
    }

#line 441 "/usr/local/share/zenc/std/string.zc"
    return count;
    }
}

#line 444 "/usr/local/share/zenc/std/string.zc"

String String__utf8_at(String* self, size_t idx)
{
    {

#line 445 "/usr/local/share/zenc/std/string.zc"
    size_t count = 0;

#line 446 "/usr/local/share/zenc/std/string.zc"
    size_t i = 0;

#line 447 "/usr/local/share/zenc/std/string.zc"
    size_t len = 
#line 447 "/usr/local/share/zenc/std/string.zc"
String__length(self);

#line 448 "/usr/local/share/zenc/std/string.zc"
while ((i < len))     {

#line 449 "/usr/local/share/zenc/std/string.zc"
    char c = 
#line 449 "/usr/local/share/zenc/std/string.zc"
Vec__char__get((&self->vec), i);

#line 450 "/usr/local/share/zenc/std/string.zc"
    size_t seq = 
#line 450 "/usr/local/share/zenc/std/string.zc"
String__utf8_seq_len(c);

#line 452 "/usr/local/share/zenc/std/string.zc"
if ((count == idx))     {

#line 453 "/usr/local/share/zenc/std/string.zc"
    return 
#line 453 "/usr/local/share/zenc/std/string.zc"
String__substring(self, i, seq);
    }

#line 456 "/usr/local/share/zenc/std/string.zc"
(i = (i + seq));

#line 457 "/usr/local/share/zenc/std/string.zc"
(count = (count + 1));
    }

#line 459 "/usr/local/share/zenc/std/string.zc"
    return 
#line 459 "/usr/local/share/zenc/std/string.zc"
String__new("");
    }
}

#line 462 "/usr/local/share/zenc/std/string.zc"

int32_t String__utf8_get(String* self, size_t idx)
{
    {

#line 463 "/usr/local/share/zenc/std/string.zc"
    size_t count = 0;

#line 464 "/usr/local/share/zenc/std/string.zc"
    size_t i = 0;

#line 465 "/usr/local/share/zenc/std/string.zc"
    size_t len = 
#line 465 "/usr/local/share/zenc/std/string.zc"
String__length(self);

#line 466 "/usr/local/share/zenc/std/string.zc"
while ((i < len))     {

#line 467 "/usr/local/share/zenc/std/string.zc"
    uint8_t c = ((uint8_t)(
#line 467 "/usr/local/share/zenc/std/string.zc"
Vec__char__get((&self->vec), i)));

#line 468 "/usr/local/share/zenc/std/string.zc"
    size_t seq = 
#line 468 "/usr/local/share/zenc/std/string.zc"
String__utf8_seq_len(((char)(c)));

#line 470 "/usr/local/share/zenc/std/string.zc"
if ((count == idx))     {

#line 471 "/usr/local/share/zenc/std/string.zc"
if ((seq == 1))     {

#line 471 "/usr/local/share/zenc/std/string.zc"
    return ((int32_t)(c));
    }

#line 472 "/usr/local/share/zenc/std/string.zc"
if ((seq == 2))     {

#line 472 "/usr/local/share/zenc/std/string.zc"
    return ((int32_t)(((((int32_t)((c & 31))) << 6) | (((int32_t)(((uint8_t)(
#line 472 "/usr/local/share/zenc/std/string.zc"
Vec__char__get((&self->vec), (i + 1)))))) & 63))));
    }

#line 473 "/usr/local/share/zenc/std/string.zc"
if ((seq == 3))     {

#line 473 "/usr/local/share/zenc/std/string.zc"
    return ((int32_t)((((((int32_t)((c & 15))) << 12) | ((((int32_t)(((uint8_t)(
#line 473 "/usr/local/share/zenc/std/string.zc"
Vec__char__get((&self->vec), (i + 1)))))) & 63) << 6)) | (((int32_t)(((uint8_t)(Vec__char__get((&self->vec), (i + 2)))))) & 63))));
    }

#line 474 "/usr/local/share/zenc/std/string.zc"
if ((seq == 4))     {

#line 474 "/usr/local/share/zenc/std/string.zc"
    return ((int32_t)(((((((int32_t)((c & 7))) << 18) | ((((int32_t)(((uint8_t)(
#line 474 "/usr/local/share/zenc/std/string.zc"
Vec__char__get((&self->vec), (i + 1)))))) & 63) << 12)) | ((((int32_t)(((uint8_t)(Vec__char__get((&self->vec), (i + 2)))))) & 63) << 6)) | (((int32_t)(((uint8_t)(Vec__char__get((&self->vec), (i + 3)))))) & 63))));
    }
    }

#line 477 "/usr/local/share/zenc/std/string.zc"
(i = (i + seq));

#line 478 "/usr/local/share/zenc/std/string.zc"
(count = (count + 1));
    }

#line 480 "/usr/local/share/zenc/std/string.zc"
    return ((int32_t)(0));
    }
}

#line 483 "/usr/local/share/zenc/std/string.zc"

Vec__int32_t String__runes(String* self)
{
    {

#line 484 "/usr/local/share/zenc/std/string.zc"
    int __z_drop_flag_v = 1; Vec__int32_t v = 
#line 484 "/usr/local/share/zenc/std/string.zc"
Vec__int32_t__new();

#line 485 "/usr/local/share/zenc/std/string.zc"
    size_t i = 0;

#line 486 "/usr/local/share/zenc/std/string.zc"
    size_t len = 
#line 486 "/usr/local/share/zenc/std/string.zc"
String__length(self);

#line 487 "/usr/local/share/zenc/std/string.zc"
while ((i < len))     {

#line 488 "/usr/local/share/zenc/std/string.zc"
    uint8_t c = ((uint8_t)(
#line 488 "/usr/local/share/zenc/std/string.zc"
Vec__char__get((&self->vec), i)));

#line 489 "/usr/local/share/zenc/std/string.zc"
    size_t seq = 
#line 489 "/usr/local/share/zenc/std/string.zc"
String__utf8_seq_len(((char)(c)));

#line 490 "/usr/local/share/zenc/std/string.zc"
    int32_t val = 0;

#line 491 "/usr/local/share/zenc/std/string.zc"
if ((seq == 1))     {

#line 492 "/usr/local/share/zenc/std/string.zc"
(val = ((int32_t)(c)));
    }

#line 493 "/usr/local/share/zenc/std/string.zc"
 else if ((seq == 2))     {

#line 494 "/usr/local/share/zenc/std/string.zc"
(val = ((int32_t)(((((int32_t)((c & 31))) << 6) | (((int32_t)(((uint8_t)(
#line 494 "/usr/local/share/zenc/std/string.zc"
Vec__char__get((&self->vec), (i + 1)))))) & 63)))));
    }

#line 495 "/usr/local/share/zenc/std/string.zc"
 else if ((seq == 3))     {

#line 496 "/usr/local/share/zenc/std/string.zc"
(val = ((int32_t)((((((int32_t)((c & 15))) << 12) | ((((int32_t)(((uint8_t)(
#line 496 "/usr/local/share/zenc/std/string.zc"
Vec__char__get((&self->vec), (i + 1)))))) & 63) << 6)) | (((int32_t)(((uint8_t)(Vec__char__get((&self->vec), (i + 2)))))) & 63)))));
    }

#line 497 "/usr/local/share/zenc/std/string.zc"
 else if ((seq == 4))     {

#line 498 "/usr/local/share/zenc/std/string.zc"
(val = ((int32_t)(((((((int32_t)((c & 7))) << 18) | ((((int32_t)(((uint8_t)(
#line 498 "/usr/local/share/zenc/std/string.zc"
Vec__char__get((&self->vec), (i + 1)))))) & 63) << 12)) | ((((int32_t)(((uint8_t)(Vec__char__get((&self->vec), (i + 2)))))) & 63) << 6)) | (((int32_t)(((uint8_t)(Vec__char__get((&self->vec), (i + 3)))))) & 63)))));
    }

#line 500 "/usr/local/share/zenc/std/string.zc"
Vec__int32_t__push((&v), val);

#line 501 "/usr/local/share/zenc/std/string.zc"
(i = (i + seq));
    }

#line 503 "/usr/local/share/zenc/std/string.zc"
    return ({ ZC_AUTO _z_ret_mv = v; memset(&v, 0, sizeof(_z_ret_mv)); __z_drop_flag_v = 0; 
#line 484 "/usr/local/share/zenc/std/string.zc"
    if (__z_drop_flag_v) Vec__int32_t__Drop__glue(&v);
_z_ret_mv; });

#line 484 "/usr/local/share/zenc/std/string.zc"
    if (__z_drop_flag_v) Vec__int32_t__Drop__glue(&v);
    }
}

#line 506 "/usr/local/share/zenc/std/string.zc"

StringCharsIter String__iterator(String* self)
{
    {

#line 507 "/usr/local/share/zenc/std/string.zc"
    return 
#line 507 "/usr/local/share/zenc/std/string.zc"
String__chars(self);
    }
}

#line 510 "/usr/local/share/zenc/std/string.zc"

StringCharsIter String__chars(String* self)
{
    {

#line 511 "/usr/local/share/zenc/std/string.zc"
    return (struct StringCharsIter){.data = 
#line 512 "/usr/local/share/zenc/std/string.zc"
String__c_str(self), .len = 
#line 513 "/usr/local/share/zenc/std/string.zc"
String__length(self)};
    }
}

#line 518 "/usr/local/share/zenc/std/string.zc"

String String__from_runes_vec(Vec__int32_t runes)
{

#line 518 "/usr/local/share/zenc/std/string.zc"
    int __z_drop_flag_runes = 1;
    {

#line 519 "/usr/local/share/zenc/std/string.zc"
    int __z_drop_flag_s = 1; String s = 
#line 519 "/usr/local/share/zenc/std/string.zc"
String__new("");

#line 520 "/usr/local/share/zenc/std/string.zc"
for (size_t i = (size_t)(0); i < runes.len; i = (i + 1))     {

#line 521 "/usr/local/share/zenc/std/string.zc"
String__push_rune((&s), Vec__int32_t__get((&runes), i));
    }

#line 523 "/usr/local/share/zenc/std/string.zc"
    return ({ ZC_AUTO _z_ret_mv = s; memset(&s, 0, sizeof(_z_ret_mv)); __z_drop_flag_s = 0; 
#line 519 "/usr/local/share/zenc/std/string.zc"
    if (__z_drop_flag_s) String__Drop__glue(&s);

#line 518 "/usr/local/share/zenc/std/string.zc"
    if (__z_drop_flag_runes) Vec__int32_t__Drop__glue(&runes);
_z_ret_mv; });

#line 519 "/usr/local/share/zenc/std/string.zc"
    if (__z_drop_flag_s) String__Drop__glue(&s);
    }

#line 518 "/usr/local/share/zenc/std/string.zc"
    if (__z_drop_flag_runes) Vec__int32_t__Drop__glue(&runes);
}

#line 526 "/usr/local/share/zenc/std/string.zc"

void String__insert_rune(String* self, size_t idx, int32_t r)
{
    {

#line 527 "/usr/local/share/zenc/std/string.zc"
    size_t i = 0;

#line 528 "/usr/local/share/zenc/std/string.zc"
    size_t count = 0;

#line 529 "/usr/local/share/zenc/std/string.zc"
    size_t len = 
#line 529 "/usr/local/share/zenc/std/string.zc"
String__length(self);

#line 530 "/usr/local/share/zenc/std/string.zc"
while (((i < len) && (count < idx)))     {

#line 531 "/usr/local/share/zenc/std/string.zc"
(i = (i + 
#line 531 "/usr/local/share/zenc/std/string.zc"
String__utf8_seq_len(Vec__char__get((&self->vec), i))));

#line 532 "/usr/local/share/zenc/std/string.zc"
(count = (count + 1));
    }

#line 535 "/usr/local/share/zenc/std/string.zc"
    uint32_t val = ((uint32_t)(r));

#line 536 "/usr/local/share/zenc/std/string.zc"
if ((val < 128))     {

#line 537 "/usr/local/share/zenc/std/string.zc"
Vec__char__insert((&self->vec), i, ((char)(val)));
    }

#line 538 "/usr/local/share/zenc/std/string.zc"
 else if ((val < 2048))     {

#line 539 "/usr/local/share/zenc/std/string.zc"
Vec__char__insert((&self->vec), i, ((char)((192 | (val >> 6)))));

#line 540 "/usr/local/share/zenc/std/string.zc"
Vec__char__insert((&self->vec), (i + 1), ((char)((128 | (val & 63)))));
    }

#line 541 "/usr/local/share/zenc/std/string.zc"
 else if ((val < 65536))     {

#line 542 "/usr/local/share/zenc/std/string.zc"
Vec__char__insert((&self->vec), i, ((char)((224 | (val >> 12)))));

#line 543 "/usr/local/share/zenc/std/string.zc"
Vec__char__insert((&self->vec), (i + 1), ((char)((128 | ((val >> 6) & 63)))));

#line 544 "/usr/local/share/zenc/std/string.zc"
Vec__char__insert((&self->vec), (i + 2), ((char)((128 | (val & 63)))));
    }
 else     {

#line 546 "/usr/local/share/zenc/std/string.zc"
Vec__char__insert((&self->vec), i, ((char)((240 | (val >> 18)))));

#line 547 "/usr/local/share/zenc/std/string.zc"
Vec__char__insert((&self->vec), (i + 1), ((char)((128 | ((val >> 12) & 63)))));

#line 548 "/usr/local/share/zenc/std/string.zc"
Vec__char__insert((&self->vec), (i + 2), ((char)((128 | ((val >> 6) & 63)))));

#line 549 "/usr/local/share/zenc/std/string.zc"
Vec__char__insert((&self->vec), (i + 3), ((char)((128 | (val & 63)))));
    }
    }
}

#line 553 "/usr/local/share/zenc/std/string.zc"

int32_t String__remove_rune_at(String* self, size_t idx)
{
    {

#line 554 "/usr/local/share/zenc/std/string.zc"
    size_t i = 0;

#line 555 "/usr/local/share/zenc/std/string.zc"
    size_t count = 0;

#line 556 "/usr/local/share/zenc/std/string.zc"
    size_t len = 
#line 556 "/usr/local/share/zenc/std/string.zc"
String__length(self);

#line 557 "/usr/local/share/zenc/std/string.zc"
while (((i < len) && (count < idx)))     {

#line 558 "/usr/local/share/zenc/std/string.zc"
(i = (i + 
#line 558 "/usr/local/share/zenc/std/string.zc"
String__utf8_seq_len(Vec__char__get((&self->vec), i))));

#line 559 "/usr/local/share/zenc/std/string.zc"
(count = (count + 1));
    }

#line 562 "/usr/local/share/zenc/std/string.zc"
if ((i >= len))     {

#line 562 "/usr/local/share/zenc/std/string.zc"
    return ((int32_t)(0));
    }

#line 564 "/usr/local/share/zenc/std/string.zc"
    uint8_t c = ((uint8_t)(
#line 564 "/usr/local/share/zenc/std/string.zc"
Vec__char__get((&self->vec), i)));

#line 565 "/usr/local/share/zenc/std/string.zc"
    size_t seq = 
#line 565 "/usr/local/share/zenc/std/string.zc"
String__utf8_seq_len(((char)(c)));

#line 566 "/usr/local/share/zenc/std/string.zc"
    int32_t val = 0;

#line 567 "/usr/local/share/zenc/std/string.zc"
if ((seq == 1))     {

#line 567 "/usr/local/share/zenc/std/string.zc"
(val = ((int32_t)(c)));
    }

#line 568 "/usr/local/share/zenc/std/string.zc"
 else if ((seq == 2))     {

#line 568 "/usr/local/share/zenc/std/string.zc"
(val = ((int32_t)(((((int32_t)((c & 31))) << 6) | (((int32_t)(((uint8_t)(
#line 568 "/usr/local/share/zenc/std/string.zc"
Vec__char__get((&self->vec), (i + 1)))))) & 63)))));
    }

#line 569 "/usr/local/share/zenc/std/string.zc"
 else if ((seq == 3))     {

#line 569 "/usr/local/share/zenc/std/string.zc"
(val = ((int32_t)((((((int32_t)((c & 15))) << 12) | ((((int32_t)(((uint8_t)(
#line 569 "/usr/local/share/zenc/std/string.zc"
Vec__char__get((&self->vec), (i + 1)))))) & 63) << 6)) | (((int32_t)(((uint8_t)(Vec__char__get((&self->vec), (i + 2)))))) & 63)))));
    }

#line 570 "/usr/local/share/zenc/std/string.zc"
 else if ((seq == 4))     {

#line 570 "/usr/local/share/zenc/std/string.zc"
(val = ((int32_t)(((((((int32_t)((c & 7))) << 18) | ((((int32_t)(((uint8_t)(
#line 570 "/usr/local/share/zenc/std/string.zc"
Vec__char__get((&self->vec), (i + 1)))))) & 63) << 12)) | ((((int32_t)(((uint8_t)(Vec__char__get((&self->vec), (i + 2)))))) & 63) << 6)) | (((int32_t)(((uint8_t)(Vec__char__get((&self->vec), (i + 3)))))) & 63)))));
    }

#line 572 "/usr/local/share/zenc/std/string.zc"
for (size_t j = (size_t)(0); j < seq; j = (j + 1))     {

#line 573 "/usr/local/share/zenc/std/string.zc"
Vec__char__remove((&self->vec), i);
    }

#line 575 "/usr/local/share/zenc/std/string.zc"
    return val;
    }
}

#line 578 "/usr/local/share/zenc/std/string.zc"

String String__utf8_substr(String* self, size_t start_idx, size_t num_chars)
{
    {

#line 579 "/usr/local/share/zenc/std/string.zc"
if ((num_chars == 0))     {

#line 579 "/usr/local/share/zenc/std/string.zc"
    return 
#line 579 "/usr/local/share/zenc/std/string.zc"
String__new("");
    }

#line 581 "/usr/local/share/zenc/std/string.zc"
    size_t byte_start = 0;

#line 582 "/usr/local/share/zenc/std/string.zc"
    size_t byte_len = 0;

#line 584 "/usr/local/share/zenc/std/string.zc"
    size_t count = 0;

#line 585 "/usr/local/share/zenc/std/string.zc"
    size_t i = 0;

#line 586 "/usr/local/share/zenc/std/string.zc"
    size_t len = 
#line 586 "/usr/local/share/zenc/std/string.zc"
String__length(self);

#line 587 "/usr/local/share/zenc/std/string.zc"
    bool found_start = false;

#line 589 "/usr/local/share/zenc/std/string.zc"
while ((i < len))     {

#line 591 "/usr/local/share/zenc/std/string.zc"
if (((!found_start) && (count == start_idx)))     {

#line 592 "/usr/local/share/zenc/std/string.zc"
(byte_start = i);

#line 593 "/usr/local/share/zenc/std/string.zc"
(found_start = true);

#line 595 "/usr/local/share/zenc/std/string.zc"
(count = 0);
    }

#line 596 "/usr/local/share/zenc/std/string.zc"
 else if ((!found_start))     {

#line 598 "/usr/local/share/zenc/std/string.zc"
    char c = 
#line 598 "/usr/local/share/zenc/std/string.zc"
Vec__char__get((&self->vec), i);

#line 599 "/usr/local/share/zenc/std/string.zc"
(i = (i + 
#line 599 "/usr/local/share/zenc/std/string.zc"
String__utf8_seq_len(c)));

#line 600 "/usr/local/share/zenc/std/string.zc"
(count = (count + 1));

#line 601 "/usr/local/share/zenc/std/string.zc"
continue;
    }

#line 605 "/usr/local/share/zenc/std/string.zc"
if ((count < num_chars))     {

#line 606 "/usr/local/share/zenc/std/string.zc"
    char c = 
#line 606 "/usr/local/share/zenc/std/string.zc"
Vec__char__get((&self->vec), i);

#line 607 "/usr/local/share/zenc/std/string.zc"
    size_t seq = 
#line 607 "/usr/local/share/zenc/std/string.zc"
String__utf8_seq_len(c);

#line 608 "/usr/local/share/zenc/std/string.zc"
(byte_len = (byte_len + seq));

#line 609 "/usr/local/share/zenc/std/string.zc"
(i = (i + seq));

#line 610 "/usr/local/share/zenc/std/string.zc"
(count = (count + 1));
    }
 else     {

#line 612 "/usr/local/share/zenc/std/string.zc"
break;
    }
    }

#line 616 "/usr/local/share/zenc/std/string.zc"
if ((!found_start))     {

#line 616 "/usr/local/share/zenc/std/string.zc"
    return 
#line 616 "/usr/local/share/zenc/std/string.zc"
String__new("");
    }

#line 618 "/usr/local/share/zenc/std/string.zc"
    return 
#line 618 "/usr/local/share/zenc/std/string.zc"
String__substring(self, byte_start, byte_len);
    }
}

#line 620 "/usr/local/share/zenc/std/string.zc"

Vec__String String__split(String* self, char delim)
{
    {

#line 621 "/usr/local/share/zenc/std/string.zc"
    int __z_drop_flag_parts = 1; Vec__String parts = 
#line 621 "/usr/local/share/zenc/std/string.zc"
Vec__String__new();

#line 622 "/usr/local/share/zenc/std/string.zc"
    size_t len = 
#line 622 "/usr/local/share/zenc/std/string.zc"
String__length(self);

#line 623 "/usr/local/share/zenc/std/string.zc"
if ((len == 0))     {

#line 623 "/usr/local/share/zenc/std/string.zc"
    return ({ ZC_AUTO _z_ret_mv = parts; memset(&parts, 0, sizeof(_z_ret_mv)); __z_drop_flag_parts = 0; 
#line 621 "/usr/local/share/zenc/std/string.zc"
    if (__z_drop_flag_parts) Vec__String__Drop__glue(&parts);
_z_ret_mv; });
    }

#line 625 "/usr/local/share/zenc/std/string.zc"
    size_t start = 0;

#line 626 "/usr/local/share/zenc/std/string.zc"
    size_t i = 0;

#line 628 "/usr/local/share/zenc/std/string.zc"
while ((i < len))     {

#line 629 "/usr/local/share/zenc/std/string.zc"
if ((
#line 629 "/usr/local/share/zenc/std/string.zc"
Vec__char__get((&self->vec), i) == delim))     {

#line 631 "/usr/local/share/zenc/std/string.zc"
Vec__String__push((&parts), String__substring(self, start, (i - start)));

#line 632 "/usr/local/share/zenc/std/string.zc"
(start = (i + 1));
    }

#line 634 "/usr/local/share/zenc/std/string.zc"
(i = (i + 1));
    }

#line 638 "/usr/local/share/zenc/std/string.zc"
if ((start <= len))     {

#line 639 "/usr/local/share/zenc/std/string.zc"
Vec__String__push((&parts), String__substring(self, start, (len - start)));
    }

#line 642 "/usr/local/share/zenc/std/string.zc"
    return ({ ZC_AUTO _z_ret_mv = parts; memset(&parts, 0, sizeof(_z_ret_mv)); __z_drop_flag_parts = 0; 
#line 621 "/usr/local/share/zenc/std/string.zc"
    if (__z_drop_flag_parts) Vec__String__Drop__glue(&parts);
_z_ret_mv; });

#line 621 "/usr/local/share/zenc/std/string.zc"
    if (__z_drop_flag_parts) Vec__String__Drop__glue(&parts);
    }
}

#line 645 "/usr/local/share/zenc/std/string.zc"

String String__trim(String* self)
{
    {

#line 646 "/usr/local/share/zenc/std/string.zc"
    size_t start = 0;

#line 647 "/usr/local/share/zenc/std/string.zc"
    size_t len = 
#line 647 "/usr/local/share/zenc/std/string.zc"
String__length(self);

#line 648 "/usr/local/share/zenc/std/string.zc"
    size_t end = len;

#line 651 "/usr/local/share/zenc/std/string.zc"
while ((start < len))     {

#line 652 "/usr/local/share/zenc/std/string.zc"
    char c = 
#line 652 "/usr/local/share/zenc/std/string.zc"
Vec__char__get((&self->vec), start);

#line 653 "/usr/local/share/zenc/std/string.zc"
if (((((c != ' ') && (c != '\t')) && (c != '\n')) && (c != '\r')))     {

#line 654 "/usr/local/share/zenc/std/string.zc"
break;
    }

#line 656 "/usr/local/share/zenc/std/string.zc"
(start = (start + 1));
    }

#line 659 "/usr/local/share/zenc/std/string.zc"
if ((start == len))     {

#line 660 "/usr/local/share/zenc/std/string.zc"
    return 
#line 660 "/usr/local/share/zenc/std/string.zc"
String__new("");
    }

#line 664 "/usr/local/share/zenc/std/string.zc"
while ((end > start))     {

#line 665 "/usr/local/share/zenc/std/string.zc"
    char c = 
#line 665 "/usr/local/share/zenc/std/string.zc"
Vec__char__get((&self->vec), (end - 1));

#line 666 "/usr/local/share/zenc/std/string.zc"
if (((((c != ' ') && (c != '\t')) && (c != '\n')) && (c != '\r')))     {

#line 667 "/usr/local/share/zenc/std/string.zc"
break;
    }

#line 669 "/usr/local/share/zenc/std/string.zc"
(end = (end - 1));
    }

#line 672 "/usr/local/share/zenc/std/string.zc"
    return 
#line 672 "/usr/local/share/zenc/std/string.zc"
String__substring(self, start, (end - start));
    }
}

#line 675 "/usr/local/share/zenc/std/string.zc"

String String__replace(String* self, char* target, char* replacement)
{
    {

#line 676 "/usr/local/share/zenc/std/string.zc"
    ZC_AUTO t_len = 
#line 676 "/usr/local/share/zenc/std/string.zc"
strlen(target);

#line 677 "/usr/local/share/zenc/std/string.zc"
if ((t_len == 0))     {

#line 677 "/usr/local/share/zenc/std/string.zc"
    return 
#line 677 "/usr/local/share/zenc/std/string.zc"
String__substring(self, 0, String__length(self));
    }

#line 680 "/usr/local/share/zenc/std/string.zc"
    size_t s_len = 
#line 680 "/usr/local/share/zenc/std/string.zc"
String__length(self);

#line 681 "/usr/local/share/zenc/std/string.zc"
    int __z_drop_flag_result = 1; String result = 
#line 681 "/usr/local/share/zenc/std/string.zc"
String__new("");

#line 683 "/usr/local/share/zenc/std/string.zc"
    size_t i = 0;

#line 684 "/usr/local/share/zenc/std/string.zc"
while ((i < s_len))     {

#line 686 "/usr/local/share/zenc/std/string.zc"
if (((i + t_len) <= s_len))     {

#line 687 "/usr/local/share/zenc/std/string.zc"
    bool is_match = true;

#line 689 "/usr/local/share/zenc/std/string.zc"
for (size_t k = (size_t)(0); k < t_len; k = (k + 1))     {

#line 690 "/usr/local/share/zenc/std/string.zc"
if ((
#line 690 "/usr/local/share/zenc/std/string.zc"
Vec__char__get((&self->vec), (i + k)) != target[k]))     {

#line 691 "/usr/local/share/zenc/std/string.zc"
(is_match = false);

#line 692 "/usr/local/share/zenc/std/string.zc"
break;
    }
    }

#line 696 "/usr/local/share/zenc/std/string.zc"
if (is_match)     {

#line 697 "/usr/local/share/zenc/std/string.zc"
    int __z_drop_flag_r_str = 1; String r_str = 
#line 697 "/usr/local/share/zenc/std/string.zc"
String__new(replacement);

#line 698 "/usr/local/share/zenc/std/string.zc"
String__append((&result), (&r_str));

#line 699 "/usr/local/share/zenc/std/string.zc"
(i = (i + t_len));

#line 700 "/usr/local/share/zenc/std/string.zc"

#line 697 "/usr/local/share/zenc/std/string.zc"
    if (__z_drop_flag_r_str) String__Drop__glue(&r_str);
continue;

#line 697 "/usr/local/share/zenc/std/string.zc"
    if (__z_drop_flag_r_str) String__Drop__glue(&r_str);
    }
    }

#line 705 "/usr/local/share/zenc/std/string.zc"
    int __z_drop_flag_v = 1; Vec__char v = 
#line 705 "/usr/local/share/zenc/std/string.zc"
Vec__char__new();

#line 706 "/usr/local/share/zenc/std/string.zc"
Vec__char__push((&v), Vec__char__get((&self->vec), i));

#line 707 "/usr/local/share/zenc/std/string.zc"
Vec__char__push((&v), 0);

#line 708 "/usr/local/share/zenc/std/string.zc"
    int __z_drop_flag_ch_s = 1; String ch_s = 
#line 708 "/usr/local/share/zenc/std/string.zc"
String__new(v.data);

#line 709 "/usr/local/share/zenc/std/string.zc"
String__append((&result), (&ch_s));

#line 710 "/usr/local/share/zenc/std/string.zc"
String__destroy((&ch_s));

#line 711 "/usr/local/share/zenc/std/string.zc"
(i = (i + 1));

#line 708 "/usr/local/share/zenc/std/string.zc"
    if (__z_drop_flag_ch_s) String__Drop__glue(&ch_s);

#line 705 "/usr/local/share/zenc/std/string.zc"
    if (__z_drop_flag_v) Vec__char__Drop__glue(&v);
    }

#line 713 "/usr/local/share/zenc/std/string.zc"
    return ({ ZC_AUTO _z_ret_mv = result; memset(&result, 0, sizeof(_z_ret_mv)); __z_drop_flag_result = 0; 
#line 681 "/usr/local/share/zenc/std/string.zc"
    if (__z_drop_flag_result) String__Drop__glue(&result);
_z_ret_mv; });

#line 681 "/usr/local/share/zenc/std/string.zc"
    if (__z_drop_flag_result) String__Drop__glue(&result);
    }
}

#line 18 "/usr/local/share/zenc/std/string.zc"

Option__int32_t StringCharsIter__next(StringCharsIter* self)
{
    {

#line 19 "/usr/local/share/zenc/std/string.zc"
if ((self->pos >= self->len))     {

#line 19 "/usr/local/share/zenc/std/string.zc"
    return 
#line 19 "/usr/local/share/zenc/std/string.zc"
Option__int32_t__None();
    }

#line 21 "/usr/local/share/zenc/std/string.zc"
    uint8_t c = ((uint8_t)(self->data[self->pos]));

#line 22 "/usr/local/share/zenc/std/string.zc"
    size_t seq = 
#line 22 "/usr/local/share/zenc/std/string.zc"
String__utf8_seq_len(((char)(c)));

#line 24 "/usr/local/share/zenc/std/string.zc"
if (((self->pos + seq) > self->len))     {

#line 25 "/usr/local/share/zenc/std/string.zc"
(self->pos = self->len);

#line 26 "/usr/local/share/zenc/std/string.zc"
    return 
#line 26 "/usr/local/share/zenc/std/string.zc"
Option__int32_t__None();
    }

#line 29 "/usr/local/share/zenc/std/string.zc"
    int32_t val = 0;

#line 30 "/usr/local/share/zenc/std/string.zc"
if ((seq == 1))     {

#line 31 "/usr/local/share/zenc/std/string.zc"
(val = ((int32_t)(c)));
    }

#line 32 "/usr/local/share/zenc/std/string.zc"
 else if ((seq == 2))     {

#line 33 "/usr/local/share/zenc/std/string.zc"
(val = ((int32_t)(((((int32_t)((c & 31))) << 6) | (((int32_t)(((uint8_t)(self->data[(self->pos + 1)])))) & 63)))));
    }

#line 34 "/usr/local/share/zenc/std/string.zc"
 else if ((seq == 3))     {

#line 35 "/usr/local/share/zenc/std/string.zc"
(val = ((int32_t)((((((int32_t)((c & 15))) << 12) | ((((int32_t)(((uint8_t)(self->data[(self->pos + 1)])))) & 63) << 6)) | (((int32_t)(((uint8_t)(self->data[(self->pos + 2)])))) & 63)))));
    }

#line 36 "/usr/local/share/zenc/std/string.zc"
 else if ((seq == 4))     {

#line 37 "/usr/local/share/zenc/std/string.zc"
(val = ((int32_t)(((((((int32_t)((c & 7))) << 18) | ((((int32_t)(((uint8_t)(self->data[(self->pos + 1)])))) & 63) << 12)) | ((((int32_t)(((uint8_t)(self->data[(self->pos + 2)])))) & 63) << 6)) | (((int32_t)(((uint8_t)(self->data[(self->pos + 3)])))) & 63)))));
    }

#line 40 "/usr/local/share/zenc/std/string.zc"
(self->pos = (self->pos + seq));

#line 41 "/usr/local/share/zenc/std/string.zc"
    return 
#line 41 "/usr/local/share/zenc/std/string.zc"
Option__int32_t__Some(val);
    }
}

#line 44 "/usr/local/share/zenc/std/string.zc"

StringCharsIter StringCharsIter__iterator(StringCharsIter* self)
{
    {

#line 45 "/usr/local/share/zenc/std/string.zc"
    return (*self);
    }
}
