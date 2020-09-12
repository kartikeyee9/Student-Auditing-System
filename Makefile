sas:	main.o Storage.o Student.o Course.o Control.o View.o  Monitor.o StuServer.o
	g++ -o sas main.o Storage.o Student.o Course.o Control.o View.o Monitor.o StuServer.o


main.o:	main.cc Control.h
	g++ $(OPT) -c main.cc

Control.o:	Control.cc Control.h
	g++ -c Control.cc

Monitor.o:	Monitor.cc Monitor.h
	g++ -c Monitor.cc



View.o:	View.cc View.h
	g++ -c View.cc

Storage.o:	Storage.cc Storage.h Student.h defs.h
	g++ -c Storage.cc

Student.o:	Student.cc Student.h Course.h defs.h List.h
	g++ -c Student.cc

Course.o:	Course.cc Course.h
	g++ -c Course.cc


clean:
	rm -f main.o Storage.o Student.o Course.o List.o Control.o View.o  Monitor.o  sas
