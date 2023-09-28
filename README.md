# xorstr-security
绕过Flare-floss检测的xorstr概念验证

### 概述

两种绕过方式，基于不同的原理完成

### xorstr_s

|            types            | status |
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

原理与绕过模式解析文章：todo

### **todo**

DECODED模式完全绕过的方案
