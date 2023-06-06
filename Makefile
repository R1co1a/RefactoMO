
mo53 : main.o calculation.o linked_list.o loader.o process.o resource_manager.o storage_type.o writer.o
	g++ -o mo53 main.o calculation.o linked_list.o loader.o process.o resource_manager.o storage_type.o writer.o

main.o : main.cpp resource_manager.cpp process.cpp
	g++ -o main.o -cpp main.cpp resource_manager.cpp process.cpp

calculation.o : calculation.cpp
	g++ -o calculation.o -cpp calculation.cpp

linked_list.o : linked_list.cpp
	g++ -o linked_list.o -cpp linked_list.cpp

loader.o : loader.cpp
	g++ -o loader.o -cpp loader.cpp

process.o : process.cpp
	g++ -o process.o -cpp process.cpp

resource_manager.o : resource_manager.cpp
	g++ -o resource_manager.o -cpp resource_manager.cpp

storage_type.o : storage_type.cpp
	g++ -o storage_type.o -cpp storage_type.cpp

writer.o : writer.cpp
	g++ -o writer.o -cpp writer.cpp

