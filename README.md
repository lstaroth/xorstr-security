<h1 align="center">
<span>xorstr-security</span>
</h1>
<p align="center">
    English | <a href="./README_CN.md">中文介绍</a>
</p>
<p align="center">
    <em>Bypass detection from Flare-floss</em><br>
</p>

# Design Background
The xorstr technique has been thoroughly compromised by several open-source tools, including Flare-floss and my own open-source tool AntiXorstr. These open-source detection tools efficiently and quickly recover the original strings from the binary samples. To address this issue, this project has been designed with a focus on effectively countering these detection methods, particularly Flare-floss.

### Overview

There are two bypass techniques implemented in this project: xorstr_s and xorstr_h. These techniques are based on different principles.

### xorstr_s

|            types            | status |
| :-------------------------: | :----: |
| Flare-floss static strings  | bypass |
|  Flare-floss stack strings  | bypass |
|  Flare-floss tight strings  | bypass |
| Flare-floss decoded strings |   /    |

testing demo

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

Test result: STACK & TIGHT bypass, DECODED mode restored part of it

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

|            types            | status |
| :-------------------------: | :----: |
| Flare-floss static strings  | bypass |
|  Flare-floss stack strings  | bypass |
|  Flare-floss tight strings  | bypass |
| Flare-floss decoded strings | bypass |

Test result: demo is consistent with xorstr_s, bypassing in all modes

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
**chinese**  
https://bbs.kanxue.com/thread-279309.htm
