# Как настроить GTest

1. Создать новый проект
    * Тип: Console application
        - Без всяких галочек 
2. Удалить всю фигню
3. Скопировать 
    * contrib\include\gtest\/*.h
    * contrib\lib\gtest.lib, gtest_main.lib, gtestd.lib, gtest_maind.lib
4. Project properties
    *  C/C++ -> Code Generation -> Runtime Library = Multi-threaded Debug (/MTd)
    *  C/C++ -> General -> Additional Include Directories
        -  contrib\include
    *  Linker -> General -> Additional Library Directories
        -  contrib\lib
        -  Да, вам надо было собрать gtest солюшн. Разве вы еще не собрали?
    *  Linker -> Input -> Additional Dependencies += gtest.lib/gtestd.lib
5. 
