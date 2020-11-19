﻿*Состав команды: Осипян Арсен, Шарипов Тимур*

## 0. Размышления над идеей. Составление ТЗ

Взявшись за сапёра, мы начали думать над организацией нашей программы.
В итоге мы пришли к единому ТЗ и зафиксировали его.
Задача "создать игру" разделилась на несколько менее трудных задач:
1. Класс `Field` - поле с клетками (наследуется от `Graph_lib::Widget`)
2. Класс `Cell` - сами клетки (наследуется от `Graph_lib::Button`)
3. Класс `Sidebar` - боковая панель управления игрой (наследуется от `Graph_lib::Widget`)

## 1. Первая попытка реализации. Правки ТЗ

После долгих попыток реализации мы пришли к выводу, что и поле, и сайдбар будут прикрепляться к окну. Проблема была в связке двух виджетов, прикрепленных к одному окну (на сайдбаре расположены кнопки, которые привязаны и к родительскому виджету, и к окну). Поразмыслив над нашей задачей, мы решили переделать ТЗ:
1. Класс Sapper (наследуется от Graph_lib::Window) 
Размер клетки поля постоянен, размер окна изменяется при изменении размеров поля

## 2. Реализация интерфейса

Добавлено 3 режима игры - 10х10, 15х15, 20х20
Реализовано случайная генерация бомб на поле при создании новой игры
Реализована привязка кнопок к окну, прописаны их коллбэки и методы, режим игры (флаг/открытие) сменяется по кнопке

'''cpp
class Cell : public Button_with_pw
{
public:
  Cell(Graph_lib::Point p, int size_, Graph_lib::Callback cb);

  void attach (Graph_lib::Window &win) override;
  void set_img (std::string name);

  void set_bomb (bool bomb) { bombed = bomb; }
  void set_flag (bool flag) { flaged = flag; }
  void set_open ()          { opened = true; }

  bool is_bombed () const { return bombed; }
  bool is_flaged () const { return flaged; }
  bool is_opened () const { return opened; }

  int bombs_around{ 0 };

  Graph_lib::Image* img_ptr { nullptr };

private:
  bool bombed{ false };
  bool flaged{ false };
  bool opened{ false };
};
'''

## 3. Написание алгоритма открытия клеток

1 версия алгоритма - рекурсивная (Тимур)
  Черновая версия с изменением цвета нажатой кнопки
2 версия алгоритма - широким поиском (Арсен)

## 4. Реализация sidebar-а

Добавлены 3 кнопки для управления полем и поле вывода кол-ва оставшихся бомб

## 5. Правки в логике

Теперь генерация расположения бомб происходит только в момент первого нажатия на поле для исключения проигрыша первым шагом
Добавлена поддержка нажатий левой и правой кнопками мыши, удалена кнопка изменения режима
Добавлено запрещение установки флага до момента первой открытой клетки
Поправлено изменение размеров окна и прикрепленных к нему кнопок

## 6. Добавление изображений

Созданы изображения
Вывод количества оставшихся бомб переделано на картинки, поле вывода из Sidebar'а удалено
Привязаны картинки к клеткам, реализовано изменение привязанной картинки
Для картинок произвезведена попытка оптимизации памяти

## 7. Добавлен таймер игровой сессии

## 6. Отладка

## 7. Конечный результат
