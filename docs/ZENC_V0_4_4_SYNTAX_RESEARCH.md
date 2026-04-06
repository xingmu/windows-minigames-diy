# Zen-C v0.4.4 语法研究报告

> 研究日期: 2026-04-06
> 源码路径: ~/github/zenc

## 1. Match 表达式

### 1.1 基本语法
```zig
match value {
    Pattern => { ... },
    _ => { ... }  // default case
}
```

### 1.2 OR 模式（重要！）
**错误语法:** `38 | 87 | 119 => { ... }`
**正确语法:** `38 || 87 || 119 => { ... }` 或 `38 or 87 or 119 => { ... }`

```zig
// ✅ 正确 - 使用 ||
1 || 2 => { return 100; }

// ✅ 正确 - 使用 'or'
3 or 4 => { return 200; }

// ❌ 错误 - 单个 |
1 | 2 => { return 100; }
```

### 1.3 Range 模式
```zig
5..<8   // 独占范围 (5, 6, 7)
10..=15 // 包容范围 (10, 11, 12, 13, 14, 15)
```

### 1.4 Enum Variant 模式
**关键:** Match 模式中 Enum 成员访问使用 `::`

```zig
enum MessageType {
    Quit,
    KeyDown,
    KeyUp
}

match event.msg {
    MessageType::Quit => { self.running = false; },
    MessageType::KeyDown => { ... },
    MessageType::KeyUp => { ... }
}
```

**注意:** 在 match 模式外，Enum 成员访问使用 `.`

```zig
// Match 模式内 - 使用 ::
MessageType::Quit =>

// 普通表达式 - 使用 .
let msg = MessageType.Quit;
```

## 2. 数组类型声明

### 2.1 固定大小数组
**错误语法:** `[N]Type`
**正确语法:** `[Type; N]`

```zig
// ❌ 错误
let arr: [4]int = [1, 2, 3, 4];

// ✅ 正确
let arr: [int; 4] = [1, 2, 3, 4];
```

### 2.2 多维数组
```zig
// ❌ 错误 - 旧语法
const DIRS: [4][2]int = [...];

// ✅ 正确 - 新语法
const DIRS: [[int; 2]; 4] = [...];
```

### 2.3 切片（动态数组）
```zig
let slice: [int] = [1, 2, 3, 4];  // 无大小 = 切片
```

## 3. Trait/接口定义与实现

### 3.1 Trait 定义
```zig
trait Greeter {
    fn greet(self, msg: string);
    fn shout(self);
}
```

### 3.2 Struct 定义
```zig
struct Robot {
    id: int;
}
```

### 3.3 Trait 实现
```zig
impl Greeter for Robot {
    fn greet(self, msg: string) {
        println "Robot {self.id} says: {msg}";
    }
    fn shout(self) {
        println "ROBOT {self.id} ACTIVATED";
    }
}
```

### 3.4 方法调用
```zig
let r: Robot = Robot { id: 42 };
r.greet("Hello");  // ✅ 使用点号调用实例方法
```

## 4. Enum 定义与使用

### 4.1 基本 Enum
```zig
enum Direction {
    DirUp,
    DirDown,
    DirLeft,
    DirRight
}
```

### 4.2 带数据的 Enum（Tagged Union）
```zig
enum Result {
    Ok(value: int),
    Err(error: string)
}
```

### 4.3 Enum 成员访问
```zig
// Match 模式内 - 使用 ::
Direction::DirUp =>

// 普通表达式 - 使用 .
let dir = Direction.DirUp;
```

## 5. 标准库 API

### 5.1 Math 库
```zig
// ✅ 正确 - 使用 Math 结构体的静态方法
Math.sqrt(4.0)    // 返回 2.0
Math.abs(-5)      // 返回 5
Math.PI           // 常量
Math::E           // 常量
```

### 5.2 Time 库
```zig
// ✅ 正确
let now = Time::now();  // 返回当前时间戳(U64)

// 睡眠
Time::sleep_ms(1000);  // 睡眠 1 秒
```

### 5.3 Random 库
```zig
// ✅ 正确
let rng = Random.new();           // 使用当前时间创建随机生成器
let rng = Random.from_seed(42);  // 使用指定种子

rng.next_int();                  // 返回随机整数
rng.next_int_range(1, 6);       // 返回 1-6 之间的随机整数
rng.next_double();               // 返回 0.0-1.0 之间的随机浮点数
rng.next_bool();                 // 返回随机布尔值
```

