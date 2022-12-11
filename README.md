# lab4_sem3_dange_walker
My first game with SFML engine.
This game is about hero, who walks through a dangerous dangen and has fiteings with different monsters.
## *_Gameplay demonstration_*
    https://youtu.be/QkKNZsThOO8

# Correct project structure
* _vs_code_game_
    * src
        * alive_obj/
        * backpack_menu/
        * containers/
        * docs
            * Doxyfile.in
        * draw/
        * environment/
        * game/
        * libs
            * glfw-3.3.8/
            * SFML/
        * menu/
        * my_stl_containers
            * dcs
                * Doxyfile.in
            * doxygen (скорее всего не нужна, если есть в системе)
            * include/
            * src
                * tests/
                * vector/
            >files
        * objects/
        * physics/
        * sfml_classes/
        * static (все логи, текстуры и звуки)
            * font/
            * img/
            * logs/
            * sound/
        * weapon/
        >files     
    * test
        * lib
            * googletest-main/
        >files
    >files

# General recomendations for installation and launching

Перехожу на русский, чтоб понятнее было.

## _Зависимости_
Во первых могут возникнуть проблемы с путями. Я постараюсь выкорчевать все места, где используется абсолютный путь.
Но вполне возможно, что я чего-то не учту, и Вам придётся вручную искать место с проблемой.
Если я знал место, где удалить абс. путь невозможно, оставлю указание здесь, где и что поменять:

> constants.hpp : line 92
> возможно где-то в CMake проглядел. Смотрите по сборке

В любом случае все обращения к логам обёрнуты в исключения. Все абс. пути хранятся в constants.hpp

## _Библиотеки_
Далее по библиотекам. Я пользовался sfml, glfw, google-tests и утилитой doxygen. Документация уже будет сгенерирована, так что в последней нет нужды, да и тесты Вы вряд ли захотите запускать - так что обязательна к установке только последняя.

## _Сборка_
Проект должен собираться в любой IDE работающей с cmake. Следующие инструкции для сборки и использования:

* Собирать цель: Game_finall или all.
* Запускать Game_finall для игры.
* Остальное по усмотрению.

Сборка вручную через терминал:

* открываем терминал в vs_code_game/ \
 >  \> mkdir build    \
    \> cmake ..       \
    \> cd src         \
    \> make
* проект собран. можно запускать: \
>   \> ./Game_finall

P.S: в дополнение к коду ещё генерируется актуальная документация в папочку doc_doxygen :)

## *Документация*
К коду прилагается авто-документация doxygen. Находится в vs_code_game/src/docs/doc_doxygen/. В VS Code можно запустить на Live-server. Главный файл - index.html. Как запустить думаю сообразите.
При желании можете нагенерировать свежую документацию например из vs_code_game/ : \
> \> doxygen src/docs/Doxyfile.in

## *Удачи*