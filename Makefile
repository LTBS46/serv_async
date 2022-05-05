default:: out/main

.SILENT: status
.PHONY:
.INTERMEDIATE:
.ONESHELL:

CPP_FLAGS=-std=c++20 -pthread -I src -c -O3 -mavx2
LK_FLAGS=-pthread -O3
LD_FLAGS=-relocatable

################################################################################
# main
################################################################################

out/main:: bin/Command.o bin/main.o bin/parser.o\
		bin/queue.o bin/regex.o
	g++ $^ -o $@ $(LK_FLAGS)

################################################################################
# reloc object
################################################################################

bin/Command.o:: bin/Command/Exit.o
	ld $(LD_FLAGS) -o $@ $^

################################################################################
# object /Command/
################################################################################

bin/Command/Exit.o:: src/Command/Exit.cpp src/Command/Exit.hpp bin/Command\
		Makefile
	g++ $(CPP_FLAGS) $< -o $@

################################################################################
#objects
################################################################################

bin/main.o:: src/main.cpp bin Makefile
	g++ $(CPP_FLAGS) $< -o $@

bin/parser.o:: src/parser.cpp bin Makefile
	g++ $(CPP_FLAGS) $< -o $@

bin/queue.o:: src/queue.cpp bin Makefile
	g++ $(CPP_FLAGS) $< -o $@

bin/regex.o:: src/regex.cpp bin Makefile
	g++ $(CPP_FLAGS) $< -o $@

################################################################################
# sources dependencies
################################################################################

src/main.cpp:: src/queue.hpp src/Command/Exit.hpp Makefile
	touch $@

src/parser.cpp:: src/parser.hpp src/regex.hpp src/Command/Exit.hpp\
		src/User/Host.hpp src/Command/Error.hpp Makefile
	touch $@

src/queue.cpp:: src/queue.hpp Makefile
	touch $@

src/regex.cpp:: src/regex.hpp Makefile
	touch $@

################################################################################
# sources dependencies /Command/
################################################################################

src/Command/Exit.cpp:: src/Command/Exit.hpp src/User/Host.hpp Makefile
	touch $@

################################################################################
# headers dependencies
################################################################################

src/Callable.hpp:: src/Object.hpp Makefile
	touch $@

src/parser.hpp:: src/Command/Base.hpp src/User/Base.hpp Makefile
	touch $@

src/queue.hpp:: src/Command/Base.hpp Makefile
	touch $@

################################################################################
# headers dependencies /Command/
################################################################################

src/Command/Base.hpp:: src/User/Observer.hpp src/Callable.hpp Makefile
	touch $@

src/Command/Echo.hpp:: src/Command/Log.hpp Makefile
	touch $@

src/Command/Error.hpp:: src/Command/Log.hpp Makefile
	touch $@

src/Command/Exit.hpp:: src/Command/Base.hpp Makefile
	touch $@

src/Command/Log.hpp:: src/Command/Base.hpp Makefile
	touch $@

################################################################################
# headers dependencies /User/
################################################################################

src/User/Base.hpp:: src/Object.hpp Makefile
	touch $@

src/User/Host.hpp:: src/User/Base.hpp Makefile
	touch $@

src/User/Observer.hpp:: src/User/Base.hpp Makefile
	touch $@

################################################################################
# folder
################################################################################

out:: Makefile
	if [ -e $@ ];then touch $@;else mkdir $@;fi

bin:: Makefile
	if [ -e $@ ];then touch $@;else mkdir $@;fi

bin/Command:: bin Makefile
	if [ -e $@ ];then touch $@;else mkdir $@;fi

bin/User:: bin Makefile
	if [ -e $@ ];then touch $@;else mkdir $@;fi

################################################################################
# misc
################################################################################

status::
	echo $(shell whoami) $(shell arch) $(shell uname)
