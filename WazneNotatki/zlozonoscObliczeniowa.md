#### Złożoność obliczeniowa charakteryzuje zmiany nakładu pracy w PROPORCJI do zmian kluczowego/kluczowychparametru/ów algorytmu. Najczęściej tym kluczowym parametrem jest N, czyli liczebność danych.

* optymistyczna - O(N) - gdy ani razu nie znajdzie prawdziwego warunku
* oczekiwana - O(N)
* pesymistyczna - O(N) - gdy za każdym razem warunek będzie prawdziwy

#### Drugi zapis to O(N) = N

#### N w nawiasie to kluczowy parametr

### algorytm sortujący poprzez wstawianie:

* optymistyczny dla ciągu takiego jakiego potrzebujemy - O(N)
* pesymistyczny dla ciągu odwrotnego do takiego jaki potrzebujmy O(N^2)
* oczekiwany dla ciągu mieszanego - O(N^2), ale zrobi szybciej niż dla pesymistycznej złożoności. 

### przeciążenie funkcji:
#### można nazwać parę funkcji tak samo, robiąc przeciążenie
#### np mamy funkcje, gdzie chcielibyśmy, żeby przyjmowała więcej typów danych - po typie danych rozróżniane jest, z jakiej dokładnie się skorzysta.