### 5.4 独立函数
```zig
// srand 是独立函数
srand(12345);  // 设置随机种子
```

## 6. 字符串插值

### 6.1 基本语法
```zig
let name = "World";
println "Hello {name}!";  // ✅ 正确
```

### 6.2 表达式插值
```zig
let a = 10;
let b = 20;
println "Sum: {a + b}";  // 输出 "Sum: 30"
```

## 7. 类型转换

### 7.1 C 风格类型转换
```zig
// ✅ 正确
let x = (int)3.14;    // 转换为 int
let y = (float)10;    // 转换为 float
```

### 7.2 旧语法（不支持）
```zig
// ❌ 错误
let n = 3.14 as int;
let n = 10 as float;
```

## 8. 可变性

### 8.1 可变变量
```zig
let mut x = 10;  // ✅ 正确 - 可变绑定
x = 20;          // 可以重新赋值
```

## 9. 指针与引用

### 9.1 指针类型
```zig
// ✅ 正确 - C 风格指针
let ptr: int* = &value;
let ptr: Canvas* = canvas_ref;
```

### 9.2 旧语法（不支持）
```zig
// ❌ 错误
let ptr: &int = &value;
```

## 10. 常量声明

### 10.1 常量定义
```zig
// ✅ 正确 - 使用 def
def PI: float = 3.14159;
def MAX_SIZE: int = 100;
```

### 10.2 旧语法（不支持）
```zig
// ❌ 错误
const PI: float = 3.14159;
```

## 11. 变量声明

### 11.1 变量定义
```zig
// ✅ 正确 - 使用 let
let x: int = 10;
let name: string = "ZenC";
```

### 11.2 旧语法（不支持）
```zig
// ❌ 错误
var x: int = 10;
```

## 12. 常见错误与修复

### 12.1 Match OR 模式
```zig
// 修复前
38 | 87 | 119 => { ... }

// 修复后
38 || 87 || 119 => { ... }
```

### 12.2 数组类型
```zig
// 修复前
let arr: [4]int;

// 修复后
let arr: [int; 4];
```

### 12.3 字符串插值
```zig
// 修复前
println("Value: {x}");

// 修复后
println "Value: {x}";
```

### 12.4 Enum 成员访问
```zig
// 修复前 (match 模式)
MessageType.Quit => { ... }

// 修复后 (match 模式)
MessageType::Quit => { ... }
```

### 12.5 类型转换
```zig
// 修复前
let n = x as int;

// 修复后
let n = (int)x;
```

### 12.6 常量声明
```zig
// 修复前
const MAX: int = 100;

// 修复后
def MAX: int = 100;
```

### 12.7 变量声明
```zig
// 修复前
var x: int = 10;

// 修复后
let mut x: int = 10;
```

### 12.8 指针语法
```zig
// 修复前
fn foo(x: &mut GameState) { }

// 修复后
fn foo(x: GameState*) { }
```

## 13. 测试文件位置

- Match 测试: `~/github/zenc/tests/language/control_flow/test_match.zc`
- Match 组合测试: `~/github/zenc/tests/language/features/match/test_match_composition.zc`
- Trait 测试: `~/github/zenc/tests/language/features/traits/test_traits_suite.zc`
- Math 标准库: `~/github/zenc/std/math.zc`
- Time 标准库: `~/github/zenc/std/time.zc`
- Random 标准库: `~/github/zenc/std/random.zc`
- IO 标准库: `~/github/zenc/std/io.zc`

## 14. 关键发现总结

1. **Match OR 模式必须用 `||` 或 `or`，不是单个 `|`**
2. **数组类型是 `[Type; N]`，不是 `[N]Type`**
3. **Enum 成员在 match 中用 `::`，match 外用 `.`**
4. **标准库使用 `Math.sqrt()` 等静态方法**
5. **时间函数是 `Time::now()`**
6. **随机数使用 `Random` 结构体**
7. **字符串插值用 `{var}`**
8. **类型转换用 `(Type)value`，不是 `value as Type`**
9. **常量用 `def`，变量用 `let mut`**
10. **指针用 `Type*`，不是 `&Type`**
