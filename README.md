# Kursov_Proekt_4k_1s
/-/
    Overview: GSL is a C-based library for numerical computing, featuring a modern API and encompassing various areas of numerical computing.

    Content: It includes routines for areas like complex numbers, polynomials, linear algebra, random numbers, and more. The manual explains these with definitions, examples, and references.

    Free Software: GSL is free software, available for use, modification, and redistribution under certain conditions.

    Obtaining GSL: Instructions for obtaining the library, including downloading and subscription details for updates, are provided.

    No Warranty: GSL comes with no warranty and is provided 'as is'.

    Reporting Bugs: Details on how to report bugs, including required information, are given.

    Further Information: Additional resources and contact information for questions are available.

    Conventions Used: The manual outlines conventions for terminal commands and examples, primarily using the GNU operating system and the Bourne shell syntax.
/-/

Сега ще се опитам да компилирам библиотеката.

/-/
###КОНФИГУРАЦИЯ###

Явно GNU разработчиците следват стандартна структура на своите проекти (Хипотеза 1- наблюдавайки спрямо GNUMP, структурата и инструкциите за инсталация и конфигурация на библиотеката са идентични, дори и конфигурационният файл използва подобни параметри)

#Хипотеза 2# - използваме "./configure --prefix="<dump_directory_of_lib_obj_files>""

Действие - компилирах, билднах и експортирах готовата библиотека и хедърни файлове за цялата библиотека, която в частност съдържа cblas.
 
Сега ще прегледам cblas файловете директно, опитвайки се да проследя как фуннкционират атомично, най-минималното което трябва да прегледам е как се случва обръщението към атомична функция като сумиране и вследствие как се извършва изчислителният процес.

#Хипотеза 3# - вероятно cblas представлява набор от инструкции в C код, директно за изпълнение върху CPU, а не GPU.

#Наблюдение 1# - след конфигурация, компилация и експорт на CBLAS, в директорията са останали и хедърните файлове които всъщност са дефиниции в C код, които би трябвало вече да са оптимално пригодени за използване върху моята хардуерна среда на обкръжение.

###АНАЛИЗ 1 - "dasum.c","source_asum_c.h"###

