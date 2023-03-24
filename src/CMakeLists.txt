add_executable(main 
    main.cpp
    Program.cpp
    Container.cpp)

target_link_libraries(main PRIVATE sfml-graphics)
