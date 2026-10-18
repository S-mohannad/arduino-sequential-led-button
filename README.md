# 💡 Sequential LED Control with Button

> **Arduino Project #26** — زر يتحكم بـ 10 LEDs تشتغل وتطفى بالتسلسل

[![Arduino](https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=arduino&logoColor=white)](https://www.arduino.cc/)
[![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://isocpp.org/)
[![Level](https://img.shields.io/badge/Level-Beginner-green?style=for-the-badge)](https://github.com/S-mohannad)

---

## 📋 Description

مشروع يتحكم بـ 10 LEDs بالتسلسل عبر زر واحد:

- **عند الضغط على الزر:** يشتغل كل LED بعد الثاني بفارق 200ms (من pin 1 إلى pin 10)
- **عند الإفراج عن الزر:** يطفى كل LED بعد الثاني بنفس الفارق
- الزر يستخدم `INPUT_PULLUP` — يقرأ 0 عند الضغط و1 عند الإفراج

---

## 🔌 Circuit

```
Arduino UNO
┌─────────────────┐
│             0 ●─┼──────────── زر ── GND
│             1 ●─┼──[220Ω]──💡 LED 1  ── GND
│             2 ●─┼──[220Ω]──💡 LED 2  ── GND
│             3 ●─┼──[220Ω]──💡 LED 3  ── GND
│             4 ●─┼──[220Ω]──💡 LED 4  ── GND
│             5 ●─┼──[220Ω]──💡 LED 5  ── GND
│             6 ●─┼──[220Ω]──💡 LED 6  ── GND
│             7 ●─┼──[220Ω]──💡 LED 7  ── GND
│             8 ●─┼──[220Ω]──💡 LED 8  ── GND
│             9 ●─┼──[220Ω]──💡 LED 9  ── GND
│            10 ●─┼──[220Ω]──💡 LED 10 ── GND
└─────────────────┘
```

- 🔘 زر على Pin 0 موصول إلى GND (INPUT_PULLUP)
- 💡 10 LEDs على Pins 1–10 مع مقاومة 220Ω لكل منها

---

## 💡 Concepts Used

- `INPUT_PULLUP` — مقاومة سحب داخلية، الزر يقرأ 0 عند الضغط و1 عند الإفراج
- `digitalRead()` — قراءة حالة الزر
- `for loop` — للمرور على الـ 10 LEDs بالتسلسل
- `delay()` — فارق 200ms بين كل LED والتالي
- التحكم بـ OUTPUT متعدد عبر حلقة واحدة

---

## 📊 Behavior

| حالة الزر | التأثير |
|-----------|---------|
| مضغوط (s == 0) | LEDs تشتغل واحداً بعد الثاني (pin 1 → 10) |
| مُفرَج (s == 1) | LEDs تطفى واحداً بعد الثاني (pin 1 → 10) |

---

## 🔗 Code

```cpp
int s = 0;
int d = 200;

void setup() {
  pinMode(0, INPUT_PULLUP);
  for (int i = 1; i < 11; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  s = digitalRead(0);
  if (s == 0) {
    for (int j = 1; j < 11; j++) {
      digitalWrite(j, HIGH);
      delay(d);
    }
  } else {
    for (int j = 1; j < 11; j++) {
      digitalWrite(j, LOW);
      delay(d);
    }
  }
}
```

---

## 🔧 How to Run

1. افتح **Arduino IDE**
2. وصّل الدائرة (زر على pin 0، 10 LEDs على pins 1–10)
3. انسخ الكود والصقه في المحرر
4. اختر **Board:** Arduino UNO
5. اختر **Port** الصحيح
6. اضغط ⬆️ **Upload**
7. اضغط الزر وراقب LEDs تشتغل بالتسلسل، أفرج وراقبها تطفى بالتسلسل

---

## 👨‍💻 Author

**S-mohannad** — [@S-mohannad](https://github.com/S-mohannad)
