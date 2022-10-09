first block project in skillfactory

Пожалуйста, по возможности осуществите компиляцию с флагом -D LINUX или -D WIN, для поддержки очистки экрана.
```
СПИСОК УЧАСТНИКОВ: Владислав Юсов
```
```
ИДЕЯ РЕШЕНИЯ:
В решении я создал три класса - Server, User, Room.
  Взаимодействие между этими классами происходит через функции, не являющиеся
членами классов.

  Для примера в функции main создается сервер.
  Для логина в нём или регистрации используется функция void entry().
  Далее в зависимости от выбора пользователя - вызываются функции для логина
или регистрации.
  В моем решении функции вызываются одна из другой, что позволяет создать
иллюзию текстового меню.
  Таким образом например возврат в предыдущее меню осуществляется путем
завершения текущей функции.

Порядок вызова основных функций:
           entry()
          /       \
    login ()      reg()
       |
   userSpace()

  Эти функции являются friend для класса Server.
  Server имеет два вектора. Один с пользователями, зарегистрированными на сервере.
  Другой с созданными комнатами. Для обмена сообщениями с другими участниками,
юзер должен быть подключен к определенной комнате.
  Обмен сообщениями будет только между участниками внутри этой комнаты.

  По умолчанию Server имеет комнату "general".
Все пользователи, впервые залогинившиеся, попадают в эту комнату.
В дальнейшем юзер может сменить комнату.
  
  Класс User имеет указатель на комнату, к которой он в данный момент подключен.
Аналогично класс Room имеет вектор с указателями на Юзеров, находящихся в комнате.
Юзер знает в какой он комнате, и комната знает, какие в ней Юзеры.
Для регулирования этого отношения есть функция join(), являющаяся friend для User и Room.

  Функция join() осуществляет обмен указателями между User и Room,
устанавливает указатель на комнату в User, и добавляет указатель на User в вектор Room.
  Функция join() не допускает разных указателей.
  Таким образом, не может быть, чтобы Комната думала что в ней есть Юзер,
который может быть подключенк другой комнате (как и обратное).
  При смене комнаты Юзером, join() заботится об удалении Юзера из Комнаты.
  
  Классы Room и User имеют вектора с сообщениями.
  Сами сообщения представляются в виде структуры: name, message.
  Где name - имя пользователя, отправившего сообщение, а message - само сообщение.
  Соответственно для отправки общего сообщения для всех пользователей в комнате,
необходимо работать с вектором в Room, а для приватных сообщений с вектором в User.
  
  Пользователь имеет возможность отправлять приватные сообщения другим пользователям,
зарегистрированным на сервере.
  При этом неважно, находятся ли они в одной комнате или разных.
  Поиск пользователя осуществляется на всём сервере.
```

```
ПРОСТРАНСТВО ПОЛЬЗОВАТЕЛЯ:
  Функция userSpace() вызывается при успешном логе на сервере.
  Если пользователь не был подключен к какой либо комнате, то по умолчанию
в функции userSpace() происходит подключение к дефолтной комнате "general" на сервере.
  У пользователя есть возможность отправлять команды прямо во время ввода.
  Для этого необходимо добавить в начале сообщения символ ':'.
  
  На данный момент список возможных команд следующий:
  :list - отображает пользователей в комнате;
  :room - отображает имя текущей комнаты;
  :join - смена комнаты. Пример: ":join second";
  :user - обращение к пользователю. Пример: ":user another_user";
    Если после имени пользователя нет аргументов, предлагается ввод сообщения
для отправки ему, иначе все переданные аргументы интерпретируются как сообщение.
  :priv - отображает НОВЫЕ приватные сообщения;
  :out (эквивалент :q) - выход из учетной записи;
  :exit - выход из программы;
  :help - вывод текущей справки.
```

```
ЗАКЛЮЧЕНИЕ:
  Мое решение не идеально, мне пришлось все делать в сжатые сроки.
  В некоторых местах команды дублируются, а обилие friend-функций
не совсем укладывается в концепцию ООП.
  Также были задумки унаследовать классы User, Room от абстрактного базового
класса IChat, т.к. есть схожий функционал. В дальнейшем пришлось от этой идеи отказаться.
  Я решил что других схожих абстракций в проекте не будет.
  Но также не стал финализировать User и Room, т.к. открывается возможность создавать
к примеру СуперПользователя, у которого будет возможность по модерированию на сервере,
созданию и удалению комнат и юзеров и т.д.
  Также я не создал проверки на валидность логина, пароля и имени при создании юзера, но
при ошибке ввода, генерируется исключение.
  Пожалуйста, предложите ваш варинат организации такой программы.
```
