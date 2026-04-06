# Zen-C v0.4.4 语法指南

## 数组类型 (Array Types)

### 正确语法
```zen
// 单维数组: Type[Size]
let arr: int[5];

// 多维数组: Type[Size1][Size2]
let matrix: int[3][4];

// 切片 (动态大小): Type[]
let slice: int[];
```

### 错误语法
```zen
// ❌ 错误 - 旧语法
let arr: [5]int;
let matrix: [3][4]int;

// ✅ 正确 - 新语法
let arr: int[5];
let matrix: int[3][4];
```

## 指针类型 (Pointer Types)

### 正确语法
```zen
// 指针: Type*
let ptr: int*;
let name: char*;

// 获取地址: &variable
let x = 10;
let px = &x;  // px is int*

// 函数参数
fn greet(p: Person*) { ... }
```

### 错误语法
```zen
// ❌ 错误 - 旧语法
let ptr: &int;
fn foo(x: &Type) { ... }

// ✅ 正确 - 新语法
let ptr: int*;
fn foo(x: Type*) { ... }
```

## 变量声明 (Variable Declarations)

### 正确语法
```zen
// 所有变量用 let 声明
let x = 10;
let name = "Test";
let point = Point { x: 0, y: 0 };
```

### 错误语法
```zen
// ❌ 错误 - var 是旧语法，mut 不是关键字
var x = 10;
let mut x = 10;

// ✅ 正确 - 只有 let
let x = 10;
```

## 类型转换 (Type Casting)

### 正确语法
```zen
// 正确 - (Type)(value)
let x: float = (float)(10);
let y: int = (int)(3.14);
```

### 错误语法
```zen
// ❌ 错误 - as 不是类型转换
let x = 10 as float;
let y = 3.14 as int;

// ✅ 正确
let x = (float)(10);
let y = (int)(3.14);
```

## 枚举成员访问 (Enum Variant Access)

### 正确语法
```zen
// ✅ Enum::Variant 在 match 和表达式中都正确
match color {
    Color::Red => { ... }
    Color::Green => { ... }
}

if c == Color::Red { ... }
```

### 错误语法
```zen
// ❌ 错误 - 点号不是枚举成员访问
Color.Red  // 在表达式中不正确

// ✅ 正确
Color::Red
```

## Match 模式 (Match Patterns)

### 范围模式
```zen
// 包容范围: start..=end (包含 end)
match x {
    1..=5 => { println "1-5"; }
}

// 排他范围: start..<end (不包含 end)
match x {
    1..<6 => { println "1-5"; }
}
```

### OR 模式
```zen
match x {
    1 || 2 || 3 => { ... }
    4 or 5 => { ... }  // or 也是可以的
}
```

### 错误语法
```zen
// ❌ 错误 - ... 不是有效范围语法
1...5 =>
1... =>
```

## 函数调用和字符串插值

### 字符串插值
```zen
// ✅ 正确
let name = "World";
println "Hello {name}";

// ❌ 错误 - ++ 连接已废弃
println "Hello " ++ name;
```

### println/print
```zen
// ✅ 正确 - 没有括号
println "Hello";
println "Value: {x}";

// ❌ 错误 - 有括号是旧语法
println("Hello");
```

## 结构体初始化 (Struct Initialization)

### 正确语法
```zen
let p = Point { x: 10, y: 20 };
let person = Person { 
    name: "Alice", 
    age: 30 
};
```

### 错误语法
```zen
// ❌ 错误 - 等号不是字段初始化
let p = Point { x = 10, y = 20 };
```

## 通用模式转换总结

| 旧语法 | 新语法 |
|--------|--------|
| `[N]Type` | `Type[N]` |
| `[N][M]Type` | `Type[N][M]` |
| `&Type` | `Type*` |
| `&mut Type` | `Type*` |
| `var x` | `let x` |
| `let mut x` | `let x` |
| `value as Type` | `(Type)(value)` |
| `Enum.Variant` | `Enum::Variant` |
| `value++` | `"{value}"` |
| `"a" ++ var` | `"a{var}"` |
| `expr...` | `expr..=` 或 `expr..<` |
| `Struct.{ }` | `Struct { }` |
| `Struct.(...)` | `Struct(...)` |
| `println(...)` | `println ...` |
