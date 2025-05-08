# C++ `<iomanip>` Notes

The `<iomanip>` header in C++ provides facilities for manipulating the input/output (I/O) formatting using stream manipulators.

---

## 🔹 Commonly Used Manipulators

### 1. `setw(n)`

* Sets the width of the next input/output field.

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

cout << setw(10) << 123 << endl; // Output:        123
```

* Pads with spaces by default.

### 2. `setfill(char)`

* Sets the fill character used with `setw()`.

```cpp
cout << setfill('*') << setw(10) << 123 << endl; // Output: *******123
```

### 3. `setprecision(n)` - means total count of digits

* Sets the precision (number of digits) for floating-point output.

```cpp
cout << setprecision(4) << 3.14159 << endl; // Output: 3.142
```

* Affects total digits unless used with `fixed`.

### 4. `fixed`  - means only after  decimal point

* Forces output in fixed-point notation.

```cpp
cout << fixed << setprecision(2) << 3.14159 << endl; // Output: 3.14
```

### 5. `scientific`

* Forces output in scientific notation.

```cpp
cout << scientific << 12345.6789 << endl; // Output: 1.234568e+04
```

### 6. `left`, `right`, `internal`

* Alignment of output within the field width.

```cpp
cout << left << setw(10) << 123 << endl;     // Output: 123       
cout << right << setw(10) << 123 << endl;    // Output:        123
cout << internal << setw(10) << -123 << endl; // Output: -       123
```

### 7. `showpos`

* Show `+` sign for positive numbers.

```cpp
cout << showpos << 42 << endl; // Output: +42
```

### 8. `noshowpos`

* Opposite of `showpos`.

```cpp
cout << noshowpos << 42 << endl; // Output: 42
```

### 9. `showpoint`

* Always show decimal point for floating-point numbers.

```cpp
cout << showpoint << fixed << setprecision(0) << 3.0 << endl; // Output: 3.
```

### 10. `hex`, `dec`, `oct`

* Change number base for integer output.

```cpp
cout << hex << 255 << endl; // Output: ff
cout << dec << 255 << endl; // Output: 255
cout << oct << 255 << endl; // Output: 377
```

### 11. `showbase`

* Show base prefix (e.g., `0x` for hex, `0` for oct).

```cpp
cout << showbase << hex << 255 << endl; // Output: 0xff
```

---

## 🔸 Notes

* These manipulators work on `cout` or any stream object.
* They persist for the stream until changed or reset.
* Combine manipulators for custom formatting.

---

## 🧠 Tip

Use `#include <iomanip>` and `using namespace std;` cautiously to avoid name clashes.

---

## ✅ Example Summary

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << showpos << fixed << setprecision(2);
    cout << setw(10) << setfill('*') << 123.456 << endl;
    return 0;
}
```

// Output: \*\*\*+123.46
