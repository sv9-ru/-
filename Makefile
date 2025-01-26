complex: bin/obj/mycomplex.o bin/obj/testcmp.o
	g++ -o bin/complex bin/obj/mycomplex.o bin/obj/testcmp.o

# Правило для компиляции mycomplex.o
bin/obj/mycomplex.o: mycomplex.cpp mycomplex.h
	if not exist bin\obj mkdir bin\obj
	g++ -o bin/obj/mycomplex.o -c mycomplex.cpp

# Правило для компиляции testcmp.o
bin/obj/testcmp.o: testcmp.cpp
	if not exist bin\obj mkdir bin\obj
	g++ -o bin/obj/testcmp.o -c testcmp.cpp

# Правило для очистки сгенерированных файлов
clean:
	del /Q bin\obj\*.o bin\complex
