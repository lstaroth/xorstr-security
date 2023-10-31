<h1 align="center">
<span>xorstr-security</span>
</h1>
<p align="center">
    <a href="./README.md">English</a> | 中文介绍
</p>
<p align="center">
    <em>绕过Flare-floss</em><br>
</p>

# 设计背景
xorstr已经被一些开源工具彻底攻破(包括Flare-floss和我自己开源的AntiXorstr)，这些开源的检测工具简单快速的从样本二进制中还原出原始的字符串。为了解决这个问题，该项目从设计之初就考虑了如何最大限度的对抗这些检测思路，尤其是Flare-floss

### 概述

两种绕过方式基于不同的原理实现，xorstr_s & xorstr_h

### xorstr_s

|            检测方式          |检测情况|
| :-------------------------: | :----: |
| Flare-floss static strings  | bypass |
|  Flare-floss stack strings  | bypass |
|  Flare-floss tight strings  | bypass |
| Flare-floss decoded strings |   /    |

测试demo

```cpp
void test()
{
    printf(Enc("Samsung\n"));
    wprintf(Enc(L"Apple\n"));
    printf(Enc("Xiaomi\n"));
    wprintf(Enc(L"Oppo Group\n"));
    printf(Enc("vivo\n"));
    wprintf(Enc(L"Transsion\n"));

    std::cout << Enc("Honor") << std::endl;
    std::wcout << Enc(L"Realme") << std::endl;
    std::cout << Enc("Motorola") << std::endl;
    std::wcout << Enc(L"Huawei") << std::endl;
    std::cout << Enc("Others") << std::endl;
}
```

测试结果：STACK & TIGHT 绕过，DECODED模式还原出一部分

```bash
 ─────────────────────
  FLOSS STACK STRINGS
 ─────────────────────

 ─────────────────────
  FLOSS TIGHT STRINGS
 ─────────────────────

 ───────────────────────
  FLOSS DECODED STRINGS
 ───────────────────────
Samsung
Apple
Xiaomi
Oppo Group
vivo
Transsion
Honor
```

### xorstr_h

|            检测方式          |检测情况|
| :-------------------------: | :----: |
| Flare-floss static strings  | bypass |
|  Flare-floss stack strings  | bypass |
|  Flare-floss tight strings  | bypass |
| Flare-floss decoded strings | bypass |

测试结果：demo与xorstr_s一致，所有模式下的绕过

```bash
 FLOSS STACK STRINGS
 ─────────────────────
o]QOIR[6<
}<L<L<P<Y<6<<<
dU]SQU6<
s<L<L<S<
<{<N<S<I<L<6<<<
JUJS6
h<N<]<R<O<O<U<S<R<6<<<
tSRSN
n<Y<]<P<Q<Y<<<
qSHSNSP]<
t<I<]<K<Y<U<<<
sHTYNO<

 ─────────────────────
  FLOSS TIGHT STRINGS
 ─────────────────────

 ───────────────────────
  FLOSS DECODED STRINGS
 ───────────────────────
o]QOIR[6<
```

### Analysis Article
https://bbs.kanxue.com/thread-279309.htm
