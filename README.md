# A. Быстрый поиск в массиве
https://contest.yandex.ru/contest/29188/problems/A/

Ограничение времени

3 секунды

Ограничение памяти

64Mb

#### Ввод

стандартный ввод или input.txt

#### Вывод

стандартный вывод или output.txt

Дан массив из <math display="inline" style="text-indent: 0em;" xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math> целых чисел. Все числа от <math display="inline" style="text-indent: 0em;" xmlns="http://www.w3.org/1998/Math/MathML"> <mo>−</mo> <mn>1</mn><msup><mrow><mn>e</mn></mrow><mrow><mn>9</mn></mrow></msup></math> до <math display="inline" style="text-indent: 0em;" xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn><msup><mrow><mn>e</mn></mrow><mrow><mn>9</mn></mrow></msup></math>.

Нужно уметь отвечать на запросы вида “Cколько чисел имеют значения от <math display="inline" style="text-indent: 0em;" xmlns="http://www.w3.org/1998/Math/MathML"><mi>L</mi></math> до <math display="inline" style="text-indent: 0em;" xmlns="http://www.w3.org/1998/Math/MathML"><mi>R</mi></math>?”.

## Формат ввода

Число <math display="inline" style="text-indent: 0em;" xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math> (<math display="inline" style="text-indent: 0em;" xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn> <mo>≤</mo> <mi>N</mi> <mo>≤</mo> <mn>1</mn><msup><mrow><mn>e</mn></mrow><mrow><mn>5</mn></mrow></msup></math>). Далее <math display="inline" style="text-indent: 0em;" xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math> целых чисел.

Затем число запросов <math display="inline" style="text-indent: 0em;" xmlns="http://www.w3.org/1998/Math/MathML"><mi>K</mi></math> (<math display="inline" style="text-indent: 0em;" xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn> <mo>≤</mo> <mi>K</mi> <mo>≤</mo> <mn>1</mn><msup><mrow><mn>e</mn></mrow><mrow><mn>5</mn></mrow></msup></math>).

Далее <math display="inline" style="text-indent: 0em;" xmlns="http://www.w3.org/1998/Math/MathML"><mi>K</mi></math> пар чисел <math display="inline" style="text-indent: 0em;" xmlns="http://www.w3.org/1998/Math/MathML"><mi>L</mi><mo>,</mo><mi>R</mi></math> (<math display="inline" style="text-indent: 0em;" xmlns="http://www.w3.org/1998/Math/MathML"> <mo>−</mo> <mn>1</mn><msup><mrow><mn>e</mn></mrow><mrow><mn>9</mn></mrow></msup> <mo>≤</mo> <mi>L</mi> <mo>≤</mo> <mi>R</mi> <mo>≤</mo> <mn>1</mn><msup><mrow><mn>e</mn></mrow><mrow><mn>9</mn></mrow></msup></math>) — собственно запросы.

## Формат вывода

Выведите <math display="inline" style="text-indent: 0em;" xmlns="http://www.w3.org/1998/Math/MathML"><mi>K</mi></math> чисел — ответы на запросы.

## Пример

#### Ввод
5\
10 1 10 3 4\
4\
1 10\
2 9\
3 4\
2 2
#### Вывод
5 2 2 0