# lab4_sem3_dange_walker
My first game with SFML engine.
This game is about hero, who walks through a dangerous dangen and has fiteings with different monsters.

# Correct project structure

src
    // sdd
test
    lib
        googletest-main
    // nothing interesting
CMakeLists.txt

# General recomendations for installation and launching

Перехожу на русский, чтоб понятнее было.
Во первых могут возникнуть проблемы с путями. Я постараюсь выкорчевать все места, где используется абсолютный путь.
Но вполне возможно, что я чего-то не учту, и Вам придётся вручную искать место с проблемой.
Если я знал место, где удалить абс. путь невозможно, оставлю указание здесь, где и что поменять:
// pathes

В любом случае все обращения к логам обёрнуты в исключения. Все абс. пути хранятся в constants.hpp

Далее по библиотекам. Я пользовался sfml, google-tests и утилитой doxygen. Документация уже будет сгенерирована, так что в последней нет нужды, да и тесты Вы вряд ли захотите запускать - так что обязательна к установке только последняя.

Проект должен собираться в любой IDE работающей с cmake. Следующие инструкции для сборки и использования:

Собирать цель: Game_finall или all. Запускать Game_finall для игры. Остальное по усмотрению.
Сборка вручную через терминал:

