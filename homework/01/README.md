# Домашна работа 1

## Задача 1. Книги в книжарница
Да се дефинира клас `Book`, представящ книга в книжарница.
Класът да има за член-данни:
- заглавие на книга (символен низ до 30 символа)
- име на автор (символен низ до 30 символа)
- брой на наличните екземпляри на книга (цяло неотрицателно число)
- цена (дробно число)
Член-данните да са капсулирани (това означава член-данните да бъдат `private`).

Да се дефинира конструктор за инициализиране на книга по заглавието й,
името на автора, броя на наличните екземпляри и цената.

Да се дефинират селектори (getters) и мутатори (setters) за член-данните на
класа.

Да се дефинира член-функция `print`, която извежда информация за книгата.
Пример:
```cpp
Book harryPotter("Harry Potter", "J. K. Rowling", 5, 15);
harryPotter.print(); // Това трябва да изведе на стандартния изход: Title: Harry Potter, Author: J. K. Rowling, Items in stock: 5, Price: 15
```

Да се напише функция, която по дадена книга, проверява дали книгата е налична.
```cpp
Book gameOfThrones("Game Of Thrones", "George R. R. Martin", 25, 20);
isAvailable(gameOfThrones); // true
Book harryPotter("Harry Potter", "J. K. Rowling", 0, 15);
isAvailable(harryPotter); // false
```

Да се напише функция, която по дадена книга и масив от книги,
проверява дали книгата се съдържа в масива.
```cpp
Book gameOfThrones("Game Of Thrones", "George R. R. Martin", 25, 20);
Book harryPotter("Harry Potter", "J. K. Rowling", 0, 15);
Book warAndPeace("War And Peace", "Tolstoy", 5, 1000000);
Book books = {gameOfThrones, harryPotter};

includes(gameOfThrones, books); // true
includes(warAndPeace, books); // false
```

Да се напише функция, която по даден масив от книги, връща най-скъпата
книга в масива.
```cpp
Book gameOfThrones("Game Of Thrones", "George R. R. Martin", 25, 20);
Book harryPotter("Harry Potter", "J. K. Rowling", 0, 15);
Book warAndPeace("War And Peace", "Tolstoy", 5, 1000000);
Book books = {gameOfThrones, harryPotter, warAndPeace};

mostExpensiveBook(books); // warAndPeace
```

## Задача 2. Човек
Да се дефинира клас `Human`, задаващ информация за човек, с три член-данни:
- име (символен низ до 30 символа)
- възраст (цяло неотрицателно число)
- енергия (цяло неотрицателно число)
Член-данните да са капсулирани (това означава член-данните да бъдат `private`).

Да се дефинира конструктор за инициализиране на човек по име и възраст.
При създаване на човек стойността на енергията му е 100.

Да се дефинират селектори (getters) и мутатори (setters) за член-данните на
класа.

Да се дефинира член-функция `print`, която извежда информация за човека.

Да се дефинира член-функция `eat`, която по брой калории
(цяло число от 100 до 2000), увеличава енергията на човека.
Eнергията се увеличава по следната формула в зависимост от възрастта на човека:
| възраст | формула                                    |
|---------|--------------------------------------------|
| 0 - 25  | `текуща енергия + брой калории / 100 + 16` |
| 26 - 50 | `текуща енергия + брой калории / 100`      |
| 51 - ∞  | `текуща енергия + брой калории / 200`      |

Да се дефинира член-функция `sleep`, която по брой часове сън
(цяло неотрицателно число), увеличава енергията на човека.
Eнергията се увеличава по формулата `текуща енергия + брой часове * 8`.

Да се дефинира член-функция `isTired`, която проверява дали човека е изморен.
Човек е изморен, ако енергията му е по-малка от 20.

Да се дефинира член-функция `walk`, която по брой часове на ходене
(цяло неотрицателно число), намалява енергията на човека спрямо броя часове на
ходене по формулата `текуща енергия - 10 * броя часове` и връща `true`,
ако човекът не е изморен, иначе връща `false`.

Да се дефинира член-функция `run`, която по брой часове на тичане
(цяло неотрицателно число), намалява енергията на човека спрямо броя часове на
тичане по формулата `текуща енергия - 20 * броя часове` и връща `true`,
ако човекът не е изморен, иначе връща `false`.

Забележка: енергията на човек не може да надвиши 100.

Да се създаде човек, на възраст между 26 и 50 години, който има следния график:
- става в 8 часа и закусва ястие с калории между 600 и 800
- в 10 часа тича 1 час
- в 1 часа обядва ястие с калории между 1000 и 1200
- следобед се разхожда 2 часа
- вечеря ястие с калории между 500 и 600
- спи 8 часа
След всяка точка от графика да се извежда информацията за човека.