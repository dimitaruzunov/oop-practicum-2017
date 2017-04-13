Домашна работа 2
================

Динамичен масив
---------------
Динамичният масив е масив с променлив размер, позволяващ произволен достъп
до свой елемент и добавяне и премахване на елементи.
За разлика от обикновения статичен масив в C++, който може да побере само
фиксиран брой елементи, зададен при създаването на масива,
динамичният масив увеличава капацитета си при добавяне на нови елементи.

Да се имплементира структурата от данни динамичен масив от цели числа.

За целта да се напише клас `DynamicArray`, който да има следните член-данни:
* `int* elements` – масив от всички елементи
* `int size` – текущ брой елементи в масива
* `int capacity` – текущ максимален брой елементи, които може да побере масивът;
това е капацитетът на динамичния масив

Дефинирайте "голяма четворка" за класа (конструктор по подразбиране,
конструктор за копиране, операция за присвояване (`operator=`) и деструктор).

Конструкторът по подразбиране трябва да инициализара празен динамичен масив
с капацитет 8.

Дефинирайте конструктор по даден масив от цели числа. Пример:
```cpp
int arrayOfNumbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
DynamicArray numbers(arrayOfNumbers, 10);

numbers.print(); // Извежда [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
```

Класът трябва да има следните публични методи:
* `getSize` – връща текущия брой елементи в масива
Пример:
```cpp
int arrayOfNumbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
DynamicArray numbers(arrayOfNumbers, 10);

cout << numbers.getSize() << '\n'; // Извежда 10
```

* `isEmpty` – връща `true`, ако масивът е празен, `false` – ако не е празен
Пример:
```cpp
DynamicArray numbers;
cout << boolalpha << numbers.isEmpty() << '\n'; // Извежда true
```

* `get(index)` – връща елемента на позиция `index` в масива. Индексирането
започва от 0, тоест първият елемент в масива е на индекс 0.
Пример:
```cpp
int arrayOfNumbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
DynamicArray numbers(arrayOfNumbers, 10);

cout << numbers.get(0) << '\n'; // Извежда 1
cout << numbers.get(5) << '\n'; // Извежда 6
```

* `set(index, newValue)` – задава нова стойност `newValue` на елемента
на позиция `index` в масива
Пример:
```cpp
int arrayOfNumbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
DynamicArray numbers(arrayOfNumbers, 10);

numbers.set(5, 42);
numbers.print(); // Извежда [1, 2, 3, 4, 5, 42, 7, 8, 9, 10]
```

* `push(element)` – добавя нов елемент след последния елемент на масива
Пример:
```cpp
DynamicArray numbers;
numbers.push(42);
numbers.push(21);

numbers.print(); // Извежда [42, 21]
```

* `pop` – премахва последния елемент в масива и го връща
Пример:
```cpp
DynamicArray numbers;
numbers.push(42);
numbers.push(21);

numbers.print(); // Извежда [42, 21]

cout << numbers.pop() << '\n'; // Извежда 21
numbers.print(); // Извежда [42]
```

* `insertAt(index, element)` – добавя нов елемент в масива на позиция `index`
Пример:
```cpp
int arrayOfNumbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
DynamicArray numbers(arrayOfNumbers, 10);

numbers.print(); // Извежда [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
numbers.insertAt(7, 42);
numbers.print(); // Извежда [1, 2, 3, 4, 5, 6, 7, 42, 8, 9, 10]
```

* `removeAt(index)` – премахва елемента на позиция `index` в масива и го връща
Пример:
```cpp
int arrayOfNumbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
DynamicArray numbers(arrayOfNumbers, 10);

numbers.print(); // Извежда [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
cout << numbers.removeAt(7) << '\n'; // Извежда 8
numbers.print(); // Извежда [1, 2, 3, 4, 5, 6, 7, 9, 10]
```

* `print` – извежда масива в следния формат:
`[елемент1, елемент2, ..., елементn]`
Ако масивът е празен, извежда: `[]`
Пример:
```cpp
DynamicArray emptyArray;
emptyArray.print(); // Извежда []

int arrayOfNumbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
DynamicArray numbers(arrayOfNumbers, 10);

numbers.print(); // Извежда [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
```

Когато имплементирате методите за добавяне на нов елемент в масива (`push` и
`insertAt`) имайте предвид, че трябва да увеличите капацитета на масива, ако
няма достатъчно място за новия елемент. Една добра стратегия е да увеличаваме
капацитета двойно. Например, ако в масива имаме 8 елемента и текущият капацитет
е 8, тогава при добавянето на девети елемент първо трябва преоразмерим масива,
като увеличим капацитета му двойно: новият капацитет ще бъде 16.

Да се дефинират следните операции за класа:
* `operator[index]` – връща елемента на позиция `index` в масива
Пример:
```cpp
int arrayOfNumbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
DynamicArray numbers(arrayOfNumbers, 10);

cout << numbers[0] << '\n'; // Извежда 1
cout << numbers[5] << '\n'; // Извежда 6
```

* `operator+=` – конкатенира два динамични масива, като резултатът от
конкатенацията се записва в първия динамичен масив; връща първия динамичен масив
Пример:
```cpp
int firstArrayOfNumbers[] = {1, 2, 3};
DynamicArray firstNumbers(firstArrayOfNumbers, 3);

int secondArrayOfNumbers[] = {4, 5, 6};
DynamicArray secondNumbers(secondArrayOfNumbers, 3);

firstNumbers += secondNumbers;

firstNumbers.print(); // Извежда [1, 2, 3, 4, 5, 6]
secondNumbers.print(); // Извежда [4, 5, 6]
```

* `operator+` – връща нов динамичен масив, който е резултатът от конкатенацията
на два динамични масива
Пример:
```cpp
int firstArrayOfNumbers[] = {1, 2, 3};
DynamicArray firstNumbers(firstArrayOfNumbers, 3);

int secondArrayOfNumbers[] = {4, 5, 6};
DynamicArray secondNumbers(secondArrayOfNumbers, 3);

DynamicArray result = firstNumbers + secondNumbers;

result.print(); // Извежда [1, 2, 3, 4, 5, 6]
firstNumbers.print(); // Извежда [1, 2, 3]
secondNumbers.print(); // Извежда [4, 5, 6]
```

* `operator-=` – премахва всички елементи от първия динамичен масив, които
са елементи на втория динамичен масив
Пример:
```cpp
int firstArrayOfNumbers[] = {1, 2, 6, 1, 3, 6, 5};
DynamicArray firstNumbers(firstArrayOfNumbers, 7);

int secondArrayOfNumbers[] = {1, 6, 5};
DynamicArray secondNumbers(secondArrayOfNumbers, 3);

firstNumbers -= secondNumbers;

firstNumbers.print(); // Извежда [2, 3]
secondNumbers.print(); // Извежда [1, 6, 5]
```

* `operator-` – връща нов динамичен масив, който е резултатът от премахването
на всички елементи от първия динамичен масив, които са елементи на втория
динамичен масив
Пример:
```cpp
int firstArrayOfNumbers[] = {1, 2, 6, 1, 3, 6, 5};
DynamicArray firstNumbers(firstArrayOfNumbers, 7);

int secondArrayOfNumbers[] = {1, 6, 5};
DynamicArray secondNumbers(secondArrayOfNumbers, 3);

DynamicArray result = firstNumbers - secondNumbers;

result.print(); // Извежда [2, 3]
firstNumbers.print(); // Извежда [1, 2, 6, 1, 3, 6, 5]
secondNumbers.print(); // Извежда [1, 6, 5]
```
